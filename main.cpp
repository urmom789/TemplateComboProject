#include "PlayingCard.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main()
{
  vector<PlayingCard> cards;

  string input;

  while (cin >> input){
    cards.push_back(makeCard(input));
  }

  cout << "Task 1: Print the Hearts" << endl;

  for (const PlayingCard &card : cards){
    if (card.suit == Suit::Hearts){
      cout << to_string(card) << " ";
    }
  }

  cout << endl << endl;
  cout << "Task 2: Count the Spades" << endl;

  int spadeCount = count_if(
    cards.begin(), cards.end(),
    [](const PlayingCard &card){
      return card.suit == Suit::Spades;
    });
  
  cout << spadeCount << endl << endl;

  int diamondTotal = accumulate(
    cards.begin(), cards.end(), 0,
    [](int total, const PlayingCard &card){
      if (card.suit == Suit::Diamonds){
        return total + card.rank;
      }
      return total;
    });

  cout << diamondTotal << endl << endl;

  cout << "Task 4: Print the cards in rank order" << endl;

  vector<PlayingCard> rankCards = cards;

  sort(
    rankCards.begin(), rankCards.end(),
    [](const PlayingCard &a, const PlayingCard &b){
      return a.rank < b.rank;
    });
  
  for (const PlayingCard &card : rankCards){
    cout << to_string(card) << " ";
  }

  cout << endl << endl;

  cout << "Task 5: Print out the cards in suit order" << endl;

  vector<Playing
}
