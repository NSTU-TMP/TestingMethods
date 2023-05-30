#ifndef SHADOW_CALCULATOR_SEGMENT_H_
#define SHADOW_CALCULATOR_SEGMENT_H_
#include <stdio.h>

typedef struct {
  float left_bound;
  float right_bound;
} segment;

float calc_shadow_length(segment *segments, size_t count);

void swap(segment *segments, int i, int j);

int partition_by_left_bound(segment *segments, int low, int high);

void quick_sort_by_left_bound(segment *segments, int low, int high);

#endif  // SHADOW_CALCULATOR_SEGMENT_H_