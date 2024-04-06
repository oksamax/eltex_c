#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list {
    char first_name[16];
    char second_name[16];
    char number[16];
};

int main(void)
{
    struct list *user = NULL;
    int item = 0, counter = 0, i = 0, counter_fd = 0;
    char find_delete[16] = {'0'};

    do {
        puts("***Telephone directory***\n     Menu:\n   1.Add user\n   2.List of users\n   3.Find user\n   4.Delete user\n   5.Exit\n\n");
        
        printf("Enter the item:");
        scanf("%d", &item);

        if (1 == item) {
            if (counter < 1) {
                user = malloc(sizeof(struct list));
                if (0 == user) {
                    printf("MEMORY ALLOCATION ERROR!!!");
                    exit(EXIT_FAILURE);
                }
                printf("Enter the first name:");
                scanf("%s", user->first_name);
                printf("Enter the second name:");
                scanf("%s", user->second_name);
                printf("Enter the number:");
                scanf("%s", user->number);
                counter++;
            }
            else if (counter < 10) {
                user = realloc(user, (counter+1)*sizeof(struct list));
                if (0 == user) {
                    printf("MEMORY ALLOCATION ERROR!!!");
                    exit(EXIT_FAILURE);
                }
                printf("Enter the first name:");
                scanf("%s", (user+counter)->first_name);
                printf("Enter the second name:");
                scanf("%s", (user+counter)->second_name);
                printf("Enter the number:");
                scanf("%s", (user+counter)->number);
                counter++;
            }
            else puts("The telephone directory is full!!!");
        }
        else if (2 == item) {
            if (counter > 0) {
                for(i = 0; i < counter; i++) {
                    printf("%d. First name: %-16s  Second name: %-16s  Number: %-16s\n",i+1, (user+i)->first_name, (user+i)->second_name, (user+i)->number);
                }
            }
            else puts("The telephone directory is empty!");

        }
        else if (3 == item) {
            if (counter > 0) {
                printf("Enter a second name to search:");
                scanf("%s", find_delete);
                for(i = 0; i < counter; i++) {
                    if (!(strcmp(find_delete, (user+i)->second_name))) {
                        printf("%d. First name: %-16s  Second name: %-16s  Number: %-16s\n",counter_fd+1, (user+i)->first_name, (user+i)->second_name, (user+i)->number);
                        counter_fd++;
                    }
                }
                if(0 == counter_fd) puts("This user is not in the telephone directory!!!");
                counter_fd = 0;
            }
            else puts("The telephone directory is empty!");
        }
        
        else if (4 == item) {
            if (counter > 0) {
                printf("Enter a first name to delete:");
                scanf("%s", find_delete);
                for(i = 0; i < counter; i++) {
                    if (!(strcmp(find_delete, (user+i)->second_name))) {
                        if (counter == 1) {
                            printf("Delete user: First name: %-16s  Second name: %-16s  Number: %-16s\n", user->first_name, user->second_name, user->number);
                            free(user);
                            user = NULL;
                            counter--;
                            counter_fd++;
                        }
                        else {
                            printf("Delete user: First name: %-16s  Second name: %-16s  Number: %-16s\n", (user+i)->first_name, (user+i)->second_name, (user+i)->number);
                            strcpy((user+i)->first_name, (user+counter-1)->first_name);
                            strcpy((user+i)->second_name, (user+counter-1)->second_name);
                            strcpy((user+i)->number, (user+counter-1)->number);
                            counter--;
                            i--;
                            counter_fd++;
                            if (0 == user) {
                                puts("MEMORY ALLOCATION ERROR!!!");
                                exit(EXIT_FAILURE);
                            }
                        }
                    }
                }
                if(0 == counter_fd) puts("This user is not in the telephone directory!!!");
                else if (counter > 0){
                    user = realloc(user,(counter)*sizeof(struct list));
                    if (0 == user) {
                        puts("MEMORY ALLOCATION ERROR!!!");
                        exit(EXIT_FAILURE);
                    }
                }
                counter_fd = 0;
            }
            else puts("The telephone directory is empty!");
        }
        else if (item != 5){
            puts("This item is not in the menu!!!");
        }
        puts("\n\n");
    } while(item != 5);

    if(user != 0) free(user);

    return 0;
}