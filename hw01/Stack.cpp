#include<iostream>
#include<cassert>
using namespace std;

class Stack {

   // what goes here?
   public:
   int stack[10];
   int n = 10;
   int top = -1;

    void push(int val) {
        if(top >= n-1)
            cout << "overflow" << '\0';

        else {
            stack[++top]=val;
        }
    }

   int pop() {
       int returnvalue;
        if(top<=-1) {
        cout << "underflow" << '\n';
        return -128;
        }
        
        else {
            returnvalue = stack[top];
            stack[top] = '\0';
            top--;
            return returnvalue;
        }
    }
};

void test_stack() {
  Stack s;
  assert(s.pop() == -128);  // test empty value
  s.push('A');
  assert(s.pop() == 'A');
  s.push('B');
  s.push('C');
  assert(s.pop() == 'C');
  assert(s.pop() == 'B');
  assert(s.pop() == -128);
//   int count = 0;
//    while (s.stack[count] != '\0') {
//        cout << s.stack[count] << "\n";
//        count+=1;
//    }
}

int main() {
  test_stack();
}
