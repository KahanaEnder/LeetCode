package Ejercicios;

public class MedianTwoSortedArrays {
	public static void main(String[] args) {
		Solution solucion = new Solution(); //Instanciamos la solucion
		int[] nums1 = {1,2,4,5,7,8,9};
		int[] nums2 = {1,2,4,5,6,7,8,8,8,9}; //Inicializar Arrays
		System.out.println(solucion.findMedianSortedArrays(nums1,nums2));
	}
}
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Aseguramos que nums1 sea el array más corto para optimizar la búsqueda binaria
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length;
        int n = nums2.length;
        int low = 0, high = m;

        while (low <= high) { //Busqueda binaria
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX; //Se ajusta automaticamente basado en la primera

            // Si partitionX es 0, no hay elementos a la izquierda en nums1. Usamos -Infinito
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : nums1[partitionX - 1];
            // Si partitionX es m, no hay elementos a la derecha en nums1. Usamos +Infinito
            int minRightX = (partitionX == m) ? Integer.MAX_VALUE : nums1[partitionX];
            //Repetimos para Y
            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? Integer.MAX_VALUE : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Hemos encontrado la partición correcta
                if ((m + n) % 2 == 0) {
                    return ((double)Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
                } else {
                    return (double)Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Estamos muy a la derecha en nums1, nos movemos a la izquierda
                high = partitionX - 1;
            } else {
                // Estamos muy a la izquierda en nums1, nos movemos a la derecha
                low = partitionX + 1;
            }
        }

        throw new IllegalArgumentException("Los arrays de entrada no están ordenados.");
    }
}
