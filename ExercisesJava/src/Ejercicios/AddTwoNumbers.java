package Ejercicios;

public class AddTwoNumbers {
	@SuppressWarnings("all")
	public static ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
		ListNode ListaInicial = new ListNode(); //Inicializa en 0
		ListNode ListaActual = ListaInicial;
		int carry = 0;
		
		while (l1 != null || l2 != null || carry != 0) {
			int valor1 = (l1 != null) ? l1.val : 0;
			int valor2 = (l2 != null) ? l2.val : 0; //Diferente sintaxis
			int suma_total = valor1 + valor2 + carry;
			carry = suma_total / 10;
			ListaActual.next = new ListNode(suma_total % 10);
			ListaActual = ListaActual.next;
			if (l1 != null) {
				l1 = l1.next;
			}
			if (l2 != null) {
				l2 = l2.next;
			}
		}
		return  ListaInicial.next;
	}
}
//Lista enlazada simple con sus constructores
class ListNode {
	int val;
	ListNode next;
	
	ListNode() {} //int inicializa en 0 por defecto y next en null
	
	ListNode(int val) {
		this.val = val;
	}
	ListNode(int val,ListNode next) {
		this.val = val;
		this.next = next;
	}
	
	
}
