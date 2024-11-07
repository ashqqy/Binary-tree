#include <stdlib.h>

#include "BinaryTree.h"

//------------------------------------------------------

tree_error_t CreateNode (tree_elem_t data)
{
    tree_node_t* node = (tree_node_t*) calloc (1, sizeof (tree_node_t));
    if (node == NULL)
        return ALLOCATION_ERROR;

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return CHIKI_PUKI;
}

//------------------------------------------------------
