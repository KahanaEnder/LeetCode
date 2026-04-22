#include <stdio.h>
//Paso por referencia
int Sum(int *number, int *number2) {
    return *number + *number2;
}
//Paso por valor
int Sum2(int numero1,int numero2) {
    return numero1 + numero2;
}
int main() {
    int primera = 3;
    int segunda = 21;
    printf("%d\n",Sum(&primera,&segunda));
    printf("%d\n",Sum2(primera,segunda));
    return 0;
}