#ifndef HEXVIEW_H
#define HEXVIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>

typedef struct file {
    FILE        *fd;
    uint8_t     *buff;
    char        *file_name;
    size_t      file_size;
} file_t;

file_t* init_hexview(const char *file);
void    close_hexview(file_t *file);
size_t get_file_size(const char *path);

#endif