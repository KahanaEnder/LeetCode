#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Siempre realizamos la búsqueda binaria en el array más pequeño
    if (nums1Size > nums2Size) { //Intercambia parametros si es necesario despues no vuelve a entrar
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) { //Busqueda binaria
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX; //Ajustamos para que corresponda con la primera

        // Si la partición está en los extremos, usamos valores infinitos
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        //Los infinitos sirven para que cualquier numero a la derecha de -INF sea mayor
        //y cualquier numero a la izquierda de +INF sea menor
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Partición correcta encontrada
            if ((m + n) % 2 == 0) {
                return (double)(MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
            } else {
                return (double)MAX(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            // Demasiado a la derecha en nums1
            high = partitionX - 1;
        } else {
            // Demasiado a la izquierda en nums1
            low = partitionX + 1;
        }
    }

    return 0.0; // Caso por defecto
}