#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int *x) {
    if (x < 0) return false;


    char str[20]; 
    sprintf(str, "%d", *x);

    int inicio = 0;
    int fin = strlen(str) - 1;

    while (inicio < fin) {
        if (str[inicio] != str[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }

    return true;
}

int main() {
    int numero = 121121121;
    
    if (isPalindrome(&numero)) {
        printf("%d es un palíndromo.\n", numero);
    } else {
        printf("%d no es un palíndromo.\n", numero);
    }
    
    return 0;
}