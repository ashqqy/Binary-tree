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

    fclose(dump_file);

    return 0;
}

//------------------------------------------------------
