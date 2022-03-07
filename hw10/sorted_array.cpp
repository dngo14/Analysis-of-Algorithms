#include<iostream>
#include<cassert>
using namespace std;

class SortedArray {
    private:
        int *array = NULL;
        int size = 0;

    public:
        SortedArray(int length) {
            array = new int[length];
            //size = length;
        }

        ~SortedArray() {
            delete[] array;
        }

        void insert(int value) {
            array[size++] = value;
            int count = size;
            int swap;
           
            while (array[count-1] > array[count-2]) {
                if (count != 1) {
                    swap = array[count-2];
                    array[count-2] = array[count-1];
                    array[count-1] = swap;
                }
                count -=1;
            }

            for (int i = 0; i < size; i++) {
                if (array[i] != 0) {
                    cout << array[i] << "\n";}
            }
            cout << "\n";

        }

        void decrease_key_index(int index, int new_value) {
            array[index] = new_value;
            int count = index;
            int swap;
           
            while (new_value < array[count]) {
                swap = array[count+1];
                array[count+1] = array[count];
                array[count] = swap;
            }
        }

        int delete_min() {
            int return_value = array[size-1];
            //array[size] = NULL;
            size-=1;
            return return_value;
        };


};

int main() {
  SortedArray pq(20); // up to 20 elements
  pq.insert(7);
  pq.insert(3);
  pq.insert(5);
  assert(pq.delete_min() == 3);
  pq.decrease_key_index(1, 1);
  pq.insert(9);
  pq.insert(2);
  assert(pq.delete_min() == 1);
  pq.decrease_key_index(1, 4);
  assert(pq.delete_min() == 2);
  assert(pq.delete_min() == 4);
}

