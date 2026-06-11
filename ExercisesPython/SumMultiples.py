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
#Solucion con fórmula de la suma de una progresión aritmética
#Solucion en O(1) en tiempo y espacio
def sumOfMultiples(n: int) -> int:
    def sum_divisible_by(target: int) -> int:
        # Número de términos divisibles por 'target' hasta n
        m = n // target
        # Fórmula de la suma aritmética: target * (1 + 2 + ... + m)
        return target * m * (m + 1) // 2

    # Principio de Inclusión-Exclusión
    print(
        sum_divisible_by(3) + sum_divisible_by(5) + sum_divisible_by(7)
        - sum_divisible_by(15) - sum_divisible_by(21) - sum_divisible_by(35)
        + sum_divisible_by(105)
    )
    return (
        sum_divisible_by(3) + sum_divisible_by(5) + sum_divisible_by(7)
        - sum_divisible_by(15) - sum_divisible_by(21) - sum_divisible_by(35)
        + sum_divisible_by(105)
    )
sumOfMultiples(7)
'''
Solucion Acotada con programacion funcional
Igual a la que hice pero en vez de contador con "sum"
'''
def sumOfMultiples2(n: int) -> int:
    return sum(x for x in range(1, n + 1) if x % 3 == 0 or x % 5 == 0 or x % 7 == 0)
