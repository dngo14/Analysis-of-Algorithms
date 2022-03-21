#include<iostream>
//#include<cassert>
using namespace std;

int* merge(int *left, int *right, int *result) {
    int i = 0;
    int j = 0;
    int length_result = 0;
    int length_left = 0;
    int length_right = 0;
    while(result[length_result]) {length_result++;}
    length_result--;
    while(left[length_left]) {length_left++;};
    length_left--;
    while(right[length_right]) {length_right++;};
    length_right--;

    //cout << length_left << "\t" << length_right << "\t" << length_result << "\n";

    for (int k = 0; k < length_result; k++) {
        if (i < length_left && (j >= length_right || left[i] <= right[j])) {
            result[k] = left[i++];
        } else {
            result[k] = right[j++];
        }
    }
    // for (int i = 0; i < length_result; i++) {
    //     cout << result[i] << "\n";
    // }
    
    return result;
}

int* merge_sort(int *stack) {
    int *results;
    int *leftstack;
    int *rightstack;
    int left = 0;
    int right = 0;
    while (stack[right]){right++;}
    right--;
    int mid = left + (right-left)/2;
    //cout << right << "\n" << "\n";
    // for (int i = 0; i < right; i++) {
    //     cout << stack[i] << "\n";
    // }
    //cout << "\n" << "\n";

    if (right >= 2) {
        leftstack = new int[mid];
        rightstack = new int[mid];
        for (int i = 0; i <= mid; i++) {
            leftstack[i] = stack[i];
        }
        int count = 0;
        for (int j = mid; j <= right; j++) {
            rightstack[count] = stack[j];
            count+=1;
        }
        merge_sort(leftstack);
        merge_sort(rightstack);
        results = merge(leftstack, rightstack, stack);
    }
    // for (int i = 0; i < 5; i++) {
    //     cout << results[i] << "\n";
    // }
    return results;
}

int main() {
    int stack[5] = {16,3,2,5,7};
    int *result;
    result = merge_sort(stack);
    for (int i = 0; i < 5; i++) {
        cout << *result++ << "\n";
    }
    return 0;
}