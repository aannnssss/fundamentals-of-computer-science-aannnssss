#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

void PreorderTraversal(const TreeNode *tree);

void InorderTraversal(const TreeNode *tree);

void PostorderTraversal(const TreeNode *tree);

//void treeClear(Tree *tree);

bool treeContains(const Tree *tree, int value);

void treeCreate(Tree *tree);

int treeErase(Tree * const tree, int value);

int treeInsert(Tree * const tree, int value);

int treeGet(const Tree *tree, size_t index, int *value);

int treeSet(Tree *tree, size_t index, int value);

size_t treeSize(const Tree *tree);

//void treeDestroy(Tree *tree);

void width_helper(TreeNode* node, int level, int width[]);

int tree_width(TreeNode* root);

#endif // TREE_H

