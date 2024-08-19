import promptSync from 'prompt-sync';



function somaVar(a: any, b : any) : void {
   
    let somaS: number = a+b;
    let resultado = "X = " + somaS + "\n";

    console.log(resultado);
   
    
}




function main(): void {
    //teste
    // somaVar(9, 4);

    // const prompt = promptSync();
    const prompt = require('prompt-sync')();

    let prim = parseInt(prompt('Digite o primeiro numero: '));
    let sec = parseInt(prompt('Digite o segundo numero: '));

    somaVar(prim, sec);

    // console.log(`Você digitou: ${input}`);
}

main();





// // RESULTADO DA IA:

// // import * as readline from 'readline';

// // const rl = readline.createInterface({
// //     input: process.stdin,
// //     output: process.stdout
// // });

// // function somaVar(a: number, b: number): void {
// //     let somaS: number = a + b;
// //     let resultado = "X = " + somaS + "\n";
// //     console.log(resultado);
// // }

// // function main(): void {
// //     rl.question('Digite o primeiro número: ', (prim) => {
// //         rl.question('Digite o segundo número: ', (sec) => {
// //             let num1 = parseFloat(prim);
// //             let num2 = parseFloat(sec);
// //             somaVar(num1, num2);
// //             rl.close();
// //         });
// //     });
// // }

// // main();
