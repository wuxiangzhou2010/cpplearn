# kernel locking

Documentation/locking/mutex-design.txt

When acquiring a mutex, there are three possible paths that can be
taken, depending on the state of the lock:

(i) fastpath: tries to atomically acquire the lock by cmpxchg()ing the owner with
    the current task. This only works in the uncontended case (cmpxchg() checks
    against 0UL, so all 3 state bits above have to be 0). If the lock is
    contended it goes to the next possible path.

(ii) midpath: aka optimistic spinning, tries to spin for acquisition
     while the lock owner is running and there are no other tasks ready
     to run that have higher priority (need_resched). The rationale is
     that if the lock owner is running, it is likely to release the lock
     soon. The mutex spinners are queued up using MCS lock so that only
     one spinner can compete for the mutex.

     The MCS lock (proposed by Mellor-Crummey and Scott) is a simple spinlock
     with the desirable properties of being fair and with each cpu trying
     to acquire the lock spinning on a local variable. It avoids expensive
     cacheline bouncing that common test-and-set spinlock implementations
     incur. An MCS-like lock is specially tailored for optimistic spinning
     for sleeping lock implementation. An important feature of the customized
     MCS lock is that it has the extra property that spinners are able to exit
     the MCS spinlock queue when they need to reschedule. This further helps
     avoid situations where MCS spinners that need to reschedule would continue
     waiting to spin on mutex owner, only to go directly to slowpath upon
     obtaining the MCS lock.

(iii) slowpath: last resort, if the lock is still unable to be acquired,
      the task is added to the wait-queue and sleeps until woken up by the
      unlock path. Under normal circumstances it blocks as TASK_UNINTERRUPTIBLE.

While formally kernel mutexes are sleepable locks, it is path (ii) that
makes them more practically a hybrid type. By simply not interrupting a
task and busy-waiting for a few cycles instead of immediately sleeping,
the performance of this lock has been seen to significantly improve a
number of workloads. Note that this technique is also used for rw-semaphores.
