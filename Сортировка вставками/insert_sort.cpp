#include "insert_sort.hpp"

template <typename T>
std::vector<T> insertion_sort(std::initializer_list<T> list) {
	std::vector<T> vec = list;
	for (int index = 1; index < vec.size(); index++) {
		int index_for_while = index;
		int key = vec[index_for_while--];
		while (index_for_while >= 0 and key <= vec[index_for_while]) {
			vec[index_for_while + 1] = vec[index_for_while];
			index_for_while--;
		}
		vec[index_for_while + 1] = key;
	}
	return vec;
}