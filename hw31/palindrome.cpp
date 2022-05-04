#include<iostream>
#include <string>
using namespace std;

int palindrome(string word) {
    int length = word.length();
    int array[length][length];
    for (int i = length - 1; i >= 0; i--) {
        array[i][i] = 1;
        for (int j = i+1; j < length; j++) {
            if (word[i] == word[j]) {
                array[i][j] = array[i+1][j-1]+2;
            } else {
                array[i][j] = max(array[i+1][j], array[i][j-1]);
            }
        }
    }
    return array[0][length-1];
}

int main() {
    int returnvalue = palindrome("racecat");
    cout << returnvalue << "\n";
    return 0;
}