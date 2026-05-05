class Nodo: #Lista enlazada doble
    def __init__(self, valor=0,siguiente=None,anterior=None):
            self.valor = valor
            self.siguiente = siguiente
            self.anterior = anterior
    def __str__(self):
        #redefine como mostrar un objeto como string
        return f"Nodo({self.valor})"
nodo1 = Nodo(10)
print(nodo1)