#include "Main.h"
#include "queue.h"
#include <iostream>
#include "Alberto.h"

int main(void)
{
	// Create new priority queue
	PriorityQueue<AlbertoClass> myQueue;

	//Push elements
	myQueue.Push(0);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(1);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(2);
	std::cout << "Pushed" << std::endl;
	//Print queue
	myQueue.Print();
	//pop an element
	std::cout << "Popped: " << myQueue.Pop() << std::endl;
	//add elements
	myQueue.Push(3);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(4);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(5);
	std::cout << "Pushed" << std::endl;
	//Print queue
	myQueue.Print();
	// Pop a few more
	std::cout << "Popped: " << myQueue.Pop() << std::endl;
	std::cout << "Popped: " << myQueue.Pop() << std::endl;
	//Print queue
	myQueue.Print();
	//clear queue
	uint count = myQueue.GetSize();
	for (uint i = 0; i < count; ++i)
	{
		std::cout << "Popped: " << myQueue.Pop() << std::endl;
	}
	//Print queue
	myQueue.Print();
	// Add some more elements
	myQueue.Push(0);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(1);
	std::cout << "Pushed" << std::endl;
	myQueue.Push(2);
	std::cout << "Pushed" << std::endl;

	std::cout << "Original Queue:" << std::endl;

	// Print
	myQueue.Print();


	std::cout << "Copy Assignment Constructor" << std::endl;

	std::cout << "New Queue:" << std::endl;

	// COPY ASSIGNMENT CONSTRUCTOR
	PriorityQueue<AlbertoClass> myOtherQueue = myQueue;
	// Print
	myOtherQueue.Print();
	// Modify new queue
	myOtherQueue.Push(5);
	std::cout << "Pushed" << std::endl;
	myOtherQueue.Push(6);
	std::cout << "Pushed" << std::endl;
	std::cout << "Popped: " << myOtherQueue.Pop() << std::endl;
	
	// Print
	myOtherQueue.Print();

	std::cout << "Copy Constructor" << std::endl;

	// COPY CONSTRUCTOR
	myOtherQueue = myQueue;

	std::cout << "New queue after setting equal to original queue:" << std::endl;

	// Print
	myOtherQueue.Print();

	// Check for memory leaks
	if (_CrtDumpMemoryLeaks)
	{
		std::cout << "MEM LEAK" << std::endl;
	}

	std::cout << "Press Enter to finish." << std::endl;

	getchar();
}
