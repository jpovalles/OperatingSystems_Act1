/* Write a program to display number 1 to 10 in octal,decimal and hexadecimal system*/

#include <stdio.h>

int main() {
    int i;

    printf("Numero\tDecimal\tOctal\tHexadecimal\n");
    printf("------------------------------------\n");

    for (i = 1; i <= 10; i++) {
        printf("%d\t%d\t%o\t%x\n", i, i, i, i);
    }

    return 0;
}