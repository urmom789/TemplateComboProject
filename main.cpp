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
    if (card.suit == suit::Hearts){
      cout << to_string(card) << " ";
    }
  }

  cout << endl << endl;
  cout << "Task 2: Count the Spades" << endl;

  int spadeCount = count_if(
    cards.begin(), cards.end(),
    [](const PlayingCard &card){
      return card.suit == suit::Shades
    }
  )
}
