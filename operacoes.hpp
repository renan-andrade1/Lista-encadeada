#include <iostream>
#include "polinomio.hpp"
using namespace std;

double potencia(double a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    return a * potencia(a, b-1);
}

Polinomio somar(Polinomio &p1, Polinomio &p2)
{
    Termo* t1 = p1.primeiro;
    Termo* t2 = p2.primeiro;
    Polinomio p3;
    inicializar(p3);

    while(t1 != nullptr && t2 != nullptr)
    {
        if(t1->expoente == t2->expoente)
        {
            inserirOrdenado(p3,t1->coeficiente + t2->coeficiente, t1->expoente);
            t1 = t1->prox;
            t2 = t2->prox;
        }

        else if(t1->expoente > t2->expoente)
        {
            inserirOrdenado(p3, t1->coeficiente, t1->expoente);
            t1 = t1->prox;
        }

        else if(t2->expoente > t1->expoente)
        {
            inserirOrdenado(p3, t2->coeficiente, t2->expoente);
            t2 = t2->prox;
        }
    }
    while(t1 != nullptr)
    {
        inserirOrdenado(p3, t1->coeficiente, t1->expoente);
        t1 = t1->prox;
    }
    while(t2 != nullptr)
    {
        inserirOrdenado(p3, t2->coeficiente, t2->expoente);
        t2 = t2->prox;
    }
    return p3;
}

Polinomio subtrair(Polinomio &p1, Polinomio &p2)
{
    Termo* t1 = p1.primeiro;
    Termo* t2 = p2.primeiro;
    Polinomio p3;
    inicializar(p3);

    while(t1 != nullptr && t2 != nullptr)
    {
        if(t1->expoente == t2->expoente)
        {
            inserirOrdenado(p3,t1->coeficiente - t2->coeficiente, t1->expoente);
            t1 = t1->prox;
            t2 = t2->prox;
        }

        else if(t1->expoente > t2->expoente)
        {
            inserirOrdenado(p3, -t1->coeficiente, t1->expoente);
            t1 = t1->prox;
        }

        else if(t2->expoente > t1->expoente)
        {
            inserirOrdenado(p3, -t2->coeficiente, t2->expoente);
            t2 = t2->prox;
        }
        while(t1 != nullptr)
        {
            inserirOrdenado(p3, t1->coeficiente, t1->expoente);
            t1 = t1->prox;
        }
        while(t2 != nullptr)
        {
            inserirOrdenado(p3, -t2->coeficiente, t2->expoente);
            t2 = t2->prox;
        }
    }
    return p3;
}

Polinomio multiplicarEscalar(Polinomio &p, double k)
{
    Termo* atual = p.primeiro;
    Polinomio resultado;
    inicializar(resultado);

    while(atual != nullptr)
    {
        inserirOrdenado(resultado, atual->coeficiente * k, atual->expoente);
        atual = atual->prox;
    }
    return resultado;
}

double valorNumerico(Polinomio &p, double x)
{
    Termo* atual = p.primeiro;
    double resultado = 0;

    while(atual != nullptr)
    {
        resultado += atual->coeficiente * potencia(x, atual->expoente);
        atual = atual->prox;
    }
    return resultado;
}

Polinomio multiplicar(Polinomio &p1, Polinomio &p2)
{
    Termo* t1 = p1.primeiro;
    Termo* t2 = p2.primeiro;
    Polinomio p3;
    inicializar(p3);

    while(t1 != nullptr && t2 != nullptr)
    {
        inserirOrdenado(p3, t1->coeficiente * t2->coeficiente, t1->expoente + t2->expoente);
        t2 = t2->prox;
        if(t2 == nullptr)
        {
            t1 = t1->prox;
            t2 = p2.primeiro;
        }
    }

    return p3;
}
