#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>
#include "sort.h"
#include "list.h"


int main() {
    List list;
    create(&list);
    
    int value, n;
    printf("Creating list. Enter the size: ");
    scanf("%d", &n);
    printf("Enter the list: ");
    while (n > 0) {
        scanf("%d", &value);
        pushBack(&list, value);
        n -= 1;
    }
    int number = -1, t = 1;
    printf("\n1. pushBack;\n2. pushFront;\n3. popBack;\n4. popFront;\n5. Erase;\n6. Destroy;\n7. Clear;\n8. Size;\n9. Sorting by simple insertion;\n10. Check if the list is empty;\n11. Print list;\n12. DebugList\n0. Quit.\n");
    while (t) {
        printf("Enter the number: ");
        scanf("%d", &number);
        if (number == 1) {  
            printf("Enter the node value: ");
            scanf("%d", &value);
            pushBack(&list, value);
        }
        else if (number == 2) {
            printf("Enter the node value: ");
            scanf("%d", &value);
            pushFront(&list, value);
        }
        else if (number == 3) {
            popBack(&list);
        }
        else if (number == 4) {
            popFront(&list);
        }
        else if (number == 5) {
            printf("Enter the node value: ");
            scanf("%d", &value);
            erase(&list, value);
        }
        else if (number == 6) {
            destroy(&list);
        }
        else if (number == 7) {
            clear(&list);
        }
        else if (number == 8) {
            size_t size = listSize(&list);
            printf("List size = %zu\n", size);
        }
        else if (number == 9) {
            sort(&list);
            printf("Sorting by simple insertion completed\n");
        }
        else if (number == 10) {
            bool empty = isEmpty(&list);
            if (empty) {
                printf("The list is not empty\n");
            }
            else {
                printf("The list is empty\n");
            }
        } else if (number == 11) {
            printList(&list);
            printf("\n");
            
        } else if (number == 12) {
            printDebugList(&list);
            printf("\n");   
         
        } else if (number == 0) {
            printf("Finished\n");
            t = 0;
        }
    }
    return 0;
}
