#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "tree.h"

size_t treeSize(Node* node) {
    if (node == NULL)
        return 0;
    int size = 1;
    if (node->nodeType == OPERATOR) {
        size += treeSize(node->nodeUnion.op.left);
        size += treeSize(node->nodeUnion.op.right);
    }
    return size;
}

Node* createNode(NodeType type) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->nodeType = type;
    return node;
}

Node* createOperatorNode(char op, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = OPERATOR;
    node->nodeUnion.op.left = left;
    node->nodeUnion.op.right = right;
    node->nodeUnion.op.op = op;
    return node;
}

Node* createValueNode(double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VALUE;
    node->nodeUnion.value = value;
    return node;
}

Node* createVariableNode(const char* variable) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VARIABLE;
    strncpy(node->nodeUnion.variable, variable, VARIABLE_LENGTH);
    return node;
}

void deleteExpressionTree(Node* root) {
    if (root == NULL){
        return;
    }
    if (root->nodeType == OPERATOR) {
        deleteExpressionTree(root->nodeUnion.op.left);
        deleteExpressionTree(root->nodeUnion.op.right);
    }
    free(root);
}

void printNode(Node* node) { 
    if (node == NULL) 
        return; 
    if (node->nodeType == OPERATOR) {
        if (node->nodeUnion.op.left == NULL || node->nodeUnion.op.right == NULL){ 
            return; 
        }
        printNode(node->nodeUnion.op.left); 
	    printf(" %c ", node->nodeUnion.op.op); 
	    printNode(node->nodeUnion.op.right); 
    } else if (node->nodeType == VALUE) { 
        printf("%.2f", fabs(node->nodeUnion.value)); 
    } 
    else if (node->nodeType == VARIABLE) { 
        printf("%s", node->nodeUnion.variable); 
    }  
}
void printExpressionTree(Node* node, int level) {
    if (node == NULL)
        return;

    if (node->nodeType == OPERATOR) {
        printExpressionTree(node->nodeUnion.op.left, level + 1);
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%c\n", node->nodeUnion.op.op); 

        printExpressionTree(node->nodeUnion.op.right, level + 1);

    } else if (node->nodeType == VALUE) {
        for (int i = 0; i < level; i++)
            printf("\t");

        printf("%.2f\n", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%s\n", node->nodeUnion.variable);
    }
}

int isOperator(char c) {
    return (c == '+'||  c == '-' || c == '*' || c == '/' || c == '^');
}

int getOperatorPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '^' || op == '/')
        return 2;
    else
        return 0;
}

int isUnaryMinus(const char* infix, int index) {
    if (index == 0){
        return 1;
    }
    char prevChar = infix[index - 1], nextChar = infix[index + 1];
    return (isOperator(prevChar) || prevChar == '(' || isdigit(nextChar) || isalpha(nextChar));
}

Node* ExpressionTreeFromPostfix(const char* postfix) {
    int len = strlen(postfix);
    Node* stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = postfix[i];

        if (isdigit(c) || (c == '-' && isUnaryMinus(postfix, i))) {
            char number[20];
            int numberIndex = 0;
            if (c == '-') {
                number[numberIndex++] = '-';
                i++;
            }
            while (isdigit(postfix[i])) {
                number[numberIndex++] = postfix[i++];
            }
            number[numberIndex] = '\0';

            double value = atof(number);
            Node* valueNode = createValueNode(value);
            stack[++top] = valueNode;
        } else if (isalpha(c)) {
            char variable[2] = {c, '\0'};
            Node* variableNode = createVariableNode(variable);
            stack[++top] = variableNode;
        } else if (isOperator(c)) {
            Node* rightOperand = stack[top--];
            Node* leftOperand = stack[top--];
            Node* operatorNode = createOperatorNode(c, leftOperand, rightOperand);
            stack[++top] = operatorNode;
        }
    }

    return stack[top];
}


