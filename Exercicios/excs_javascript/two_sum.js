/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

// BruteForce Solution (O(n²))
var twoSum = function(nums, target) {
    for (i=0; i < nums.length; i++) {
        for (k=0; k < nums.length; k++) {

            /* Compares the sum two by two in different positions
            of the same list. */

            if(nums[i] + nums[k] == target && i != k) {
                return [i, k]
            }
        }
    }
};



// MELHOR solucao:

// HashMap Solution O(n)

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const newMap = {} // objeto para armazenar os numeros e sua posicao

    for (let i = 0; i < nums.length; i++) {
    	const difference = target - nums[i] //o complemento que falta para chegar ao 'target' passado
    
    	if (difference in newMap) return [i, newMap[difference]]

        // Armazena o numero atual e sua posicao
    	newMap[nums[i]] = i
    }
};
