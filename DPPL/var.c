#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    int i = 0, *ptr = NULL;

    printf("Enter number: ");
    
    while (1) {
        ch = getchar();  // Input ek ek character lekar
        if (ch == '\n')  // Enter press hone pe loop break
            break;

        int *temp = realloc(ptr, (i + 1) * sizeof(int));  // Memory badhao
        if (!temp) {
            printf("\nMemory allocation failed!\n");
            free(ptr);
            return 1;
        }
        ptr = temp;  // Safe realloc

        ptr[i] = ch - '0';  // Character to integer conversion
        i++;
    }
    
    printf("Your Number: ");
    for (int j = 0; j < i; j++) {
        printf("%d", ptr[j]);
    }

    free(ptr);  // Memory free karo
    return 0;
}
