#include <iostream>
 
#include "../include/Matriz.hpp"
#include "../include/SegTree.hpp"

using namespace std;

int main(){
    //Qtd de instantes de tempo  
    int n; 
    //qtd de operacoes
    
    int q; 
    char op; 

    cin >> n >> q;


    //instancia a arvore.
    SegTree arvore(n);
 

    for(int i = 0; i < q; i++){
        cin >> op;

        if(op == 'u'){ 
            //update
            int instante;
            unsigned long int a, b, c, d;

            cin >> instante;

            cin >> a >> b;
            cin >> c >> d;

            Matriz mat(a, b, c, d);
            
            arvore.update(instante, mat, 1, 0, n-1);
        }
        else if(op == 'q'){
            //query
            int t0, td;


            unsigned long int x, y;

            cin >> t0 >> td >> x >> y;

            Matriz resultado = arvore.query(t0, td, 1, 0, n-1);
            Matriz p_desaparece(x, y);

            Matriz respFinal;
            respFinal = respFinal.multipicaMatriz(resultado, p_desaparece);
            cout << respFinal.c_m11() << " " << respFinal.c_m21() << endl;
        }
    }   

    return 0;
}