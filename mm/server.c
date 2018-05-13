#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8000
int main(void)
{
	int lfd; 
	int cfd;
	int len;
	char buf[1024];
       	socklen_t clin_len;	
	struct sockaddr_in serv_addr, clin_addr;
	// AF_INET: ipv4  SOCK_STREAM: STREAM 协议，0： tcp
	lfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_family =AF_INET;
	//IP + port
	bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	listen(lfd,128);
	clin_len = sizeof(clin_addr);
	cfd = accept(lfd, (struct sockaddr *)&clin_addr,&clin_len) ;

	len = 	read(cfd, buf, sizeof(buf));
	write(STDOUT_FILENO, buf, len);

	close(lfd);
	close(cfd);
	
	return 0;
}
