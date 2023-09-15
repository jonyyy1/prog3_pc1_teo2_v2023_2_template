//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
using namespace std;

static void test_1_2() {
  battleship::board<char, 5, '~'> bb = {
      '~', 'D', '~', '~', '~',
      '~', '~', '~', '~', '~',
      '~', '~', 'B', '~', '~',
      '~', '~', '~', '~', 'C',
      '~', '~', '~', '~', '~',
  };
  cout << bb;
  cout << string(13,'-') << endl;
  auto bb2 = bb;
  bb2(4, 0) = 'A';
  cout << bb2;
  cout << string(13,'-') << endl;
  cout << bb;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}