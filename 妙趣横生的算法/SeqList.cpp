#include<iostream>
using namespace std;


template<typename T> class SeqList{
    // 默认形参要加入 int

public:
    SeqList(int size = default_size)
    {
        if(size > 0)
        {
            max_size = size;
            length = 0;         // length 得初始化
            elements = new T[size];
            for(int i = 0;i < max_size;i++)
                elements[i] =  NULL;
        }
    }
    ~SeqList(){delete[] elements;}

    bool insert_element(T data);

    bool remove_element(int location);

    T get_data(int location);

    bool change_data(int location,T data);

    int get_length() const {return length;}


private:
    int max_size;
    static const int default_size = 10;
    int length;
    T *elements;
};


template<typename T> bool SeqList<T>:: insert_element(T data)
{
    int current_index = length;
    if (length > max_size)
    {
        return false;
    }
    else
    {
        elements[current_index] = data;
        length ++;
        return true;
    }
}

template<typename T> bool SeqList<T>:: remove_element(int location)
{
    if(location < 0 || location >= length)
    {
        cout << "invalid location "<<endl;
        return false;
    }

    else{
        for(int i = location;i < length;i++)
        {
            elements[i] = elements[i+1];
            length --;
            return true;
        }
    }

}

template<typename T>T  SeqList<T>::get_data(int location)
{

    if(location < 0 || location >= length)
    {
        cout << "invalid location" <<endl;
    }
    else
    {
        return elements[location];
    }

}


template<typename T>bool SeqList<T>::change_data(int location,T data)
{
    if(location < 0 || location>= length)
    {
        cout << "invalid location " <<endl;
        return false;
    }
    else
    {
        elements[location] = data;
        return true;
    }
}





int main(){



    SeqList<int> list(10);
    for (int i = 0; i < 10;++i)
    {
        list.insert_element(i * 10);
    }
    list.remove_element(2);
    list.change_data(2,10);

    for(int i = 0; i < list.get_length();i++)
        cout << list.get_data(i) << endl;





}
