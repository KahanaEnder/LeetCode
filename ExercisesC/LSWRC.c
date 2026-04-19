#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char *s) {
    // Usamos un arreglo para simular el hashmap last_seen
    // El índice es el valor ASCII del carácter
    int last_seen[256];
    
    // Inicializamos todo con -1 equivalente a NULL pero para primitivos
    for (int i = 0; i < 256; i++) {
        last_seen[i] = -1;
    }

    int izquierda = -1;
    int maximo = 0;
    int n = strlen(s);

    for (int derecha = 0; derecha < n; derecha++) {
        // Convertimos el carácter a su valor numérico (0-255)
        unsigned char actual = s[derecha];
        
        int ultimo = last_seen[actual];

        // Si ya lo vimos y está dentro de nuestra ventana actual
        if (ultimo != -1 && izquierda < ultimo) {
            izquierda = ultimo;
        }

        // Actualizamos la última posición vista
        last_seen[actual] = derecha;

        // Calculamos la distancia y actualizamos el máximo
        maximo = MAX(maximo, derecha - izquierda);
    }

    return maximo;
}

int main() {
    char *texto = "abcabcbb";
    printf("La longitud máxima es: %d\n", lengthOfLongestSubstring(texto));
    return 0;
}