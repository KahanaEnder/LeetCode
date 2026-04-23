package Ejercicios;

public class PalindromeNumber {
	
	public static boolean isPalindrome(int numero) {
		String cadena = Integer.toString(numero);
		int i = 0;
		int longitud = cadena.length();
		int condicion = longitud / 2;
		while (i < condicion) {
			if (cadena.charAt(i) != cadena.charAt(longitud - 1 - i)) {
				return false;
			}
			i++;
		}
		return true;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(isPalindrome(4331334));

	}

}
