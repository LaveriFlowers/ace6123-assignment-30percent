#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int year;
    char era[10];
    float age;
    int forms;
} Ultraman;

int compareforms(const void *a, const void *b) {
    Ultraman *u1 = (Ultraman *)a;
    Ultraman *u2 = (Ultraman *)b;
    return u2->forms - u1->forms;
}

int compareage(const void *a, const void *b) {
    Ultraman *u1 = (Ultraman *)a;
    Ultraman *u2 = (Ultraman *)b;
    return u2->age - u1->age;
}

void display_entries(Ultraman *entries, int count) {
    printf("\n-------------------|--------------------|----------|-----------------------|-------------");
    printf("\n [NAME]            | [YEAR RELEASED]    | [ERA]    |  [AGE (YEARS x1000)]  |  [FORMS]");
    printf("\n-------------------|--------------------|----------|-----------------------|-------------\n"); 

    for (int i = 0; i < count; i++) {
        printf("%d. %s|   %-16d | %7s| %15.3f       | %5d\n",
            i + 1, entries[i].name, entries[i].year, entries[i].era,
            entries[i].age, entries[i].forms);
    }
}

int main(){
    FILE *fileread;
    fileread = fopen("ultradata.txt", "r");
    
    char nebula_m78[9999];
    char search_term[30];
    char line[9999];
    int found = 0;
    int option, count, i;
    char exitchoice;

    if(fileread == NULL) {
        printf("Not able to open the file.");
    } else {
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        printf("\n\t\t\tFile read successfully. Please use all caps.\n\t\t\t\tWelcome to The Land of Light!");
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    }
    
    do {                                                                                                                                                                                                                                                                                                                                                               
        printf("\n - - - - - - - - - - - - -");
        printf("\n  View all Entries |  1  |\n  Search by Term   |  2  |\n  Sort by Forms    |  3  |");
        printf("\n  Sort by Age      |  4  |\n  Add Entry        |  5  |\n  Remove Entry     |  6  |");
        printf("\n  Exit             |  0  |\n - - - - - - - - - - - - -");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        rewind(fileread);
    

        if (option == 1) /* View all Entries */{
            
            {
                printf("\n-------------------|--------------------|----------|-----------------------|-------------");
                printf("\n [NAME]            | [YEAR RELEASED]    | [ERA]    |  [AGE (YEARS x1000)]  |  [FORMS]");
                printf("\n-------------------|--------------------|----------|-----------------------|-------------\n"); 
                
                if (fgets(nebula_m78, sizeof(nebula_m78), fileread) != NULL) {
                    printf("%s", nebula_m78);
                }
                while (fgets(nebula_m78, sizeof(nebula_m78), fileread)) {
                    printf("%s", nebula_m78);
                }
            }    
            
            printf("-------------------|--------------------|----------|-----------------------|-------------\n");
        
        } else if (option == 2) /* Search by Term */{
            printf("\n REMEMBER TO USE ALL CAPS!\n Search Term (i.e. 'SHOWA', 'ULTRA_SEVEN'): ");
            scanf("%s", search_term);
            found = 0;
            
            {
                printf("\n-------------------|--------------------|----------|-----------------------|-------------");
                printf("\n [NAME]            | [YEAR RELEASED]    | [ERA]    |  [AGE (YEARS x1000)]  |  [FORMS]");
                printf("\n-------------------|--------------------|----------|-----------------------|-------------\n");
                
                while (fgets(line, sizeof(line), fileread)) {
                    if (strstr(line, search_term) != NULL) {
                        printf("%s", line);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\n\t\t\t\tNo match found for '%s'.\n\n", search_term);
                }
                printf("-------------------|--------------------|----------|-----------------------|-------------\n");
                
            }
            
        /* Sort by Forms */    
        } else if (option == 3) /* Sort by Forms */{
            
            {
                printf("\n-------------------|--------------------|----------|-----------------------|-------------");
                printf("\n [NAME]            | [YEAR RELEASED]    | [ERA]    |  [AGE (YEARS x1000)]  |  [FORMS]");
                printf("\n-------------------|--------------------|----------|-----------------------|-------------\n");            

                Ultraman betacapsule[9999];
                count = 0;

                while (fgets(line, sizeof(line), fileread)) {
                    if (line[0] == '-') continue;
                        sscanf(line, "%[^|] | %d | %[^|] | %f | %d ",
                            betacapsule[count].name, &betacapsule[count].year, betacapsule[count].era,
                            &betacapsule[count].age, &betacapsule[count].forms);
                        count++;
                } 

                qsort(betacapsule, count, sizeof(Ultraman), compareforms);

                for (i = 0; i < count; i++) {
                    printf("%s|   %-16d | %7s| %15.3f       | %5d\n",
                        betacapsule[i].name, betacapsule[i].year, betacapsule[i].era,
                        betacapsule[i].age, betacapsule[i].forms);
                }
        
                printf("-------------------|-------------------------------------------------------|-------------\n");
            }

        } else if (option == 4) /* Sort by Age */{
           
            {
                printf("\n-------------------|--------------------|----------|-----------------------|-------------");
                printf("\n [NAME]            | [YEAR RELEASED]    | [ERA]    |  [AGE (YEARS x1000)]  |  [FORMS]");
                printf("\n-------------------|--------------------|----------|-----------------------|-------------\n");            

                Ultraman betacapsule[9999];
                count = 0;

                while (fgets(line, sizeof(line), fileread)) {
                    if (line[0] == '-') continue;
                        sscanf(line, "%[^|] | %d | %[^|] | %f | %d ",
                            betacapsule[count].name, &betacapsule[count].year, betacapsule[count].era,
                            &betacapsule[count].age, &betacapsule[count].forms);
                        count++;
                } 

                qsort(betacapsule, count, sizeof(Ultraman), compareage);

                for (i = 0; i < count; i++) {
                    printf("%s|   %-16d | %7s| %15.3f       | %5d\n",
                        betacapsule[i].name, betacapsule[i].year, betacapsule[i].era,
                        betacapsule[i].age, betacapsule[i].forms);
                }
                
                printf("-------------------|--------------------|----------|-----------------------|-------------\n");            
            }
            
            
        } else if (option == 5) /* Add Entry */{
            printf("\n - - - - - - - - - - - - - \n Add a new Ultraman entry. \n - - - - - - - - - - - - -");

            Ultraman new_entry;

            printf("\n Enter name: ");
            scanf(" %[^\n]", new_entry.name); 

            printf(" Enter year: ");
            scanf("%d", &new_entry.year);

            printf(" Enter era: ");
            scanf("%s", new_entry.era);

            printf(" Enter age (in thousands of years): ");
            scanf("%f", &new_entry.age);

            printf(" Enter number of forms: ");
            scanf("%d", &new_entry.forms);

            FILE *fptr_append = fopen("ultradata.txt", "a");
            if (fptr_append == NULL) {
                printf("Error opening file for appending.\n");
            } else {
                fprintf(fptr_append, " %-17s |   %-16d | %-8s | %14.3f        | %5d\n",
                        new_entry.name, new_entry.year, new_entry.era, new_entry.age, new_entry.forms);
                fclose(fptr_append);
                
                printf("\n - - - - - - - - - - - - - - - - - - - - - ");
                printf("\n Entry added successfully. ");
                printf("\n - - - - - - - - - - - - - - - - - - - - - ");
            }
        
        } else if (option == 6) /* Remove Entry */{ 
            Ultraman betacapsule[9999];
            count = 0;

            while (fgets(line, sizeof(line), fileread)) {
                if (line[0] == '-') continue;
                sscanf(line, "%[^|] | %d | %[^|] | %f | %d ",
                    betacapsule[count].name, &betacapsule[count].year, betacapsule[count].era,
                    &betacapsule[count].age, &betacapsule[count].forms);
                count++;
            }

            display_entries(betacapsule, count);
            
            printf("-----------------------------------------------------------------------------------------\n");
            
            int entry_to_delete;
            printf("\n Enter the number of the entry you want to delete: ");
            scanf("%d", &entry_to_delete);

            if (entry_to_delete > 0 && entry_to_delete <= count) {
                FILE *fptr_write = fopen("ultradata.txt", "w");
                if (fptr_write == NULL) {
                    printf("Error opening file for writing.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        if (i != entry_to_delete - 1) {
                            fprintf(fptr_write, "%s|   %-16d | %7s| %15.3f       | %5d\n",
                                    betacapsule[i].name, betacapsule[i].year, betacapsule[i].era,
                                    betacapsule[i].age, betacapsule[i].forms);
                        }
                    
                    }
                    
                    fclose(fptr_write);
                    printf("\n Entry deleted successfully.\n");
                }
            
            } else {
                printf("\n Invalid entry number.\n");
            }
            
        
        } else if (option == 7) /* Ultraseven reference */{
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t\t\tSeven, Seven, Seven, Seven, Seven! Seven! Seven!\n\t\t\t\t ~~ You found an easter egg! ~~");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
        
        } else if (option == 0) /* Exit */{
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");            
            printf("\n\t\t\t\tAre you sure you want to exit?\n\n\t\t\t   YES - | Y |\t\t\t  NO  - | N |");
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");   
            printf("\n\t\t\t\t\t  CHOICE: ");
            scanf("\n\n %c", &exitchoice);
            
            if (exitchoice == 'Y' || exitchoice == 'y') {
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
                printf("\n\t\t\t\tLeaving the Land of Light...\n");
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            } else if (exitchoice == 'N' || exitchoice == 'n') {
                option = -1;
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");                
            }
            
        } else /* When user inputs = invalid */{
            printf("\n\t\t\t\tPlease select from the available options\n");
        }

    } while (option != 0);
    
    fclose(fileread);

    return 0;
}

