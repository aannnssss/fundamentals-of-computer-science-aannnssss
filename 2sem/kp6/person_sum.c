#include "person.h" 

int main(int argc, char* argv[]) { 
    if (argc != 2) { 
        fprintf(stderr, "Wrong number of args!\n"); 
        return 1; 
    } 

    FILE* file = fopen(argv[1], "rb"); 
    if (file == NULL) { 
        fprintf(stderr, "Can't open file!\n"); 
        return 1; 
    } 

    int counter; 
    if (fread(&counter, sizeof(int), 1, file) != 1) { 
        fprintf(stderr, "Read number of elems error!\n"); 
        return 1; 
    }

    Person* person = (Person*) malloc(counter * sizeof(Person)); 
    if (person == NULL) { 
        fprintf(stderr, "Unable to allocate memory for array of persons!\n"); 
        return 1; 
    } 

    int p1, p2, cnt = 0; 
    printf("Input p1 and p2: "); 
    scanf("%d %d", &p1, &p2); 

    if (fread(person, sizeof(Person), counter, file) != counter) { 
        fprintf(stderr, "Error while reading persons data from file!\n"); 
        free(person); 
        return 1; 
    } 
    if (0<=p1 && p1<=300 && 0<=p2 && p2<=300) {
		for (int i = 0; i < counter; ++i) { 
		    if (p1 <= person[i].marks && person[i].marks <= p2) {
		        printf("\n%s, %u", person[i].surname, person[i].marks);
		        cnt++;
		    }
		} 
		if (cnt == 0) {
		    printf("No people!\n");  
		    return 1; 
		}
    } else {
		printf("Wrong values!\n");
		return 1;
    }
    printf("\n");
    free(person); 
    return 0; 
}

