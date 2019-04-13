#include <iostream>

void foo(int i) {std::cout<< "foo_int" << std::endl;}
void foo(char * pc){std::cout << "foo_char*"<< std::endl;}
int main() {
    //foo(NULL); // Ambiguity -- > error: call to 'foo' is ambiguous
    foo(0); // Ambiguity -- > error: call to 'foo' is ambiguous
    //c++11
    foo(nullptr); //call foo(char*)
}