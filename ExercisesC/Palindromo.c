#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Casos base: 
    // 1. Los números negativos no son palíndromos (por el signo -).
    // 2. Si el número termina en 0, solo es palíndromo si es 0 mismo.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int original = x;
    long reverso = 0; // Usamos long para evitar desbordamiento (overflow)

    while (x > 0) {
        //Formula
        reverso = (reverso * 10) + (x % 10); 
        x /= 10; // Eliminamos el último dígito de x
    }

    
    return original == reverso;
}

int main() {
    int numero = 121;

    if (isPalindrome(numero)) {
        printf("%d es un palíndromo.\n", numero);
    } else {
        printf("%d no es un palíndromo.\n", numero);
    }

    return 0;
}