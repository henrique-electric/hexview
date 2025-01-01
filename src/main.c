#include "hexview.h"

void read_file(file_t *file) {
    if (file == NULL) {
        return;
    }

    fgets(file->buff, file->file_size, file->fd);
    printf("%ld bytes read from %s\n", file->file_size, file->file_name);
}

void print_content(const file_t *file) {
    if (file == NULL) {
        return;
    }

    uint32_t count = 0;
    while (count < (uint32_t) file->file_size) {
        printf("%x %x\n", file->buff[count], file->buff[count + 1]);
        count += 2;
    }
    
}

int main(int argc, const char *argv[]) {
    file_t *fd = init_hexview("test");
    read_file(fd);
    print_content(fd);
    close_hexview(fd);
    return 0;
}
