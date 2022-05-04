#include<iostream>
#include <string>
using namespace std;

int restaurants(int *array, int size, int milesapart, int *arraydistances) {
    int P[size] = {0};
    P[0] = 0;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            int temp;
            if (arraydistances[i] - arraydistances[j] < milesapart) {
                temp = P[j];
            } else {
                temp = P[j] + array[i];
            }
            if (temp > P[i]) {
                temp = P[i];
            }
        }
        if (P[i] < array[i]) {
            P[i] = array[i];
        }
    }
    return P[size-1];
}

int main() {
    int yuckdistances[] = {0, 300, 350, 475, 500};
    int yuckprofits[] = {200, 400, 600, 100, 200};
    int size = 5;
    int miles = 175;

    int returnvalue = restaurants(yuckprofits, size, miles, yuckdistances);
    cout << returnvalue << "\n";
}