#include<iostream>
#include <string>
using namespace std;

int contiguous(int *array, int size) {
    int max1 = array[0];
    int current = array[0];

    for (int i = 1; i < size; i++) {
        current = max(array[i], max1+array[i]);
        max1 = max(max1, current);
    }
    return max1;
}

int main() {
    int array[] = {2,3,5,2};
    int returnvalue = contiguous(array, 4);
    cout << returnvalue << "\n";
    return 0;
}