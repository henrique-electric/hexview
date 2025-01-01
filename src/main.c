#include "../include/hexview.h"

void read_file(file_t *file) {
    if (file == NULL) {
        return;
    }

    printf("%ld bytes read from %s\n", file->file_size, file->file_name);
}

void print_content(const file_t *file) {
    if (file == NULL) {
        return;
    }

    // Loop to print the content
    for (uint64_t counter = 0; counter <= file->file_size; counter++) {

        /*
            Whenever the counter prints 8 segments of 2 bytes it break the line and print
            the nex value of data Ex: 00000000 -> 00000010
        */
        if (counter % 8 == 0) {
            printf("\n");
            printf("%08lx: ", counter * 2);
        }

        printf(WHITE_BOLD "%02x%02x " RESET_COLOR, file->buff[counter], file->buff[counter + 1]); // Print with a white bold terminal color the data
    }
    printf("\n"); // Breaks a line to not mess with the shell
}

void check_args(int argc, const char **argv) {
    if (argc < 2) {
        printf("How to use hexview \n ./hexview {file} -{args}\n");
    }
    
}

int main(int argc, const char *argv[]) {
    file_t *fd = init_hexview("test");
    fgets(fd->buff, fd->file_size, fd->fd);
    print_content(fd);
    close_hexview(fd);
    return 0;
}
