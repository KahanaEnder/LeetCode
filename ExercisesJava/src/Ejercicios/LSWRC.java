package Ejercicios;
import java.util.HashMap;
import java.util.Map;

public class LSWRC {
	public static int lengthOfLongestSubstring(String texto) {
		Map<Character,Integer>  hashmap = new HashMap<Character, Integer>();		
		int maximo = 0;
		int izquierdo = -1;
		Integer ultimo;
		
		for (int derecho = 0; derecho < texto.length(); derecho++) {
			
			char caracter = texto.charAt(derecho);
			ultimo = hashmap.get(caracter);
			
			if (ultimo != null && izquierdo < ultimo) {
				izquierdo = ultimo;
			}
			
			hashmap.put(caracter, derecho);
			maximo = Math.max(maximo, derecho - izquierdo); 
		}
		return maximo;
	}
	public static void main(String[] args) {
		int resultado = lengthOfLongestSubstring("qwertyy");
		System.out.println(resultado);
	}
}
