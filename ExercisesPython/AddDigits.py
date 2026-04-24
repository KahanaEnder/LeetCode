class Solution:
    def addDigits(self, num: int) -> int: #Solución con Keinner
        if num <= 0:
            return 0
        if num < 10:
            return num
        else:
            while num % 10 != num:
                ultimo_digito = num%10
                num-=ultimo_digito
                num//=10
                num = num + ultimo_digito
                if num % 10 == num:
                    return num
                else:
                    continue
class SolutionO1:
    def AddDigits(self,num:int) ->int:
        if num <= 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9

if __name__ == "__main__":
    instancia = Solution()
    print(instancia.addDigits(123))
    solucion = SolutionO1()
    print(solucion.AddDigits(1234))