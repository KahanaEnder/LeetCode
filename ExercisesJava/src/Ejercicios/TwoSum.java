package Ejercicios;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

public class TwoSum {
	
	public static int[] ejercicioN2(int[] numbers,int target) {
		for (int i = 0; i < numbers.length; i++) {
			for (int j = i+1; j < numbers.length; j++) {
				if (numbers[i] + numbers[j] == target) {
					int[] result = {i,j};
					return result;
				}
			}
		}
		return new int[] {};
	}
	
	public static int[] ejercicioHash(int[] nums,int target) {
		Map<Integer, Integer> hashmap = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			int complemento = target - nums[i];
			if (hashmap.containsKey(complemento)) {
				int indice_anterior = hashmap.get(complemento);
				return new int [] {indice_anterior, i};
			}
			hashmap.put(nums[i],i);
		}
		
		
		return new int[] {};
	}


	public static void main(String[] args) {
		//Respuesta en N^2
		int[] numbers = {2,7,11,9};
		int  target = 9;
		int[] primero = ejercicioN2(numbers, target);
		System.out.println(Arrays.toString(primero));
		int[] nums = {3,2,4};
		int target2 = 6;
		int[] segundo = ejercicioN2(nums, target2);
		System.out.println(Arrays.toString(segundo));
		int[] numeros = {3,3};
		int target3 = 6;
		int [] tercero = ejercicioN2(numeros, target3);
		System.out.println(Arrays.toString(tercero));
		
		//Respuesta con Hash
		
		int[] resultado = ejercicioHash(numeros, target3);
		System.out.println(Arrays.toString(resultado));
		
		
	}

}
