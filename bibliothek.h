#ifndef BIBLIOTHEK_H_INCLUDED
#define BIBLIOTHEK_H_INCLUDED

int is_leapyear(int year);
int get_days_for_month(int year, int month);
int exists_date(int day, int month, int year);
int input_date(int *day, int *month, int *year);
int day_of_the_year(int day, int month, int year);

#endif // BIBLIOTHEK_H_INCLUDED
