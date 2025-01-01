#ifndef HEXVIEW_H
#define HEXVIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>

//Colors
#define RED_BOLD  "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"
#define RESET_COLOR "\033[0m"
#define WHITE_BOLD  "\033[1;37m"

//struct hexview_args {
    
//};

// Main file struct 
typedef struct file {
    FILE        *fd;             // pointer to the file that the program will open
    uint8_t     *buff;          // A buffer to hold the data from the file
    char        *file_name;     // The path to the file that will be opened by the program
    size_t      file_size;      // The actual size of the file
} file_t;

file_t* init_hexview(const char *file); // Function to initialize the struct and data related to
void    close_hexview(file_t *file);    // Free all memory consumed by the struct and close the opened file
size_t  get_file_size(const char *path); // Function to get the file size
#endif