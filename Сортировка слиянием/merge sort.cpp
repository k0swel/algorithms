#include "merge sort.hpp"
#include <vector>

template<typename T>
std::vector<T> merge(std::vector<T>& left, std::vector<T>& right) {
    int i = 0, j = 0;
    std::vector<T> result;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        }
        else {
            result.push_back(right[j]);
            j++;
        }
    }
    for (; i < left.size(); i++)
        result.push_back(left[i]);
    for (; j < right.size(); j++)
        result.push_back(right[j]);
    return result;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> list) {
    if (list.size() <= 1)
        return list;
    int middle = list.size() / 2;
    std::vector<T> left(list.begin(), list.begin() + middle);
    std::vector<T> right(list.begin() + middle, list.end());
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

// Явная инстанциация для int
template std::vector<int> merge_sort<int>(std::vector<int>);
template std::vector<int> merge<int>(std::vector<int>&, std::vector<int>&);