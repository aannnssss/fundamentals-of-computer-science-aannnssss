#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned int uint;
#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a') | 1u << ('o' - 'a'))

typedef enum{
    OUT,
    IN
}State;

uint char_to_set(char c) {

    c = tolower(c);
    if(c < 'a' || c > 'z')
        return 0;
    else 
        return 1u << (c-'a'); }

bool check(uint n) {
    if (n > 0 && (n & (n - 1)) == 0)
        return true;
    return false; }
   

bool process() {
    State state = OUT;
    uint word_set = 0;
    bool result = false;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        switch (state) {
            case OUT:
                if (isspace(ch) || ch == ',') continue;
                
                else 
                    state = IN;
            case IN:
                if (isspace(ch) || ch == ',') {
               
                    state = OUT;
                    word_set = word_set&VOWELS;
                    result = result || check(word_set);
                    continue; }
                    
                else {
                    if (isalpha(ch)) {
                        word_set = word_set | char_to_set(ch);
                        continue; }
                    
                }
        }
    }
    return result;
}




int main() {
    if (process()) 
        printf("YES");
    else
        printf("NO");
    printf("\n");
    return 0;
}
