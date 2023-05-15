// Wyłączenie ostrzeżeń dla funkcji niezalecanych
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Liczba punktów do obliczenia całki
#define ilosc_przedzialow 1000

// Zakres całkowania
double poczatek_przedzialu, koniec_przedzialu;

// Definicja funkcji, której całkę będziemy obliczać
double f3(double x)
{
    return sin(x) + 1;
}

double f4(double x)
{
    return 6.23 * x * x * x - 3.5 * x * x - 28;
}

// Metoda prostokątów
double prostokaty(double(*f)(double))
{
    double step, p, sum = 0;
    // Obliczenie szerokości pojedynczego prostokąta
    step = (koniec_przedzialu - poczatek_przedzialu) / ilosc_przedzialow;
    for (p = poczatek_przedzialu+step; p < koniec_przedzialu; p += step)
        // Dodanie pola kolejnego prostokąta
        sum += (*f)(p) * step;
    return sum;
}

// Metoda trapezów
double trapezy(double (*f)(double))
{
    double step = (koniec_przedzialu - poczatek_przedzialu) / ilosc_przedzialow;
    double sum = 0;
    for (double i = poczatek_przedzialu; i < koniec_przedzialu; i += step)
    {
        // Obliczenie pola trapezu i dodanie do sumy całkowitej
        sum = sum + ((*f)(i) + (*f)(i + step)) * step / 2;
    }
    return sum;
}

// Funkcja zwracająca losowy punkt w przedziale [pkt_1, pkt_2]
double randomPkt(double pkt_1, double pkt_2) {
    return pkt_1 + (double)rand() / ((double)(RAND_MAX) + 1) * (pkt_2 - pkt_1);
}

// Metoda Monte Carlo
double mc(double(*f)(double))
{
    double integral = 0;
    srand(10);
    for (int i = 0; i < ilosc_przedzialow; i++) {
        // Obliczenie wartości funkcji w losowym punkcie i dodanie do całki
        integral += (*f)(randomPkt(poczatek_przedzialu, koniec_przedzialu));
    }

    // Obliczenie średniej wartości całki i przemnożenie przez długość przedziału całkowania
    integral = (integral / (double)ilosc_przedzialow) * (koniec_przedzialu - poczatek_przedzialu);

    return integral;
}
