/**
* Ein Programm, dass den Tag des Jahres wiedergibt.
* Autor: Juliane Meyer
* Erstellt am: 12.10.2021
**/

#include "bibliothek.h"

int main()
{
    int day,month,year;

    input_date(&day, &month, &year);

    printf(" *** Tag des Jahres *** \n");

    printf("Der %d.%d.%d Es ist der %d. Tag des Jahres.",day, month, year, day_of_the_year(day, month, year));
    return 0;
}
