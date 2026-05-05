#include <stdlib.h>
#include <stdio.h>
struct Nodo //Lista enlazada doble
{
    int valor; //Valor del nodo
    struct Nodo *siguiente; //Al comentar en la declaracion de variables o objetos, el comentario se convierte en la descripcion del atributo o instancia como este
    struct Nodo *anterior;
};
int main(int argc, char const *argv[])
{
    struct Nodo *nodo1 = malloc(sizeof(struct Nodo)); //Creado en heap memoria dinamica
    struct Nodo nodo2 = {20,NULL,NULL}; //Creado en pila/stack muere al acabar la funcion
    nodo1 -> valor = 10; //Si se inicializa una struct por defecto todo es 0
    nodo1 -> siguiente = NULL; //Evitamos basura
    nodo1 -> anterior = NULL; //Evitamos posible segmentation fault
    printf("%d\n",nodo1->valor); //Obtenemos valor con puntero no con nodo1.valor
    printf("%d\n",nodo2.valor); //Tamaño fijo por compilador, ambito local mejor usar si sé cuantos nodos son
    printf("%p\n",nodo2.siguiente); //(nil)(nihil/nada) NULL == 0 o 0x0 direccion restringida que inmediatamente causa segmentation fault
    printf("%p\n",nodo2.anterior);
    free(nodo1);//Liberamos la memoria dinamica
    return 0;
}

