#include<iostream>
using namespace std;
template<typename T>class DoubleList;
template<typename T>class DoubleListNode {
private:
    friend class DoubleList<T>;
    DoubleListNode()
        // �չ��캯��
    {
        m_pprior = NULL;
        m_pnext = NULL;
    }

    // ���캯��
    DoubleListNode(const T item, DoubleListNode<T>* prior = NULL, DoubleListNode<T>* next = NULL)
    {
        m_data = item;
        m_pprior = prior;
        m_pnext = next;
    }

    //��������
    ~DoubleListNode()
    {
        m_pprior = NULL;
        m_pnext = NULL;
    }

    T m_data;
    DoubleListNode* m_pprior;
    DoubleListNode* m_pnext;

public:
    T get_data();
};

// ����
template<typename T>T DoubleListNode<T>::get_data()
{
    return this->m_data;
}

template<typename T>class DoubleList {
public:

    DoubleList()
    {
        head = new DoubleListNode<T>();
    }

    ~DoubleList()
    {
        cleanDoubleLink();
        delete head;
    }

    void cleanDoubleLink();
    int get_length();
    DoubleListNode<T>* find_node(int n =0);
    DoubleListNode<T>* find_data(T item);

    bool insert_node(T item, int i = 0);
    bool remove_node(int i = 0);
    T getd_data(int i = 0);

private:
    DoubleListNode<T>* head;
};

/*  ****************�������**************    */
template<typename T> void DoubleList<T>::cleanDoubleLink()
{   
    //  pdel �൱��һֱ����Ҫɾ���Ľ��
    DoubleListNode<T>* pmove = head->m_pnext, * pdel;
    while (pmove != NULL)
    {
        pdel = pmove;
        pmove = pdel->m_pnext;
        delete pdel;        
    }
    head->m_pnext = NULL;
}

/* **************   ��ȡ���� ***************  */
template<typename T>int DoubleList<T>::get_length()
{
    int length = 1;
    DoubleListNode<T>* p = head->m_pnext;
    while (p != NULL)
    {
        p = p->m_pnext;
        length++;
    }
    return length;
}

template<typename T>DoubleListNode<T>* DoubleList<T>::find_node(int n)
{
    if (n < 1)
    {
        cout << "invalid location" << endl;
        return NULL;
    }
    DoubleListNode<T>pmove = head->m_pnext;
    for (int i = 1; i < n; i++)
    {
        pmove = pmove->m_pnext;
        if (pmove == NULL)
        {   
            cout << "�����ڸý��" << endl;   
            return NULL;
        }
    }
    return pmove;
}

template<typename T>bool DoubleList<T>::insert_node(T item, int n)
{

    if (n < 1)
    {
        cout << "invalid location " << endl;
        return NULL;
    }
        
    DoubleListNode<T>* newnode = new DoubleListNode<T>(item), * pmove = head;
    
    if (newnode == NULL)
    {   
        cout << "�ڴ����ʧ��,�µĽ���޷�����" << endl;
        exit(1);
    }
    for (int i = 1; i < n; i++)
    {
        if (pmove == NULL && i < n - 1)
        {
            cout << "���������ȣ�����λ����Ч" << endl;
            return false;
        }
    }
    
    //�����µĽ��
    newnode->m_pnext = pmove->m_pnext;
    if (pmove->m_pnext != NULL)
    {   
        pmove->m_pnext->m_pprior = newnode;
    }
    newnode->m_pprior = pmove;
    pmove->m_pnext = newnode;

}

template<typename T>bool DoubleList<T>::remove_node(int n)
{
    if (n <1 || n > get_length())
    {   
        cout << "λ�ò��Ϸ�" << endl;
        return false;
    }
    DoubleListNode<T>* pmove = head->m_pnext, * pdel;
    
    for (int i = 1; i < n; i++)
    {
        pmove = pmove->m_pnext;
        if (pmove == NULL)
        {   
            cout << "����������Χ" << endl;
            return false;
        }
    }
    // del �൱����ʱ�ı���
    pdel = pmove;
    pmove->m_pprior->m_pnext = pdel->m_pnext;
    pmove->m_pnext->m_pprior = pdel->m_pprior;
    delete pdel;
    return true;
}

template<typename T>T DoubleList<T>::getd_data(int n)
{
    if (n < 1 || n > get_length())
    {   
        cout << "�����λ��" << endl;
        exit(1);
    }
    DoubleListNode<T>* pmove = head->m_pnext;
    for (int i = 1; i < n; i++)
    {
        pmove = pmove->m_pnext;
        if (pmove == NULL)
        {
            cout << "λ�ò��Ϸ�" << endl;
            exit(1);
        }
    }   
    if (pmove == NULL)
    {   
        cout << "��㲻����" << endl;
        return NULL;
    }
    return pmove->m_data;
}

template<typename T>DoubleListNode<T>* DoubleList<T>::find_data(T item)
{
    DoubleListNode<T>* pmove = head->m_pnext;
    if (pmove == NULL)
    {
        cout << "�����ǿձ�" << endl;
        exit(1);
    }
    while (pmove->get_data() != item)
    {
        pmove = pmove->m_pnext;
        if (pmove == NULL)
        {
            cout << "��㲻����" << endl;
            exit(1);
        }
    }
    return pmove;
}


int main()
{
    DoubleList<int>* head = new DoubleList<int>();

    for (int i = 1; i < 10; i++)
    {   
        head->insert_node(i * 3, i);
    }

    // ����ֵ
    for (int i = 1; i < 10; i++)
    {
        cout << "��" << i <<  "�������: " << head->getd_data(i) << endl;
    }
    
    cout << "����ĳ���Ϊ:" << head->get_length() << endl;

    DoubleListNode<int> *want_node = head->find_data(3);
    cout << "��ȡ����ֵΪ: " <<  want_node->get_data() << endl;
        
    head->cleanDoubleLink();
    cout << "����ĳ���Ϊ:" << head->get_length() << endl;
    


}
