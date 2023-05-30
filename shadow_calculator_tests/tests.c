
#include <stdio.h>
#include <stdlib.h>

#include "segment.h"
#include "shadow_calculator_tests.h"

void shadow_calc_run_test(FILE* output_stream, int test_num, segment* segments,
                          int count, float real_result, float eps) {
  float test_res = calc_shadow_length(segments, count);
  shadow_calc_assert_test_result(output_stream, test_num, real_result,
                                 calc_shadow_length(segments, count), eps);
}

void shadow_calc_run_test_1(FILE* output_stream) {
  int count = 5;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = 1;
  segments[0].right_bound = 5;

  segments[1].left_bound = 2;
  segments[1].right_bound = 8;

  segments[2].left_bound = 6;
  segments[2].right_bound = 7;

  segments[3].left_bound = 10;
  segments[3].right_bound = 12;

  segments[4].left_bound = 11;
  segments[4].right_bound = 16;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 1, 13,
                                 calc_shadow_length(segments, count), 0.1);

  free(segments);
}

void shadow_calc_run_test_2(FILE* output_stream) {
  int count = 4;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = 1;
  segments[0].right_bound = 10;

  segments[1].left_bound = 2;
  segments[1].right_bound = 5;

  segments[2].left_bound = 3;
  segments[2].right_bound = 6;

  segments[3].left_bound = 7;
  segments[3].right_bound = 8;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 2, 9,
                                 calc_shadow_length(segments, count), 0.1);

  free(segments);
}
void shadow_calc_run_test_3(FILE* output_stream) {
  int count = 5;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = 0;
  segments[0].right_bound = 4;

  segments[1].left_bound = 1;
  segments[1].right_bound = 7;

  segments[2].left_bound = 5;
  segments[2].right_bound = 6;

  segments[3].left_bound = 9;
  segments[3].right_bound = 11;

  segments[4].left_bound = 10;
  segments[4].right_bound = 15;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 3, 13,
                                 calc_shadow_length(segments, count), 0.1);

  free(segments);
}
void shadow_calc_run_test_4(FILE* output_stream) {
  int count = 5;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = 0.2;
  segments[0].right_bound = 4.2;

  segments[1].left_bound = 1.2;
  segments[1].right_bound = 7.2;

  segments[2].left_bound = 5.2;
  segments[2].right_bound = 6.2;

  segments[3].left_bound = 9.2;
  segments[3].right_bound = 11.2;

  segments[4].left_bound = 10.2;
  segments[4].right_bound = 15.2;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 4, 13,
                                 calc_shadow_length(segments, count), 0.001);

  free(segments);
}
void shadow_calc_run_test_5(FILE* output_stream) {
  int count = 5;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = -5;
  segments[0].right_bound = -2;

  segments[1].left_bound = -1;
  segments[1].right_bound = 7;

  segments[2].left_bound = 5;
  segments[2].right_bound = 6;

  segments[3].left_bound = 9;
  segments[3].right_bound = 11;

  segments[4].left_bound = 10;
  segments[4].right_bound = 15;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 5, 17,
                                 calc_shadow_length(segments, count), 0.001);

  free(segments);
}
void shadow_calc_run_test_6(FILE* output_stream) {
  int count = 1;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = -5;
  segments[0].right_bound = -2;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 6, 3,
                                 calc_shadow_length(segments, count), 0.001);

  free(segments);
}

void shadow_calc_run_test_7(FILE* output_stream) {
  int count = 2;
  segment* segments = (segment*)malloc(sizeof(segment) * count);

  segments[0].left_bound = -5;
  segments[0].right_bound = -2;
  segments[1].left_bound = -5;
  segments[1].right_bound = -2;

  float test_res = calc_shadow_length(segments, count);

  shadow_calc_assert_test_result(output_stream, 6, 3,
                                 calc_shadow_length(segments, count), 0.001);

  free(segments);
}

void shadow_calc_run_test_8(FILE* output_stream) {
  segment* segments = NULL;

  float test_res = calc_shadow_length(segments, 5);

  shadow_calc_assert_test_result(output_stream, 8, -1,
                                 calc_shadow_length(segments, 5), 0.001);

  free(segments);
}