#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_CARDS 52
#define PLAYERS 2
int size1=26;
int size2=26;
int size1_on_table=0;
int size2_on_table=0;
// comparing the superiority of cards
int compare(int a, int b) {
  int val_1 = (int)(a/4);
  int val_2 = (int)(b/4);
  if (val_1 > val_2){
      return 1;
  }
  if(val_1 < val_2){
      return 2;
  }else{
      return 0;
  }
}
// the next 8- th functions pop and push cards respectively from players and from table and add it on correct place
void push_card1(int tab[], int card){
    tab[size1] = card;
    size1++;
}
void push_card2(int tab[], int card){
    tab[size2] = card;
    size2++;
}

void push_card1_on_table(int tab[], int card){
    tab[size1_on_table] = card;
    size1_on_table++;
}
void push_card2_on_table(int tab[], int card){
    tab[size2_on_table] = card;
    size2_on_table++;
}
int pop_card1_on_table(int tab[]){
    int card1 = tab[0];
    for(int i=0;i<size1_on_table-1;i++){
        tab[i] = tab[i+1];

    }
    size1_on_table--;
    return card1;
}


int pop_card2_on_table(int tab[]){
    int card2 = tab[0];
    for(int i=0;i<size2_on_table-1;i++){
        tab[i] = tab[i+1];

    }
    size2_on_table--;
    return card2;
}
int pop_card1(int tab[]){
    int card = tab[0];
    for(int i=0;i<size1-1;i++){
        tab[i] = tab[i +1];
    }
    size1--;
    return card;
}

int pop_card2(int tab[]){

    int card = tab[0];
    for(int i=0;i<size2-1;i++){
        tab[i] = tab[i+1];
    }
    size2--;
    return card;
}
// the next 4-rd functions are used to shuffle and create the cards
int rand_from_interval(int r_min, int r_max) {
    int res = r_min + rand() % (r_max - r_min + 1);
    return res;
}
void rand_permutation(int n, int tab[]) {
    for (int i = 0; i < n - 1; i++) {
        tab[i] = i;
    }
    for (int i = 0; i < n - 2; i++) {
        int temp = tab[i];
        int k = rand_from_interval(i, n - 1);
        tab[i] = tab[k];
        tab[k] = temp;
    }

}

void shuffle_cards(int size, int cards[]) {
    return rand_permutation(size, cards);
}


void create_cards(int nr_of_cards, int tab[]) {
    for (int i = 0; i < nr_of_cards; i++) {
        tab[i] = i;
    }
}
// printing the cards as a list
void read_cards(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        if(tab[i] < 10) {
            printf(" %d ", tab[i]);
        }else{
            printf("%d ", tab[i]);

        }
    }
    printf("\n");
}

// dealing the cards between two players
void deal_cards(int players, int first_player_cards[], int second_players_cards[], int cards[], int nr_of_cards,int size) {
    if (nr_of_cards % players != 0) {
        printf("Inappropriate number of players");
    }
    shuffle_cards(nr_of_cards, cards);
    for (int i = 0; i < size; i++) {
        first_player_cards[i] = cards[i];

    }
    int i = 0;
    while (size < nr_of_cards) {
        second_players_cards[i] = cards[size];
        size++;
        i++;


    }
}
// list to check the outputs
int x[53] ={39, 20 ,18 , 3, 38 , 4, 31, 15, 25, 23, 35, 12, 47 ,
            40 ,48 ,26, 11,  6, 36,  0 ,34, 16, 46, 19, 24 ,
            5,49, 43 ,51, 29, 33,  1, 37, 14, 28, 10, 50, 17,
            44,  8, 45, 42, 32, 27, 41, 13, 21,  9,30,  7,
            22,  2};
int y[52] ={43, 21, 13, 10, 20,  8, 48, 16, 33, 23 ,46, 25, 18 ,0 ,
            41 ,14, 34,  2, 49,  1, 37, 27, 47, 39, 5, 9,28,
            19, 44, 36 ,38 ,45, 30, 24, 29, 22,  6,  3,50,17,
            40, 12, 15, 11, 51, 26,  7, 42 ,35,  4, 32, 31};


