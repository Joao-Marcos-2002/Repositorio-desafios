function bubbleSort(arr) {
    let n = arr.length;
    let swapped;

    do {
        swapped = false;
        for (let i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];  // Troca
                swapped = true;
            }
        }
        n--;  // A maior parte é colocada no final da lista após cada iteração
    } while (swapped);

    return arr;
}

const array = [64, 34, 25, 12, 22, 11, 90];
console.log(bubbleSort(array));  // Saída: [11, 12, 22, 25, 34, 64, 90]


// function selectionSort(arr) {
//     let n = arr.length;

//     for (let i = 0; i < n - 1; i++) {
//         let minIndex = i;
//         for (let j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         if (minIndex !== i) {
//             [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];  // Troca
//         }
//     }

//     return arr;
// }

// const array = [64, 25, 12, 22, 11];
// console.log(selectionSort(array));  // Saída: [11, 12, 22, 25, 64]


// function insertionSort(arr) {
//     let n = arr.length;
//     for (let i = 1; i < n; i++) {
//         let key = arr[i];
//         let j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
//     return arr;
// }

// const array = [12, 11, 13, 5, 6];
// console.log(insertionSort(array));  // Saída: [5, 6, 11, 12, 13]

// function mergeSort(arr) {
//     if (arr.length <= 1) {
//         return arr;
//     }

//     const middle = Math.floor(arr.length / 2);
//     const left = arr.slice(0, middle);
//     const right = arr.slice(middle);

//     return merge(mergeSort(left), mergeSort(right));
// }

// function merge(left, right) {
//     let result = [];
//     let leftIndex = 0;
//     let rightIndex = 0;

//     while (leftIndex < left.length && rightIndex < right.length) {
//         if (left[leftIndex] < right[rightIndex]) {
//             result.push(left[leftIndex]);
//             leftIndex++;
//         } else {
//             result.push(right[rightIndex]);
//             rightIndex++;
//         }
//     }

//     return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
// }

// const array = [38, 27, 43, 3, 9, 82, 10];
// console.log(mergeSort(array));  // Saída: [3, 9, 10, 27, 38, 43, 82]

// function quickSort(arr) {
//     if (arr.length <= 1) {
//         return arr;
//     }

//     const pivot = arr[arr.length - 1];
//     const left = [];
//     const right = [];

//     for (let i = 0; i < arr.length - 1; i++) {
//         if (arr[i] < pivot) {
//             left.push(arr[i]);
//         } else {
//             right.push(arr[i]);
//         }
//     }

//     return [...quickSort(left), pivot, ...quickSort(right)];
// }

// const array = [10, 7, 8, 9, 1, 5];
// console.log(quickSort(array));  // Saída: [1, 5, 7, 8, 9, 10]


// // Função principal que inicializa o array e chama a função de ordenação
// function main() {
//     const array = [10, 7, 8, 9, 1, 5];
//     console.log("Array original:", array);
    
//     const sortedArray = quickSort(array);
//     console.log("Array ordenado:", sortedArray);
// }

// // Função de ordenação Quick Sort
// function quickSort(arr) {
//     if (arr.length <= 1) {
//         return arr;
//     }

//     const pivot = arr[arr.length - 1];
//     const left = [];
//     const right = [];

//     for (let i = 0; i < arr.length - 1; i++) {
//         if (arr[i] < pivot) {
//             left.push(arr[i]);
//         } else {
//             right.push(arr[i]);
//         }
//     }

//     return [...quickSort(left), pivot, ...quickSort(right)];
// }

// // Chama a função principal
// main();

// // Função principal que inicializa o array e chama a função de ordenação
// function main() {
//     const array = [64, 34, 25, 12, 22, 11, 90];
//     console.log("Array original:", array);
    
//     bubbleSort(array);
//     console.log("Array ordenado:", array);
// }

// // Função de ordenação Bubble Sort
// function bubbleSort(arr) {
//     let n = arr.length;
//     let swapped;

//     do {
//         swapped = false;
//         for (let i = 0; i < n - 1; i++) {
//             if (arr[i] > arr[i + 1]) {
//                 [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];  // Troca
//                 swapped = true;
//             }
//         }
//         n--;  // A maior parte é colocada no final da lista após cada iteração
//     } while (swapped);

//     return arr;
// }

// // Chama a função principal
// main();