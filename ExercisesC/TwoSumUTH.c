#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"


struct my_struct {
    int id;            //valor
    int index;         //indice
    UT_hash_handle hh; //hasheable
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct my_struct *mapa = NULL; //tabla hash vacia
    int* result = malloc(2 * sizeof(int)); //Espacio de memoria para 2 ints como variables o array

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        
        struct my_struct *Nodo; //Nodo con par clave-valor
        
        HASH_FIND_INT(mapa, &complemento, Nodo);

        if (Nodo != NULL) {
            
            result[0] = Nodo->index;
            result[1] = i;
            *returnSize = 2;

            //Liberar la memoria de la tabla antes de return
            struct my_struct *current, *tmp;
            HASH_ITER(hh, mapa, current, tmp) {
                HASH_DEL(mapa, current);
                free(current);
            }
            return result;
        }

        //Si no existe se agrega
        Nodo = malloc(sizeof(struct my_struct));
        Nodo->id = nums[i];
        Nodo->index = i;
        HASH_ADD_INT(mapa, id, Nodo);
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