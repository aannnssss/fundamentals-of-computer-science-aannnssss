#include "key.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    key k;
    char val[99];
} map;

int keycmp(key k1, key k2) { 
    if (k1.num == k2.num) {
        return 0;
    } else if (k1.num < k2.num) {
        return -1;
    } else {
        return 1;
    }
}

bool read_keys(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].k, sizeof(key), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

bool read_art(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].val, sizeof(char[99]), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

void bubble_sort(int table_size, map* m) {
    map tmp;
    for (int i = 0; i < table_size - 1; i++) {
        for (int j = 0; j < table_size - 1 - i; j++) {
            if (keycmp(m[j].k, m[j + 1].k) > 0) {
                tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }
}

void print_art(int n, map* m) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", m[i].k.num);
        printf("%s\n", m[i].val);
    }
}

key get_key() { 
    key k; 
    scanf("%f", &k.num);
    return k; 
} 
 
int binary_search(key k, int n, map* m) {  
    int low = 0, high = n - 1;  
    while (low <= high) {  
        int mid = (low + high) / 2;  
        int cmp = keycmp(m[mid].k, k);  
        if (cmp == 0) {  
            return mid;  
        } else if (cmp < 0) {  
            low = mid + 1;  
        } else {  
            high = mid - 1;  
        }  
    }  
    return -1;  
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* art = fopen(argv[1], "rb");
    if (art == NULL) {
        fprintf(stderr, "Can't open the second file!\n");
        return 2;
    }
    FILE* keys = fopen(argv[2], "rb");
    if (keys == NULL) {
        fprintf(stderr, "Can't open the first file!\n");
        return 2;
    }
    int n;
    if (fread(&n, sizeof(int), 1, keys) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 3;
    }

    map m[n];
    if (!read_keys(keys, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    if (!read_art(art, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    fclose(keys);
    fclose(art);
    print_art(n, m);
    bubble_sort(n, m);
    printf("\n");
    print_art(n, m);
    while (true) {
        printf("Enter key:\n");
        key user = get_key();
        int idx = binary_search(user, n, m);
        if (idx < 0) {
            printf("Key not found!\n");
            break;
        } else {
            printf("%s\n", m[idx].val);
        }
    }

    return 0;
}
