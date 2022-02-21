#include<iostream>
using namespace std;
#include"randomarray.cpp"
#include"elapsed_time.h"

void sort_array(double *a, int n) {

	// what goes here?
  float swapped;
  start_timer();
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-2; j++) {
      if (a[j] > a[j+1]) {
        swapped = a[j];
        a[j] = a[j+1];
        a[j+1] = swapped;
      }
    }
  }
  double cycles = elapsed_time();
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
