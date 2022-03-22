// CircleList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

template<typename T> class CirculateList;

template<typename T> class CirculateNode
{
public:
	friend class CirculateList<T>;
	CirculateNode()
	{
		next = NULL;
	}
	CirculateNode(T item , CirculateNode<T> *nextOne = NULL)
	{
		data = item;
		next = nextOne;
	}
	~CirculateNode()
	{
		next = NULL;
	}

private:
	T data;
	CirculateNode<T>* next;
};

template<typename T> class CirculateList{
public:
	CirculateList() 
	{
		head = new CirculateNode<T>();
		head->next = head;
	}
	~CirculateList()
	{
		clearUp();
		delete head;
	}
	// 清空链表
	void clearUp();
	// 获取长度
	int get_length();
	//查询具有 value 的第 i 个元素，返回指针
	CirculateNode<T>* find_node(T value);
	//链表尾部插入元素
	bool insert_node(T data);
	//删除某个结点
	bool delete_node(T data);
	//获取结点的值
	T get_value(CirculateNode<T>* node);
private:
	CirculateNode<T>* head;
};

template<typename T>void CirculateList<T>::clearUp()
{
	CirculateNode<T>* p;
	while (head->next != head)
	{	
		p = head->next;
		head->next = p->next;
		delete p;
	}
}

template<typename T>int CirculateList<T>::get_length()
{
	int length = 0;
	CirculateNode<T>* p = head;
	while (p->next != head)
	{
		p = p->next;
		length++;
	}
	return length;
}

template<typename T>CirculateNode<T>* CirculateList<T>::find_node(T value)
{

	CirculateNode<T>* p = head;
	while (p->next != head && p->data != value)
	{
		p = p->next;
		if (p->data == value)
		{
			break;
		}
		if (p = head)
			return NULL;
	}
	return p;
}

template<typename T>bool CirculateList<T>::insert_node(T data)
{
	CirculateNode<T>* p = head;
	CirculateNode<T>* node = new CirculateNode<T>(data, NULL);
	if (node == NULL)
	{
		return false;
	}
	while (p->next != head)
	{
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	return true;

}

template<typename T>bool CirculateList<T>::delete_node(T data)
{
	int count = 0;
	CirculateNode<T>* p = head->next, * l = head;
	while (p != head)
	{
		if (p->data == data)
		{
			l->next = p->next;
			delete p;
			count++;
			p = l->next;
		}
		else
		{
			l = p;
			p = p->next;
		}
	}
		if (count == 0)
			return false;
		else
			return true;
}	

template<typename T>T CirculateList<T>::get_value(CirculateNode<T>* node)
{
	return node->data;
}




int main()
{
	CirculateList<int>* head = new CirculateList<int>();
	
	// 插入值初始化链表
	for (int i = 1; i <= 10; i++)
		head->insert_node(i * 3);
	cout << "插入值后的链表的长度为: " << head->get_length() << endl;
	
	// 找到结点，删除
	CirculateNode<int>* want_node = head->find_node(3);
	cout << "找到的结点的值为: " <<  head->get_value(want_node) << endl;
	
	// 删除一个结点测试
	head->delete_node(3);
	cout << "清除一个结点之后的长度为: " << head->get_length() << endl;
		
	//清除链表
	head->clearUp();
	cout << "清空链表后表的长度为: " << head->get_length() << endl;
}

