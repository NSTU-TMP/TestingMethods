#include "polish_notation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "stack.h"

struct stack* parse_input_in_polish_notation(char* input) {
  input = str_transformation(input);
  struct stack *res = NULL, *oper = NULL;
  char* num = NULL;
  while (*input != '\0') {

    if (*input == '(' && *(input + 1) == ')') input += 2;
    if (is_math_symbol(*input) || is_func(*input)) {
      if (oper == NULL || priority_compare(*input, pick(oper))) {
        oper = push(oper, *input);
      } else {
        while (oper != NULL && !priority_compare(*input, pick(oper)) &&
               pick(oper) != '(') {
          res = push(res, pick(oper));
          oper = pop(oper);
        }
        oper = push(oper, *input);
        if (*input == '(') oper = push(oper, *input);
      }
      if (*input != '\0') input++;
    }
    if (is_num(*input)) {
      input = get_num(input, &num);
      if (*num != 'x') {
        res = push_num(res, atof(num));
      } else {
        res = push(res, *num);
      }
      free(num);
    }
    if (*input == ')') {
      while (oper->data != '(') {
        res = push(res, pick(oper));
        oper = pop(oper);
      }
      oper = pop(oper);
      input++;
    }
  }
  while (oper != NULL) {
    res = push(res, pick(oper));
    oper = pop(oper);
  }
  destroy(oper);
  return res;
}
