#include<iostream>
#include<cassert>
using namespace std;

class Queue {

   // what goes here?
   public:

   int queue[10];
   int n = 10;
   int back = 0;

   void inject(int val) {
        if (back >= n-1) {
            cout << "overflow" << '\n';
        } else {
            //cout << queue[back] << '\n'; 
            queue[back++] = val;
        }
   }

   int eject() {
        int returnvalue;

        if (back <= 0) {
            cout << "underrflow" << '\n';
            return -128;
        } else {
            returnvalue = queue[0];
            for (int i = 0; i < back; i++) {
                queue[i] = queue[i+1];
                //cout << queue[i] << '\n';
            }
            queue[back] = '\0';
            back--;
            return returnvalue;
        }
    }
};

void test_queue() {
  Queue q;
  assert(q.eject() == -128);  // test empty value
  q.inject('A');
  assert(q.eject() == 'A');
  q.inject('B');
  q.inject('C');
  assert(q.eject() == 'B');
  assert(q.eject() == 'C');
  assert(q.eject() == -128);
//   int count = 0;
//   while (q.queue[count] != '\0') {
//        cout << q.queue[count] << "\n";
//        count+=1;
//    }
}

int main() {
  test_queue();
}
