#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 10

void visualizzaPoligoni(Shape **, int);
// void modificaProprieta(Shape **, int);
// void spostaPoligono(Shape **, int);
void inserisciPoligono(Shape **, int &);

int main()
{
    Shape *shapes[MAX_SHAPES];
    int nShapes = 0;

    int choice = -1;
    do
    {
        cout << endl;
        cout << "1 - Visualizza tutti i poligoni" << endl;
        cout << "2 - Modifica le proprietà di un poligono " << endl;
        cout << "3 - Sposta un poligono sulla griglia " << endl;
        cout << "4 - Inserisci un nuovo poligono " << endl;
        cout << "5 - Cancella un poligono " << endl;
        cout << "6 - Cancella tutti i poligoni " << endl;
        cout << "0 - Esci " << endl
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            visualizzaPoligoni(shapes, nShapes);
            break;
        case 2:

            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            inserisciPoligono(shapes, nShapes);
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            break;
        default:
            cout << "Valore non valido" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

void visualizzaPoligoni(Shape **shapes, int nShapes)
{
    cout << endl
         << "===== LISTA POLIGONI =====" << endl;
    for (int i = 0; i < nShapes; i++)
    {
        cout << "Index: " << i << endl;
        shapes[i]->ShortDump();
    }
    int choice = 0;
    do
    {
        cout << "Inserisci indice figura per dump completo. -1 per uscire" << endl;
        cin >> choice;
        if (choice >= 0 && choice < nShapes)
        {
            cout << endl
                 << "Index: " << choice << endl;
            shapes[choice]->Dump();
        }
    } while (choice != -1);
}

/*
void modificaProprieta(Shape **shapes, int nShapes)
{
}

void spostaPoligono(Shape **shapes, int nShapes)
{
}
*/

void inserisciPoligono(Shape **shapes, int &nShapes)
{
    int choice;
    float x, y, w, h;
    cout << endl
         << "===== INERISCI POLIGONO =====" << endl;
    do
    {
        cout << endl;
        cout << "1 - Inserisci rettangolo" << endl;
        cout << "2 - Inserisci rombo" << endl;
        cout << "3 - Inserisci triangolo rettangolo" << endl;
        cout << "0 - Esci " << endl
             << endl;

        cin >> choice;
        if (choice > 0 && choice <= 3)
        {
            cout << "Inserisci coordinata x:" << endl;
            cin >> x;
            cout << "Inserisci coordinata y:" << endl;
            cin >> y;
            cout << "Inserisci larghezza:" << endl;
            cin >> w;
            cout << "Inserisci altezza:" << endl;
            cin >> h;
            switch (choice)
            {
            case 1:
                shapes[nShapes++] = new Rectangle(x, y, w, h);
                break;
            case 2:
                shapes[nShapes++] = new Rhombus(x, y, w, h);
                break;
            case 3:
                shapes[nShapes++] = new RightTriangle(x, y, w, h);
                break;
            }
        }
        else
            cout << "Valore non valido" << endl;

    } while (choice != 0);
}