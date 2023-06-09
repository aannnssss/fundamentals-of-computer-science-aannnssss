#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    List* list = listCreate();
    printf("\n1. pushBack;\n2. pushFront;\n3. popBack;\n4. popFront;\n5. size;\n6. task;\n7. print list;\n8. insert node;\n9. delete node;\n0. quit.\n");
    for (bool flag = true; flag; ) {
        int value, index, number = -1;
        printf("Enter the number: ");
        scanf("%d", &number);
        switch (number) {
            case 1:
                printf("Enter the node value: ");
                scanf("%d", &value);
                listPushBack(list, value);
                break;
            case 2:
                printf("Enter the node value: ");
                scanf("%d", &value);
                listPushFront(list, value);
                break;
            case 3:
                listPopBack(list);
                break;
            case 4:
                listPopFront(list);
                break;
            case 5:
                printf("Size = %d\n", listSize(list));
                break;
            case 6:
                printf("Input k: ");
                scanf("%d", &value);
                Swap(list, value);
                break;
            case 7:
                listPrint(list);
                break;
            case 8:
                printf("Input index and value: ");
                scanf("%d %d", &index, &value);
                nodeInsert(list, index, value);
                break;
            case 9:
                printf("Input index: ");
                scanf("%d", &index);
                nodeDelete(list, index);
                break;
            case 0:
                printf("Finished\n");
                flag = false;
                break;
        }
    }
    return 0;
}
