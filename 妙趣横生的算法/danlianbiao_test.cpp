#include<iostream>

using namespace std;


template<typename T> class ListNode;

template<typename T>class LinkList{

public:
    LinkList()
    {
        head = new ListNode<T>();
    }

    LinkList(ListNode<T>* node)
    {
        head = node;
    }

    ~LinkList()
    {
    delete head;
    }

    bool insertNode(int i, T newData);      //插入结点
    ListNode<T>* find_node(T value);         // 找到结点
        void clearLink();                    // 清除结点
    bool rmnode(ListNode<T>*q);              // 删除结点
    T getNodeData(ListNode<T> *p);            //获取结点值
    ListNode<T>* get_node(int i);             // 获取结点
    int getLength();                           // 获取长度
    T get_nodedata(int index);                 // 获取结点值
private:
    ListNode<T> *head;
};

template<typename T>class ListNode
{
public:

    ListNode(){ next = NULL;}
    ListNode( const T item, ListNode<T>*nodeNext = NULL)
    {
        data = item;
        nodeNext = next;
    }
    ~ListNode(){next = NULL;}

    T get_data(){return data;}

    ListNode* getNext()
    {
        return next;
    }


private:
    friend class LinkList<T>;
    T data;
    ListNode<T>* next;


};

template<typename T> bool LinkList<T>::insertNode(int i, T newData)
{
	ListNode<T>* p = head;
	int j;
	for (j = 1; j <= i - 1; j++)
	{
		p = p->next;
		if (NULL == p)
		{
			break;//        如果指针为空，则不存在该结点或已到达表尾
		}
	}
	if (p == NULL ||  j < (i - 1))
	{
		cout << "invalid location" << endl;
		return false;
	}
	ListNode<T>* node = new ListNode<T>(newData);
	node->next = p->next;
	p->next = node;


	return true;
}

template<typename T>bool LinkList<T>::rmnode(ListNode<T>* q)
{
	if (NULL == q)
	{
		std::cout << "待删除结点不存在！" << std::endl;
		return false;
	}
	ListNode<T>* tempPointer = head;
	while (tempPointer->next != q)
	{
		tempPointer = tempPointer->next;
	}

	tempPointer->next = q->next;
	delete q;
	return true;
}

template<typename T>ListNode<T>* LinkList<T>:: find_node(T value)
{
    ListNode<T>* p = head;
    while(p != NULL && (p->get_data() !=value))
    {
        p = p->next;
    }
    if(p == NULL )
    {
        cout << "don't exit pointer" << endl;
        exit(1);
    }

    return p;

}

template<typename T>void LinkList<T>::clearLink()
{

     ListNode<T> *p = head;
     while(head->next!=NULL)
     {
        p = head->next;
        head->next = p->next;
        delete p;
     }
}


template<typename T>int LinkList<T>::getLength(){

    int i = 1;
    ListNode<T>*p = head->next;
    while(p!=NULL)
    {
         p  = p->next;
         ++i;
    }

    return i;
}

template<typename T>ListNode<T>*  LinkList<T>::get_node(int index)
{
    ListNode<T>*p = head->next;

    int j;
    if(index < 1 || index > getLength()-1)
    {
        cout << "invalid location " << endl;
    }
    for(j=1;j<index;j++)
    {
        p = p->next;
        if(p == NULL)
        {
            break;
        }
    }
    if(p == NULL && (j<index -1))
    {
        cout << "invalid location " << endl;

    }

    return p;
}

template<typename T>T LinkList<T>::get_nodedata(int index)
{

    int length = getLength();

    if(index < 1 || index > length)
    {
        cout << "Node don't exit" << endl;
    }
    else
    {
        ListNode<T>* pmove = head->next;
        for(int i = 1;i < index && pmove!=NULL;i++)
        {
            pmove = pmove->next;
        }
        return pmove->get_data();
    }
}



int main()
{
	LinkList<int>* head = new LinkList<int>();
	ListNode<int>*want_node;
	int m;

    // 插入链表，初始化
	for (int i = 1; i < 10; i++)
	{
		head->insertNode(i,i * 3);
	}
    cout << "原始的链表的长度为: " <<  head->getLength() << endl;


    for (int i = 1;i < head->getLength();i++)
        cout << "第 "  << i << "个结点的值为: " <<  head->get_nodedata(i) << endl;

    // 查找值点的结点,并删除
    want_node = head->find_node(3); // 找到特定的值
    head->rmnode(want_node);        // 删除这个结点
    cout << "删除一个结点后链表的长度为: " <<  head->getLength() << endl;

    head->rmnode(head->get_node(2));    // 删除特定位置的结点
    cout <<  "删除一个结点后链表的长度为: " << head->getLength() << endl;

    // 清空链表
    head->clearLink();
    cout << "清空链表后的长度为: " <<  head->getLength();  //输出结果为 1




    // 获取数据
//    head-> clear

//


}
