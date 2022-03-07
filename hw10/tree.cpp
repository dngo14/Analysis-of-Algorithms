#include<iostream>
#include<cassert>
#include <string>
using namespace std;

// add your code here
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode(int data) {
        data = data;
        left = 0;
        right = 0;
    } //data(data), left(0), right(0) {} 
};

string as_string(TreeNode *Node) {
    if (Node -> data == 0) {
        return "";
    }
    string stringreturn = to_string(Node -> data);
    if (Node -> left != 0) {
        stringreturn += "(" + as_string(Node -> left) + ")";
    }
    if (Node -> right != 0) {
        stringreturn += "(" + as_string(Node -> right) + ")";
    }

    return stringreturn;
}



int main() {
  TreeNode root(2);
  TreeNode a(3), b(4), c(5);
  root.left = &a;
  root.right = &b;
  a.right = &c;
  cout << as_string(&root) << endl;
  assert(as_string(&c) == "(5)");
  assert(as_string(&b) == "(4)");
  assert(as_string(&a) == "(3(5))");
  assert(as_string(&root) == "((3(5))2(4))");
}
