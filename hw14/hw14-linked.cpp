//Worked with Ruben, Griffin, Santi, and Duncan
#include<iostream>
#include<cassert>
using namespace std;

struct element {
    char value;
    element *last;

    element(int val) {
        value = val;
    }
};

class Stack {

   // what goes here?

   public:
   int size;
   element *top;

   Stack() {
   }

   ~Stack() {
   }

    void push(char val) {
        if (top == NULL) {
            top = new element(val);
        } else {
            element *node = new element(val);
            element *temp = top;
            top = node;
            top -> last = temp;
        }
    }

   int pop() {
       if (top == NULL) {
           cout << "underflow" << "\n";
           return -128;
       } else {
           element *temp = top;
           top = top -> last;
           char returnvalue = temp -> value;
           free(temp);
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
  s.push('A');
  s.push('B');
  s.push('C');
  s.push('D');
  s.push('E');
  s.push('F');
  s.push('G');
  s.push('H');
  s.push('I');
  s.push('J');
  s.push('K');
  s.push('L');
  s.push('P');
}

int main() {
  test_stack();
}
