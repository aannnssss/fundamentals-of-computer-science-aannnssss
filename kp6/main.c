#include "person.h"
     
int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage();
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    Person person;
    FILE* input = fopen(argv[2], "r");
    FILE* output = fopen(argv[1], "w");
    if (input == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        return 2;
    }
    if (output == NULL) {
        fprintf(stderr, "Can't create output file!\n");
        return 2;
    }
    int counter = 0;
    for (int medal, essay; fscanf(input, "%s\t%s\t%c\t%u\t%d\t%u\t%d\n", person.surname, person.initials, &person.gender, &person.school_number, &medal, &person.marks, &essay) == 7; counter++) {
        person.medal = medal != 0;
        person.essay = essay != 0;
        if (fwrite(&person, sizeof(person), 1, output) != 1) {
            fprintf(stderr, "Write error!");
            return 1;
        }
        counter++;
    }
    fclose(input);
    fclose(output);
    return 0;
}

