#include<iostream>
#include<cassert>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    // constructor
    TreeNode(int data) {
        data = data;
        left = 0;
        right = 0;
        parent = 0;
    }
    TreeNode() {
        data = 0;
        left = 0;
        right = 0;
        parent = 0;
    }
    TreeNode(int data, TreeNode *node) {
        data = data;
        left = 0;
        right = 0;
        parent = node;
    }
};

class HeapTree {
    private:
        TreeNode *array = NULL;
        int size = 0;
        int maxsize;
        TreeNode root = {0};
        TreeNode *rootnode = &root;
        
    public:

    HeapTree(int length) {
        maxsize = length;
        //array = new TreeNode[length];
        //array[0] = root;
    }
    ~HeapTree() {

    }

    void bubble_up(TreeNode *Node) {
        int swap;
        if (Node -> parent = 0) {
            return;
        } if (Node -> data < Node -> parent -> data) {
            swap = Node -> data;
            Node -> data = Node -> parent -> data;
            Node -> parent -> data = swap;
            bubble_up(Node -> parent);
        }
    }

    TreeNode *helperinsert (TreeNode *node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
        } else {
            if (value < node -> data) {
                helperinsert(node -> left, value);
            } else {
                helperinsert(node -> right, value);
            }
        }

    }

    void insert(int value){
        if (size == 0) {
            array[0].data = value;
            size+=1;
        }
        else {
            helperinsert(&array[0], value);
            size+=1;
        }
    }
};

int main() {
  HeapTree pq(20); // up to 20 elements
  pq.insert(7);
  pq.insert(3);
  pq.insert(5);
//   assert(pq.delete_min() == 3);
//   pq.decrease_key_from(7, 1);
//   pq.insert(9);
//   pq.insert(2);
//   assert(pq.delete_min() == 1);
//   pq.decrease_key_from(9, 4);
//   assert(pq.delete_min() == 2);
//   assert(pq.delete_min() == 4);
}
