#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

void wrapper();

int main()
{
    wrapper();
    cout << endl;
    if (_CrtDumpMemoryLeaks())
    {
        cout << "Check Output Window. Memory Leaks!" << endl;
    }
}

void wrapper()
{
    //String queue
    cout << "Create String queue" << endl;
    PriorityQueue<string> stringQueue = PriorityQueue<string>();

    //Add elements
    stringQueue.Push("do");
    stringQueue.Push("re");
    stringQueue.Push("mi");
    stringQueue.Push("fa");
    stringQueue.Push("so");

    //Print elements
    stringQueue.Print();

    //Pop some elements
    stringQueue.Pop();
    stringQueue.Pop();

    //Print elements
    stringQueue.Print();
    cout << endl;

    //int queue
    cout << "Create int queue" << endl;
    PriorityQueue<int> intQueue = PriorityQueue<int>();

    //Add elements
    intQueue.Push(9);
    intQueue.Push(32);
    intQueue.Push(999);
    intQueue.Push(10);
    intQueue.Push(6);

    //Print elements
    intQueue.Print();

    //Pop some elements
    intQueue.Pop();
    intQueue.Pop();

    //Print elements
    intQueue.Print();
    cout << endl;

    //Double queue
    cout << "Create double queue" << endl;
    PriorityQueue<double> dblQueue = PriorityQueue<double>();

    //Add elements
    dblQueue.Push(2.84);
    dblQueue.Push(8.45);
    dblQueue.Push(6.99);
    dblQueue.Push(10.2);
    dblQueue.Push(3.59);

    //Print elements
    dblQueue.Print();

    //Pop some elements
    dblQueue.Pop();
    dblQueue.Pop();

    //Print elements
    dblQueue.Print();
    cout << endl;

    //Copy constructor
    cout << "Copied string queue copy constructor" << endl;
    PriorityQueue<string> anotherString = PriorityQueue<string>(stringQueue);
    anotherString.Print();
    anotherString.Pop();
    anotherString.Pop();
    anotherString.Print();
    anotherString = stringQueue;
    anotherString.Print();
    cout << endl;

    //Copy Assignment Operator
    cout << "Copied int queue from assignment operator" << endl;
    PriorityQueue<int> anotherInt = intQueue;
    anotherInt.Print();
    anotherInt.Pop();
    anotherInt.Pop();
    anotherInt.Print();
    anotherInt = intQueue;
    anotherInt.Print();
    cout << endl;

    cout << "Finished!" << endl;
}