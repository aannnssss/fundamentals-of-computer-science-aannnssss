#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define COMMAND_LEN 32

int main() {
    Tree *tree = malloc(sizeof(Tree));;
    treeCreate(tree);
    treeInsert(tree, NULL, 1);
    treeInsert(tree, tree -> root, 2.5);
    treeInsert(tree, tree -> root, 6.9);
    treeInsert(tree, tree -> root -> child, 7.6);
    treeInsert(tree, tree -> root -> child, 45.7);
    treeInsert(tree, tree -> root -> child -> rightBrother, 12.5);
    treeInsert(tree, tree -> root -> child, 4.1);
    treeInsert(tree, tree -> root -> child -> child, 5.7);
    treeInsert(tree, tree -> root -> child -> child -> rightBrother, 8.9);
    treeInsert(tree, tree -> root -> child -> child, 71.2);
    treeInsert(tree, tree -> root -> child -> child -> rightBrother -> child, 63.3);
    treeInsert(tree, tree -> root -> child, 1.2);
    treeInsert(tree, tree -> root, 3.6);
    treeInsert(tree, tree -> root -> child, 15.5);
    treeInsert(tree, tree -> root -> child, 5.69);
    
    treePrint(tree -> root, 0);
    printf("\nSize of the tree = %ld\n", treeSize(tree));
    printf("width = %d\n", treeWidth(tree));
    
    printf("PreOrder:\n");
    treePreorder(tree -> root);
    printf("\n");
    
    printf("InOrder:\n");
    treeInorder(tree -> root);
    printf("\n");
    
    printf("PostOrder:\n");
    treePostorder(tree -> root);
    printf("\n"); 

    treeErase(tree, tree -> root -> child -> child);
    printf("Size of the tree = %ld\n", treeSize(tree));
    
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    
    printf("PreOrder:\n");
    treePreorder(tree -> root);
    printf("\n");
    
    printf("InOrder:\n");
    treeInorder(tree -> root);
    printf("\n");
    
    printf("PostOrder:\n");
    treePostorder(tree -> root);
    printf("\n"); 
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    printf("\nSize of the tree = %ld\n", treeSize(tree));
    
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    
    printf("PreOrder:\n");
    treePreorder(tree -> root);
    printf("\n");
    
    printf("InOrder:\n");
    treeInorder(tree -> root);
    printf("\n");
    
    printf("PostOrder:\n");
    treePostorder(tree -> root);
    printf("\n"); 
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    treeErase(tree, tree -> root -> child -> rightBrother -> child -> rightBrother);
    
    printf("\nSize of the tree = %ld\n", treeSize(tree));
    
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    
    printf("PreOrder:\n");
    treePreorder(tree -> root);
    printf("\n");
    
    printf("InOrder:\n");
    treeInorder(tree -> root);
    printf("\n");
    
    printf("PostOrder:\n");
    treePostorder(tree -> root);
    printf("\n"); 
    
    treeErase(tree, tree -> root -> child);
    treeErase(tree, tree -> root -> child -> rightBrother);
    
    printf("\nSize of the tree = %ld\n", treeSize(tree));
    
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    
    printf("PreOrder:\n");
    treePreorder(tree -> root);
    printf("\n");
    
    printf("InOrder:\n");
    treeInorder(tree -> root);
    printf("\n");
    
    printf("PostOrder:\n");
    treePostorder(tree -> root);
    printf("\n"); 

    treeDestroy(tree);
    printf("\nSize of the tree = %ld\n", treeSize(tree));
}
