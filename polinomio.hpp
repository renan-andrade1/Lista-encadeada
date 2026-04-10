#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>
using namespace std;

struct Termo{
    double coeficiente;
    int expoente;
    Termo* prox;
};

struct Polinomio{
    Termo* primeiro;
};

void inicializar(Polinomio &polinomio)
{
    polinomio.primeiro = nullptr;
}

void inserirOrdenado(Polinomio &polinomio, double coeficiente, int expoente)
{
    if (coeficiente == 0.0) 
    {
        return;
    }

    Termo* novo = new Termo;
    novo->coeficiente = coeficiente;
    novo->expoente = expoente;
    novo->prox = nullptr;

    if (polinomio.primeiro == nullptr || polinomio.primeiro->expoente < expoente)
    {
        novo->prox = polinomio.primeiro;
        polinomio.primeiro = novo;
        return;
    }

    if(polinomio.primeiro->expoente == expoente)
    {
        polinomio.primeiro->coeficiente += coeficiente;
        return;
    }

    Termo* atual = polinomio.primeiro;

    
    while (atual->prox != nullptr && atual->prox->expoente > expoente) 
    {
        atual = atual->prox;      
    }

    if(atual->prox != nullptr && atual->prox->expoente == expoente)
    {
        atual->prox->coeficiente += coeficiente;
        delete novo;
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void inserirFinal(Polinomio &polinomio, double coeficiente, int expoente) 
{
    if (coeficiente == 0.0) return;

    Termo* novo = new Termo;
    novo->coeficiente = coeficiente;
    novo->expoente = expoente;
    novo->prox = nullptr;

    if (polinomio.primeiro == nullptr)
    {
        novo->prox = polinomio.primeiro;
        polinomio.primeiro = novo;
        return;
    }

    Termo* atual = polinomio.primeiro;

    while (atual->prox != nullptr) 
    {
        atual = atual->prox;     
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void removerMonomio(Polinomio* polinomio, int expoente)
{
    if (polinomio->primeiro == nullptr) return;

    Termo* atual = polinomio->primeiro;
    Termo* anterior = nullptr;

    while (atual != nullptr && atual->expoente != expoente)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == nullptr) return;

    if(anterior == nullptr)
    {
        polinomio->primeiro = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    delete atual;
}

bool descobrirExpoente(Polinomio* polinomio, int expoente)
{
    Termo* atual = polinomio->primeiro;

    while(atual != nullptr)
    {
        if(atual->expoente == expoente)
        {
            return true;
        }
        atual = atual->prox;
    }
    return false;
}

void imprimir(Polinomio* polinomio)
{
    Termo* atual = polinomio->primeiro;

    while(atual != nullptr)
    {
        cout << atual->coeficiente << "x^" << atual->expoente;

        if (atual->prox != nullptr)
        {
            cout << " + ";
        }

        atual = atual->prox;
    }

    cout << endl;

}

#endif
