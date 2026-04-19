"""Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring."""
def lengthofLongestSubstring(s: str) -> int:
    char_map = {} 
    longest = 0 
    inicio = 0 #puntero inicio

    for fin in range(len(s)): #puntero fin
        charActual = s[fin]

        #Usamos ventana deslizante con 2 punteros y comprobamos, añadimos y actualizamos posicion con hashmap
        if charActual in char_map and char_map[charActual] >= inicio:
            # Movemos el inicio de la ventana deslizante
            inicio = char_map[charActual] + 1
        
        #Agregamos al hashmap y si se repite se actualiza la posicion
        char_map[charActual] = fin
        
        # Calculamos la distancia de la ventana actual y comparamos con el anterior
        longest = max(longest, fin - inicio + 1)

    return longest

texto = "abcabd"
#print(f"La longitud máxima es: {lengthofLongestSubstring(texto)}")
#Mejor solucion
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        izquierda = -1 #puntero izquierda
        maximo = 0

        for derecha in range(len(s)): #puntero derecha
            ultimo = last_seen.get(s[derecha]) #ultimo es igual a la letra en el puntero de la derecha si esta en el hash
            if ultimo != None and izquierda < ultimo: #si no ultimo es None
                izquierda = ultimo
            last_seen[s[derecha]] = derecha #asignamos las letras al hashmap

            maximo = max(maximo, derecha - izquierda) #calculo de distancia de caracteres no repetidos
            #retorna el maximo entre el anterior maximo o el calculo de la distancia en la ventana deslizante
        return maximo 
s = Solution()
resultado = s.lengthOfLongestSubstring(texto)
print(resultado)