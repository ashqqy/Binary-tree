#ifndef BINARY_TREE
#define BINARY_TREE

typedef int tree_elem_t;

struct tree_node_t
{
    tree_elem_t data;
    tree_node_t* left;
    tree_node_t* right;
};

struct tree_t
{
    tree_node_t* root_node;
    int n_nodes;
};

enum tree_error_t
{
    CHIKI_PUKI = 1,

    ALLOCATION_ERROR = 2
};

tree_error_t TreeInit (tree_t* tree);
tree_error_t CreateNode (tree_t* tree, tree_elem_t data);
tree_node_t* FindPtrToInsert (tree_t* tree, tree_elem_t data);
void PrintTree (tree_node_t* node);
void TreeDump (FILE* dump_file, tree_t* tree);
void TreeNodeDescrDump (FILE* dump_file, tree_node_t* node);
void TreeNodeLinkDump (FILE* dump_file, tree_node_t* node);

#endif // BINARY_TREE
