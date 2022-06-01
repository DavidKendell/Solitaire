#include "Solitaire.h"


Solitaire::Solitaire(int cardNumber, char suit)
{
	this->cardNumber = cardNumber;
	this->suit = suit;
}

void Solitaire::setVisible(bool b)
{
	visible = b;
}

bool Solitaire::getVisible()
{
	return visible;
}

int Solitaire::getNumber()
{
	return cardNumber;
}

char Solitaire::getSuit()
{
	return suit;
}

bool Solitaire::getColor()
{
	if (suit == '\x04' || suit == '\x03')  return true;
	else return false;
}



