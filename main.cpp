#include <iostream>
#include "polinomio.hpp"
#include "operacoes.hpp"

// Polinomio somar(Polinomio &p1, Polinomio &p2);
// Polinomio subtrair(Polinomio &p1, Polinomio &p2);
// Polinomio multiplicar(Polinomio &p1, Polinomio &p2);
// Polinomio multiplicarEscalar(Polinomio &p, double k);
// double valorNumerico(Polinomio &p, double x);

using namespace std;

int main()
{
    Polinomio p1, p2, resultado;
    inicializar(p1);
    inicializar(p2);
    inicializar(resultado);

    int opcao;

    double c;
    int e;

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
        cout << "9 - Multiplicar P2 por um escalar\n";
        cout << "10 - Valor numerico de P1\n";
        cout << "11 - Valor numerico de P2\n";
        cout << "12 - Descobrir expoente em P1\n";
        cout << "13 - Descobrir expoente em P2\n";
        cout << "14 - Remover monomio em P1\n";
        cout << "15 - Remover monomio em P2\n";
        cout << "0 - Sair\n";
        cout << "------------\n";
        cout << "\nOpcao: ";
       
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Coeficiente: ";
            cin >> c;
            cout << "Expoente(0 para constante): "; 
            cin >> e;

            inserirOrdenado(p1, c, e);
            break;

        case 2:
            cout << "Coeficiente: ";
            cin >> c;
            cout << "Expoente(0 para constante): "; 
            cin >> e;

            inserirOrdenado(p2, c, e);
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
            double k;
            cout << "Digite o escalar: ";
            cin >> k;
            resultado = multiplicarEscalar(p2, k);
            imprimir(&resultado);
            break;
        }

        case 10:
        {
            double x;
            cout << "Digite o valor de x: ";
            
            cin >> x;
            
            cout << "Resultado: " << valorNumerico(p1, x) << endl;
            break;
        }

        case 11:
        {
            double x;
            cout << "Digite o valor de x: ";
            
            cin >> x;

            cout << "Resultado: " << valorNumerico(p2, x) << endl;
            break;
        }

        case 12:
        {
            cout << "Digite o expoente a ser descoberto: ";
            cin >> e;

            descobrirExpoente(p1, e);
            break;
        }

        case 13:
        {
            cout << "Digite o expoente a ser descoberto: ";
            cin >> e;

            descobrirExpoente(p2, e);
            break;
        }

        case 14:
        {
            cout << "Digite o expoente do monomio a ser removido: ";
            cin >> e;

            removerMonomio(p1, e);
            break;
        }

        case 15:
        {
            cout << "Digite o expoente do monomio a ser removido: ";
            cin >> e;

            removerMonomio(p2, e);
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
