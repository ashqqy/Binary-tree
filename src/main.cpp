#include <stdio.h>

#include "BinaryTree.h"

//------------------------------------------------------

int main ()
{
    FILE* dump_file = fopen ("./dump/dump.dot", "w");

    tree_t tree = {};
    TreeInit (&tree);

    CreateNode (&tree, 50);
    CreateNode (&tree, 60);
    CreateNode (&tree, 20);
    CreateNode (&tree, 70);
    CreateNode (&tree, 80);
    CreateNode (&tree, 75);
    CreateNode (&tree, 52);

    PrintTree (tree.root_node);

    TreeDump (dump_file, &tree);

    fclose(dump_file);

    return 0;
}

//------------------------------------------------------
