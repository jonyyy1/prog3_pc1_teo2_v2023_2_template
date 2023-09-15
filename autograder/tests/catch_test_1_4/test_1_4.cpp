//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "P1.h"
using namespace std;

static void test_1_4() {
  enum navy { sea, torpedo, bomber, submarine };
  battleship::board<navy, 5, navy::sea> bb = {
      sea, bomber, sea,       sea, sea,
      sea, sea,    sea,       sea, sea,
      sea, sea,    submarine, sea, sea,
      sea, sea,    sea,       sea, sea,
      sea, sea,    torpedo  , sea, sea,
  };
  cout << bb;
  cout << string(13,'-') << endl;
  battleship::board<navy, 5, navy::sea> bb2;
  bb2 = bb;
  bb2(4, 0) = bomber;
  for (int i = 0; i < bb2.cells(); ++i) {
    for (int j = 0; j < bb2.cells(); ++j) {
      switch (bb2(i, j)) {
      case sea:
        cout << setw(4) << "~";
        break;
      case torpedo:
        cout << setw(4) << "T";
        break;
      case bomber:
        cout << setw(4) << "B";
        break;
      case submarine:
        cout << setw(4) << "S";
        break;
      }
    }
    cout << endl;
  }
  cout << string(13,'-') << endl;
  cout << bb;
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}