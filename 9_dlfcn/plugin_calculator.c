#include <dlfcn.h>
#include <stdio.h>

int main(void)
{
    float (*func[10])(float, float) = { NULL }, var_a = 0, var_b = 0;
    void *dl_lib = NULL;

    dl_lib = dlopen("libcalc.so", RTLD_LAZY);

    if (NULL == dl_lib){
        printf("there isn't such library\n");
    }

    func[0] = dlsym(dl_lib, "add");

    if (NULL == func[0]) {
        printf("there isn't such func");
    }

    var_a = 10;
    var_b = 11.1;

    printf("a + b = %.2f", func[0](var_a, var_b));

    dlclose(dl_lib);

    return 0;
}