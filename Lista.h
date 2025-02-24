#pragma once

#include <iostream>

class Lista
{
private:
    struct No // Estrutura que cada nó da lista encadeada tem, que é o valor guardado na memória e o ponteiro para o próximo nó
    {
        int dado;
        No *proximo;
    };

    No *cabeca; // Cabeça é o ponteiro para o primeiro elemento da lista
    int tamanho;

public:
    Lista();  // Construtor da lista
    ~Lista(); // Destrutor da lista, para liberar o espaço reservado na memória

    bool listaVazia();                          // Verifica se a lista está vazia
    int obterTamanho();                         // Obtém o tamanho da lista
    int obterElemento(int pos);                 // Obtém o elemento de uma posição
    bool modificarElemento(int pos, int valor); // Modifica o valor de uma posição
    bool inserirElemento(int pos, int valor);   // Insere um elemento em uma posição
    bool removerElemento(int pos);              // Remove um elemento de uma posição
    void imprimirLista();                       // Exibe os elementos da lista
};
