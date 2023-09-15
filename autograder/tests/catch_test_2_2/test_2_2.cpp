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

static void test_2_2() {
  std::vector<double> v1 = {5, 7, 9, 3.5};
  std::vector<double> v2 = {1.1, 8, 3, 5};
  std::list<double> l1 = {6.5, 3.0};
  std::list<double> l2 = {1.5};
  std::list<double> l3 = {4, 2.4};
  std::list<double> l4 = {8, 2.1, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1, v2, l1, l2, l3, l4);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}