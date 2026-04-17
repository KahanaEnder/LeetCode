class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val   #Lista enlazada simple, valor inicializado en 0
        self.next = next #Siguiente nodo, inicializado en NULL (None)

class Solution:
    def addTwoNumbers(self, l1, l2):
        ListaInicial = ListNode() #Empieza en 0 y luego al llamar a .next se retira y queda la solucion
        actual = ListaInicial
        LlevaUnidades = 0 #Contador de cuantas unidades, decenas, centenas... lleva al sumar
        
        while l1 or l2 or LlevaUnidades: #Mientras las listas sean verdaderas o sea existan != None o no sea While(0) y para evitar que falten sumas
            if (l1):
                valor1 = l1.val
            else:
                valor1 = 0
            if (l2):
                valor2 = l2.val
            else:
                valor2 = 0

            SumaTotal = valor1 + valor2 + LlevaUnidades
            LlevaUnidades = SumaTotal // 10 #Si es un digito de 2 cifras se acarrea a la siguiente suma el digito resultante
            actual.next = ListNode(SumaTotal % 10) #Se crea el siguiente nodo con la suma  o el residuo de 10

            actual = actual.next #Se pasa al siguiente nodo
            #Si siguen existiendo nodos con valores != None se pasa al siguiente
            if (l1):
                l1 = l1.next
            if (l2):        
                l2 = l2.next
            
        return ListaInicial.next #Se devuelve el resultado y el .next quita el 0 inicial de ListNode()

def imprimir_lista(nodo):
    elementos = []
    while nodo: #Mientras hayan nodos con valores
        elementos.append(str(nodo.val)) #Agregar al array en valor como string
        nodo = nodo.next #Se recorre la lista
    print(" -> ".join(elementos)) #Se imprime 2->4->3
    return " -> ".join(elementos)

if __name__ == "__main__":
    #342
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    #465
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    
    print("Lista 1: ", end="")
    imprimir_lista(l1)
    
    print("Lista 2: ", end="")
    imprimir_lista(l2)
    
    #Instanciamos
    sol = Solution()
    resultado = sol.addTwoNumbers(l1, l2)
    
    print("Resultado: ", end="")
    cadena =imprimir_lista(resultado) # Debería imprimir 7 -> 0 -> 8 (807)
    print("[" + cadena + "]")