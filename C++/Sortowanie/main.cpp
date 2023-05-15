#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "algorytmy.hpp"

using namespace std;
using namespace chrono;
using namespace this_thread;

void save_to_file(int *tab, int n, string filename) {
    ofstream outfile;
    outfile.open(filename);

    for (int i = 0; i < n; i++) {
        outfile << tab[i] << endl;
    }

    outfile.close();
}

void clone_tab(int *tab, int *tab_clone, int n) {
    for (int i = 0; i < n; i++) {
        tab_clone[i] = tab[i];
    }
}

int main() {
    system("clear");
    int n, choice, *tab;
    char input;

    while (true) {
        cout << "\033[1;47;30m Projekt sortowanie \033[0m \033[1;47;30m Ernest Lesniak \033[0m\n";
        cout << "Wprowadź rozmiar tablicy:\n > ";

        cin >> n;
        while (getchar() != '\n');

        tab = new int[n];
        if (!tab) {
            cout << "\033[1;47;30m Nie udało się zaalokować pamięci \033[0m\n\n";
            continue;
        }

        ifstream infile;
        infile.open("test1.txt");
        if (!infile) {
            cout << "\033[1;47;30m Nie udało się otworzyć pliku! \033[0m\n\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            infile >> tab[i];
        }

        infile.close();

        while (true) {
            int *tab_clone = new int[n];
            clone_tab(tab, tab_clone, n);

            cout << "\n------------------------------------------------\n\n";
            cout << "Wybierz algorytm sortowania dla "<< n<<" elementów\n\n";
            cout << "  \033[1;47;30m[1]\033[0m Przez wstawianie\n";
            cout << "  \033[1;47;30m[2]\033[0m Przez selekcję\n";
            cout << "  \033[1;47;30m[3]\033[0m Bąbelkowe\n";
            cout << "  \033[1;47;30m[4]\033[0m Quicksort\n";
            cout << "  \033[1;47;30m[5]\033[0m Shella\n";
            cout << "  \033[1;47;30m[6]\033[0m Przez kopcowanie\n";
            cout << "  \033[1;47;30m[7]\033[0m Bogosort\n\n"; 
            cout << "  \033[1;47;30m[r]\033[0m Restart\n";
            cout << "  \033[1;47;30m[q]\033[0m Wyjście\n\n > ";

            choice = getchar();
            while (getchar() != '\n');
            cout << endl;

            if (choice == 'r'){
            system("clear");
            break;
            }

            else if (choice == 'q') return 0;

            auto start = high_resolution_clock::now();

            switch (choice) {
                case '1':
                    insertionSort(tab_clone, n);
                    break;
                case '2':
                    selectionSort(tab_clone, n);
                    break;
                case '3':
                    bubbleSort(tab_clone, n);
                    break;
                case '4':
                    quickSort(tab_clone, 0, n - 1);
                    break;
                case '5':
                    shellSort(tab_clone, n);
                    break;
                case '6':
                    heapSort(tab_clone, n);
                    break;
                case '7':
                    bogosort(tab_clone, n);
                    break;
              
                default:
                    system("clear");
                    cout << "\033[1;47;30m Program do sortowania tablic \033[0m \033[1;47;30m Power Turbo 2.1 \033[0m\n";
                    cout << "Niepoprawny wybór algorytmu!\n\n";
                    continue;
            }

            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            
          
            int progress = 0;
            const int total = 50;
            while (progress <= total) 
            {
              cout << "Sortowanie: [";
               for (int i = 0; i < total; i++) {
                if (i < progress) {
                 cout << "=";
                  } else if (i == progress) {
                  cout << ">";
                  } else 
                  {
                  cout << " ";
                  }
            }
            cout << "] " << progress*2 << "%\r\n";
            cout <<"\033[1A\033[2K";
            sleep_for(milliseconds(50));
            progress++;
            }
            
            system("clear");
            
           cout << "\033[1;47;30m Program do sortowania tablic \033[0m \033[1;47;30m Power Turbo 2.1 \033[0m\n";

            cout << "Czas sortowania: " << duration.count() << " mikrosekund\n";

            save_to_file(tab_clone, n, "posortowane.txt");
            cout << "Wynik zapisano do pliku output.txt\n";

            delete[] tab_clone;
        }

        delete[] tab;
    }

    return 0;
}
