/**
 *  Author: Juliane Meyer
 *  Datum: 15.05.2022
 *  Programm: Tag des Jahres in mehreren Funktionen
 **/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/*
Hier wird geprüft, ob ein Schaltjahr vorliegt.
*/
int is_leapyear(int year){
    if(year<1582) return -1;
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }
           return 0;
        }
        return 1;
    }
    return -1;
}

/*
Hier wird der Tag, der Monat und das Jahr eingelesen. Wenn das angegebene Datum
ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
*/
void input_date(int *day, int *month, int *year){
    char datum[10];
    printf(" *** Tag des Jahres *** \n");
    printf("Bitte geben Sie ein Datum ein: ");
    scanf("%10s",datum);
    char *token=strtok(datum,".");
    *day=atoi(token);
    token=strtok(NULL,".");
    *month=atoi(token);
    token=strtok(NULL,".");
    *year=atoi(token);
}

/*
Hier wird bestimmt, wie viel Tage der eingegebene Monat hat.
*/
int get_days_for_month(int month, int year){
    tage_pro_monat[1]=28;
    if((month<1 || month>12) || (year<1582 || year>2400)) return -1;
    if(is_leapyear(year)) tage_pro_monat[1]++;
    return tage_pro_monat[month];
}


/*
Das Daten wir hier überprüft. Ungültig ist das Datum vor dem 1.1.1582 und alles nach dem 31.12.2400.
*/
int exists_date(int day, int month, int year){
    if (year<1582 || year>2400) return 0;
    if(month<1 || month>12) return 0;
    if(tage_pro_monat[month-1]<day || day<1) return 0;
    return 1;
}


/*
Hier wird die Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
*/
int day_of_the_year(int day, int month, int year){
    if(!exists_date(day,month,year)) return -1;
    int erg=0;
    if(is_leapyear(year)){
        tage_pro_monat[1]++;
    }
    if(month==1){
        return day;
    }

    for (int i = 0; i <= month-1; i++) {
        erg+=get_days_for_month(i,year);
    }
    if(is_leapyear(year)) tage_pro_monat[1]--;
    erg+=day;
    return erg;
}

/*
Hauptfunktion: Hier werden die Funktionen aufgerufen und die Ausgabe der Zahl des Tages erfolgt.
*/
int main()
{
    int year,month,day=0;
    input_date(&day,&month,&year);
    printf("Das Datum ist der %d. Tag des Jahres %d",day_of_the_year(day,month,year),year);


    return 0;
}
