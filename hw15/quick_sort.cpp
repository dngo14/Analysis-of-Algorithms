#include<iostream>
#include<cassert>
using namespace std;

int partition(double *a, int start_index, int end_index) {
  // your code here
  int pivot = a[start_index];
  int start = start_index+1;
  int end = end_index;

for (int i = 0; i < end_index; i++) {
    while (start < end && a[start] <= pivot) {
        start = start + 1;
    }
    while (end > start && a[end - 1] >= pivot) {
        end = end -1;
    }
    if (end <= start) {
        break;
    } else {
        int swap = a[start];
        a[start] = a[end - 1];
        a[end - 1] = swap;
    }
    }
    if (start != end -1) {
        int swap = a[start_index];
        a[start_index] = a[end - 1];
        a[end - 1] = swap;
    }
    return end;

}

void quick_sort(double *a, int start_index, int end_index) {
  // your code here
  if (end_index - start_index >= 2) {
      int split = partition(a, start_index, end_index);
      quick_sort(a, start_index, split);
      quick_sort(a, split, end_index);
  }

}

bool is_sorted(double *a, int num_elements) {
  for (int i = 0; i + 1 < num_elements; ++i)
    if (a[i] > a[i+1]) return false;
  return true;
}

int main() {
  double A[] = {.5, .3, .2, .7, .8, .1, .9, .4, .6};
  int N = sizeof(A)/sizeof(double);

  quick_sort(A, 0, N);

  assert(is_sorted(A, N));
}
