#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int lottery(int min, int max, std::vector<int>& exclude);
int main() {
	
	int max = 10;

	std::vector<int> exclusion = {};

	std::cout<<lottery(1,max,exclusion)<<"\n";
}

int lottery(int min, int max, std::vector<int>& exclusion) {
	std::random_device device;

	int result;
	std::default_random_engine eng(device());
	std::uniform_int_distribution<int> range(1, max);
	if (exclusion.size() == (max - min + 1)) {
		return -1;
	}
	while (std::find(exclusion.begin(), exclusion.end(), (result = range(eng))) != exclusion.end());

	return result;
}