Node* ExpressionTreeFromInfix(const char* infix) {
    int len = strlen(infix);
    char postfix[len * 2];
    int postfixIndex = 0;

    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        if (isdigit(c) || (c == '-' && isUnaryMinus(infix, i))) {
            while (isdigit(infix[i]) || (infix[i] == '-' && isUnaryMinus(infix, i))) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--;
        } else if (isalpha(c)) {
            while (isalpha(infix[i])) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--;
        } else if (isOperator(c)) {
            while (top >= 0 && stack[top] != '(' && getOperatorPriority(stack[top]) >= getOperatorPriority(c)) {
                    postfix[postfixIndex++] = stack[top--];
                    postfix[postfixIndex++] = ' ';
            }
            stack[++top] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[postfixIndex++] = stack[top--];
                postfix[postfixIndex++] = ' ';
            }
            top--;
        }
    }

    while (top >= 0) {
        postfix[postfixIndex++] = stack[top--];
        postfix[postfixIndex++] = ' ';
    }

    postfix[postfixIndex] = '\0';
    return ExpressionTreeFromPostfix(postfix);
}

void simplifyExpression(Node* root, char* expression) {  
    if (root == NULL)  
        return;  
    int negativeCount = 0, sign;  
    for (int i = 0; i < strlen(expression); i++) {  
        if (expression[i] == '-') {  
            if (i == 0 || expression[i-1] == '(') {  
                negativeCount++; 
            }  
        }  
    }

    if (negativeCount % 2 != 0) {  
        if (expression[0] == '-' && expression[1] == '*') {  
            Node* newNode = createNode(OPERATOR);  
            newNode->nodeUnion.op.op = '*';  
            newNode->nodeUnion.op.left = createNode(VALUE);  
            newNode->nodeUnion.op.left->nodeUnion.value = -1;  
            newNode->nodeUnion.op.right = root->nodeUnion.op.right;  
            root->nodeUnion.op.right = newNode;  
            expression += 2;  
        } else {  
            sign = 0;  
        }  
    } else {  
        sign = 1;  
    }  
    if (!sign) printf("-("); 
    printNode(root);  
    if (!sign) printf(")"); 
}  
            
void prefixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        printf("%c ", node->nodeUnion.op.op);
        prefixTraversal(node->nodeUnion.op.left);
        prefixTraversal(node->nodeUnion.op.right);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

void infixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        infixTraversal(node->nodeUnion.op.left);
        printf("%c ", node->nodeUnion.op.op);
        infixTraversal(node->nodeUnion.op.right);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

void postfixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        postfixTraversal(node->nodeUnion.op.left);
        postfixTraversal(node->nodeUnion.op.right);
        printf("%c ", node->nodeUnion.op.op);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

double treeCalculator(Node* node) { 
    if (node == NULL) 
        return 0.0; 
    if (node->nodeType == OPERATOR) { 
        double leftValue = treeCalculator(node->nodeUnion.op.left); 
        double rightValue = treeCalculator(node->nodeUnion.op.right); 
        switch (node->nodeUnion.op.op) { 
            case '+': 
                return leftValue + rightValue; 
            case '-': 
                return leftValue - rightValue; 
            case '*': 
                return leftValue * rightValue; 
            case '/': 
                return leftValue / rightValue; 
            case '^': 
                return pow(leftValue, rightValue); 
        } 
    } else if (node->nodeType == VALUE) { 
        return node->nodeUnion.value; 
    } else if (node->nodeType == VARIABLE) { 
        printf("Input value:\n"); 
        scanf("%lf",&(node->nodeUnion.value)); 
        return node->nodeUnion.value; 
    } 
    return 0; 
}


int main(void) {
    char infixExpression[NODES_LENGTH];
    printf("Enter the expression:\n");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';
    Node* expressionTree = ExpressionTreeFromInfix(infixExpression);

    printf("Expression tree:\n");
    printExpressionTree(expressionTree, 0);

    printf("Tree size: %ld\n", treeSize(expressionTree));
    
    printf("\nPrefix traversal: ");
    prefixTraversal(expressionTree);
    printf("\nInfix traversal: ");
    infixTraversal(expressionTree);
    printf("\nPostfix traversal: ");
    postfixTraversal(expressionTree);
    printf("\nSimplified expression:\n");
    simplifyExpression(expressionTree, infixExpression);
    printf("\n");
    
    double result = treeCalculator(expressionTree);
    printf("Result: %.2f\n", result);

    deleteExpressionTree(expressionTree);
    
    return 0;
}
