#include <stdio.h>

int AddDigits(int *number) {
    if (*number == 0)
    {
        return 0;
    }
    

    if (*number % 9 == 0)
    {
        return 9;
    }
    

    return *number % 9;
}

int main() {
    int number = 123;
    int resultado = AddDigits(&number);
    printf("%d\n", resultado);
    int number2 = 18;
    int resultado2 = AddDigits(&number2);
    printf("%d\n", resultado2);
    int number3 = 0;
    int resultado3 = AddDigits(&number3);
    printf("%d\n", resultado3);
    int number4 = 999;
    int resultado4 = AddDigits(&number4);
    printf("%d\n", resultado4);
}