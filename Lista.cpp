#include "Lista.h"
#include <iostream>
#include <fstream>

using namespace std;

Lista::Lista() // Constrói a lista
{
    cabeca = NULL;
    tamanho = 0;
}

Lista ::~Lista()
{ // Esvazia um por um os nós da lista
    No *atual = cabeca;
    while (atual != nullptr)
    {
        No *temp = atual;       // Armazena o valor de atual
        atual = atual->proximo; // Atualiza "atual"
        delete temp;            // Libera o espaço do nó
    }
}
bool Lista::listaVazia()
{
    if (tamanho == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Lista::obterTamanho()
{
    return tamanho;
}

int Lista::obterElemento(int posicao)
{
    No *aux = cabeca;
    int cont = 1;
    if (listaVazia())
    {
        cout << "Não existe nenhum elemento na lista" << endl;
    }
    if ((posicao > tamanho) || (posicao < 1)) // Verifica se a posição existe
    {
        cout << "Posição inexistente" << endl;
    }
    else
    {
        while (cont < posicao) // Atualiza a variável aux até a posição desejada, para obter o valor
        {
            aux = aux->proximo;
            cont++;
        }
    }

    return aux->dado;
}

bool Lista::modificarElemento(int posicao, int valor)
{
    if ((posicao < 1) || (posicao > tamanho)) // Verifica se a posição é válida
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    else
    {
        No *temp = cabeca;                // Cria a variável auxiliar começando pelo primeiro nó
        for (int i = 1; i < posicao; i++) // Percorre a lista até a posição desejada
        {
            temp = temp->proximo;
        }
        temp->dado = valor; // Atribui o valor à posição indicada
        return true;
    }
}

bool Lista::inserirElemento(int posicao, int valor)
{
    if ((listaVazia() && (posicao != 1)) || (posicao < 1)) // Verifica se a posição é válida
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    // Nó auxiliar
    No *novoNo = new No;
    novoNo->dado = valor;
    novoNo->proximo = nullptr;

    // Inserir no inicio da lista
    if (posicao == 1)
    {
        novoNo->proximo = cabeca; // Faz com que o nó seguinte  do auxiliar seja o antigo "primeiro nó"
        cabeca = novoNo;          // A cabeça da lista agora é o nó que será inserido
        tamanho++;
        return true;
    }
    No *temp = cabeca;                    // Iniciamos o nó auxiliar pelo primeiro nó
    for (int i = 1; i < posicao - 1; i++) // O nó auxiliar percorre a lista até a posição desejada
    {
        temp = temp->proximo;
    }
    novoNo->proximo = temp->proximo; // Novo nó sendo inserido
    temp->proximo = novoNo;
    tamanho++;
    return true;
}

bool Lista::removerElemento(int posicao)
{
    if ((listaVazia()) || (posicao < 1) || (posicao > tamanho)) // Verifica se a posição é válida
    {
        cout << "Posição inexistente " << endl;
        return false;
    }
    No *temp = cabeca; // Nó auxiliar começa a sua posição pela cabeça da lista
    if (posicao == 1)  // Se for remover o primeiro nó
    {
        cabeca = cabeca->proximo; // A cabeça da lista passa a ser o segundo nó, para que o primeiro seja deletado
        delete temp;
        tamanho--;
        return true;
    }
    No *prev = nullptr; // Nó auxiliar
    for (int i = 1; i < posicao; i++)
    {
        prev = temp;          // Prev recebe o valor de temp
        temp = temp->proximo; // Temp recebe o nó que estava uma posição depois da sua
    }
    prev->proximo = temp->proximo;
    delete temp;
    tamanho--;
    return true;
}

void Lista::imprimirLista()
{
    if (listaVazia())
    {
        cout << "A lista está vazia." << endl;
    }
    cout << endl;
    cout << "Lista: " << endl;

    No *temp = cabeca; // Printa a lista começando pela cabeça da lista
    while (temp)
    {
        cout << temp->dado << " -> ";
        temp = temp->proximo;
    }
    cout << endl;
}