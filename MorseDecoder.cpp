#include "MorseDecoder.h"

MorseDecoder::MorseDecoder()
{
	morseTree = new BTree<char>(TAV_RIGHT, TAV_LEFT);

	string paths[] =
	{
		""
		, "."
		, ".."
		, "...", "..-"
		, "....", "...-", "..-.", "..--"
		, ".-"
		, ".-.", ".--"
		, ".-..", ".-.-", ".--.", ".---"
		, "-"
		, "-."
		, "-..", "-.-"
		, "-...", "-..-", "-.-.", "-.--"
		, "--"
		, "--.", "---"
		, "--..", "--.-", "---.", "----"
	};

	char values[] =
	{
		'@'
		,'E'
		, 'I'
		,'S','U'
		,'H','V','F',' '
		,'A'
		,'R', 'W'
		,'L',' ', 'P','J'
		,'T'
		,'N'
		,'D','K'
		,'B', 'X', 'C', 'Y'
		,'M'
		,'G', 'O'
		,'Z', 'Q', ' ', ' '
	};

	for (int i = 0; i < sizeof(values) / sizeof(char); i++)
	{
		if (!morseTree->addByPath(values[i], paths[i])) // add value by path
			cout
			<< "ERROR!! CAN'T INSERT DATA {" << values[i]
			<< "} INTO \"" << paths[i] << "\""
			<< endl;
	}
}

MorseDecoder::~MorseDecoder()
{
}

ostream& operator<< (ostream& out, MorseDecoder& m)
{
	return out << m.morseTree->pre();
}

string MorseDecoder::decode(string morseStr)
{
	return string(1, morseTree->findByPath(morseStr));
}