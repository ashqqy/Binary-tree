#ifndef BINARY_TREE
#define BINARY_TREE

typedef int tree_elem_t;

struct tree_node_t
{
    tree_elem_t data;
    tree_node_t* left;
    tree_node_t* right;
};

enum tree_error_t
{
    CHIKI_PUKI = 1,

    ALLOCATION_ERROR = 2
};

tree_error_t CreateNode (tree_elem_t data);

#endif // BINARY_TREE