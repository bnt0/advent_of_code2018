#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct Point {
	uint x, y;

	struct Hash {
		std::size_t operator()(const Point& p) const {
			return p.x << 1 ^ p.y;
		}
	};

	bool operator==(const Point& p) const {
		return x == p.x && y == p.y;
	}
};

struct Rectangle {
	Point top_left;
	uint width;
	uint height;
	uint id;
	Rectangle(Point&& p, uint w, uint h, uint id) : top_left(std::move(p)), width(w), height(h), id(id) {};
};

std::vector<Rectangle> parseInput() {
	std::vector<Rectangle> v;
	char separator;

	while (std::cin >> separator) {
		assert(separator == '#');
		uint id;
		std::cin >> id;

		std::cin >> separator;
		assert(separator == '@');

		Point top_left = {0, 0};
		std::cin >> top_left.x;

		std::cin >> separator;
		assert(separator == ',');

		std::cin >> top_left.y;

		std::cin >> separator;
		assert(separator == ':');

		uint width, height = 0;
		std::cin >> width;

		std::cin >> separator;
		assert(separator == 'x');

		std::cin >> height;
		v.emplace_back(std::move(top_left), width, height, id);
	}

	return v;
}

uint getNotOverlappingClaim(const std::vector<Rectangle>& v, const std::unordered_set<Point, Point::Hash>& double_filled_points) {
	for (const auto& r : v) {
		bool may_be_the_one = true;
		for (uint x = r.top_left.x; x < r.top_left.x + r.width && may_be_the_one; x++) {
			for (uint y = r.top_left.y; y < r.top_left.y + r.height; y++) {
				Point p{x, y};
				if (double_filled_points.find(p) != double_filled_points.end()) {
					may_be_the_one = false;
					break;
				}
			}
		}
		if (may_be_the_one) {
			return r.id;
		}
	}
	assert(false);
}

int main() {
	auto v = parseInput();

	// bit lame
	std::unordered_set<Point, Point::Hash> filled_points = {};
	std::unordered_set<Point, Point::Hash> double_filled_points = {};
	for (const auto& r : v) {
		for (uint x = r.top_left.x; x < r.top_left.x + r.width; x++) {
			for (uint y = r.top_left.y; y < r.top_left.y + r.height; y++) {
				Point p{x, y};
				if (filled_points.find(p) != filled_points.end()) {
					double_filled_points.insert(std::move(p));
				} else {
					filled_points.insert(std::move(p));
				}
			}
		}
	}

	std::cout << "good_fabric_area: " << double_filled_points.size() << std::endl;

	std::cout << "not_overlapping_id: " << getNotOverlappingClaim(v, double_filled_points) << std::endl;

	return 0;
}
