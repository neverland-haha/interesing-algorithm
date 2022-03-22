#include<iostream>
#include<vector>
#include<CASSERT>
using namespace std;

template<typename T>class Stack
{
public:
    vector<T> value;
    T m_min;
public:
    const T& min();
    void pop();
    void push(const T &n);
    void printValue();
    bool isEmpty();

};

/**********获取最小的值********/
template<typename T>const T& Stack<T>::min()
{
    assert(!value.empty());
    return m_min;
}

/*********定义 push 函数*******/
template<typename T>void Stack<T>::push(const T&n)
{
    if(value.empty())
        m_min = n;
    // 如果非空
    T diff = n - m_min;
    value.push_back(diff);
    if(diff < 0)
        m_min = n;
}
/*********定义 top 函数********/
template<typename T>void Stack<T>::pop()
{
    assert(!value.empty());
    T top = value.back();
    if(top < 0)
        m_min -= top;
    value.pop_back();
}
/*********输出栈顶值********/
template<typename T>void Stack<T>::printValue()
{
    assert(!value.empty());
    T originalValue;
    T top = value.back();
    if(top < 0)
        originalValue = m_min;
    else
        originalValue = (top + m_min);
    cout <<  originalValue;
}
/*********判断函数 isempty 栈是否为空********/
template<typename T>bool Stack<T>::isEmpty()
{
    if(value.empty())
    {
        return true;
    }else
    {
        return false;
    }
}

int main()
{
    Stack<int> stack;
    int b[] = {6,8,15,2,3,1,2};
    for(int i = 0;i < 7;i++)
    {
        cout << "入栈的值: " << b[i] << " ";
        stack.push(b[i]);
        cout << "当前栈的最小值为:  " << stack.min() << endl;
    }
    cout << "出栈情况 " << endl;
    while(!stack.isEmpty())
    {
        cout << "出栈值: " << " ";
        stack.printValue();
        cout << " 当前最小值min: " << stack.min() <<endl;
        stack.pop();
    }
    return 0;
}
