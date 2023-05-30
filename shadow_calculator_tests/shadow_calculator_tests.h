#ifndef SHADOW_CALCULATOR_SEGMENT_TESTS_H_
#define SHADOW_CALCULATOR_SEGMENT_TESTS_H_

#include <stdio.h>
#include <stdlib.h>

#include "segment.h"

void print_segments(FILE* output_stream, char* message, segment* segments,
                    size_t count);

void shadow_calc_assert_test_result(FILE* output_stream, int test_num,
                                    float real_result, float test_result,
                                    float eps);

void shadow_calc_run_test(FILE* output_stream, int test_num, segment* segments,
                          int count, float real_result, float eps);

void shadow_calc_run_test_1(FILE* output_stream);
void shadow_calc_run_test_2(FILE* output_stream);
void shadow_calc_run_test_3(FILE* output_stream);
void shadow_calc_run_test_4(FILE* output_stream);
void shadow_calc_run_test_5(FILE* output_stream);
void shadow_calc_run_test_6(FILE* output_stream);
void shadow_calc_run_test_7(FILE* output_stream);
void shadow_calc_run_test_8(FILE* output_stream);

#endif  // SHADOW_CALCULATOR_SEGMENT_TESTS_H_