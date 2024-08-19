from typing import List


#  MELHOR solucao:

#  HashMap Solution O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        newMap = {} #dicionario para add valores e indices
        for index, value in enumerate(nums):  
            print(f"Index: {index}, Value: {value}")
            difference = target - nums[index] #calcula a diferenca em relacao ao target

            # Procura a diferenca no Map.
            if(difference in newMap):
                return [newMap[difference], index]
            
            # Armazena o indice e valor atual no dicionario.
            newMap[nums[index]]=index
        




# Exemplo de uso:
solution = Solution()
solution.twoSum([2, 7, 11, 15], 9)
