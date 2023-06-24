#include "Test.h"

Test::Test() {
  
}

Test::run_all_test() {
  wp.test();
  wpc.test();
  qc.test();
  cout << "Tests passed!"
}