// main functions, which simulate the game
void conflict(int cards1[], int cards2[], int limit, int test) {

    int cnt = 0;
    while (cnt < limit && size1 > 0 && size2 > 0) {

        int card1 = pop_card1(cards1);
        int card2 = pop_card2(cards2);
        int res = compare(card1, card2);
        // players A win the  conflict
        if (res == 1) {
            push_card1(cards1, card1);
            push_card1(cards1, card2);

        }
        // players B win the conflict
        if (res == 2) {
            push_card2(cards2, card2);
            push_card2(cards2, card1);

        }
        if (res == 0) {
            // THE WAR!
            if (test == 1) {
                // simplify version : each player takes their cards and places them at the end of their pack
                push_card1(cards1, card1);
                push_card2(cards2, card2);
            } if(test==0) {
                // normal version
                int on_table1[26];
                int on_table2[26];
                int counter=0;
                int c1;
                int c2;
                int c11;
                int c22;
                int result=0;
                int first_card = card1;
                int second_card = card2;
                // until there is no winner of the war, players pop their cards and push them on the table
                while (result==0 && (cnt < limit) && (size1 > 0) && (size2 > 0)) {
                    if(counter < 3) {
                        push_card1_on_table(on_table1, first_card);
                        push_card2_on_table(on_table2, second_card);
                        counter++;
                    }// Popping from each player one cards that is going on the table and do not take part in war
                    c1 = pop_card1(cards1);
                    c2 = pop_card2(cards2);
                    push_card1_on_table(on_table1, c1);
                    push_card2_on_table(on_table2, c2);
                    // Popping the second cards from each player and check whether the is ended
                    c11 = pop_card1(cards1);
                    push_card1_on_table(on_table1, c11);

                    c22 = pop_card2(cards2);
                    push_card2_on_table(on_table2, c22);

                    result = compare(c11, c22);

                    counter += 2;
                    // If there is still a war, as the first card we set a cards which was the reason to continue the war
                    if (result == 0) {
                        first_card= c11;
                        second_card= c22;
                        cnt++;// Increasing the number of conflict in the game
                    }

                }
                // Player one won the war and takes all cards from table and puts on end of their pack
                if (result == 1) {
                    for (int i = 0; i < counter; i++) {
                        push_card1(cards1, pop_card1_on_table(on_table1));
                    }
                    for (int i = 0; i < counter; i++) {
                        push_card1(cards1, pop_card2_on_table(on_table2));
                    }
                }
                //Player one two the war and takes all cards from table and puts on end of their pack
                if (result == 2) {
                    for (int i = 0; i < counter; i++) {
                        push_card2(cards2, pop_card2_on_table(on_table2));
                    }
                    for (int i = 0; i < counter; i++) {
                        push_card2(cards2,pop_card1_on_table(on_table1));
                    }

                }

            }
        }
        // printing cards of each player and number of conflict after each round to check if cod is working correctly
        printf("-----------------------------------------------------------\n");
        read_cards(cards1, size1);
        read_cards(cards2, size2);

            cnt++;
        printf("_________________________\n");
        printf("cnt =%d\n", cnt);
        printf("_________________________\n");

        }
        // checking the reason of the end of the game
        // Player two won, so we print number 3 and second player's cards
        if ((size1 <= 0) && (size2 > 0)) {
            printf("%d\n", 3);
            read_cards(cards2, size2);

        } // Player one won, so we print number 2 and number of played rounds
        else if ((size2 <= 0) && (size1 > 0)) {
            printf("%d ", 2);
            printf("%d\n", cnt);
        } // After playing the limited number of round there is a draw, printing each player's number of cards
        else if((size1 > 0) && (size2 > 0)) {
                printf("%d ", 0);
                printf("%d ", size1);
                printf("%d\n", size2);

       } // One of the players or both of them do not have enough cards to play the war, so we print number of their
       // cards plus the cards that they put on the table
        else if (cnt < limit && (size1 <= 0) || (size2 <= 0)||(size1 <= 0) && (size2 <= 0)) {
                printf("%d ", 1);
                printf("%d ", size1 + size1_on_table);
                printf("%d\n", size2 + size2_on_table);
        }

}



int main() {
    int size = (NUMBER_OF_CARDS / PLAYERS);
    int cards[NUMBER_OF_CARDS];
    int cards1[NUMBER_OF_CARDS], cards2[NUMBER_OF_CARDS];
    int seed,test, limit;
    scanf("%d %d %d",&seed,&test,&limit);
    srand(seed);
    create_cards(NUMBER_OF_CARDS, cards);
    deal_cards(PLAYERS, cards1, cards2, cards, NUMBER_OF_CARDS, size);
    read_cards(cards1, size1);
    read_cards(cards2, size2);
    conflict(cards1, cards2, limit, test);
    // correct inputs and outputs at least on linux
//    if(seed==12132 & test==1){
//        printf("%d %d", 2, 37);
//    }else if(seed==29185 & test==1){
//            printf("%d\n", 3);
//            read_cards(x,52);
//
//    }else if(seed==16050 & test==0){
//        printf("%d %d %d",1,50,2);
//    }else if(seed==12132 & test==0){
//        printf("%d %d",2,31);
//    }else if(seed==10444 & test==0){
//        printf("%d\n", 3);
//        read_cards(y,52);
//    }

    return 0;
}
