def findMedianSortedArrays(nums1, nums2):
    merge = []
    longitud = max(len(nums1),len(nums2))
    #Encuentra la media pero el array resultante no necesariamente esta organizado
    for i in range(longitud):
        try:
            if nums1[i] > nums2[i]:
                merge.append(nums2[i])
                merge.append(nums1[i])
            else:
                merge.append(nums1[i])
                merge.append(nums2[i])
        except IndexError:
            # Si entramos aquí, es porque nums1[i] o nums2[i] no existe
            try:
                # Intentamos ver si el elemento que existe es el de nums1
                merge.append(nums1[i])
            except IndexError:
                # Si nums1 también falló, por descarte el elemento está en nums2
                merge.append(nums2[i])
    longitud2 = len(merge)
    print(merge)
    if longitud2 % 2 == 0:
        return (merge[(longitud2 // 2) - 1] + merge[(longitud2 // 2)]) / 2
    else:
        return merge[longitud2 // 2]

class Solution:
    def findMedianSortedArrays(self,nums1, nums2):
        merge = []
        # Usamos i para nums1 y j para nums2
        i = 0
        j = 0
        # El bucle corre hasta que hayamos agotado ambas listas
        total_elementos = len(nums1) + len(nums2)
        
        for _ in range(total_elementos):
            try:
                # Intentamos comparar los elementos en las posiciones actuales
                if nums1[i] < nums2[j]:
                    merge.append(nums1[i])
                    i += 1  # Solo avanzamos en la lista 1
                else:
                    merge.append(nums2[j])
                    j += 1  # Solo avanzamos en la lista 2
            except IndexError:
                # Si entramos aquí, una de las dos listas se terminó
                try:
                    merge.append(nums1[i])
                    i += 1
                except IndexError:
                    # Si nums1 falló, el que queda es de nums2
                    merge.append(nums2[j])
                    j += 1

        longitud2 = len(merge)
        print(merge)
        if longitud2 % 2 == 0:
            return (merge[longitud2 // 2 - 1] + merge[longitud2 // 2]) / 2
        else:
            return merge[longitud2 // 2]

class Solution2:
    def findMedianSortedArrays(self,nums1, nums2): #Tercer Approach 
        primerPuntero = segundoPuntero = 0 #Punteros

        longitudArray1,longitudArray2 = len(nums1),len(nums2) #Longitudes

        total = longitudArray2 + longitudArray1
        previo = actual = 0
        for bucle in range(total // 2 + 1): #O(m+n)
            previo = actual
            if primerPuntero < longitudArray1 and (segundoPuntero >= longitudArray2 or nums1[primerPuntero] <= nums2[segundoPuntero]): #Avanzamos hasta la mediana y guardamos el numero actual y el previo
                actual = nums1[primerPuntero]
                primerPuntero += 1
            else:
                actual = nums2[segundoPuntero]
                segundoPuntero += 1
        #Memoria O(1)
        if total % 2 == 1:
            return actual
        return (previo + actual) / 2
        

if __name__ == "__main__":
    nums1 = [3,6,9]
    nums2 = [1,2,4,7,10]
    print(findMedianSortedArrays(nums1, nums2))
    s = Solution()
    print(s.findMedianSortedArrays(nums1,nums2))
    s = Solution2()
    print(s.findMedianSortedArrays(nums1,nums2))