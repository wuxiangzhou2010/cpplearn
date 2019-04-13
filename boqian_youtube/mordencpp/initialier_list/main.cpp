#include <iostream>
#include <vector>




class myvector {
    std::vector<int> m_vec;
public:

    myvector(const std::initializer_list<int> &v) {
        for(const auto &itr :v) {
            m_vec.push_back(itr);
        }
    }
};

int main() {
    int arr[] = {2,3,4,5};
    std::vector<int> v = {2,3,4,5};
    std::vector<int> v2 {2,3,4,5};
    std::cout << "Hello, World!" << std::endl;
    myvector mv = {1,2,36,4};
    myvector mm{1,2,45,6};
    return 0;
}


