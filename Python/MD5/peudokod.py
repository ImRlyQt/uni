Funkcja md5(wejście):
    inicjuj zmienne a0, b0, c0, d0 jako stałe wartości
    zdefiniuj listę k zawierającą 64 stałe wartości
    zdefiniuj funkcje pomocnicze F, G, H, I

    przekształć wejście w ciąg bitów w sposób zgodny z standardem MD5
    dodaj bit '1' na końcu ciągu bitów
    dopełnij ciąg bitów tak, aby jego długość była kongruentna z 448 modulo 512
    dodaj 64-bitowy blok zawierający długość wejścia

    podziel ciąg bitów na 16 słów 32-bitowych: M[0], M[1], ..., M[15]

    inicjuj zmienne a, b, c, d jako a0, b0, c0, d0

    wykonaj 4 rundy algorytmu:
        dla i = 0 do 15 wykonaj
            F = F(b, c, d)
            g = i
        dla i = 16 do 31 wykonaj
            G = G(b, c, d)
            g = (5*i + 1) modulo 16
        dla i = 32 do 47 wykonaj
            H = H(b, c, d)
            g = (3*i + 5) modulo 16
        dla i = 48 do 63 wykonaj
            I = I(b, c, d)
            g = (7*i) modulo 16
        a, b, c, d = d, a + F + M[g] + k[i], b, c

    zwróć 128-bitowy hash jako konkatenację wartości a, b, c, d 








