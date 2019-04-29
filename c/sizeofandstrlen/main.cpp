#include <iostream>
#include <mem.h>

void sizeofinfunc(char test[]) {
    std::cout << "strlen() in sizeofinfunc "<< strlen(test) << " sizeof in sizeofinfunc " <<  sizeof(test) << std::endl;
}
int main() {
    char test[] = "what a fine day today!";
    std::cout << "strlen() "<< strlen(test) << " sizeof " <<  sizeof(test ) << std::endl;
    sizeofinfunc(test);
    return 0;
}