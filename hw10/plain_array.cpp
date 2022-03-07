#include<iostream>
#include<cassert>
using namespace std;

class PlainArray {
    private:
        int *array = NULL;
        int size = 0;
        //int arraylength = NULL;

    public:
        PlainArray(int length) {
            array = new int[length];
            //int arraylength = length;
        }

        ~PlainArray() {
            delete[] array;
        }

        void insert(int value) {
            array[size++] = value;
        }

        void decrease_key_index(int index, int new_value) {
            array[index] = new_value;
        }

        int delete_min() {
            int min_value = 0;
            int count = 1;
            while(array[count] != NULL) {
                if (array[count] < array[min_value]) {
                    min_value = count;
                }
                count+=1;
            }
            int return_value = array[min_value];
            //cout << return_value << "\n";
            for (int i = min_value; i < size; i++) {
                array[i] = array[i+1];
            }
            return return_value;
        };


};



int main() {
  PlainArray pq(20); // up to 20 elements
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
