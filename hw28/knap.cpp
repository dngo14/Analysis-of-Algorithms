#include<iostream>
#include <string>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int *items, int *weights, int itemslength, int weightmax) {
    int array[itemslength+1][weightmax+1];
    for (int i = 0; i < itemslength; i++) {
        array[i][0] = i;
    }
    for (int i = 0; i < weightmax; i++) {
        array[0][i] = i;
    }
    
    for (int i = 0; i <= itemslength; i++) {
        for (int j = 0; j <= weightmax; j++) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (weights[i-1] <= j) {
                array[i][j] = max(items[i - 1] + array[i - 1][j - weights[i - 1]], array[i - 1][j]);

            } else {
                array[i][j] = array[i - 1][j];
            }
        }
    }
    return array[itemslength][weightmax];
}

int main() {
    int items[] = {12, 14, 20, 7};
    int weights[] = {3, 4, 8, 2};
    int weight = 10;
    int size = sizeof(items)/sizeof(items[0]);
    //cout << size << "\n";
    int returnvalue = knapsack(items, weights, size, weight);

    cout << "The max value is " << returnvalue << "\n";
    return 0;
}