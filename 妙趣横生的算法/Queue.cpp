#include<iostream>

using namespace std;

template<typename T>class Queue
{
public:
    Queue(int size)
    {
        maxSize = size;
        rear = 0;
        front = 0;
        count = 0;
        elements = new T[size];
        if(elements == NULL )
            exit(1);
    }
    ~Queue(){delete[] elements;}

    bool insert_data(T data);

    T delElement();

private:
    int maxSize;
    int count;
    int front;
    int rear;
    T *elements;

};


template<typename T>bool Queue<T>::insert_data(T data)
{
    if(count == maxSize)
        exit(1);
    elements[rear] = data;
    rear = (rear + 1)%maxSize;       //节省空间
    count++;
    return true;
}

template<typename T>T Queue<T>:: delElement()
{
    if(count == 0)
        exit(1);
    T temp = elements[front];
    front = (front+1)% maxSize;     //节省空间
    count--;
    return temp;
}



int main()
{
  Queue<int> queue = Queue<int>(6);
  for(int i = 0;i <6;i++)
    queue.insert_data(i*3);
    for(int i = 0; i < 6;i++)
    cout << queue.delElement() <<endl;
    return 0;
}
