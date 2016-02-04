#include <iostream>
using namespace std;
/*
 * Binary search tree
 */
class BST {
  
 public:

  // DO NOT change the declarations of the given methods.
  BST* left;
  BST* right;
  int val;
  // constructor
  BST(){
    val = -999;
    left = 0;
    right = 0;
  }

  //destructor
  ~BST();
  
  // inserts "val" into the tree
  void insert(int val)
  {
    if( this -> val == -999){            //catch empty tree
      this -> val = val;
    }
    else if(val < this -> val){
      if(this -> left){
        this -> left -> insert(val);
      }
      else{
        BST* new_node = new BST;
        new_node -> val = val;
        this -> left = new_node;
      }
    }
    else{
      if(this -> right){
        this -> right -> insert(val);
      }
      else{
        BST* new_node = new BST;
        new_node -> val = val;
        this -> right = new_node;
      }
    }
  }

  // returns true if and only if "val" exists in the tree.
  bool find(int val){
    if(this -> val == val){
      return true;
    }
    else if(val < this -> val){
      if(left){            //left is not null
        left -> find(val);
      }
      else{
        return false;
      }
    }
    else{
      if(right){           //right is not null
        right -> find(val);
      }
      else{
        return false;
      }
    }
  }

  // prints the tree elements in the in-order traversal order
  void print_inorder()  {
    cout <<"printing: "<< val << endl;
    if(this -> left){                       //if left is not null
        left ->print_inorder();
    }
    if(this -> right){                      //if right is not null
        right -> print_inorder();
    }
  }
};

int main () {

  BST tree;

  // Test case 1: insert 1
  std::cout << "Test case 1: Insert 1" << endl;
  tree.insert(1);
  tree.print_inorder();
  if (tree.find(1)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1.\n";

  //Test case 2: insert 7
  std::cout << "Test case 2: Insert 7\n";
  tree.insert(7);
  tree.print_inorder();
  if (tree.find(1) && tree.find(7)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1, 7.\n";

  // Test case 3: insert -1
  std::cout << "Test case 3: Insert -1\n";
  tree.insert(-1);
  tree.print_inorder();
  if (tree.find(-1) && tree.find(7) && tree.find(1))
    std::cout << "Passed!\n";
  else     
    std::cout << "Failed! Tree should contain -1, 1, 7.\n";


  // ADD YOUR TESTS HERE
  
  return 0;
}
