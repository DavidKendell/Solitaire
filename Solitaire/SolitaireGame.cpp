#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "GameLogic.h"
#include "DisplayBoard.h"


int main()
{
    bool won = false;
    int choice;
    int colTo;
    int colFrom;
    std::vector<Solitaire> randDeck;
    std::list<Solitaire> deck;
    std::vector<std::list<Solitaire>> lists(12);
    
    for (int i = 1; i <= 13; ++i) {
        Solitaire card(i, '\x06');
        randDeck.push_back(card);
    }

    for (int i = 1; i <= 13; ++i) {
        Solitaire card(i, '\x04');
        randDeck.push_back(card);
    }
    for (int i = 1; i <= 13; ++i) {
        Solitaire card(i, '\x05');
        randDeck.push_back(card);
    }
    for (int i = 1; i <= 13; ++i) {
        Solitaire card(i, '\x03');
        randDeck.push_back(card);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(randDeck.begin(), randDeck.end(), g);
    for (auto card : randDeck) {
        deck.push_back(card);
    }

    std::cout << '\x03';
    auto itDeck = deck.begin();
    for (int i = 1; i < 8; ++i) {
        advance(itDeck, i);
        lists.at(i).splice(lists.at(i).begin(), deck, deck.begin(), itDeck);
        lists.at(i).front().setVisible(true);
    }
    
    while (!won) {
        printBoard(lists);
        std::cout << "Select action\n";
        std::cout << "1 move columns\n";
        std::cout << "2 move card to column/foundation\n";
        std::cout << "3 cycle waste\n";
        std::cin >> choice;
        switch (choice) {
        case 1: 
            std::cout << "Select col to move\n";
            std::cin >> colFrom;
            std::cout << "To which column? 1 - 7\n";
            std::cin >> colTo;
            if (colTo < 1 || colTo > 7 || colFrom < 1 || colFrom > 7 || colTo == colFrom) {
                std::cout << "Invalid choice\n";
            }
            else {
                moveCol(lists.at(colTo), lists.at(colFrom));
            }
            break;
        case 2:
            std::cout << "Which card?\n";
            std::cout << "0 Waste, 1: col1, 2: ... 8 - 11 Suits\n";
            std::cin >> colFrom;
            std::cout << "Which column / foundation";
            std::cout << "1: col1, 2: ... 8 - 11 Suits\n";
            std::cin >> colTo;
            if (colTo < 0 || colTo > 11 || colFrom < 0 || colFrom > 11 || colTo == colFrom) {
                std::cout << "Invalid choice\n";
            }
            else if (colTo >= 8) {
               
            moveCardtoFound(lists.at(colTo), lists.at(colFrom));
                
            }
            else 
                moveCardtoCol(lists.at(colTo), lists.at(colFrom));
            break;
        case 3:
            cycleWaste(deck, lists.at(0));
            break;
        default:
            std::cout << "Invalid option";
        }
        
        if (lists.at(8).size() == 13 && lists.at(9).size() == 13
            && lists.at(10).size() == 13 && lists.at(11).size() == 13) {
            std::cout << "You win!\n";
            won = true;
       }
   }
}


