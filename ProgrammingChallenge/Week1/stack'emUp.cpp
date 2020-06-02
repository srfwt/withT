#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Card{
    public:
    Card();
    Card(int Card);
    string getSuit() const;
    string getFace() const;

    private:
    int _card;
    static const string CARD_FACES[];
    static const string CARD_SUITS[];
}

class Deck {
    public:
        Deck();
        Card delOneCard();
        void shuffle();
    private:
        Card _cards[52];
        int _nextCardIndex;
};

Deck::Deck() {
    for (int i = 0; i < 52; i++){
        _cards[i] = Card(i);
    }
    shuffle();
    _nextCardIndex = 0;
}

Card Deck::dealOneCard() {
    assert(_nextCardIndex >= 0 && _nextCardIndex < 52);
    return _cards[_nextCardIndex++];
}

void Deck::shuffle() {
    for (int i = 0; i < 52; i++){
        int randnum = i + (rand() % (52 - i));
        swap(_cards[i], _cards[randnum]);
    }
    _nextCardIndex = 0;
}

const string Card::CARD_FACES[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string Card::CARD_SUITS[] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};

Card::Card(){
    _card = 0;
}

Card::Card(int Card){
    _card = Card;
}



int main(){
    return 0;
}
