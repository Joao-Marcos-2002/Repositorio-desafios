#include <iostream>
#include "../include/segtree.hpp"

using namespace std;

const int MAX = 100000;
int elementos[MAX];

int main()
{

    // Entrada de dados
    int n, q;
    cin >> n >> q;
    Segtree arvore;

    for (int i = 0; i < q; i++)
    {
        cin >> elementos[i];
    }

    arvore.build(1, 0, n - 1);
    while (q--)
    {
        int metodo;
        cin >> metodo;

        if (metodo == 'u')
        {
            // update
            int i, x;
            cin >> i >> x;
            arvore.update(i, x, 1, 0, n - 1);
        }
        else if (metodo == 'q')
        {
            // consulta
            int l, r;

            cin >> l >> r;
            r--;

            // auto [x, y] = arvore.query(l, r, 1, 0, n - 1);
            // cout << x << " " << y << endl;


            auto result = arvore.query(l, r, 1, 0, n - 1);
            cout << result.m11 << " " << result.m12 << " " << result.m21 << " " << result.m22 << endl;

        }
    }

    return 0;
}