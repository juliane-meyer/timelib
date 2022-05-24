/*
Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gegorianischen Kalender ein Schaltjahr
ist.
*/
int is_leapyear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return 1;
            }
           return 0;
        }
        return 1;
    }
    return 0;
}

/*
Die Funktion bestimmt für einen gegebenen Monat, eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
*/

int get_days_for_month(int year, int month){
    if(month > 12 || month < 1){
        return -1;
    }
    int days_of_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(is_leapyear(year) && month == 2){
            return 29;
        }
    return days_of_months[month-1];
}

/*
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.
*/
int exists_date(int day, int month, int year){
    if(year < 1582 || month < 1 || day < 1 || year > 2400 || month > 12 || day > 31){
        return 0;
    }
    if(get_days_for_month(year, month) < day) {
        return 0;
    }
    return 1;
}

/*
Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
*/

int input_date(int *day, int *month, int *year){
    do{
        printf("Geben Sie ein Jahr ein: ");
        scanf("%d", year);
        printf("Geben Sie einen Monat ein: ");
        scanf("%d", month);
        printf("Geben Sie einen Tag ein: ");
        scanf("%d", day);
    } while (exists_date(*day, *month, *year) != 1);
}

/* Funktion um herauszufinden, welcher Tag im Jahr das ist.
Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
*/
int day_of_the_year(int day, int month, int year){
    if(exists_date(day, month, year) != 1){
        return -1;
    }

    int result = 0;

    for (int i = 1; i < month; i++) {
        result += get_days_for_month(year, i);
    }
    result += day;

    return result;
}

// Hauptfunktion
int main()
{
    int day,month,year;

    input_date(&day, &month, &year);

    printf(" *** Tag des Jahres *** \n");

    printf("Der %d.%d.%d Es ist der %d. Tag des Jahres.",day, month, year, day_of_the_year(day, month, year));
    return 0;
}
