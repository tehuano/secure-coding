#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 10

void my_process(const char* input) {
    char buf[BUFFER_SIZE];
    printf("The stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
    strcpy(buf, input);
    printf("Now the stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

void print_message(void) {
    printf("I made a discovery today. I found a computer. Wait a second, this is cool.\n");
}

int main(int argc, char* argv[]) {
    printf("Address of my_process = %p\n", my_process);
    printf("Address of print_message = %p\n", print_message);
    if (argc != 2) {
        printf("Please supply a string as an argument!\n");
        return -1;
	} 
    my_process(argv[1]);
    return 0;
}