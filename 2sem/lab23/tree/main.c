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
    
    /*printf("\n1. PreOrder;\n2. InOrder;\n3. PostOrder;\n4. NodeDelete;\n5. TreeDestroy;\n6. TreeSize;\n7. TreeIsEmpty;\n8. TreePrint;\n9. TreeWidth;\n10. Insert head;\n10. Insert tree->root;\n10. Insert tree->root->child;\n10. Insert tree->root->child->child;\n10. Insert tree->root->child->child->rightbrother;\n10. Insert tree->root->child->rightbrother->child;\n10. Insert tree->root->child->child->rightbrother->child;\n10. Erase head;\n10. Erase tree->root;\n10. Erase tree->root->child;\n10. Erase tree->root->child->child;\n10. Erase tree->root->child->child->rightbrother;\n10. Erase tree->root->child->rightbrother->child;\n10. Erase tree->root->child->child->rightbrother->child;\n0. Quit.\n");
    
    for (bool flag = true; flag; ) {
        int value, number = -1;
        printf("Enter the number: ");
        scanf("%d", &number);
        switch (number) {
            case 1:
                treePreorder(tree -> root);
                break;
            case 2:
                treeInorder(tree -> root);
                break;
            case 3:
                treePostorder(tree -> root);
                break;
            case 4:
                treeDestroy(tree);
                break;
            case 5:
                printf("Size of the tree = %ld\n", treeSize(tree));
                break;
            case 6:
                treeIsEmpty(tree);
                break;
            case 7:
                treePrint(tree -> root, 0);
                break;
            case 8:
                printf("width = %d\n", treeWidth(tree));
                break;
            case 9:
                             /?
                break;
            case 10:
                             /?
                break;
            case 11:
                             /?
                break;
            case 12:
                             /?
                break;
            case 13:
                             /?
                break;
            case 14:
                             /?
                break;
            case 15:
                             /?
                break;
            case 16:
                             /?
                break;
            case 17:
                             /?
                break;
            case 18:
                             /?
                break;
            case 19:
                             /?
                break;
            case 20:
                             /?
                break;
            case 21:
                             /?
                break;
            case 22:
                             /?
                break;
            case 0:
                printf("Finished\n");
                flag = false;
                break;
        }
    }
    return 0;
}
*/   
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
    printf("width = %d\n", treeWidth(tree));
    
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n"); 

    treeErase(tree, tree -> root -> child -> child);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    treeErase(tree, tree -> root -> child -> rightBrother -> child -> rightBrother);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");

    treeErase(tree, tree -> root -> child);
    treeErase(tree, tree -> root -> child -> rightBrother);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    printf("width = %d\n", treeWidth(tree));
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");

    treeDestroy(tree);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
}
