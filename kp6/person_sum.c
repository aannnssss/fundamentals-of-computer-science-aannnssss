#include "person.h" 

void printUp(){
    printf ("______________________________________________________________________\n");
    printf ("|  surname  | initials | gender |school number| medal| marks | essay |\n");
}

void listPrint(FILE *input) { 
    Person person; 
    while (fread(&person, sizeof(person), 1, input)) {
        person.medal = person.medal != 0;
        person.essay = person.essay != 0;
        printf("|%-11s|%-10s|%-8c|%-13u|%-6d|%-7u|%-7d|\n", person.surname, person.initials, person.gender, person.school_number, person.medal, person.marks, person.essay);    
    } 
}

void printDown(){
    printf ("______________________________________________________________________\n");
}

int listStudents(FILE * file, int p1, int p2) {  
    int cnt = 0; 
    Person person;
    if (0<=p1 && p1<=300 && 0<=p2 && p2<=300 && p1<=p2) { 
        printUp(); 
        while (fread (&person, sizeof(person), 1, file) == 1) {
    	    person.medal = person.medal != 0;
            person.essay = person.essay != 0; 
            if (p1 <= person.marks && person.marks <= p2) {  
                printf ("|%-11s|%-10s|%-8c|%-13u|%-6d|%-7u|%-7d|\n",  person.surname, person.initials, person.gender, person.school_number, person.medal, person.marks, person.essay);    
                cnt++;  
            }  
        } 
        printDown();   
        if (cnt == 0) {  
            printf("No people!\n");    
            return 1;   
        } else { 
            printf("%d people were found!", cnt); 
        } 
    } else {  
        printf("Wrong values!\n");  
        return 1;  
    } 
    printf("\n");  
    return 0;  
}  

int main(int argc, char *argv[]) {   
    if (argc < 3) {   
        usage(); 
        fprintf(stderr, "Wrong number of args!\n");   
        return 1;   
    }   
  
    FILE* file = fopen(argv[1], "r");   
    if (file == NULL) {   
        fprintf(stderr, "Can't open file!\n");   
        return 1;   
    }   
    if(!strcmp(argv[2], "-f")){ 
        printUp(); 
        listPrint(file); 
        printDown(); 
    } else {
        int p1 = atoi(argv[2]), p2 = atoi(argv[3]); 
        if (p1 && p2) listStudents(file, p1, p2); 
    }
    fclose(file);  
    return 0;   
}
