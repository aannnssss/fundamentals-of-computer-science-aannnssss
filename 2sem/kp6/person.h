#ifndef PERSON_H
#define PERSON_H
#define LINE_SIZE (40U)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

typedef struct {
    char surname[LINE_SIZE];
    char initials[LINE_SIZE];
    char gender;
    uint school_number;
    bool medal;
    uint marks;
    bool essay;
} Person;

void usage(){
    printf("Usage: program filename\n");
}
#endif //PERSON_H

