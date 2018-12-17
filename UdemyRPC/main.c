#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[30];
    int age;
    struct  occupation *occ;
    struct person *boss;
    struct  person *mentor;
};


struct occupation {
    char designation[30];
    int salary;
};

int main() {

    printf("size= %lu\n", sizeof(struct person));
    return 0;
}