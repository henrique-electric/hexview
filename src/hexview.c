#include "../include/hexview.h"

file_t *init_hexview(const char *file) {
    if (file == NULL) {
        fprintf(stderr, "No file provided\n");
        exit(1);
    }
    
    // Alloc and check memory for the main file struct
    file_t *new_file_struct = (file_t *) malloc(sizeof(file_t));
    if (new_file_struct == NULL) {
        fprintf(stderr, "Error on allock file struct\n");
        return NULL;
    }

    // Try to get the size of the file
    new_file_struct->file_size = get_file_size(file);
    if (new_file_struct->file_size == 0) {
        fprintf(stderr, "Error on get file size, aborting program\n");
        free(new_file_struct);
        return NULL;
    }

    // Allocates memory for the buffer that will hold the program data
    new_file_struct->buff     = (uint8_t *) malloc(new_file_struct->file_size);
    if (new_file_struct->buff == NULL) {
        fprintf(stderr, "Error on alloc to buffer");
        free(new_file_struct);
        return NULL;
    }

    // Allocates a buffer to hold the name of the file
    new_file_struct->file_name = (char *) malloc(strlen(file) + 1);
    if (new_file_struct->file_name == NULL) {
        fprintf(stderr, "Failed to alloc memory for file_name buffer");
        free(new_file_struct->buff);
        free(new_file_struct);
        return NULL;
    }
    strcpy(new_file_struct->file_name, file);

    // Tries to open the file in read mode
    new_file_struct->fd = fopen(file, "rb");
    if (new_file_struct->fd == NULL) {
        fprintf(stderr, "File dont exist");
        free(new_file_struct->file_name);
        free(new_file_struct->buff);
        free(new_file_struct);
        return NULL;
    }
     
    return new_file_struct;
}

// Close the file and free all the memory
void close_hexview(file_t *file) {
    if (file != NULL) {
        if (file->fd != NULL) {
            fclose(file->fd); // Close the file if pointer isn't NULL
        }
        free(file->buff);     // Free the buffer that holds the binary data
        free(file);           // Free the struct itself
        file = NULL;          // Set the pointer to the struct to NULL
    }
}

// Using Linux syscall to get the attributes about the file that hexview will open and return the size
size_t get_file_size(const char *path) {
    if (path == NULL) {
        return 0;
    }
    
    struct stat file_status; // Buffer to store the attributes
    
    // Invoking Syscall to get attributes
    if (stat(path, &file_status) != 0) { 
        fprintf(stderr, "Error on get the size of the file");
        return 0;
    }

    return (size_t) file_status.st_size; // return the casted type size
}
