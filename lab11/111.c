#include <stdio.h>
#include <ctype.h>
#include <math.h>

int to_km (int mi) { 
    int i = 0;
    i = round(mi * 1.609);
    return i;
}

typedef enum {
    OUT,
    IN_DIGIT,
    CONTINUE,
    IN_MAYBE_MILE,
    IN_MILE
} state;


int main() {
    state state = OUT;
    int n = 0;
    for (int c = getchar(); c != EOF; c = getchar()) {
        switch (state){
            case OUT:
                if (isdigit(c)){
                    state = IN_DIGIT;
                    n += (c - '0');
                } else if ((c == ' ') || (c == '\n')) {
                    putchar(c);
                } else {
                    putchar(c);
                    state = CONTINUE;
                }
                break;
            case IN_DIGIT:
                if(isdigit(c)) {
                    n = n * 10 + (c - '0');
                } else if(c == 'm') {
                    state = IN_MAYBE_MILE;
                } else if((c == ' ') || (c == '\n')) {
                    printf("%d%c", n, c);
                    n = 0;
                    state = OUT;
                } else {
                    state = CONTINUE;
                    printf("%d", n);
                    n = 0;
                    putchar(c);
                }
                break;
            case CONTINUE:
                if ((c == ' ') || (c == '\n')) {
                    putchar(c);
                    state = OUT;
                } else {
                    putchar(c);
                }
                break;
            case IN_MAYBE_MILE:
                if (c == 'i') {
                    state = IN_MILE;
                } else if((c == ' ') || (c == '\n')) {
                    printf("%dm%c", n, c);
                    n = 0;
                    state = OUT;
                } else {
                    printf("%dm", n);
                    n = 0;
                    putchar(c);
                    state = CONTINUE;
                }
                break;
            case IN_MILE:
                if((c == ' ') || (c == '\n')) {
                    printf("%dkm%c", to_km(n), c);
                    n = 0;
                    state = OUT;
                } else {
                    state = CONTINUE;
                    printf("%dmi", n);
                    n = 0;
                    putchar(c);
                }
                break;
        }
    }
    return 0;
}

