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

static void test_2_4() {
  std::vector<float> v1 = {1.1f, 8, 3, 5};
  std::list<float> l1 = {1.5f};
  std::deque<float> d1 = {4, 2.4f};
  std::deque<float> d2 = {8, 2.1f, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated<std::deque>(v1, l1, d1, d2);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}