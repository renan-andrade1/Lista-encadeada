#include <iostream>
#include "polinomio.hpp"
#include "operacoes.hpp"

// Polinomio somar(Polinomio &p1, Polinomio &p2);
// Polinomio subtrair(Polinomio &p1, Polinomio &p2);
// Polinomio multiplicar(Polinomio &p1, Polinomio &p2);
// Polinomio multiplicarEscalar(Polinomio &p, double k);
// double valorNumerico(Polinomio &p, double x);

using namespace std;

void inserirTermos(Polinomio &p)
{
    double c;
    int e;

    cout << "Coeficiente: ";
    cin >> c;
    cout << "Expoente: ";
    cin >> e;

    inserirOrdenado(p, c, e);
}

int main()
{
    Polinomio p1, p2, resultado;
    inicializar(p1);
    inicializar(p2);
    inicializar(resultado);

    int opcao;

    do
    {
        cout << "\n---- MENU ----\n";
        cout << "1 - Inserir termo no P1\n";
        cout << "2 - Inserir termo no P2\n";
        cout << "3 - Mostrar P1\n";
        cout << "4 - Mostrar P2\n";
        cout << "5 - Somar (P1 + P2)\n";
        cout << "6 - Subtrair (P1 - P2)\n";
        cout << "7 - Multiplicar (P1 * P2)\n";
        cout << "8 - Multiplicar P1 por um escalar\n";
        cout << "9 - Valor numerico de P1\n";
        cout << "0 - Sair\n";
        cout << "------------\n";
        cout << "\nOpcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            inserirTermos(p1);
            break;

        case 2:
            inserirTermos(p2);
            break;

        case 3:

            cout << "P1 = ";

            imprimir(&p1);
            break;

        case 4:

            cout << "P2 = ";

            imprimir(&p2);
            break;

        case 5:
            resultado = somar(p1, p2);

            cout << "Resultado: ";

            imprimir(&resultado);
            break;

        case 6:
            resultado = subtrair(p1, p2);

            cout << "Resultado: ";

            imprimir(&resultado);
            break;

        case 7:
            resultado = multiplicar(p1, p2);

            cout << "Resultado: ";

            imprimir(&resultado);
            break;

        case 8:
        {
            double k;
            cout << "Digite o escalar: ";
            cin >> k;
            resultado = multiplicarEscalar(p1, k);
            imprimir(&resultado);
            break;
        }

        case 9:
        {
            double x;
            cout << "Digite o valor de x: ";
            cin >> x;
            cout << "Resultado: " << valorNumerico(p1, x) << endl;
            break;
        }

        case 0:
            cout << "Fim\n";
            break;

        default:
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
