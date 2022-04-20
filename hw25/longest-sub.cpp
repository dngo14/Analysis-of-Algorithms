#include<iostream>
using namespace std;



int longest_subsequence(int *list_of_numbers, int length) {
    int substring[length] = { 1 };
    int longest = 1;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (list_of_numbers[i] > list_of_numbers[j]) {
                if (substring[i] < substring[j]+1) {
                    substring[i] = substring[j]+1;
                }
            }
        }
        if (substring[i] > longest) {
            longest = substring[i];
        }
    }
    return longest;
}

int main() {
    int numbers[] = {5,2,8,6,3,6,9,7};
    int length = 8;
    int count = longest_subsequence(numbers, length);
    cout << count << "\n";
}