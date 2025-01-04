#include "../include/hexview.h"

void print_content(const file_t *file) {
    if (file == NULL) {
        return;
    }

    // Loop to print the content
    for (uint64_t counter = 0; counter <= file->file_size; counter++) {
        if (counter % 2 == 0) {
            printf(" ");
            
        }
        /*
            Whenever the counter prints 8 segments of 2 bytes it break the line and print
            the nex value of data Ex: 00000000 -> 00000010
        */
        if (counter % 16 == 0) {
            printf("\n");
            printf("%08llx: ", counter);
        }
    
        printf(WHITE_BOLD "%02x" RESET_COLOR, file->buff[counter]); // Print with a white bold terminal color the data
    }
    printf("\n"); // Breaks a line to not mess with the shell
}

void check_args(int argc, const char **argv) {
    if (argc < 2) {
        printf("How to use hexview \n ./hexview {file} -{args}\n");
        exit(EXIT_FAILURE);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "File does not exist\n");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

int main(int argc, const char *argv[]) {
    check_args(argc, argv);
    file_t *fd = init_hexview(argv[1]);
    read(fd->fd, fd->buff, fd->file_size);
    analyze_file(fd);
    //print_content(fd);
    close_hexview(fd);
    return 0;
}
