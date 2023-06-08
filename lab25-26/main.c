#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "list.h"

int main(void) {
    List list;
    listCreate(&list);

    printf("Creating list. Enter the size: ");
    ptrdiff_t n;
    scanf("%td", &n);
    printf("Enter the list: ");
    for (; n > 0; --n) {
        int value;
        scanf("%d", &value);
        listPushBack(&list, value);
    }

    printf("\n1. pushBack;\n2. pushFront;\n3. popBack;\n4. popFront;\n5. erase;\n6. destroy;\n7. clear;\n8. size;\n9. Sorting by simple insertion;\n10. Check if the list is empty;\n11. Print list;\n12. Print list debug;\n0. Quit.\n");
    for (bool flag = true; flag; ) {
        int value, number = -1;
        printf("Enter the number: ");
        scanf("%d", &number);
        switch (number) {
            case 1:
                printf("Enter the node value: ");
                scanf("%d", &value);
                listPushBack(&list, value);
                break;
            case 2:
                printf("Enter the node value: ");
                scanf("%d", &value);
                listPushFront(&list, value);
                break;
            case 3:
                listPopBack(&list);
                break;
            case 4:
                listPopFront(&list);
                break;
            case 5:
                printf("Enter the node value: ");
                scanf("%d", &value);
                listErase(&list, value);
                break;
            case 6:
                listDestroy(&list);
                break;
            case 7:
                listClear(&list);
                break;
            case 8:
                printf("List size = %td\n", listSize(&list));
                break;
            case 9:
                printf("Sorting by simple insertion completed: %d\n", sort(&list));
                break;
            case 10:
                printf("The list is%s empty\n", listIsEmpty(&list) ? "" : " not");
                break;
            case 11:
                listPrint(&list);
                printf("\n");
                break;
            case 12:
                listDebugPrint(&list);
                break;
            case 0:
                printf("Finished\n");
                flag = false;
                break;
        }
    }
    return 0;
}
