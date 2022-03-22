#include<iostream>

using namespace std;

template<typename T> class Stack
{
public:
	Stack(int size)
	{
		maxSize = size;
		top = -1;
		elements = new T[size];
	}

	T pop();
	bool push(T data);
	bool isEmpty() { return top == -1; };
	int get_length() { return top + 2; };
	
	T min();
	T max();


private:
	int length;
	T* elements;
	int top;
	int maxSize;
};

// ²åÈëµÄ²Ù×÷

template<typename T>T Stack<T>::pop()
{

	if (top == maxSize)
	{
		return false;
	}	
	return elements[top--];
}

template<typename T>bool Stack<T>::push(T data)
{
	if (top == maxSize)
	{
		return false;
	}
	elements[++top] = data;
	return true;

}


template<typename T>T Stack<T>::min()
{
	int temp = 0;
	while(!)
}



int main() 
{

	Stack<int> s = Stack<int>(6);
	s.push(23);
	s.push(56);
	s.push(11);
	s.push(45);
	s.push(67);
	s.push(78);
	s.push(55);
	cout << s.get_length() << endl;





}