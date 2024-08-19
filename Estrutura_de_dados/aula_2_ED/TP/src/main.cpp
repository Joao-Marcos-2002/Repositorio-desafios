#include <iostream>
using namespace std;


//Fatorial iterativo.
int fatorialIter(int n) {
    int i=1, fat = 1;

    while(i <= n) {
        fat = fat * i;
        i++;
    }
    return fat;
}

// Fatorial recursivo.
int fatorialRec(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * fatorialRec(n - 1);
    }
};

//Fibonacci recursivo.
int fibonacciRec(int n) {
    if(n < 3) {
        return 1;
    } else {
        return fibonacciRec(n - 1) + fibonacciRec(n-2);
    }
}

//Fibonacci iterativo.
void fibonacciIter() {
    int n, i=3, temp, ult=1, penult=1;

    cout << "Faixa de valores: 1 a 46" << endl;
    cout << "Quantos termos da sequencia: ";
    cin >> n;

    cout << penult << endl << ult << endl;

    while (i <= n) {
        //Exibir os termos:
        penult = ult;
        cout << (ult+penult) << endl;
        temp = penult;
        ult = ult + temp;

        i++;
    }
}

int main() {
    int n, num, op;
    cout << "Qual tarefa a ser utilizada 1 para fatorial ou 2 para fibonacci" << endl;
    cin >> n;

    if(n == 1) {
        cout << "Qual a versao a selecionar (digite 1 para iterativa ou 2 para recursiva)" << endl;
        cin >> op;

        cout << "Fatorial de: " << endl;
        cin >> num;

        if(op == 1) { 
            cout << "O fatorial eh: " << fatorialRec(num) << endl;
        } else if(op == 2) {
            cout << "O fatorial eh: " << fatorialIter(num) << endl;
        }

    } else if (n == 2) {
        cout << "Qual a versao a selecionar (digite 1 para iterativa ou 2 para recursiva)" << endl;
        cin >> op;

        if(op == 1) {
            fibonacciIter();
        } else if(op == 2) {
            cout << "Faixa de valores: 1 a 46" << endl;
            int n;
            cin >> n;

            cout << "A sequência de Fibonacci até o " << n << "º termo é: ";
            for (int i = 1; i <= n; ++i) {
                cout << fibonacciRec(i) << " ";
            }    
        }
    }
}


