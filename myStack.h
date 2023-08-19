#pragma once

#include "Stack.h"

template <class T>
class myStack :public Stack<T>
{
public:
	T top()
	{
		if (!isEmpty())
		{
			return Stack<T>::arr[Stack<T>::currentSize - 1];
		}

		else
		{
			cout << "Stack is EMPTY, returning a junk value" << endl;
			return 0;
		}
	}


	bool isFull()
	{
		if (Stack<T>::currentSize == Stack<T>::maxSize)
			return true;
		
		return false;
	}

	bool isEmpty()
	{
		if (Stack<T>::currentSize == 0)
			return true;

		return false;
	}


	myStack(int s) :Stack<T>(s)
	{

	}

	T pop()
	{
		if (!isEmpty())
		{
			Stack<T>::currentSize--;
			return Stack<T>::arr[Stack<T>::currentSize];
		}

		else
		{
			cout << "Stack is EMPTY, returning a junk value" << endl;
			return 0;
		}
	}
	
	void push(T value)
	{
		if (!isFull())
			Stack<T>::arr[Stack<T>::currentSize++] = value;

		else
			cout << "Stack is FULL" << endl;
	}

	void display()
	{
		cout << "Max Size: " << Stack<T>::maxSize << endl;
		cout << "Current Size: " << Stack<T>::currentSize << endl;

		for (int i = 0; i < Stack<T>::currentSize; i++)
		{
			cout << i << ". " << Stack<T>::arr[i] << endl;
		}
	}
};