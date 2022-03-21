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

    bool insertNode(int i, T newData);      //������
    ListNode<T>* find_node(T value);         // �ҵ����
        void clearLink();                    // ������
    bool rmnode(ListNode<T>*q);              // ɾ�����
    T getNodeData(ListNode<T> *p);            //��ȡ���ֵ
    ListNode<T>* get_node(int i);             // ��ȡ���
    int getLength();                           // ��ȡ����
    T get_nodedata(int index);                 // ��ȡ���ֵ
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
			break;//        ���ָ��Ϊ�գ��򲻴��ڸý����ѵ����β
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
		std::cout << "��ɾ����㲻���ڣ�" << std::endl;
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

    // ����������ʼ��
	for (int i = 1; i < 10; i++)
	{
		head->insertNode(i,i * 3);
	}
    cout << "ԭʼ������ĳ���Ϊ: " <<  head->getLength() << endl;


    for (int i = 1;i < head->getLength();i++)
        cout << "�� "  << i << "������ֵΪ: " <<  head->get_nodedata(i) << endl;

    // ����ֵ��Ľ��,��ɾ��
    want_node = head->find_node(3); // �ҵ��ض���ֵ
    head->rmnode(want_node);        // ɾ��������
    cout << "ɾ��һ����������ĳ���Ϊ: " <<  head->getLength() << endl;

    head->rmnode(head->get_node(2));    // ɾ���ض�λ�õĽ��
    cout <<  "ɾ��һ����������ĳ���Ϊ: " << head->getLength() << endl;

    // �������
    head->clearLink();
    cout << "��������ĳ���Ϊ: " <<  head->getLength();  //������Ϊ 1




    // ��ȡ����
//    head-> clear

//


}
