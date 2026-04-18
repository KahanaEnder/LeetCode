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
    inicio = 0

    for fin in range(len(s)):
        charActual = s[fin]

        # Si el carácter ya existe en la ventana actual
        if charActual in char_map and char_map[charActual] >= inicio:
            # Movemos el inicio de la ventana
            inicio = char_map[charActual] + 1
        
        # Actualizamos la posición del carácter
        char_map[charActual] = fin
        
        # Calculamos la distancia de la ventana actual y comparamos
        longest = max(longest, fin - inicio + 1)

    return longest

texto = "abcabd"
print(f"La longitud máxima es: {lengthofLongestSubstring(texto)}")