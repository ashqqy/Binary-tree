#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "BinaryTree.h"

//------------------------------------------------------

tree_error_t TreeInit (tree_t* tree)
{
    tree->root_node = NULL;
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
        tree->root_node = node;
    }
    else
    {
        if (data >= ptr_insert_leaf->data)
            ptr_insert_leaf->right = node;
        else // (data < ptr_insert_leaf->data)
            ptr_insert_leaf->left = node;
    }

    tree->n_nodes += 1;

    return CHIKI_PUKI;
}

//------------------------------------------------------

tree_node_t* FindPtrToInsert (tree_t* tree, tree_elem_t data)
{
    assert (tree != NULL);
    
    tree_node_t* ptr_insert_leaf = tree->root_node;

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
    //inorder (infix)

    if (node == NULL)
        return;

    printf ("(");
    if (node->left  != NULL) PrintTree (node->left);
    printf ("%d", node->data);
    if (node->right != NULL) PrintTree (node->right);
    printf (")");
}

//------------------------------------------------------

void TreeDump (FILE* dump_file, tree_t* tree)
{
    assert (dump_file != NULL);
    assert (tree      != NULL);

    fprintf (dump_file, "digraph G\n");
    fprintf (dump_file, "{\n");
    fprintf (dump_file, "node[shape=\"record\", style=\"rounded, filled\"];\n\n");

    // определяем узлы 
    fprintf (dump_file, "p0x%p[label = \"{ <p>ptr = 0x%p | <d>data = %d| { <l>left|<r>right } }\"];\n", 
                                              tree->root_node, tree->root_node, tree->root_node->data);
    TreeNodeDescrDump (dump_file, tree->root_node->left);
    TreeNodeDescrDump (dump_file, tree->root_node->right);
    fprintf (dump_file, "\n");

    // соединяем узлы
    TreeNodeLinkDump (dump_file, tree->root_node);

    fprintf (dump_file, "}\n");
}

void TreeNodeDescrDump (FILE* dump_file, tree_node_t* node)
{
    assert (dump_file != NULL);

    if (node == NULL)
        return;

    fprintf (dump_file, "p0x%p[label = \"{ <p>ptr = 0x%p| <d>data = %d| { <l>left|<r>right } }\"];\n", 
                                                                            node, node, node->data);
    
    if (node->left  != NULL) TreeNodeDescrDump (dump_file, node->left);
    if (node->right != NULL) TreeNodeDescrDump (dump_file, node->right);
}

void TreeNodeLinkDump (FILE* dump_file, tree_node_t* node)
{   
    assert (dump_file != NULL);

    if (node->left  != NULL) 
    {
        fprintf (dump_file, "p0x%p:<l> -> p0x%p\n", node, node->left);
        TreeNodeLinkDump (dump_file, node->left);
    }
    if (node->right != NULL) 
    {
        fprintf (dump_file, "p0x%p:<r> -> p0x%p\n", node, node->right);
        TreeNodeLinkDump (dump_file, node->right);
    }
}

//------------------------------------------------------
