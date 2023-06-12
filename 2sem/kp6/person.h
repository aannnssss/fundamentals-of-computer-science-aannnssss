#ifndef PERSON_H
#define PERSON_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

typedef struct {
    char surname[50];
    char initials[2];
    char gender;
    uint school_number;
    char medal; //0 - NO, 1 - YES
    uint marks;
    char essay; //0 - NO, 1 - YES
} Person;
#endif //PERSON_H

