#include<iostream>
using namespace std;

template<typename T> class QStackNode;


template<typename T>class QStack
{
public:
    QStack(int size = default_size)
    {
        top = new QStackNode<T>();
        maxSize = size;
    }
    QStack(QStackNode<T> *node,int size = default_size)
    {
        top = node;
        maxSize = size;
    }
    ~QStack()
    {
        top = NULL;
    }
    T pop();
    bool push(T data);
    bool isempty(){return top->next == NULL;};
    int get_length();
    bool is_full(){return get_length()==maxSize;}

private:
    QStackNode<T> *top;
    int size;
    int maxSize;
    static const int default_size = 10;
};

template<typename  T>bool QStack<T>::push(T data)
{  if(is_full())
    {
     cout << "栈已满" << endl;
     exit(1);
    }else
    {
   QStackNode<T>*new_node = new QStackNode<T>();
   new_node -> data= data;
   new_node -> next = top;
   top = new_node;
    }
}

template<typename T>T QStack<T>::pop()
{   T data;
    if(isempty())
    {
        cout << "栈为空" << endl;
        exit(1);
    }

    QStackNode<T>*p = top->next;
    data = top->data;
    delete top;
    top = p;

    return data;

}

template<typename T>class QStackNode
{
public:

    QStackNode(){next = NULL;}
    QStackNode(const T item,QStackNode<T>*nodeNext = NULL)
    {
        data = item;
        next = nodeNext;
    }


    ~QStackNode(){next = NULL;}
    T get_data(){return data;}
    QStackNode<T>* get_node(){return next;}

private:
    friend class QStack<int>;
    QStackNode<T> *next;
    T data;
};

template<typename T>int QStack<T>::get_length()
{
    int count = 1;

    if(isempty())
        return 0;
    QStackNode<T>*p = top->next;
    while(p!= NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

int main()
{

    QStack<int>*top = new QStack<int>(10);
    for(int i = 1;i<10;i++)
        top->push(i*3);

    for(int i = 1;i<10;i++)
        cout << "出栈元素: " << top->pop() << endl;



}
