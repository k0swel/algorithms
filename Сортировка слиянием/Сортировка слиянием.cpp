#include <iostream>
#include "merge sort.hpp"
#include <vector>

int main()
{
    std::vector<int> vec = { 4,3,2,8,9,15,44,32,4 };
    for (auto& el : merge_sort(vec)) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    system("pause");
}
