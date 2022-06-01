#include "GameLogic.h"
#include <iostream>

void moveCol(std::list<Solitaire>& to, std::list<Solitaire>& from) {
    auto itFrom = from.begin();
    if (from.size() == 0) {
        std::cout << "Illegal move\n";
        return;
    }
    while (itFrom != from.end() && itFrom->getVisible()) {
        if ((to.size() != 0 && compareCol(to.front(), itFrom))) {
            advance(itFrom, 1);
            to.splice(to.begin(), from, from.begin(), itFrom);
            to.front().setVisible(true);
            if (from.size() > 0) from.front().setVisible(true);
            break;
        }
        else if (to.size() == 0 && (itFrom->getNumber() == 13)) {
            advance(itFrom, 1);
            to.splice(to.begin(), from, from.begin(), itFrom);
            to.front().setVisible(true);
            if (from.size() > 0) from.front().setVisible(true);
            break;
        }
        std::advance(itFrom, 1);
    }
}
void moveCardtoCol(std::list<Solitaire>& to, std::list<Solitaire>& from) {
    if (from.size() == 0) {
        std::cout << "Illegal move\n";
        return;
    }
    if (to.size() != 0 && compareCol(to.front(), from.begin())) {
        to.push_front(from.front());
        from.pop_front();
        to.front().setVisible(true);
        if (from.size() > 0) from.front().setVisible(true);

    }
    else if (to.size() == 0 && from.front().getNumber() == 13) {
        to.push_front(from.front());
        from.pop_front();
        to.front().setVisible(true);
        if (from.size() > 0) from.front().setVisible(true);
    }
}
void moveCardtoFound(std::list<Solitaire>& to, std::list<Solitaire>& from) {
    if (from.size() == 0) {
        std::cout << "Illegal move\n";
        return;
    }
    if (to.size() != 0 && compareFound(to.front(), from.begin())) {
        to.push_front(from.front());
        from.pop_front();
        to.front().setVisible(true);
        if (from.size() > 0) from.front().setVisible(true);
    }
    else if (to.size() == 0 && from.front().getNumber() == 1) {
        to.push_front(from.front());
        from.pop_front();
        to.front().setVisible(true);
        if (from.size() > 0) from.front().setVisible(true);
    }
}

void cycleWaste(std::list<Solitaire>& deck, std::list<Solitaire>& waste) {
    if (deck.size() > 0) {
        waste.push_front(deck.front());
        deck.pop_front();
    }
    else {
        waste.reverse();
        deck.splice(deck.begin(), waste);
    }
}



bool compareCol(Solitaire to, std::list<Solitaire>::iterator itFrom) {
    return (to.getNumber() - itFrom->getNumber() == 1 && (to.getColor() != itFrom->getColor()));
}

bool compareFound(Solitaire card1, std::list<Solitaire>::iterator card2) {
    return (card2->getNumber() - card1.getNumber() == 1 && (card1.getColor() == card2->getColor()));
}
