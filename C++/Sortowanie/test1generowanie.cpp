#include <iostream>
#include <fstream>
#include <vector>
#include <random>

int main()
{
    const int N = 100000;
    const int min_val = -100;
    const int max_val = 100;

    std::vector<int> numbers(N);

    // generator liczb losowych
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_val, max_val);

    // generowanie liczb losowych
    for (int i = 0; i < N; ++i) {
        numbers[i] = dis(gen);
    }

    // zapisywanie do pliku
    std::ofstream file("test1.txt");
    if (file.is_open()) {
        for (int i = 0; i < N; ++i) {
            file << numbers[i] << "\n";
        }
        file.close();
        std::cout << "Liczby zostaly zapisane do pliku 'test1.txt'\n";
    } else {
        std::cout << "Nie udalo sie otworzyc pliku do zapisu\n";
    }

    return 0;
}
