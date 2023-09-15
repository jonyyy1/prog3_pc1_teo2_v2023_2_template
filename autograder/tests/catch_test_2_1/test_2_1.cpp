//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P2.h"
#include <vector>
#include <list>
#include <deque>
using namespace std;

static void test_2_1() {
  std::vector<int> v1 = {5, 7, 9, 2};
  std::vector<int> v2 = {1, 8, 3, 5};
  std::list<int> l1 = {6, 8, 2, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1, v2, l1);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}