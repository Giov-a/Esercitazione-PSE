#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape *shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 8, 6);
    shapes[nShapes++] = new RightTriangle(-2, -2, 8, 6);

    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo");

    // 3. Dump polimorfico
    cout << endl
         << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++)
    {
        cout << endl
             << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    // 5. Scalamento figure
    float sf;
    int shape = 0;
    while (true)
    {
        cout << "Inserire numero figura da scalare (secondo dump precedente); -1 per uscire" << endl;
        cin >> shape;
        if (shape == -1)
            break;
        cout << "Inserire fattore di scala" << endl;
        cin >> sf;
        shapes[shape]->Scale(sf);
    }

    // 6. Dump post scalamento
    cout << endl
         << "===== DUMP POST SCALAMENTO =====" << endl;

    for (int i = 0; i < nShapes; i++)
    {
        cout << endl
             << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    // 7. Cancellazione figure
    for (int i = 0; i < nShapes; i++)
        delete shapes[i];

    cout
        << endl
        << "===== FINE TEST =====" << endl;

    return 0;
}