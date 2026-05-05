package Ejercicios;

public class LinkedLista {
	public static void main(String[] args) {
		Nodo nodo1 = new Nodo(10);
		Nodo nodo2 = new Nodo(23,nodo1);
		System.out.println(nodo1.getValor());
		System.out.println(nodo2.getValor());
		System.out.println(nodo2.getSiguiente());
	}
}

class Nodo {
    private int valor;
    private Nodo siguiente;
    private Nodo anterior;

    // Constructor base
    public Nodo(int valor) {
        this.valor = valor;
        this.siguiente = null;
        this.anterior = null;
    }

    // Constructor con siguiente (usa el constructor anterior para evitar repetir código)
    public Nodo(int valor, Nodo siguiente) {
        this(valor); 
        this.siguiente = siguiente;
    }

    // Constructor completo
    public Nodo(int valor, Nodo siguiente, Nodo anterior) {
        this(valor, siguiente);
        this.anterior = anterior;
    }

    // Getters y Setters
    public int getValor() { return valor; }
    public void setValor(int valor) { this.valor = valor; }
    
    public Nodo getSiguiente() { return siguiente; }
    public void setSiguiente(Nodo siguiente) { this.siguiente = siguiente; }
    
    public Nodo getAnterior() { return anterior; }
    public void setAnterior(Nodo anterior) { this.anterior = anterior; }
}