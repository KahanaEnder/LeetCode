package Ejercicios;

public class AddDigits {
	
	public static int addDigits(int number) {
		if (number <= 0) {
			return 0;
		}
		if (number % 9 == 0) {
			return 9;
		}
		return number % 9;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int numero = 123;
		int numero2 = 1234;
		System.out.println(addDigits(numero));
		System.out.println(addDigits(numero2));
		

	}

}
