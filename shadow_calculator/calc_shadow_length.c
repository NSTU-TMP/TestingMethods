
#include "segment.h"

float calc_shadow_length(segment *segments, size_t count) {
  if (!segments) {
    return -1;
  }
  quick_sort_by_left_bound(segments, 0, count - 1);

  float res = segments[0].right_bound - segments[0].left_bound;

  float current_right_bound = segments[0].right_bound;

  for (size_t i = 0; i < count - 1; i++) {
    if (segments[i + 1].right_bound > current_right_bound) {
      res += segments[i + 1].right_bound -
             (segments[i + 1].left_bound < segments[i].right_bound
                  ? segments[i].right_bound
                  : segments[i + 1].left_bound);
      current_right_bound = segments[i + 1].right_bound;
    }
  }

  return res;
}

void swap(segment *segments, int i, int j) {
  segment temp = segments[i];
  segments[i] = segments[j];
  segments[j] = temp;
}

int partition_by_left_bound(segment *segments, int low, int high) {
  float pivot = segments[high].left_bound;
  int i = low - 1;

  for (int j = low; j <= high - 1; ++j) {
    if (segments[j].left_bound < pivot) {
      ++i;
      swap(segments, i, j);
    }
  }
  swap(segments, i + 1, high);
  return i + 1;
}

void quick_sort_by_left_bound(segment *segments, int low, int high) {
  if (low < high) {
    int pi = partition_by_left_bound(segments, low, high);
    quick_sort_by_left_bound(segments, low, pi - 1);
    quick_sort_by_left_bound(segments, pi + 1, high);
  }
}