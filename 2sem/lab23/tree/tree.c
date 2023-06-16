#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "tree.h"

TreeNode *nodeLeftBrother(TreeNode * const node) {
    assert(node != NULL);
    return node->leftBrother;
}

TreeNode *nodeLeftmostChild(TreeNode * const node) {
    assert(node != NULL);
    return node->child;
}

TreeNode *nodeParent(TreeNode * const node) {
    assert(node != NULL);
    return node->parent;
}

TreeNode *nodeRightBrother(TreeNode * const node) {
    assert(node != NULL);
    return node->rightBrother;
}

TreeNode *treeRoot(Tree * const tree) {
    assert(tree != NULL);
    return tree->root;
}

void treeCreate(Tree * const tree) {
    tree -> root = NULL;
    tree -> size = 0;
}

void treePreorder(TreeNode * const node) {
    if (node == NULL){
        return;
    } 
    printf("%-.2f ", node->value);
    treePreorder(node -> child);
    treePreorder(node -> rightBrother);
} 


void treeInorder(TreeNode * const node) {
    if (node == NULL){ 
        return;
    }
    treeInorder(node -> child);
    printf("%-.2f ", node->value);
    treeInorder(node -> rightBrother); 
} 

void treePostorder(TreeNode * const node) {
    if (node == NULL){
        return;
    }
    treePostorder(node ->child);
    treePostorder(node -> rightBrother);
    printf("%-.2f ", node->value);
} 

static size_t nodeDelete(TreeNode * const node) {
    if(node == 0){
        return 0;
    }
    size_t count = 1;
    TreeNode *child = node -> child;
    while(child != NULL){
        count += nodeDelete(child);
        child = child -> rightBrother;
    }
    free(node);
    return count;
}

void treeDestroy(Tree * const tree){
    assert(tree != NULL);
    if(tree -> root != NULL){
        nodeDelete(tree -> root);
    }
    tree -> size = 0;
}

int treeInsert(Tree * const tree, TreeNode * const parent, const float value) {
    assert(tree != NULL && (tree->root != NULL || parent == NULL));
    TreeNode * const node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL)
        return errno;
    node->parent = parent;
    node->leftBrother = node->child = NULL;
    node->value = value;
    if (parent != NULL) {
        node->rightBrother = parent->child;
        if (parent->child != NULL)
            parent->child->leftBrother = node;
        parent->child = node;
    } else {
        node->rightBrother = NULL;
        tree->root = node;
    }
    ++tree->size;
    return 0;
}

void treeErase(Tree * const tree, TreeNode * const node) {
    assert(tree != NULL && tree->root != NULL);
    if (node->leftBrother != NULL)
        node->leftBrother->rightBrother = node->rightBrother;
    else if (node->parent != NULL)
        node->parent->child = node->rightBrother;
    else
        tree->root = NULL;

    if (node->rightBrother != NULL)
        node->rightBrother->leftBrother = node->leftBrother;

    tree->size -= nodeDelete(node);
}

size_t treeSize(const Tree * const tree){
    return tree -> size;
}

bool treeIsEmpty(const Tree * const tree){
    return tree -> size == 0;
}

void treePrint(TreeNode * const node, int level) {
    if(node == NULL){
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("-");
    }
    printf("%-.2f\n", node -> value);
    treePrint(node -> child, level + 1);
    treePrint(node -> rightBrother, level);
}

int LevelWidth(TreeNode *root, int current_level, int finish_level) { 
    if (finish_level == current_level) 
        return 1; 
    else { 
        int width = 0; 
        TreeNode *child = root->child; 
        while (child != NULL){ 
            width += LevelWidth(child, current_level + 1, finish_level); 
            child = child->rightBrother; 
        } 
        return width; 
    } 
} 
 
int treeWidth(Tree *tree) { 
    int max_width = 0, current_width = 1, level = 0; 
    while (current_width != 0){ 
        current_width = LevelWidth(tree->root, 0, level); 
        ++level; 
        if (max_width < current_width){ 
            max_width = current_width; 
        } 
    } 
    return max_width; 
}

