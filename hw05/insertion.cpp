#include<iostream>
using namespace std;
#include"randomarray.cpp"
#include"elapsed_time.h"

void sort_array(double *a, int n) {

	// what goes here?
  float element;
  int max;

  start_timer();
  for (int i = 1; i < n; i++) {
      element = a[i];
      max = i-1;

      while(element < a[max] && max >= 0) {
        a[max+1] = a[max];
        --max;
      }
      a[max+1] = element;
  }
  double cycles = elapsed_time();  // also from elapsed_time.h
  cout << " Total cycles: " << cycles << endl;
}

int main() {
  cout << "Choose array size: ";
  int N;
  cin >> N;
  double *A = build_random_array(N);

  sort_array(A, N);

  if (N <= 100) {  // print out result for smaller sizes
    for (int i = 0; i < N; ++i) cout << A[i] << ' ';
    cout << endl;
  }
  delete [] A;
}
