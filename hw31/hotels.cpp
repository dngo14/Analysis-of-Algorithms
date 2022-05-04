#include<iostream>
#include <string>
using namespace std;

int hotels(int *array, int size) {
    int d[size] = {0};
    d[0] = 0;
    for (int i = 1; i < size; i++) {
        d[i] = d[0]+(200-(array[0]-array[i]))^2;
        for (int j = 1; j < i; j++) {
            if (d[i] > d[j]+(200-(array[j]-array[i]))^2) {
                d[i] = d[j]+(200-(array[j]-array[i]))^2;
            }
        }
    }
    return d[size-1];
}

int main() {
    int hotellist[] = {0, 200, 401, 650};
    int returnvalue = hotels(hotellist, 4);
    cout << returnvalue << "\n";
}