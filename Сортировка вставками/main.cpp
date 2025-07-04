#include <iostream>
#include "insert_sort.cpp"

int main(int argc, char **argv)
{
	for (auto el : insertion_sort({ 4,3,2,8,9,15,44,32,4 })) {
		std::cout << el << std::endl;
	}
	system("pause");
}