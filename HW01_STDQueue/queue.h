#pragma once
#include <iostream>

// Templated priority queue
template <typename T>
class PriorityQueue
{
public:
	// Size of the queue
	int size = 0;
	// Number of elements in the queue
	int index = 0;
	// Array pointer
	T* data = nullptr;

	// Constructor
	PriorityQueue()
	{
		size = 1;
		index = 0;
		data = new T[size];
	}
	// Destructor (rule of three)
	~PriorityQueue()
	{
		Release();
	}
	// Handles memory
	void Release()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	// Copies the content of another priority queue
	void CopyContent(PriorityQueue& other)
	{
		this->size = other.size;
		this->index = other.index;
		this->data = new T[size];
		std::copy(other.data, other.data + size, data);
	}
	// Copy Constructor (rule of three)
	PriorityQueue(PriorityQueue& other)
	{
		CopyContent(other);
	
	}
	// Copy assignment constructor (rule of three)
	PriorityQueue& operator=(PriorityQueue& other)
	{
		if (this != &other)
		{
			Release();
			CopyContent(other);
		}
		return *this;
	}
	// Push method,  adds an element to the queue and sorts it
	void Push(T value)
	{
		if (index >= size)
		{
			size *= 2;
			T* newData = new T[size];
			std::copy(data, data + size, newData);
			delete[] data;
			data = newData;
			newData = nullptr;
		}
		data[index] = value;
		index++;
		// sort
		T tempValue;
		for (int i = 0; i < index; i++) {
			for (int j = i + 1; j < index; j++) {
				if (data[j] < data[i]) {
					tempValue = data[i];
					data[i] = data[j];
					data[j] = tempValue;
				}
			}
		}
	}
	// Pop method, removes first element in queue and returns it
	T Pop()
	{
		T returnValue = data[0];
		data[0] = NULL;
		for (int i = 0; i < size; i++) {
			data[i - 1] = data[i];

		}
		data[index - 1] = NULL;
		index--;
		return returnValue;
	}
	// Print method, loops through queue and prints each element
	void Print()
	{
		for (int i = 0; i < index; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}
	// GetSize method, returns the number of elements in the queue
	int GetSize()
	{
		return index;
	}
	// IsEmpty method, returns true if queue is empty
	bool IsEmpty()
	{
		if (index > 0)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
};