#include <iostream>
#include "matrish.h"

using namespace std;

int main()
{
    Matris mainMatris;

    /*
    //Değer ataması
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mainMatris.setValue(i, j, i * j);
        }
    }
    */
    mainMatris.randomSet();
    mainMatris.display();

    Matris mainMatris2;
    mainMatris2.identityMatrisSet();
    mainMatris2.display();

    Matris mainMatris3=mainMatris2;
    mainMatris3.display();
   
   
    mainMatris.addMatris(mainMatris2);
    


    return 0;
}

