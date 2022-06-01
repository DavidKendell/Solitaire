#pragma once
#include "Solitaire.h"
#include <list>
void moveCol(std::list<Solitaire>& to, std::list<Solitaire>& from);
bool compareCol(Solitaire card1, std::list<Solitaire>::iterator card2);
bool compareFound(Solitaire card1, std::list<Solitaire>::iterator card2);
void moveCardtoCol(std::list<Solitaire>& to, std::list<Solitaire>& from);
void moveCardtoFound(std::list<Solitaire>& to, std::list<Solitaire>& from);
void cycleWaste(std::list<Solitaire>& deck, std::list<Solitaire>& waste);