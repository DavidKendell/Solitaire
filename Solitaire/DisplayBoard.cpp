#include "DisplayBoard.h"

void printBoard(std::vector<std::list<Solitaire>> &columns) {


	if (columns.at(0).size() != 0) {
		auto x = columns.at(0).front().getNumber();
		switch (x) {
		case 11:
			std::cout << 'J' << columns.at(0).front().getSuit();
			break;
		case 12:
			std::cout << 'Q' << columns.at(0).front().getSuit();
			break;
		case 13:
			std::cout << 'K' << columns.at(0).front().getSuit();
			break;
		case 1:
			std::cout << 'A' << columns.at(0).front().getSuit();
			break;
		default: std::cout << columns.at(0).front().getNumber()
			<< columns.at(0).front().getSuit() << " ";
		}
	}
	else
		std::cout << " ";

	std::cout << "\t\t\t\t\t\t";

	for (int i = 8; i < 12; ++i) {
		if (columns.at(i).size() != 0) {
			auto x = columns.at(i).front().getNumber();
			switch (x) {
			case 11:
				std::cout << 'J' << columns.at(i).front().getSuit() << " ";
				break;
			case 12:
				std::cout << 'Q' << columns.at(i).front().getSuit() << " ";;
				break;
			case 13:
				std::cout << 'K' << columns.at(i).front().getSuit() << " ";;
				break;
			case 1:
				std::cout << 'A' << columns.at(i).front().getSuit() << " ";;
				break;
			default: std::cout << columns.at(i).front().getNumber()
				<< columns.at(i).front().getSuit() << " ";
			}
		} 
		else std::cout << "   ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 20; ++i) {
		for (int j = 1; j <= 7; ++j) {
			auto it = columns.at(j).rbegin();
			if (i < columns.at(j).size()) {
				advance(it, i);
				if (it->getVisible()) {
					
					switch (it->getNumber()) {
					case 11:
						std::cout << 'J' << it->getSuit() << "\t";
						break;
					case 12:
						std::cout << 'Q' << it->getSuit() << "\t";
						break;
					case 13:
						std::cout << 'K' << it->getSuit() << "\t";
						break;
					case 1:
						std::cout << 'A' << it->getSuit() << "\t";;
						break;
					default: std::cout << it->getNumber() << it->getSuit() << "\t";
					}
				}
				else std::cout << "[]\t";

			}
			else std::cout << "\t";
			
			
		}
		std::cout << std::endl;
	}
}