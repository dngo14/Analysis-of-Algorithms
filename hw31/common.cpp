#include<iostream>
#include <string>
using namespace std;

int common(string first, string second) {
    int length1 = first.length();
    int length2 = second.length();

    int array[length1+1][length2+1];
    int maxlength;

    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (first[i-1] == second[j-1]) {
                array[i][j] = array[i-1][j-1] + 1;
                maxlength = max(maxlength, array[i][j]);
            } else {
                array[i][j] = 0;
            }
        }
    }
    return maxlength;
}

int main() {
    int returnvalue = common("hello", "hellcat");
    cout << returnvalue << "\n";
    return 0;
}