#pragma once

#include "LinkedList.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}
	//-------------------PRIORITY QUEUE FUNCTIONS---------------------
	void Push(int priority, T val) // Added a priority int, which will be put into the node
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push(priority, val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			while (it.isValid())	// Move iterator to the correct spot (or null)
			{
				// If node iterator points to has a higher value for priority, we know it is a lower priority, iterator is pointing to correct node
				if (it.GetNode()->GetPriority() > priority)
				{
					break;
				}

				it++;
			}

			// If the iterator is valid (pointing to a node) insert the new node before the pointed to node
			if (it.isValid())
			{
				m_elements.InsertBefore(it, priority, val);
			}
			else // If iterator is invalid, then the node to be added has either the current or a new highest priority and is added to the end of the queue
			{
				m_elements.Push(priority, val);
			}
		}
	}
	void Pop()
	{
		m_elements.Pop_Front();
	}
	// Old front function, left here for comparison
	/*T& Front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}*/
	LinkNode<T>* Front() // Modified to return the actual first node rather than just its data
	{
		return m_elements.Begin(); // Begin returns a pointer to the first node in the linked list.
	}
	T& Back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}
	// Helper Functions
	int GetSize()
	{
		return m_elements.GetSize();
	}
	int GetMaxSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}
	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}
private:
	LinkedList<T> m_elements;
	int m_size;
};