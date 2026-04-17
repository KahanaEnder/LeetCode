"""Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]"""
#nums = [2,7,11,15]
#target = 9
#nums = [3,2,4]
#target = 6
nums = [3,3]
target = 6
#Respuesta en N^2
def TwoSum(nums,target):
    output = []
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if (nums[i] + nums[j]) == target:
                output.append(i)
                output.append(j)
                print(output)
                return output
    return output
#TwoSum(nums,target)

#Respuesta con Hash

def TwoSumHash(nums,target):
    hashmap = {}
    for i in range(len(nums)):
        complemento = target - nums[i]

        if (complemento in hashmap):
            indice_anterior = hashmap[complemento]
            resultado = [indice_anterior,i]
            print(resultado)
            return resultado
        hashmap[nums[i]] = i
    print([])
    return []
TwoSum(nums,target)

