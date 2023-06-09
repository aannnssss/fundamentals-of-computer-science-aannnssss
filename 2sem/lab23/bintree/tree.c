#include "tree.h"
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    TreeNode *parent, *left, *right;
    int value;
};

typedef struct TreeNode Treenode;

void PreorderTraversal(const TreeNode * const node){
    if (node != NULL){
        printf("%d ", node->value);
        PreorderTraversal(node->left);
        PreorderTraversal(node->right);
    }
}

void InorderTraversal(const TreeNode * const node){
    if (node != NULL){
        InorderTraversal(node->left);
        printf("%d ", node->value);
        InorderTraversal(node->right);
    }
}

void PostorderTraversal(const TreeNode * const node){
    if (node != NULL){
        InorderTraversal(node->left);
        InorderTraversal(node->right);
        printf("%d ", node->value);
    }
}

bool treeContains(const Tree * const tree, const int value) {
    TreeNode *node = tree->root;
    while (node != NULL) {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return true;
    }
    return false;
}

void treeCreate(Tree * const tree) {
    tree->root = NULL;
    tree->size = 0;
}

int treeErase(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            break;
    }
    if (node == NULL)
        return EINVAL;

    assert(node->value == value);
    if (node->left != NULL && node->right != NULL) {
        int * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL) {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL) {
        assert(node->right == NULL);
        *ptr = node->left;
        node->left->parent = node->parent;
    } else if (node->right != NULL) {
        assert(node->left == NULL);
        *ptr = node->right;
        node->right->parent = node->parent;
    } else
        *ptr = NULL;
    free(node);
    --tree->size;
}

int treeInsert(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            return EINVAL;
    }
    *ptr = malloc(sizeof(TreeNode));
    if (*ptr == NULL)
        return errno;
    ++tree->size;
    (*ptr)->parent = node;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = value;
    return 0;
}

bool treeIsEmpty(const Tree * const tree) {
    return tree->size == 0;
}

size_t treeSize(const Tree * const tree) {
    return tree->size;
}

// Помощник - рекурсивная функция для обхода дерева
void width_helper(TreeNode* node, int level, int width[]) {
    if (node == NULL) {
        return;
    }
    
    width[level]++; // Увеличиваем количество узлов на текущем уровне
    
    // Рекурсивно обходим левое и правое поддерево
    width_helper(node->left, level + 1, width); 
    width_helper(node->right, level + 1, width);
}

// Функция для нахождения ширины бинарного дерева
int tree_width(TreeNode* root) {
    int level = 0; // Начинаем с корня дерева
    int max_width = 0; // Максимальная ширина дерева
    int width[1000] = {0}; // Массив для хранения количества узлов на каждом уровне

    // Обходим дерево, запоминая количество узлов на каждом уровне
    width_helper(root, level, width);
    
    // Ищем максимальное количество узлов на любом из уровней
    for (int i = 0; i < 1000; i++) {
        if (width[i] > max_width) {
            max_width = width[i];
        }
    }
    
    return max_width;
}
int main() {
    printf("YES");
    return 0;
}

