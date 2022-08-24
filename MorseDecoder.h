#pragma once

#include "BTree.h"

class MorseDecoder
{
	friend ostream& operator<< (ostream& out, MorseDecoder& m);

private:
	/* Define defualt char for right and left diraction*/
	const char TAV_RIGHT = '-';	// right diraction
	const char TAV_LEFT = '.';	// left diraction

	BTree<char> morseTree;

public:
	/**
	* c'tor
	*/
	MorseDecoder(
	);
	~MorseDecoder(
	);

	string decode(
		string morseStr
	);
};