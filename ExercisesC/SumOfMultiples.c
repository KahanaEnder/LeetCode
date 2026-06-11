#include <stdio.h>

// Función auxiliar para calcular la suma de múltiplos usando la fórmula de la progresión aritmética
long long sum_divisible_by(long long n, long long target) {
    long long m = n / target;
    return target * m * (m + 1) / 2;
}

int sumOfMultiples(int n) {
    long long N = (long long)n; //Previene desbordamiento long long
    
    // Principio de Inclusión-Exclusión
    long long total_sum = 
        sum_divisible_by(N, 3) + sum_divisible_by(N, 5) + sum_divisible_by(N, 7)
        - sum_divisible_by(N, 15) - sum_divisible_by(N, 21) - sum_divisible_by(N, 35)
        + sum_divisible_by(N, 105);
        
    return (int)total_sum;
}

int main() {
    int n = 7;
    printf("Resultado para n = %d: %d\n", n, sumOfMultiples(n)); // Output: 21
    return 0;
}