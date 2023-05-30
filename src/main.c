
#include "polish_notation_tests.h"
#include "shadow_calculator_tests.h"

void run_shadow_calc_tests(FILE* output_stream) {
  shadow_calc_run_test_1(output_stream);
  shadow_calc_run_test_2(output_stream);
  shadow_calc_run_test_3(output_stream);
  shadow_calc_run_test_4(output_stream);
  shadow_calc_run_test_5(output_stream);
  shadow_calc_run_test_6(output_stream);
  shadow_calc_run_test_7(output_stream);
  shadow_calc_run_test_8(output_stream);
}

void run_polish_notation_tests(FILE* output_stream) {
  polish_notation_run_test_1(output_stream);
  polish_notation_run_test_2(output_stream);
  polish_notation_run_test_3(output_stream);
}

int main() {
  run_polish_notation_tests(stdout);
  return 0;
}
