#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    float (*func[10])(float, float) = {NULL}, var_a = 0, var_b = 0, result = 0;
    void *ptr_dl_lib = NULL;
    char lib_name[16] = {'0'}, func_list[10][16] = {'0'}, func_name[16] = {'0'};
    int counter = 0, item = 0, i = 0;

    do {
        printf("Enter the library name:");
        scanf("%s",lib_name);

        ptr_dl_lib = dlopen(lib_name, RTLD_LAZY);

        if (NULL == ptr_dl_lib){
            printf("There isn't such library!!!\n\n");
        }
    } while (NULL == ptr_dl_lib);

    do {
        printf("Creating a calculator menu:\n    1.Add function\n    2.Function list\n    3.Exit\n\n");
        printf("Enter the item:");
        scanf("%d", &item);

        if(1 == item){
            if(counter < 10){
                printf("Enter the function name:");
                scanf("%s",func_name);
                printf("\n");
                if (dlsym(ptr_dl_lib, func_name) != NULL) {
                    func[counter] = dlsym(ptr_dl_lib, func_name);
                    strcpy(func_list[counter],func_name);
                    counter++;
                }
                else printf("There isn't such function!!!\n");
            }
            else printf("The menu if full!!!\n");
        }

        else if (2 == item) {
            if (counter != 0) {
                for(i = 0; i < counter; i++){
                    printf("%d. %s\n", (i+1), func_list[i]);
                }
            }
            else printf("The menu is empty!!!\n");
        }
        else if (item != 3) printf("There isn't item on the menu!!!\n");
        printf("\n");
    } while (item != 3);

    do {
        printf("\n\nMenu:\n");
        for(i = 0; i < counter; i++){
            printf("  %d. %s\n", i+1, func_list[i]);
        }
        printf("  %d. exit\n\n",i+1);

        printf("Enter the item:");
        scanf("%d", &item);
        item--;
        printf("\n");

        if ((item != counter)&&(item > -1)&&(item < (counter+1))){
            printf("Enter the variable a:");
            scanf("%f", &var_a);
            printf("Enter the variable b:");
            scanf("%f", &var_b);
            result = func[item](var_a, var_b);
            printf("Result = %.2f\n", result);
        }
        else if(item != counter) printf("There isn't item on the menu!!!\n");
        printf("\n");
    } while (item != counter);

    dlclose(ptr_dl_lib);

    return 0;
}