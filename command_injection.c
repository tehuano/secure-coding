#include <stdio.h>
#include <string.h>

#define MAX_CMD 128

int main(int argc, char *argv[]) {
    char cat[] = "cat ";
    char command[MAX_CMD];
    size_t commandLength;
    commandLength = strlen(cat) +
    strlen(argv[1]) + 1;
    strncpy(command, cat, commandLength);
    strncat(command, argv[1],(commandLength - strlen(cat)) );
    system(command);
	return 0;
}