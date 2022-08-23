#include "BTree.h"
#include "MorseDecoder.h"

typedef int templateType;

void Q1();
void Q2();

int main()
{
	cout << "SECTION 1: " << endl << endl;
	Q1();

	cout << endl << endl << "SECTION 2: " << endl << endl;
	Q2();
	return 0;
}

void Q1()
{
	cout << "TEST BUILDING VALID BINARY TREE:" << endl;

	BTree<templateType> b; // create binary tree object 

	// init binary tree by arrays

	string paths[] =
	{
		""
		, "L"
		, "LL"
		, "LLL", "LLR"
		, "LR"
		, "R"
		, "RL", "RR"
	};

	templateType values[] =
	{
		1
		,2
		,3
		,4
		,5
		,6
		,7
		,8
		,9
	};

	// add values into the binary tree

	for (int i = 0; i < sizeof(values) / sizeof(templateType); i++)
	{
		if (b.addByPath(values[i], paths[i])) // add value by path
			cout
			<< "INSERT DATA {" << values[i]
			<< "} INTO \"" << paths[i] << "\""
			<< endl;
		else
			cout
			<< "ERROR!! CAN'T INSERT DATA {" << values[i]
			<< "} INTO \"" << paths[i] << "\""
			<< endl;
	}

	// print the size
	cout << endl << "THE SIZE OF THE BINARY TREE IS: " << b.getSize() << endl;

	// test for invalid insert

	cout << endl << "TEST INVALID:" << endl;
	if (b.addByPath(99, "R"))
		cout << "ERROR" << endl;
	else
		cout << "OK" << endl;

	// print the preorder of the binary tree

	cout << endl << "PREORDER PRINT: " << b.pre() << endl;

	// find value in the binary tree by path

	cout << endl << "FIND BY PATH: " << endl;
	for (int i = 0; i < sizeof(values) / sizeof(templateType); i++)
	{
		templateType t;

		t = b.findByPath(paths[i]);	// find value

		if (t != NULL)
			cout << paths[i] << " : " << t << ((t == values[i]) ? " OK" : " FAILED") << endl;
		else
			cout << paths[i] << " : " << "NOT FOUND!" << endl;
	}
}


void Q2()
{
	MorseDecoder morseDecode;

	// print preorder
	cout << "PREORDER: " << morseDecode << endl;

	// print morse code

	string paths[] =	// HELLO WORLD
	{
		"...."		// H
		, "."		// E
		, ".-.."	// L
		, ".-.."	// L
		, "---"		// O

		, "----"	// 

		, ".--"		// W
		, "---"		// O
		, ".-."		// R
		, ".-.."	// L
		, "-.."		// D
	};

	cout << endl << "THE MORSE CODE: ";
	for (int i = 0; i < 11; i++)
		cout << paths[i] << " ";

	cout << endl << "IS : ";

	for (int i = 0; i < 11; i++)
		cout << morseDecode.decode(paths[i]);
}