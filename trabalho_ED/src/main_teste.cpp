// #include <iostream>
// #include "../include/segtree.hpp"

// using namespace std;


// int main()
// {
//     srand(time(NULL));
//     struct timespec Time_Clock_Begin, Time_Clock_End;

//     // Entrada de dados
//     int n, q;
//     cin >> n >> q;

//     Segtree arvore(n);

//     arvore.build(1, 0, n - 1);
//     Matriz result = Matriz{1, 0, 0, 1};
//     for (int i = 0; i < q; i++)
//     {
//         //Seleciona o metodo.
//         char metodo;
//         cin >> metodo;

//         if (metodo == 'u')
//         {
//             // update
//             int i;
//             cin >> i; 
//             Matriz x(0, 0);

//             // Ler os elementos da matriz x
//             cin >> x.m[0][0] >> x.m[0][1] >> x.m[1][0] >> x.m[1][1];

//             arvore.update(i, x, 1, 0, n - 1);
//         }
//         else if (metodo == 'q')
//         {
//             // consulta
//             int l, r, x, y;

//             cin >> l >> r >> x >> y;

//             auto result = arvore.query(l, r, 1, 0, n - 1);
//             Matriz segunda(x, y);

//     clock_gettime(CLOCK_MONOTONIC, &(Time_Clock_Begin));
//     Matriz resultadoFinal = resultadoFinal.multMatriz(result, segunda);
//     clock_gettime(CLOCK_MONOTONIC, &(Time_Clock_End));
//     double tempoDecorrido = (Time_Clock_End.tv_sec - Time_Clock_Begin.tv_sec) +
//     (Time_Clock_End.tv_nsec - Time_Clock_Begin.tv_nsec) / 1e9;

//     cout << "tempo decorrido multMatriz:" << tempoDecorrido << endl;



//             cout << resultadoFinal.m[0][0] << " " << resultadoFinal.m[1][0] << endl;
       
//         }
//     }

//     return 0;
// } 
