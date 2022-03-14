//Worked with Ruben, Griffin, Santi, and Duncan
#include<iostream>
#include<cassert>
using namespace std;

class Stack {

   // what goes here?

   public:
   char *stack;
   int n;
   int top = -1;

   Stack(int size) {
       stack = new char [size];
       n = size;
   }

   ~Stack() {
       free(stack);
   }

    void push(char val) {
        if(top >= n-1)
            expand(val);
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

    void expand(char val) {
        n = n+10;
        char *newstack = new char[n];
        for (int i = 0; i <= top; i++) {
            newstack[i] = stack[i];
        } 
        newstack[++top]=val;
        free(stack);
        stack = newstack;
    }
};

void test_stack() {
  Stack s(10);
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

  int i = 0;
  while (s.stack[i] != 'P') {
      cout << s.stack[i] << " " << i << "\n";
      i++;
  }
}

int main() {
  test_stack();
}
