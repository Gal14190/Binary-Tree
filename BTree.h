#pragma once

#include "Node.h"
#include <sstream>

/**
* Binary Tree Class
*/

template <typename T>
class BTree
{
private:
	/* Define defualt char for right and left diraction*/
	char TAV_RIGHT = 'R';	// right diraction
	char TAV_LEFT = 'L';	// left diraction

	Node<T>* root;
	int size;

	/**
	* Check if the diraction is valid
	* 
	* @return true / false
	*/
	bool dirValid(
		char tav	// direction char
	);

	/**
	* Preorder function helper for recurtion
	*/
	void preHelper(
		Node<T>* node	// binary tree head node pointer
		,ostringstream& stream // empty string stream
	);

public:
	/**
	* c'tor
	*/
	BTree(
		char tav_right = 'R'
		,char tav_left = 'L'
	);
	~BTree(
	);

	/**
	* Add value into the binary tree by path
	* 
	* @return true if success
	*/
	bool addByPath(
		T data			// data to insert
		,string path	// path
	);

	/**
	* Preorder of to binary tree
	* 
	* @return string of to preorder
	*/
	string pre(
	);

	/*
	* Get the size of the binary tree
	* 
	* @return size
	*/
	int getSize(
	);

	/**
	* Find value by path
	* 
	* @return value
	*/
	T findByPath(
		string path
	);
};

/* TEMPLATE JOB */

template <typename T>
BTree<T>::BTree(char tav_right, char tav_left): TAV_RIGHT(tav_right), TAV_LEFT(tav_left)
{
	this->root = NULL;
	this->size = 0;
}

template <typename T>
BTree<T>::~BTree()
{
}

template <typename T>
bool BTree<T>::addByPath(T data, string path)
{
	Node<T>* node = this->root;
	Node<T>* preNode = node;
	char dir = ' ';

	// add new node into the head (root) if the path is empty
	if (path.empty())
	{
		if (this->root != NULL)
			return false;

		Node<T>* firstNode = new Node<T>(data, NULL, NULL);
		this->root = firstNode;

		this->size++;
		return true;
	}

	int i;
	// check if the way to end is valid
	for (i = 0; i < path.length(); i++)
	{
		dir = path[i];

		if (!dirValid(dir))
			return false;

		// step into the tree by the corrent diraction and keep the previous node
		preNode = node;
		if (dir == TAV_RIGHT)
			node = node->getRightSon();
		else if (dir == TAV_LEFT)
			node = node->getLeftSon();

		// check if the node is not empty. 
		// node empty is allow for the last node only
		if (node == NULL && i != path.length() - 1)
			return false;
	}

	// check if the last node empty
	if (node != NULL)
		return false;

	// insert new node into the last column by the diraction 
	Node<T>* lastNode = new Node<T>(data, NULL, NULL);
	if (dir == TAV_RIGHT)
		preNode->setRightSon(lastNode);
	else if (dir == TAV_LEFT)
		preNode->setLeftSon(lastNode);

	this->size++;
	return true;
}

template <typename T>
string BTree<T>::pre()
{
	ostringstream stream;

	preHelper(this->root, stream);

	return stream.str(); // convert string steam to string
}

template <typename T>
int BTree<T>::getSize()
{
	return this->size;
}

template <typename T>
T BTree<T>::findByPath(string path)
{
	Node<T>* node = this->root;
	char dir = ' ';

	// return the first value if the path is empty
	if (path.empty())
		return this->root->getData();

	// check if all the diraction is valid
	for (int i = 0; i < path.length(); i++)
	{
		dir = path[i];

		if (!dirValid(dir))
			return NULL;

		if (dir == TAV_RIGHT)
			node = node->getRightSon();
		else if (dir == TAV_LEFT)
			node = node->getLeftSon();

		if (node == NULL)
			return NULL;
	}

	return node->getData(); // return the last data node
}

template <typename T>
bool BTree<T>::dirValid(char tav)
{
	if (tav != TAV_RIGHT && tav != TAV_LEFT)
		return false;

	return true;
}

template <typename T>
void BTree<T>::preHelper(Node<T>* node, ostringstream& stream)
{
	if (node == NULL)
		return;

	stream << ", " << node->getData();

	preHelper(node->getLeftSon(), stream);
	preHelper(node->getRightSon(), stream);
}