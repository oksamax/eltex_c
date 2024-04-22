#include <dlfcn.h>
#include <stdio.h>

int main(void)
{
    float (*func[10])(float, float) = { NULL }, var_a = 0, var_b = 0;
    void *ptr_dl_lib = NULL;
    char lib_name[16] = {'0'}, func_list[10][16] = {'0'}, func_name[16] = {'0'};
    int count = 0, item = 0;

    do {
        printf("Enter the library name:");
        scanf("%s",lib_name);

        ptr_dl_lib = dlopen(lib_name, RTLD_LAZY);

        if (NULL == ptr_dl_lib){
            printf("There isn't such library\n");
        }
    } while (NULL == ptr_dl_lib);

    do {
        printf("creating a calculator menu")

        if(1 == item){
            printf("Enter the function name:");
            scanf("%s",func_name);
            if (dlsym(ptr_dl_lib, func_name) != NULL) {
                func[count] = dlsym(ptr_dl_lib, func_name);
                strcpy();
                count++;
            }
            else printf("there isn't such func");
            
        }
        else if (2 == item) {

        }
        else if (item != 3) printf();
  
    } while (item != 3)

    dlclose(ptr_dl_lib);

    return 0;
}