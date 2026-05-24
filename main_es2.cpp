/*! \file main_es2.cpp
    \brief implementation of the user input menu
    \author Giovanni Canepa
*/

#include <iostream>
#include <cmath>

#include ".\src\CShape.h"
#include ".\src\CRectangle.h"
#include ".\src\CRhombus.h"
#include ".\src\CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 10

void visualizzaPoligoni(Shape **, int);
void modificaProprieta(Shape **, int);
void spostaPoligono(Shape **, int);
void inserisciPoligono(Shape **, int &);
void eliminaPoligono(Shape **shapes, int &nShapes, bool userInput = 1);
int main()
{
    Shape *shapes[MAX_SHAPES];
    int nShapes = 0;

    int choice = -1;
    do
    {
        cout << endl;
        cout << "1 - Visualizza tutti i poligoni" << endl;
        cout << "2 - Modifica le proprieta' di un poligono " << endl;
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
            modificaProprieta(shapes, nShapes);
            break;
        case 3:
            spostaPoligono(shapes, nShapes);
            break;
        case 4:
            inserisciPoligono(shapes, nShapes);
            break;
        case 5:
            eliminaPoligono(shapes, nShapes);
            break;
        case 6:
            eliminaPoligono(shapes, nShapes, false);
            break;
        case 0:
            break;
        default:
            cout << "Valore non valido" << endl;
            break;
        }
    } while (choice != 0);

    eliminaPoligono(shapes, nShapes, false);
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

void modificaProprieta(Shape **shapes, int nShapes)
{
    int choice, selection;
    float w, h, sf;
    char text[TEXTSIZE];
    cout << endl
         << "===== MODIFICA POLIGONO =====" << endl;
    do
    {
        cout << endl;
        cout << "Inserisci l'indice del poligono da modificare, -1 per uscire. " << endl;
        cin >> selection;
        if (selection >= 0 && selection < nShapes)
        {
            do
            {
                cout << "0 - Esci" << endl;
                cout << "1 - Inserisci nuove dimensioni" << endl;
                cout << "2 - Scala shape" << endl;
                cout << "3 - Modifica testo" << endl;
                cin >> choice;

                switch (choice)
                {
                case 0:
                    break;
                case 1:
                    cout << "Inserisci larghezza:" << endl;
                    cin >> w;
                    cout << "Inserisci altezza:" << endl;
                    cin >> h;
                    shapes[selection]->SetDim(w, h);
                    break;
                case 2:
                    cout << "Inserisci fattore di scala:" << endl;
                    cin >> sf;
                    shapes[selection]->Scale(sf);
                    break;
                case 3:
                    cout << "Inserisci nuovo testo:" << endl;
                    cin >> text;
                    shapes[selection]->SetText(text);
                    break;
                default:
                    cout << "Selezione invalida, riprova" << endl;
                }
            } while (choice != 0);
        }
        else if (selection != -1)
            cout << "Valore non valido" << endl;
    } while (selection != -1);
}

void spostaPoligono(Shape **shapes, int nShapes)
{
    int selection;
    float x, y;
    cout << endl
         << "===== SPOSTA POLIGONO =====" << endl;
    do
    {
        cout << endl;
        cout << "Inserisci l'indice del poligono da spostare, -1 per uscire. " << endl;
        cin >> selection;
        if (selection >= 0 && selection < nShapes)
        {
            cout << "Inserisci nuova posizione x:" << endl;
            cin >> x;
            cout << "Inserisci nuova posizione y:" << endl;
            cin >> y;
            shapes[selection]->SetPosition(x, y);
        }
    } while (selection != -1);
}

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

void eliminaPoligono(Shape **shapes, int &nShapes, bool userInput)
{
    int choice;
    cout << endl
         << "===== ELIMINA POLIGONO =====" << endl;
    if (userInput)
        do
        {
            cout << "Inserisci indice del poligono da eliminare. -1 per uscire." << endl;
            cin >> choice;
            if (choice >= 0 && choice < nShapes)
            {
                delete shapes[choice];
                for (int i = choice; i < nShapes - 1; i++)
                {
                    shapes[i] = shapes[i + 1];
                }
                nShapes--;
                cout << "Poligono eliminato correttamente." << endl;
            }
            else
                cout << "Valore non valido" << endl;

        } while (choice != -1);
    else
    {
        for (int i = 0; i < nShapes; i++)
            delete shapes[i];
        nShapes = 0;
        cout << "Poligoni eliminati correttamente." << endl;
    }
}
