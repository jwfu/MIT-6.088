#include <assert.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/*
 * Define a tree structure.
 */
typedef struct bst {
  int* vals;
  int size;
} bst_t;

/* Returns a bst_t structure with an int array vals of size "size" and the
 * size field set appropriately. */
bst_t* make_tree(int size){
  bst_t* new_tree = new bst;
  new_tree -> size = size;
  new_tree ->vals = new int[size];
  return new_tree;
}

/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */
void init_tree(bst_t* tree){
  for(int i = 0; i < tree -> size; i++)  {
    tree -> vals[i] = -1;
  }
}

/*
 * Inserts a new value into a given tree.
 */
void insert(int val, bst_t* tree, int cur_root)
{
  if(tree -> vals[cur_root - 1] == -1){      //NULL analog
    tree -> vals[cur_root - 1] = val;       //insert here
  }
  else{
    if(val < tree -> vals[cur_root - 1]){
      insert(val, tree, 2*cur_root);
    }
    else{
      insert(val, tree, 2*cur_root + 1);
    }
  }
}

//Returns true if a value is in the tree, false otherwise
bool find_val(int val, bst_t* tree, int cur_root){
  if(tree -> vals[cur_root - 1] == val){
    return 1;
  }
  
  else if(tree -> vals[cur_root - 1] == -1){
    return 0;
  }
  
  else if(val < tree -> vals[cur_root - 1]){
    find_val(val, tree, 2*cur_root);
  }
  
  else if(val > tree -> vals[cur_root - 1])
  {
    find_val(val, tree, 2*cur_root + 1);
  }
}

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree){
  delete [] tree;
}

/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree){
  for(int i = 0; i < tree -> size; i++){
    cout << tree -> vals[i] << " ";
  }
  cout << endl;
}


int main() {
  int root = 1;
  /* Insert 0. */
  bst_t* cur = make_tree(32);
  init_tree(cur);
  

  insert(1, cur, root);
  assert(find_val(1, cur, root) == 1);
  print_bst(cur); printf("\n");

  /* Insert 1. */
  insert(0, cur, root);
  assert(find_val(0, cur, root) == 1);
  print_bst(cur); printf("\n");

  /* Insert 2. */
  insert(2, cur, root);
  assert(find_val(2, cur, root) == 1);
  print_bst(cur); printf("\n");

  /* Insert 4. */
  insert(4, cur, root);
  assert(find_val(4, cur, root) == 1);
  print_bst(cur); printf("\n");

  /* Insert 3 */
  insert(3, cur, root);
  assert(find_val(3, cur, root) == 1);
  print_bst(cur);
  printf("\n");
  
  /* Delete the list. */
  delete_bst(cur);

  return 0;
}
