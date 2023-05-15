#include <iostream>
using namespace std;

// Funkcja pomocnicza, która przenosi dysk z kolumny A na kolumnę B
void moveDisk(int disk, char from, char to) {
    cout << "Przenoszenie dysku " << disk << " z " << from << " na " << to << endl;
}

// Funkcja rekurencyjna, która rozwiązuje wieże Hanoi
void hanoiTower(int n, char from, char to, char aux) {
    // Jeśli jest tylko jeden dysk, to przenieś go na kolumnę docelową i zakończ rekurencję
    if (n == 1) {
        moveDisk(n, from, to);
        return;
    }
    
    // Przenieś n-1 dysków z kolumny źródłowej na kolumnę pomocniczą, używając kolumny docelowej jako pomocniczej
    hanoiTower(n-1, from, aux, to);
    
    // Przenieś pozostały dysk z kolumny źródłowej na kolumnę docelową
    moveDisk(n, from, to);
    
    // Przenieś n-1 dysków z kolumny pomocniczej na kolumnę docelową, używając kolumny źródłowej jako pomocniczej
    hanoiTower(n-1, aux, to, from);
}

int main() {
    int n; // Liczba dysków
    cin>>n;
    cout << "Rozwiazanie wiezy Hanoi dla " << n << " dyskow:" << endl;
    hanoiTower(n, 'A', 'C', 'B'); // Kolumny A, B i C
    return 0;
}

