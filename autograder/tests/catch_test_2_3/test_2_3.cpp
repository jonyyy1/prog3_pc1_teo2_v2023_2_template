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

static void test_2_3() {
  std::vector<double> v1 = {5, 7, 9, 3.5};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}