#include <iostream>
using namespace std;

void eratosthenesSieve(int n) {
    // Tworzenie tablicy liczb naturalnych od 2 do n
    bool* prime = new bool[n + 1];
    // Wypełnienie tablicy wartościami true
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    // Wykonywanie sita Eratostenesa
    for (int p = 2; p * p <= n; p++) {
        // Jeśli liczba jest oznaczona jako pierwsza, to oznacz wszystkie jej wielokrotności jako złożone
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    // Wyświetlanie wszystkich liczb pierwszych
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    
    // Usuwanie zaalokowanej pamięci
    delete[] prime;
}

int main() {
    int n = 30;
    cout << "Liczby pierwsze mniejsze lub równe " << n << " to: ";
    eratosthenesSieve(n);
    return 0;
}
