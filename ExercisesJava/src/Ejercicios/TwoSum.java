package Ejercicios;

public class TwoSum {
	
	public static int[] ejercicioN2(int[] numbers,int target) {
		for (int i = 0; i < numbers.length; i++) {
			for (int j = i+1; j < numbers.length; j++) {
				if (numbers[i] + numbers[j] == target) {
					int[] result = {i,j};
					for (int k = 0; k < result.length; k++) {
						System.out.println(result[k]);
					}
					return result;
				}
			}
		}
		return new int[] {};
	}


	public static void main(String[] args) {
		//Respuesta en N^2
		int[] numbers = {2,7,11,9};
		int  target = 9;
		//ejercicioN2(numbers, target);
		int[] nums = {3,2,4};
		int target2 = 6;
		//ejercicioN2(nums, target2);
		int[] numeros = {3,3};
		int target3 = 6;
		//ejercicioN2(numeros, target3);
		
	}

}
