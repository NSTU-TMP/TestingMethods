#include "shadow_calculator_tests.h"

void print_segments(FILE* output_stream, char* message, segment* segments,
                    size_t count) {
  fprintf(output_stream, message);

  for (size_t i = 0; i < count; ++i) {
    fprintf(output_stream,
            "segments[%ld].left_bound = %lf\nsegments[%ld].right_bound = %lf\n",
            i, i, segments[i].left_bound, segments[i].right_bound);
  }
}
void shadow_calc_assert_test_result(FILE* output_stream, int test_num,
                                    float real_result, float test_result,
                                    float eps) {
  fprintf(output_stream, "TEST #%d\n", test_num);
  if (abs(real_result - test_result) > eps) {
    fprintf(output_stream, "FAILED\n");
  } else {
    fprintf(output_stream, "PASSED\n");
  }
  fprintf(output_stream, "Expected: %f\nReturned: %lf\nDeifference: %lf \n",
          real_result, test_result, real_result - test_result);
}