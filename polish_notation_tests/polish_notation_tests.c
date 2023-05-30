#include "polish_notation_tests.h"

#include "stack.h"

void print_stack(FILE* output_stream, struct stack* stc) {
  struct stack* runner = stc;
  int i = 0;
  while (runner != NULL) {
    fprintf(output_stream, "Index = %d\nNum=%f\nData=%c\n", i, runner->num,
            runner->data);
    ++i;
    runner = runner->next;
  }
}

int is_stack_equal(struct stack* stc_1, struct stack* stc_2) {
  struct stack* runner_1 = stc_1;
  struct stack* runner_2 = stc_2;
  while (runner_1 != NULL && runner_2 != NULL) {
    if (runner_1->data != runner_2->data || runner_1->num != runner_2->num) {
      return 0;
    }
    runner_1 = runner_1->next;
    runner_2 = runner_2->next;
  }
  if (runner_1 != runner_2) {
    return 0;
  }
  return 1;
}

void polish_notation_assert_test_result(FILE* output_stream, int test_num,
                                        struct stack* real_stack,
                                        struct stack* test_stack) {
  fprintf(output_stream, "TEST #%d\n", test_num);
  if (is_stack_equal(test_stack, real_stack)) {
    fprintf(output_stream, "PASSED\n");
  } else {
    fprintf(output_stream, "FAILED\n");
    fprintf(output_stream, "EXPECTED:\n");
    print_stack(output_stream, real_stack);
    fprintf(output_stream, "RETURNED:\n");
    print_stack(output_stream, test_stack);
  }
}
