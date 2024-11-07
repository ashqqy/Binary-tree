#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "BinaryTree.h"

//------------------------------------------------------

tree_error_t TreeInit (tree_t* tree)
{
    tree->root = NULL;
    tree->n_nodes = 0;

    return CHIKI_PUKI;
}

//------------------------------------------------------


tree_error_t CreateNode (tree_t* tree, tree_elem_t data)
{
    assert (tree != NULL);

    tree_node_t* node = (tree_node_t*) calloc (1, sizeof (tree_node_t));
    if (node == NULL)
        return ALLOCATION_ERROR;

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    tree_node_t* ptr_insert_leaf = FindPtrToInsert (tree, data);

    // если нет узлов, то вставляем в корень
    if (ptr_insert_leaf == 0)
    {
        tree->root = node;
    }
    else
    {
        if (data >= ptr_insert_leaf->data)
            ptr_insert_leaf->right = node;
        else // (data < ptr_insert_leaf->data)
            ptr_insert_leaf->left = node;
    }

    return CHIKI_PUKI;
}

//------------------------------------------------------

tree_node_t* FindPtrToInsert (tree_t* tree, tree_elem_t data)
{
    assert (tree != NULL);
    
    tree_node_t* ptr_insert_leaf = tree->root;

    if (ptr_insert_leaf == NULL)
        return NULL;
        //TODO verify n_nodes = 0
    
    while (1)
    {
        if (data >= ptr_insert_leaf->data)
        {   
            if (ptr_insert_leaf->right == NULL)
                return ptr_insert_leaf;

            ptr_insert_leaf = ptr_insert_leaf->right;
        }
        
        else // (data < ptr_insert_leaf->data)
        {
            if (ptr_insert_leaf->left == NULL)
                return ptr_insert_leaf;

            ptr_insert_leaf = ptr_insert_leaf->left;
        }
    }
}

//------------------------------------------------------

void PrintTree (tree_node_t* node)
{
    if (node == NULL)
        return;

    printf ("(");
    if (node->left  != NULL) PrintTree (node->left);
    printf ("%d", node->data);
    if (node->right != NULL) PrintTree (node->right);
    printf (")");
}

//------------------------------------------------------

void TreeDump ()
{
    return;
}

//------------------------------------------------------