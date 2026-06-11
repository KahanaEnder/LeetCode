package Ejercicios;

public class SumMultiple {
	public static void main(String[] args) {
		sumMultiple(7);
	}
	public static int sumMultiple(int n) {
		int contador = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
				contador+=i;
			}
		}
		System.out.println(contador);
		return contador;
	}
}
