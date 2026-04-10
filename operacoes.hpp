#include <iostream>
#include <cmath>
#include "polinomio.hpp"
using namespace std;

Polinomio somar(Polinomio* p1, Polinomio* p2)
{
    Termo* t1 = p1->primeiro;
    Termo* t2 = p2->primeiro;
    Termo* t3 = nullptr;

    while(t1 != nullptr && t2 != nullptr)
    {
        if(t1->expoente == t2->expoente)
        {
            t3->coeficiente = t1->coeficiente + t2->coeficiente;
        }

        if(t1->expoente > t2->expoente)
        {
            t3->coeficiente = t1->coeficiente;
            t3->expoente =
        }
        t1 = t1->prox;
        t2 = t2->prox;
    }
}

Polinomio subtrair(Polinomio* p1, Polinomio* p2)
{

}

Polinomio multiplicarEscalar(Polinomio* p, double k)
{

}

double valorNumerico(Polinomio* p, double x)
{

}

Polinomio multiplicar(Polinomio* p1, Polinomio* p2)
{

}
