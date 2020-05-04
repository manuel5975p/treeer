#include <catch2/catch.hpp>

#include "treeer.hpp"

TEST_CASE("get_valid_starting_point")
{
	tree_node singleton {};

	auto start = get_valid_starting_point(singleton, 0);
	REQUIRE(start);
	CHECK(start == &singleton);
	CHECK(get_valid_starting_point(singleton, 1) == nullptr);

	tree_node one_child {};
	one_child.children.push_back(std::make_unique<tree_node>());
	start = get_valid_starting_point(one_child, 0);
	REQUIRE(start);
	CHECK(start == &one_child);

	start = get_valid_starting_point(one_child, 1);
	REQUIRE(start);
	CHECK(start == &one_child);

	start = get_valid_starting_point(one_child, 2);
	CHECK(!start);
}
