#include<iostream>
using namespace std;
#include"randomarray.cpp"
#include"elapsed_time.h"

void sort_array(double *a, int n) {

	// what goes here?
  int minvalueplace;
  float swapped;

  start_timer();
  for (int i = 0; i < n-1; i++) {
      minvalueplace = i;
      for (int j = i+1; j < n; j++) {
          if (a[minvalueplace] > a[j]) {
              minvalueplace = j;
          }
      }
    swapped = a[i];
    a[i] = a[minvalueplace];
    a[minvalueplace] = swapped;
    minvalueplace+=1;
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
