#ifndef POLISH_NOTATION_TESTS_H_
#define POLISH_NOTATION_TESTS_H_

#include <stdio.h>
#include <stdlib.h>

#include "polish_notation.h"

void print_stack(FILE* output_stream, struct stack* stc);

int is_stack_equal(struct stack* stc_1, struct stack* stc_2);

void polish_notation_assert_test_result(FILE* output_stream, int test_num,
                                        struct stack* real_stack,
                                        struct stack* test_stack);

polish_notation_run_test_1(output_stream);
polish_notation_run_test_2(output_stream);
polish_notation_run_test_3(output_stream);

#endif  // SHADOW_CALCULATOR_SEGMENT_TESTS_H_