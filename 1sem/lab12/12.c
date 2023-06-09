#include <stdio.h>
#include <ctype.h>

typedef unsigned uint;

typedef enum {
    OUTSIDE,
    FIRST,
    SECOND,
    THIRD,
    MIDDLE
} State;

void process(void);

int main(void) {
    process();
    return 0;
}

void process(void) {
    State state = OUTSIDE;
    int temp[1] = { 0 };
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        switch (state) {
            case OUTSIDE:
                if (isdigit(ch)) {
                    state = FIRST;
                    temp[1] = ch;
                } else
                    putchar(ch);
                break;
            case FIRST:
                if (isdigit(ch)) {
                    temp[0] = ch;
                    state = SECOND;
                } else {
                    state = OUTSIDE;
                    putchar(temp[1]);
                    putchar(ch);
                }
                break;
            case SECOND:
                if (isdigit(ch)) {
                    state = THIRD;
                    putchar(temp[1]);
                    temp[1] = temp[0];
                    temp[0] = ch;
                } else {
                    state = OUTSIDE;
                    putchar(ch);
                }
                break;
            case THIRD:
                if (isdigit(ch)) {
                    state = MIDDLE;
                    temp[1] = temp[0];
                    temp[0] = ch;
                } else {
                    state = OUTSIDE;
                    putchar(temp[0]);
                    putchar(ch);
                }
                break;
            case MIDDLE:
                if (isdigit(ch)) {
                    putchar(temp[1]);
                    temp[1] = temp[0];
                    temp[0] = ch;
                } else {
                    state = OUTSIDE;
                    putchar(temp[0]);
                    putchar(ch);
                }
                break;
        }
    }
}
