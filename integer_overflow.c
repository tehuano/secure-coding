#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[80];
    int i = atoi(argv[1]);
    unsigned short s = i;
    if (s >= 80) {
        printf("Check failed\n");
        return 0;
    }
    printf("Check passed\n");
    memcpy(buf, argv[2], i);
    return 0;
}
