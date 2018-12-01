#include <iostream>
#include <set>
#include <assert.h>
#include <optional>
#include <vector>

std::vector<long int> parseInput() {
	std::vector<long int> v;
	char sign;
	while (std::cin >> sign) {
		long int frequency_change;
		std::cin >> frequency_change;
		if (sign == '-') {
			frequency_change *= -1;
		} else {
			assert(sign == '+');
		}
		v.push_back(frequency_change);
	}
	return v;
}
// Read from stdin
int main() {
	std::vector<long int> input = parseInput();

	long int total_frequency = 0;
	for (auto frequency_change : input) {
		total_frequency += frequency_change;
	}

	auto curr_total = 0;
	std::set<long int> reached_freqs = { curr_total };
	std::optional<long int> first_reacked_twice = {};
	auto index = 0;

	while (!first_reacked_twice.has_value()) {
		auto curr_val = input[index];

		curr_total += curr_val;
		if (reached_freqs.find(curr_total) == reached_freqs.end()) {
			reached_freqs.insert(curr_total);
		} else {
			first_reacked_twice = { curr_total };
		}

		index = (index + 1) % input.size();
	}


	std::cout << "total_frequency: " << total_frequency << std::endl;

	std::cout << "first_reached_twice: " << first_reacked_twice.value() << std::endl;
	return 0;
}
