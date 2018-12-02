#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<std::string> readInput() {
	std::vector<std::string> out;

	std::string curr;
	while (std::cin >> curr) {
		out.push_back(curr);
	}

	return out;
}

std::unordered_map<char, uint> countLetterFrequencies(std::string s) {
	std::unordered_map<char, uint> frequency_map;
	for (char c : s) {
		auto current_count = frequency_map.find(c);
		if (current_count == frequency_map.end()) {
			frequency_map.insert_or_assign(c, 1);
		} else {
			current_count->second++;
		}
	}
	return frequency_map;
}

uint checksum(const std::vector<std::string>& v) {
	uint num_2s = 0;
	uint num_3s = 0;

	for (const auto& s : v) {
		auto freqs = countLetterFrequencies(s);
		bool has_exactly_2 = false;
		bool has_exactly_3 = false;
		for (auto& it : freqs) {
			if (it.second == 2) {
				has_exactly_2 = true;
			} else if (it.second == 3) {
				has_exactly_3 = true;
			}
		}
		if (has_exactly_2) {
			num_2s++;
		}
		if (has_exactly_3) {
			num_3s++;
		}
	}
	uint checksum = num_2s * num_3s;

	return checksum;
}

bool hammond_distance_is_1(const std::string& s1, const std::string& s2) {
	assert(s1.length() == s2.length());
	bool has_one_diff = false;
	for (uint i = 0; i < s1.length(); i++) {
		if (!has_one_diff) {
			has_one_diff = s1[i] != s2[i];
		} else {
			if (s1[i] != s2[i]) {
				return false;
			}
		}
	}
	return true;
}

std::string get_common_part(const std::string& s1, const std::string& s2) {
	std::string common_part;
	for (uint i = 0; i < s1.length(); i++) {
		if (s1[i] == s2[i]) {
			common_part.push_back(s1[i]);
		}
	}
	return common_part;
}

std::string common_letters_brute_force(const std::vector<std::string>& v) {
	for (uint i = 0; i < v.size(); i++) {
		for (uint j = i + 1; j < v.size(); j++) {
			if (hammond_distance_is_1(v[i], v[j])) {
				return get_common_part(v[i], v[j]);
			}
		}
	}
	assert(false);
}

int main() {
	std::vector<std::string> v = readInput();
	uint sum = checksum(v);
	std::cout << "checksum: " << sum << std::endl;
	std::cout << "common_letters: " << common_letters_brute_force(v) << std::endl;

	return 0;
}