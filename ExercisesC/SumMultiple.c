#include <stdio.h>
int sumMultiple(int n) {
    int contador; //Depende del compilador puede dar error si no inicializa en 0 por defecto
    for (int i = 1; i <= n; i++ ) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            contador+=i;
        }
    }
    printf("%d\n",contador);
    return contador;
}
int main() {
    sumMultiple(7);
    return 0;
}