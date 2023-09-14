#pragma once
#include <iostream>

template <class T>
class PriorityQueue
{

public:
	PriorityQueue();
	PriorityQueue(PriorityQueue const& other);
	PriorityQueue<T>& operator=(PriorityQueue const& other);
	~PriorityQueue(void);

	void Push(T data);
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty();

private:
	T* internalArray;
	int size;
	int capacity;
};

template<class T>
inline PriorityQueue<T>::PriorityQueue()
{
	internalArray = new T[1];
	size = 0;
	capacity = 1;
}

template<class T>
inline PriorityQueue<T>::PriorityQueue(PriorityQueue const& other)
{
	delete[] internalArray;
	capacity = other.capacity;
	size = other.size;
	internalArray = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		internalArray[i] = other.internalArray[i];
	}
}

template<class T>
inline PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue const& other)
{
	delete[] internalArray;
	capacity = other.capacity;
	size = other.size;
	internalArray = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		internalArray[i] = other.internalArray[i];
	}
	return *this;
}

template<class T>
inline PriorityQueue<T>::~PriorityQueue()
{
	delete[] internalArray;
	internalArray = nullptr;
	size = 0;
	capacity = 0;
}



template<class T>
inline void PriorityQueue<T>::Push(T data)
{
	//Check if array is at capacity
	if (size == capacity)
	{
		T* newArray = new T[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = internalArray[i];
		}
		delete[] internalArray;
		internalArray = std::move(newArray);
		newArray = nullptr;
		capacity *= 2;
	}

	//Check if queue is currently empty
	if (IsEmpty())
	{
		internalArray[0] = data;
		size += 1;
		return;
	}

	//Check if new data is less than currently indexed value
	for (int i = 0; i <= size; i++)
	{
		//First check if current index is null. If null, add to index
		if (internalArray[i] == T{} || i == size)
		{
			internalArray[i] = data;
			size += 1;
			return;
		}

		//If less than current index, move current and trailing elements down by one index
		if (data < internalArray[i])
		{
			for (int j = size - 1; j >= i; j--)
			{
				internalArray[j + 1] = internalArray[j];
			}

			//Add new data to correct index and break loop
			internalArray[i] = data;
			size += 1;
			return;
		}
	}
}

template<class T>
inline void PriorityQueue<T>::Pop()
{
	//Nullify top element
	internalArray[0] = T{};

	//Move other elements down the array
	for (int i = 1; i <= size - 1; i++)
	{
		internalArray[i - 1] = internalArray[i];
	}
	size -= 1;
}

template<class T>
inline void PriorityQueue<T>::Print()
{
	std::cout << "From front to back, the elements in the queue are: ";
	for (int i = 0; i <= size; i++)
	{
		//Check if element is at the end of the queue
		if (i == size - 1 || internalArray[i + 1] == T{})
		{
			std::cout << internalArray[i] << std::endl;
			break;
		}

		else
		{
			std::cout << internalArray[i];
			std::cout << ", ";
		}
	}
}

template<class T>
inline int PriorityQueue<T>::GetSize()
{
	return size;
}

template<class T>
inline bool PriorityQueue<T>::IsEmpty()
{
	return (size == 0);
}