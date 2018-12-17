//
// Created by aslan on 30.11.18.
//


#include <stdio.h>
#include <string.h>

extern int create_and_write_shared_memory (char *mmap_key,
                                    char *value,
                                    unsigned int size);

int
main (int argc, char **argv){

    char *key = "/intro";
    char *intro = "Hello, i am Aslan";
    create_and_write_shared_memory(key, intro, strlen(intro));
    return 0;
}
