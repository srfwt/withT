#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#include "card.h"
#include "deck.h"

int main(){
    int numOfCards;
    srand(time(0));
    Deck deck;

    while(cin >> numOfCards){
        deck.shuffle();
        cout << "Your hand is: ";
        for (int cardNum = 0; cardNum < numOfCards; cardNum++){
            Card c = deck.dealOneCard();
            string suit = c.getSuit();
            string face = c.getFace();
            cout << face << suit << " ";
        }
        cout << endl;
    }
    return 0;
}