
//Recursiva::

function fibonacci(n) {
    if(n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n - 2);
}


console.log("fib recursiva::", fibonacci(10));


// Iterativa::

function fibonacciIterativa(n) {
    if(n <= 1) return n;
    
    let a1=0; let a2 = 1;
    for (let i = 2; i <= n; i++) {
        let k = a1 + a2;
        a1 = a2;
        a2 = k;
    }
    return a2;
}


console.log("iterativa", fibonacciIterativa(10));

