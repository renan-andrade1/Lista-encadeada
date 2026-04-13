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
        cout << "Insira um valor diferente de zero para o coeficiente." << endl;
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

void removerMonomio(Polinomio &polinomio, int expoente)
{
    if (polinomio.primeiro == nullptr){
        cout << "Polinomio vazio." << endl;
        return;
    }

    Termo* atual = polinomio.primeiro;
    Termo* anterior = nullptr;

    while (atual != nullptr && atual->expoente != expoente)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == nullptr){
        cout << "Monomio com expoente " << expoente << " nao encontrado neste polinomio." << endl;
        return;
    }

    if(anterior == nullptr)
    {
        polinomio.primeiro = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }
    cout << "Monomio com expoente " << expoente << " e coeficiente " << atual->coeficiente << " removido do polinomio." << endl;
    delete atual;
}

bool descobrirExpoente(Polinomio &polinomio, int expoente)
{
    Termo* atual = polinomio.primeiro;

    while(atual != nullptr)
    {
        if(atual->expoente == expoente)
        {
            cout << "Expoente " << expoente << " encontrado neste polinomio." << endl;
            return true;
        }
        atual = atual->prox;
    }
    cout << "Expoente " << expoente << " nao encontrado neste polinomio." << endl;
    return false;
}

void imprimir(Polinomio* polinomio)
{
    Termo* atual = polinomio->primeiro;

    while(atual != nullptr)
    {
        if(atual->coeficiente < 0)
        {
            cout << "(";
        }
        if(atual->coeficiente == 1 && atual->expoente == 1){
            cout << "x";
        } else if(atual->coeficiente == 1){
            cout << "x^" << atual->expoente;
        }else if(atual->expoente == 1){
            if(atual->coeficiente == -1){
                cout << "-x";
            }
            else{
                cout << atual->coeficiente << "x";
            }
        } else if(atual->expoente == 0){
            cout << atual->coeficiente;
        } else {
            cout << atual->coeficiente << "x^" << atual->expoente;
        }

        if(atual->coeficiente < 0)
        {
            cout << ")";
        }

        if (atual->prox != nullptr)
        {
            cout << " + ";
        }

        atual = atual->prox;
    }

    cout << endl;

}

#endif
