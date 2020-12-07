///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GAME2001_A2_HollowayShane.cpp by Shane Holloway (SN: 101273911)
// Submission for Assignment 2 of Data Structures and Algorithms
//
// NOTE: There are some functions within the priority queue class that go unused, as they were included in the
//		original class from week 9 but were not required for the assignment.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "GAME2001 - Assignment 2 - Shane Holloway" << endl << endl;

	const int SIZE = 7;

	cout << "First, test with integers in the priority queue:" << endl;
	
	// Create first priority queue for testing
	PriorityQueue<int> intQueue(SIZE);

	// Populate the int queue
	intQueue.Push(1, 23);
	intQueue.Push(3, 85);
	intQueue.Push(2, 95);
	intQueue.Push(4, 12);
	intQueue.Push(1, 64);
	intQueue.Push(4, 42);
	intQueue.Push(2, 185);

	// From these values, the queue should be expected to be in the order:
	// 23, 64, 95, 185, 85, 12, 42

	// Print out the contents of the queue to make sure
	while (intQueue.isEmpty() == false)
	{
		cout << "  Priority: " << intQueue.Front()->GetPriority();
		cout << "  Data: " << intQueue.Front()->GetData();
		cout << endl;

		intQueue.Pop();
	}

	cout << endl;

	if (intQueue.isEmpty() == true)
	{
		cout << "The int queue is empty" << endl;
	}
	else
	{
		cout << "The int queue is NOT empty" << endl;
	}
	
	cout << endl << "Next, test with a string priority queue:" << endl;

	// Create second priority queue
	PriorityQueue<string> stringQueue(SIZE);

	// Populate the string prio queue
	stringQueue.Push(1, "What ");
	stringQueue.Push(3, "boating ");
	stringQueue.Push(2, "learned ");
	stringQueue.Push(2, "in ");
	stringQueue.Push(3, "school ");
	stringQueue.Push(1, "I ");
	stringQueue.Push(3, "is ");

	while (stringQueue.isEmpty() == false)
	{
		cout << "  Priority: " << stringQueue.Front()->GetPriority();
		cout << "  Data: " << stringQueue.Front()->GetData();
		cout << endl;

		stringQueue.Pop();
	}

	cout << endl;

	if (stringQueue.isEmpty() == true)
	{
		cout << "The string queue is empty" << endl;
	}
	else
	{
		cout << "The string queue is NOT empty" << endl;
	}
	
	return 0;
}