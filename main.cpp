#include <iostream>
#include <cstdlib>
#include "Lista.h"

using namespace std;

int main()
{

    Lista lista;
    bool escolha = false;

    do
    {

        cout << "Escolha as seguintes operações: " << endl;
        cout << "1- Criar lista" << endl;
        cout << "2- Inserir elemento na lista" << endl;
        cout << "3- Remover elemento da lista" << endl;
        cout << "4- Modificar elemento da lista" << endl;
        cout << "5- Obter elemento da lista" << endl;
        cout << "6- Obter tamanho da lista" << endl;
        cout << "7- Verificar se a lista está vazia" << endl;
        cout << "8- Imprimir lista" << endl;

        int operacao;

        cin >> operacao;

        if (operacao == 1)
        {
            cout << "Lista criada com sucesso" << endl;
        }
        else if (operacao == 2)
        {
            cout << "Insira o valor que deseja inserir:" << endl;
            int valor;
            cin >> valor;
            cout << "Insira a posição em que deseja inserir o valor:" << endl;
            int pos;
            cin >> pos;

            if (lista.inserirElemento(pos, valor))
            {
                cout << "Elemento " << valor << " inserido na posição " << pos << ".\n";
                lista.imprimirLista();
            }
            else
            {
                cout << "Falha ao inserir elemento.\n";
            }
        }
        else if (operacao == 3)
        {

            cout << "Insira a posição que deseja remover: " << endl;
            int pos;
            cin >> pos;

            if (lista.removerElemento(pos))
            {
                cout << "Elemento na posição " << pos << " removido.\n";
                lista.imprimirLista();
            }
            else
            {
                cout << "Falha ao remover elemento.\n";
            }
        }
        else if (operacao == 4)
        {
            cout << "Insira o novo valor que deseja inserir:" << endl;
            int novo_valor;
            cin >> novo_valor;
            cout << "Insira a posição em que deseja inserir o valor:" << endl;
            int pos;
            cin >> pos;

            if (lista.modificarElemento(pos, novo_valor))
            {
                cout << "Elemento na posição " << pos << " modificado para " << novo_valor << ".\n";
                lista.imprimirLista();
            }
            else
            {
                cout << "Falha ao modificar elemento.\n";
            }
        }
        else if (operacao == 5)
        {

            cout << "Insira a posição da qual deseja obter o valor:" << endl;
            int pos;
            cin >> pos;
            int valor = lista.obterElemento(pos);
            cout << "Elemento na posição " << pos << ": " << valor << "\n";
        }
        else if (operacao == 6)
        {
            int n = lista.obterTamanho();

            cout << "Tamanho: " << n << "\n";
        }
        else if (operacao == 7)
        {
            if (lista.listaVazia())
            {
                cout << "Lista Vazia" << endl;
            }
            else
            {
                cout << "Lista não está vazia" << endl;
            }
        }
        else if (operacao == 8)
        {
            lista.imprimirLista();
        }
        else
        {
            cout << "Operação desconhecida.\n";
        }

        cout << "Deseja continuar? 1-Sim, 0-Não" << endl;
        cin >> escolha;
        if ((escolha != 1) && (escolha != 0))
        {
            escolha = 0;
        }

    } while (escolha);

    lista.~Lista(); // Esvazia a lista quando não foi mais desejado fazer as operações;

    return 0;
}
