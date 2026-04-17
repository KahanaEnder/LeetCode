#include <stdio.h>
#include <stdlib.h>

// Definimos el tamaño de nuestra tabla (un número primo suele ser mejor)
#define HASH_SIZE 10007

struct Node {
    int valor;
    int indice;
    struct Node* siguiente; // Para manejar colisiones (Lista enlazada)
};

struct HashTable {
    struct Node* baldes[HASH_SIZE]; //Array de punteros de tamaño 10007 -> baldes o sea buckets
};
// Función hash con modulo del tamaño, si es negativo le suma el tamaño si no lo deja tal cual
int hash(int clave) {
    int idx = clave % HASH_SIZE;
    return (idx < 0) ? idx + HASH_SIZE : idx; 
}


void insertar(struct HashTable* tabla, int valor, int indice) {
    int h = hash(valor);
    struct Node* nuevo = malloc(sizeof(struct Node));
    nuevo->valor = valor;
    nuevo->indice = indice;
    nuevo->siguiente = tabla->baldes[h];
    tabla->baldes[h] = nuevo;
}


int buscar(struct HashTable* tabla, int valor) {
    int h = hash(valor);
    struct Node* actual = tabla->baldes[h];
    while (actual != NULL) {
        if (actual->valor == valor) return actual->indice;
        actual = actual->siguiente;
    }
    return -1; // No encontrado
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct HashTable* tabla = calloc(1, sizeof(struct HashTable));
    int* resultado = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        int indiceEncontrado = buscar(tabla, complemento);

        if (indiceEncontrado != -1) {
            resultado[0] = indiceEncontrado;
            resultado[1] = i;
            *returnSize = 2;
            return resultado;
        }
        insertar(tabla, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[] = {2,7,11,9};
    int target = 9;
    int size = 4;
    int returnSize;

    int *res = twoSum(nums,size,target,&returnSize);
    if (res != NULL) {
        printf("[%d, %d]\n",res[0],res[1]);
        free(res);
    }
    return 0;
}