#include "fill_massiv.h"

std::vector<int> create_rand_massiv(int size, int min_rand_number, int max_rand_number) {
	std::vector<int> massiv(size);
	for (int i = 0; i < size; i++) {
		srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		massiv[i] = min_rand_number + (rand() % (max_rand_number - min_rand_number + 1));
	}
	return massiv;
}