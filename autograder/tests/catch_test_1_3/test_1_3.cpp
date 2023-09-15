//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
#include <algorithm>
using namespace std;

static void test_1_3() {
  battleship::board<int, 4> bb;
  battleship::board<int, 4> bb2 {
      0, 0, 3, 0,
      0, 0, 0, 0,
      0, 0, 0, 4,
      1, 0, 0, 0,
  };
  cout << bb;
  cout << string(10, '-') << endl;
  cout << bb2;
  cout << string(10, '-') << endl;
  std::swap(bb, bb2);
  cout << bb;
  cout << string(10, '-') << endl;
  cout << bb2;
  cout << string(10, '-') << endl;
  auto [is_shooted, navy] = bb.shoot(3, 0);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  std::tie(is_shooted, navy) = bb.shoot(3, 3);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  std::tie(is_shooted, navy) = bb.shoot(0, 2);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  battleship::board<char, 4, '~'> bb3 {
      '~', '~', '~', '~',
      '~', 'C', 'A', '~',
      '~', '~', '~', '~',
      '~', 'B', '~', '~',
  };
  auto [is_shooted_char, char_navy] = bb3.shoot(3, 1);
  cout << boolalpha << is_shooted_char << " " << char_navy << endl;
  std::tie(is_shooted_char, char_navy) = bb3.shoot(1, 1);
  cout << boolalpha << is_shooted_char << " " << char_navy << endl;
  cout << bb3;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}