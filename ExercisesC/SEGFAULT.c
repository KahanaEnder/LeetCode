#include <stdio.h>
//Core dumped
int main() {
    int *puntero = NULL;
    
    printf("Intentando escribir en NULL...\n");
    
    // Aquí ocurre el Segmentation Fault
    *puntero = 42; 
    //Intentado escribir en 0x0 memoria restringida
    return 0;
}
#include <stdio.h>

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};
    
    // Accedemos a la posición 10,000. 
    // Esa dirección no pertenece a nuestro arreglo.
    //Fuera de limites de la memoria definida
    numeros[10000] = 999; 
    //Violación de segmento (`core' generado) buserror
    return 0;
}