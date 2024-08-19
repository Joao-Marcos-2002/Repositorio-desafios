#include "Set.hpp"

StringSet::StringSet(int tamanho)
{
     /* define o tamanhoOriginal e inicializa o tamanho
    da tabela como o dobro. */
    tamanhoOriginal = tamanho;
    tamanhoTabela = tamanho;
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanhoTabela];

    //inicializa tabela como vazia.
    for(int i = 0; i < tamanhoTabela; i++)
    {
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }
}

StringSet::~StringSet()
{
    // libera memoria alocada.
    delete[] tabela;
}

void StringSet::Inserir(string s)
{
    int pos = Hash(s);
    int i = 0;
    while(i < tamanhoTabela)
    {
        if(tabela[pos].vazio || tabela[pos].retirada)
        {
            tabela[pos].dado = s;
            tabela[pos].vazio = false;
            tabela[pos].retirada = false;
            tamanhoConjunto++;
            break;
        }
        else if(tabela[pos].dado == s)
        {
            break;
        }
        else
        {
            pos = (pos + 1) % tamanhoTabela;
            i++;
        }
    }
    if(i == tamanhoTabela)
    {
        Rehash(pos);
        Inserir(s);
    }
}

void StringSet::Remover(string s)
{
    int pos = Hash(s);
    int k = 0;


    while(k < tamanhoTabela)
    {
        if(tabela[pos].vazio)
        {
            break;
        }
        else if(tabela[pos].dado == s)
        {
            tabela[pos].retirada = true;

            //decresce o tamanho do conjunto apos a retirada.
            tamanhoConjunto--;
            break;
        }
        else
        {
            pos = (pos + 1) % tamanhoTabela;
            k++;
        }
    }
}

bool StringSet::Pertence(string s)
{
    int pos = Hash(s);
    int count = 0;
    while(count < tamanhoTabela)
    {
        if(tabela[pos].vazio)
        {
            return false;
        }
        else if(tabela[pos].dado == s)
        {
            return true;
        }
        else
        {
            pos = (pos + 1) % tamanhoTabela;
            count++;
        }
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S)
{
    StringSet* intersecaoConjunto = new StringSet(tamanhoOriginal);
    for(int i = 0; i < tamanhoTabela; i++)
    {
        if(!tabela[i].vazio && !tabela[i].retirada && S->Pertence(tabela[i].dado))
        {
            intersecaoConjunto->Inserir(tabela[i].dado);
        }
    }
    return intersecaoConjunto;
}

StringSet* StringSet::Uniao(StringSet* S)
{
    StringSet* uniaoConj = new StringSet(tamanhoOriginal);


    for(int i = 0; i < tamanhoTabela; i++)
    {
        if(!tabela[i].vazio && !tabela[i].retirada)
        {
            uniaoConj->Inserir(tabela[i].dado);
        }
    }
    for(int i = 0; i < S->tamanhoTabela; i++)
    {
        if(!S->tabela[i].vazio && !S->tabela[i].retirada)
        {
            uniaoConj->Inserir(S->tabela[i].dado);
        }
    }
    return uniaoConj;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S)
{
    StringSet* diferencaSimetrica = new StringSet(tamanhoOriginal);

    // Pega a diferenca entre o primeiro conjunto e o segundo

    for (int i = 0; i < tamanhoTabela; i++)
    {
        if(!tabela[i].vazio && !tabela[i].retirada && !S->Pertence(tabela[i].dado))
        {
            diferencaSimetrica->Inserir(tabela[i].dado);
        }
    }


    for(int i = 0; i < S->tamanhoTabela; i++)
    {
        if(!S->tabela[i].vazio && !S->tabela[i].retirada && !Pertence(S->tabela[i].dado))
        {
            diferencaSimetrica->Inserir(S->tabela[i].dado);
        }
    }
    return diferencaSimetrica;
}

//Impressao
void StringSet::Imprimir()
{
    cout << "{";
    for(int i = 0; i < tamanhoTabela; i++)
    {
        if(!tabela[i].vazio && !tabela[i].retirada)
        {
            cout << tabela[i].dado;
            if(i < tamanhoTabela - 1)
            {
                cout << ", ";
            }
        }
    }
    cout << "}" << endl;
}

int StringSet::Hash(string s)
{
    int hash = 0;
    int tamanhoS = s.length();

    for(int i = 0; i < tamanhoS; i++)
    {
        hash = (hash * 256 + s[i]) % tamanhoTabela;
    }
    return hash;
}

void StringSet::Rehash(int pos)
{
    int c = 0;
    while(c < tamanhoTabela)
    {
        if(tabela[pos].vazio || tabela[pos].retirada)
        {
            break;
        }
        else
        {
            pos = (pos + 1) % tamanhoTabela;
            c++;
        }
    }

    //faz o redimensionamento:::
    if(c == tamanhoTabela)
    {
        Resize(tamanhoTabela * 2);
    }
    else
    {
        Resize(tamanhoTabela);
    }
}

void StringSet::Resize(size_t tamanho)
{
    ElementoTabela* novaTabela = new ElementoTabela[tamanho];
    for(int i = 0; i < tamanho; i++)
    {
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }
    for (int i = 0; i < tamanhoTabela; i++)
    {
        if(!tabela[i].vazio && !tabela[i].retirada)
        {
            int pos = Hash(tabela[i].dado);
            int c = 0;
            while(c < tamanho)
            {
                if(novaTabela[pos].vazio)
                {
                    novaTabela[pos].dado = tabela[i].dado;
                    novaTabela[pos].vazio = false;
                    novaTabela[pos].retirada = false;
                    break;
                }
                else
                {
                    pos = (pos + 1) % tamanho;
                    c++;
                }
            }
        }
    }
    delete[] tabela;
    tabela = novaTabela;
    tamanhoTabela = tamanho;
}