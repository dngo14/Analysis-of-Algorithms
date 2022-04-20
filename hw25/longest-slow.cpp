#include<iostream>
using namespace std;



int longest_subsequence(int *list_of_numbers, int i, int length, int previous) {
    if (i == length) {
        return 0;
    }

    int not_included = longest_subsequence(list_of_numbers, i+1, length, previous);

    int include = 0;
    if (list_of_numbers[i] > previous) {
        include = 1 + longest_subsequence(list_of_numbers, i+1, length, list_of_numbers[i]);
    }

    if (include > not_included) {
        return include;
    } else {
        return not_included;
    }
}

int main() {
    int numbers[] = {5,2,8,6,3,6,9,7};
    int length = 8;
    int count = longest_subsequence(numbers,0,length,-1);
    cout << count << "\n";
}