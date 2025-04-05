#include <iostream>
#include "fill_massiv.h"

#define SIZE 10
#define MIN 50
#define MAX 2515

void select_sort(std::vector<int>& massiv) {
    for (int first_iterator = 0; first_iterator < massiv.size(); first_iterator++) {
        int min_index = first_iterator;
        for (int i = first_iterator; i < massiv.size(); i++) {
            if (massiv[i] < massiv[min_index])
                min_index = i;
        }
        if (first_iterator != min_index) {
            int temp = massiv[first_iterator];
            massiv[first_iterator] = massiv[min_index];
            massiv[min_index] = temp;
        }
    }
}


int main()
{
    std::vector<int> massiv = create_rand_massiv(5000, MIN, MAX);
    select_sort(massiv);
    for (auto el : massiv) {
        std::cout << el << " ";
    }
}