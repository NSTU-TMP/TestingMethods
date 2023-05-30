#include "polish_notation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "stack.h"

struct stack* parse_input_in_polish_notation(char* input) {
  struct stack *pol_notation_expression = NULL, *operations = NULL;
  char* num = NULL;
  while (*input != '\0') {
    if (*input == '(' && *(input + 1) == ')') {
      input += 2;
    }
    if (is_math_symbol(*input) || is_func(*input)) {
      if (operations == NULL || priority_compare(*input, pick(operations))) {
        operations = push(operations, *input);
      } else {
        while (operations != NULL &&
               !priority_compare(*input, pick(operations)) &&
               pick(operations) != '(') {
          pol_notation_expression =
              push(pol_notation_expression, pick(operations));
          operations = pop(operations);
        }
        operations = push(operations, *input);
        if (*input == '(') {
          operations = push(operations, *input);
        }
      }
      if (*input != '\0') {
        input++;
      }
    }
    if (is_num(*input)) {
      input = get_num(input, &num);
      if (*num != UNNOKNW_WARRIABLE) {
        pol_notation_expression = push_num(pol_notation_expression, atof(num));
      } else {
        pol_notation_expression = push(pol_notation_expression, *num);
      }
      free(num);
    }
    if (*input == ')') {
      while (operations->data != '(') {
        pol_notation_expression =
            push(pol_notation_expression, pick(operations));
        operations = pop(operations);
      }
      operations = pop(operations);
      input++;
    }
  }
  while (operations != NULL) {
    pol_notation_expression = push(pol_notation_expression, pick(operations));
    operations = pop(operations);
  }
  destroy(operations);
  return pol_notation_expression;
}
