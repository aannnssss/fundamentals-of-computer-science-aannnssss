#include "person.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 2;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create output file!\n");
        return 3;
    }
    Person person;
    int counter = 0;
    fseek(output, sizeof(int), SEEK_SET);
    while(fscanf(input, "%[^ ] %2s %c %u %d %u %d\n", person.surname, person.initials, &person.gender, &person.school_number, &person.medal, &person.marks, &person.essay) == 7){
        if (fwrite(&person, sizeof(Person), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        counter++;
    }
    fseek(output, 0, SEEK_SET);
    if (fwrite(&counter, sizeof(int), 1, output) != 1) {
        fprintf(stderr, "Write error!\n");
        return 1;
    }
    printf("%d lines are written\n", counter);
    fclose(input);
    fclose(output);
    return 0;
}
