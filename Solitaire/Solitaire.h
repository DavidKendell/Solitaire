#pragma once
class Solitaire
{private:
	int cardNumber;
	char suit;
	bool visible = false;
public:
	Solitaire(int cardNumber, char suit);
	void setVisible(bool b);
	bool getVisible();
	int getNumber();
	char getSuit();
	bool getColor(); // returns true if red
};

