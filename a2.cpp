#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
 * Define a node structure.
 */
typedef struct node {
  int val;
  struct node* left;
  struct node* right;
} node_t;

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val);

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root);

bool find_val(int val, node_t* root);

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(node_t* root);

/* Given a pointer to the root, prints all of the values in a tree. */
void print_bst(node_t* root);


/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = new node;
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

//Tree movement helper function
node_t* traverse(int val, node_t* cur_node, bool & dir){
  if(val < cur_node -> val){                  //if less, go left
    if(cur_node -> left != NULL){             //if not empty
      traverse(val, cur_node -> left, dir);   //go down a level
    }
    else{
      dir = 0;                                //pass left back
      return cur_node;                        //pass node location
    }
  }
  
  else{                                       // else go right
    if(cur_node -> right != NULL){            //if not empty
      traverse(val, cur_node -> right, dir);  //go down a level
    }
    else{
      dir = 1;                                //pass right back
      return cur_node;                        //pass node location
    }
  }
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root){
  bool dir;
  node_t* cur_node = traverse(val, cur_root, dir);
  if(dir == 0){
    cur_node -> left = make_tree(val);
  }
  else{
    cur_node -> right = make_tree(val); 
  }
  return cur_root;
}

//Returns true if a value is in the tree, false otherwise
bool find_val(int val, node_t* root){
  if(root -> val == val){
    return true;
  }
  else if(val < root -> val){
    if(root -> left == NULL){
      return false;
    }
    else{
      find_val(val, root -> left);
    }
  }
  else
  {
    if(root -> right == NULL){
      return false;
    }
    else{
      find_val(val, root -> right);
    }
  }
}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
  if(root -> left != NULL){
    delete_bst(root -> left);
  }
  else if(root -> right != NULL){
    delete_bst(root -> right);
  }
  else{
    delete root;
  }
}

/* Given a pointer to the root, prints all of the values in a tree. */
void print_bst(node_t* root) {
  if (root != NULL) {
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}


int main() {
  /* Insert 0. */
  node_t* cur = make_tree(1);
  print_bst(cur);
  printf("\n");
  assert(find_val(1, cur) == 1);

  /* Insert 1. */
  cur = insert(0, cur);
  assert(find_val(0, cur) == 1);
  cout << "left " << cur -> left -> val << endl;
  print_bst(cur);
  printf("\n");

  /* Insert 2. */
  cur = insert(2, cur);
  assert(find_val(2, cur) == 1);
  cout << "right " << cur -> right -> val << endl;

  /* Print the tree. */
  print_bst(cur);
  printf("\n");

  /* Insert 4. */
  cur = insert(4, cur);
  assert(find_val(4, cur) == 1);
  cout << "right " << cur -> right -> right -> val << endl;

  /* Insert 3 */
  cur = insert(3, cur);
  assert(find_val(3, cur) == 1);
  cout << "left " << cur -> right -> right -> left -> val << endl;
  print_bst(cur);
  printf("\n");
  
  // /* Delete the list. */
   delete_bst(cur);

  return 0;
}
