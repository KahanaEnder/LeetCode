class Solution:
    def isPalindrome(self,x):
        cadena =str(x)
        i = 0
        puntero = len(cadena)
        while(i < puntero // 2):
            if (cadena[i] != cadena[puntero - 1 - i]):
                return False
            i += 1
        return True
    
    def isPalindrome2(self,x):
        cadena = str(x)
        return cadena == cadena[::-1]
if __name__ == "__main__":
    instancia = Solution()
    print(instancia.isPalindrome(4334))
    print(instancia.isPalindrome2(4223))

