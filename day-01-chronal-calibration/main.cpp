#include <iostream>
#include <assert.h>

// Read from stdin
int main() {
	long int total_frequency = 0;
	bool is_eof;
	while (std::iostream::traits_type::not_eof(std::cin.peek())) {
		char sign;
		long int frequency_change;
		std::cin >> sign;
		std::cin >> frequency_change;
		if (sign == '-') {
			frequency_change *= -1;
		} else {
			assert(sign == '+');
		}
		total_frequency += frequency_change;
		std::cin.get();
	}

	std::cout << total_frequency << std::endl;
	return 0;
}
