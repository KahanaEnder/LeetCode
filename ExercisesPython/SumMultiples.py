class Solution:
    def sumOfMultiples(self, n: int) -> int:
        contador = 0
        for i in range(1,n+1):
            if (i % 3 == 0) or (i % 5 == 0) or (i % 7 == 0):
                contador += i
        print(contador)
        return contador
Solucion = Solution()
Solucion.sumOfMultiples(7)