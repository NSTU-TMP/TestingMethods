#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
  char data;
  float num;
  struct stack *next;
};

struct stack *init(char val, float d);
struct stack *push(struct stack *h, char val);
struct stack *push_num(struct stack *h, float val);
struct stack *pop(struct stack *h);
void destroy(struct stack *h);
char pick(struct stack *h);
struct stack *reverse(struct stack *s);
int stack_size(struct stack *s);
int is_stack_equal(struct stack *stc_1, struct stack *stc_2);

#endif  // SRC_STACK_H_
