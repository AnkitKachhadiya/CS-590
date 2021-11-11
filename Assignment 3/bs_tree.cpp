
#include "bs_tree.h"
#include <list>
#include <iostream>

using namespace std;

int sortArrIndex = 0;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{ /*<<<*/
    /*
 * create T_nil element
 */
    T_nil = new bs_tree_node();
    T_nil->p = T_nil;
    T_nil->left = T_nil;
    T_nil->right = T_nil;

    /*
 * root of rb tree
 */
    T_root = T_nil;
} /*>>>*/

bs_tree::~bs_tree()
{ /*<<<*/
    /*
 * delete nil element and all other allocated nodes
 */
    remove_all(T_root);

    delete T_nil;
} /*>>>*/

void bs_tree::insert(int key, bs_tree_i_info &t_info)
{ /*<<<*/
    /*
 * wrapper around insert
 * -> creates black node with key
 * -> inserts node
 */
    bs_tree_node *z;

    z = new bs_tree_node;
    z->key = key;

    insert(z, t_info);
} /*>>>*/

void bs_tree::insert(bs_tree_node *z, bs_tree_i_info &t_info)
{ /*<<<*/
    /*
 * binary tree type insert 
 * -> search position, insert new node
 * -> fix properties after insert
 */
    bs_tree_node *x;
    bs_tree_node *y;

    int tempCount = 0;

    y = T_nil;
    x = T_root;
    while (x != T_nil)
    {

        if (z->key == x->key)
        {
            t_info.i_duplicate++;
            return;
        }

        y = x;

        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->p = y;
    if (y == T_nil)
        T_root = z;
    else
    {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }

    z->left = T_nil;
    z->right = T_nil;

} /*>>>*/

void bs_tree::inorder_output(bs_tree_node *x, int level, int *toSortArray)
{ /*<<<*/
    /*
 * in order walk through binary tree
 * -> see book or slides
 */
    if (x != T_nil)
    {
        inorder_output(x->left, level + 1, toSortArray);

        toSortArray[sortArrIndex] = x->key;
        sortArrIndex++;

        inorder_output(x->right, level + 1, toSortArray);
    }
} /*>>>*/

// TODO: modified inorder tree walk method to save the
// sorted numbers in the first argument: int* array.
// question 2
int bs_tree::convert(int *toSortArray, int n)
{
    if (T_root != T_nil)
    {
        inorder_output(T_root, 1, toSortArray);
    }

    return sortArrIndex;
}

void bs_tree::remove_all(bs_tree_node *x)
{ /*<<<*/
    /*
 * recursively remove all tree elements
 */
    if (x != T_nil)
    {
        remove_all(x->left);
        remove_all(x->right);

        delete x;
    }
} /*>>>*/
