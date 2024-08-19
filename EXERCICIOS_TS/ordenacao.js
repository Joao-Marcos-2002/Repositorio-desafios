
// function ordenacaoPadrao() {
//     let arr = [];
//     arr.push(33, 3, 2, 99, 0, 42, 1, 22, 1, 9);
//     arr.sort();
//     console.log(arr);
// }



function bubbleSort(arr) {

    let num = arr.length;
    let trocado = true; 

    while(trocado) {
        trocado = false;
        for(let i = 0; i < num; i++) {
            if(arr[i] > arr[1 + i]) {
                // troca os elementos se for maior que o elemento da frente.
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
                trocado = true;
            }
        }
        num--; //diminui o array na proxima iteracao.
    }
    return arr;

}



function main() {
 
    const arr = [38, 27, 11, 3, 9, 80, 15, 100];
    console.log("array padrao:", arr);

    const arrOrdenado = bubbleSort(arr);
    console.log("Ordenado:", arrOrdenado);

}

main();
