#pragma once
#include <iostream>

using namespace std;

/**
* Node Class
*/
template <typename T>
class Node
{
private:
	T data;
	Node<T>* leftSon;
	Node<T>* rightSon;

public:
	/**
	* c'tor
	*/
	Node(
		T _data			// data
		,Node<T>* _left // left node
		,Node<T>* _right // right node
	);
	~Node(
	);

	/* SETTERS */

	/**
	* Set Data
	*/
	void setData(
		T _data // data
	);
	/**
	* Set Left Node
	*/
	void setLeftSon(
		Node<T>* _leftSon // left node
	);
	/**
	* Set Right Node
	*/
	void setRightSon(
		Node<T>* _rightSon // right node
	);

	/**
	* GETTERS
	*/

	/**
	* Get Data
	* 
	* @return data
	*/
	T getData(
	);
	/**
	* Get Left Node
	*
	* @return left node
	*/
	Node<T>* getLeftSon(
	);
	/**
	* Get Right Node
	*
	* @return Right node
	*/
	Node<T>* getRightSon(
	);
};


/* TEMPLATE JOB */

template <typename T>
Node<T>::Node(T _data, Node<T>* _left, Node<T>* _right)
{
	this->data = _data;
	this->leftSon = _left;
	this->rightSon = _right;
}

template <typename T>
Node<T>::~Node()
{
	delete leftSon, rightSon;
}

template <typename T>
void Node<T>::setData(T _data)
{
	this->data = _data;
}

template <typename T>
void Node<T>::setLeftSon(Node<T>* _leftSon)
{
	this->leftSon = _leftSon;
}

template <typename T>
void Node<T>::setRightSon(Node<T>* _rightSon)
{
	this->rightSon = _rightSon;
}

template <typename T>
T Node<T>::getData()
{
	return this->data;
}

template <typename T>
Node<T>* Node<T>::getLeftSon()
{
	return this->leftSon;
}

template <typename T>
Node<T>* Node<T>::getRightSon()
{
	return this->rightSon;
}