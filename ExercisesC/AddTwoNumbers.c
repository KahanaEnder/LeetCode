#include <stdio.h>
#include <stdlib.h>

struct ListNode //Lista enlazada simple
{
    int val;
    struct ListNode* next;
};
struct ListNode* AddTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ListaInicial = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListaInicial->val = 0;
    ListaInicial->next = NULL;

    struct ListNode* ListaActual = ListaInicial;
    int Lleva = 0;

    while (l1 != NULL || l2 != NULL || Lleva != 0)
    {
        int valor1 = 0;
        int valor2 = 0;
        if (l1 != NULL)
        {
            valor1 = l1->val;
            l1 = l1->next; //Avanzamos de una vez en la lista
        }
        else {
            valor1 = 0;
        }
        if (l2 != NULL)
        {
            valor2 = l2->val;
            l2 = l2->next;
        }
        else {
            valor2 = 0;
        }
        int total = valor1 + valor2 + Lleva;
        Lleva = total / 10;
        int digito = total % 10;
        struct ListNode* nuevoNodo = (struct ListNode*)malloc(sizeof(struct ListNode));
        nuevoNodo->val = digito;
        nuevoNodo->next = NULL;
        ListaActual->next = nuevoNodo;
        ListaActual = ListaActual->next;
    }
    return ListaInicial->next;
}
void imprimir(struct ListNode* nodo) {
    while (nodo != NULL) {
        printf("%d\n",nodo->val);
        nodo = nodo->next;
    }
}
struct ListNode* crearNodo(int valor) {
    struct ListNode* nuevo = (struct ListNode*)malloc(sizeof(struct ListNode));
    nuevo->val = valor;
    nuevo->next = NULL; // Siempre inicializa a NULL por seguridad
    return nuevo;
}
void insertarAlInicio(struct ListNode** cabeza, int valor) {
    struct ListNode* nuevo = crearNodo(valor);
    nuevo->next = *cabeza;
    *cabeza = nuevo;
}
int main(int argc, char const *argv[])
{
    struct ListNode *nodo1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    nodo1->val = 3;
    struct ListNode *nodo2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    nodo1->next = nodo2;
    nodo2->val = 4;
    printf("Primera manera\n");
    imprimir(nodo1);
    struct ListNode *cabeza = crearNodo(5);
    cabeza->next = crearNodo(29);
    cabeza->next = crearNodo(12);
    printf("Segunda manera\n");
    imprimir(cabeza);
    struct ListNode* insertarReversa = NULL;
    insertarAlInicio(&insertarReversa,10);
    insertarAlInicio(&insertarReversa,20);
    insertarAlInicio(&insertarReversa,30);
    insertarAlInicio(&insertarReversa,40);
    insertarAlInicio(&insertarReversa,50);
    insertarAlInicio(&insertarReversa,60);
    insertarAlInicio(&insertarReversa,70);
    insertarAlInicio(&insertarReversa,80);
    printf("Tercera manera\n");
    imprimir(insertarReversa);
    return 0;
}


