//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
using namespace std;

static void test_1_1() {
  battleship::board<char, 8, '~'> bb;
  cout << bb;
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}