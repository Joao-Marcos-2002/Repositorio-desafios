// function isValid(s: string): boolean {
//     // cria um array vazio para armazenar os brackets de abertura (pilha).
//     const stack: string[] = [];
//     const matchingBrackets: { [key: string]: string } = {
//         ')': '(',
//         '}': '{',
//         ']': '['
//     };
//     for (let char of s) {
//         // Verifica se o caractere é uma chave no objeto: bracket de fechamento.
//         if(char in matchingBrackets) {
//             // verifica se o elemento está no topo da pilha.
//             const elementoAcima = stack.length > 0 ? stack.pop() : '#';
//             // Verifica se o elemento do topo eh  o correspondente de abertura esperado.
//             if(elementoAcima != matchingBrackets[char]) {
//                 return false;
//             }
//         } else {
//             // adiciona o colhete encontrado da string na pilha
//             stack.push(char)
//         }
//     }
//      // Verifica se a pilha está vazia ao final
//     return stack.length === 0;
// }
// console.log(isValid('({})'));
function isValid(s) {
    var stack = [];
    var matchingBrackets = {
        ')': '(',
        '}': '{',
        ']': '['
    };
    s.split('').forEach(function (char) {
        if (char in matchingBrackets) {
            var elementoAcima = stack.length > 0 ? stack.pop() : '#';
            if (elementoAcima != matchingBrackets[char]) {
                return false;
            }
        }
        else {
            stack.push(char);
        }
    });
    return stack.length === 0;
}
console.log(isValid('({}})'));
