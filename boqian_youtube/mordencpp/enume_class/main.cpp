#include <iostream>

int main() {

//    enum apple {green_a, red_a,};
//    enum orange { big_o, small_o};
//
//    apple a =green_a;
//    orange o = big_o;
//
//    if (a == o) { //always true
//        std::cout <<"green apple and big orange are the same" << std::endl;
//    }
//    else {
//        std::cout<< "green apple and big orange are not the same " << std::endl;
//    }
//


//c++11
    enum class apple {green_a, red_a,};
    enum class orange { big_o, small_o};

    apple a =apple::green_a;
    orange o = orange::big_o;

    if (a == o) { // compile failed, because appe == orange is not defined
        std::cout <<"green apple and big orange are the same" << std::endl;
    }
    else {
        std::cout<< "green apple and big orange are not the same " << std::endl;
    }

    return 0;
}