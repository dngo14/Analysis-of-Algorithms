#include<iostream>
#include <string>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int edits(string word1, string word2) {
    int rowsize = word1.length();
    int colsize = word2.length();
    int array[rowsize][colsize];

    for (int i = 0; i < rowsize; i++) {
        array[i][0] = i;
    }
    for (int i = 0; i < colsize; i++) {
        array[0][i] = i;
    }

    for(int row = 1; row < rowsize; row++) {
        for (int col = 1; col < colsize; col++) {
            if(word1[col - 1] == word2[row - 1]) {
                array[row][col] = array[row - 1][col - 1];
            } else {
                array[row][col] = (min(array[row][col - 1], array[row - 1][col], array[row - 1][col - 1])) + 1;
            }
            // if (row == 0) {
            //     array[row][col] = col;
            // }
            // else if (col == 0) {
            //     array[row][col] = row;
            // }
            // else if (word1[row - 1] == word2[col - 1]) {
            //     array[row][col] = array[row-1][col-1];
            // }
            // else {
            //     array[row][col] = min(array[row][col-1], array[row - 1][col], array[row - 1][col - 1]/2) + 1;
            // }
        }
    }
    return array[rowsize-1][colsize-1];
}

int main() {
    int length;
    length = edits("anagram", "agnar");
    cout << length << "\n";
}