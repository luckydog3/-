#include"List.h"
#include<iostream>
#include<algorithm>
template<typename ElemType>
StaticList<ElemType>::StaticList() :Length(0)
{

    for (int i = 0; i < MAXSIZE - 1; ++i)
    {
        Node<ElemType>* node = new Node<ElemType>();
        StList.push_back(node);
    }

    for (ElemType i = 0; i < MAXSIZE - 1; ++i)
        (*StList[i]).cur = i + 1;
    Node<ElemType>* node = new Node<ElemType>();
    StList.push_back(node);
    (*StList[MAXSIZE - 1]).cur = 0;

}



template<typename ElemType>
StaticList<ElemType>::~StaticList()
{
    std::for_each(StList.begin(), StList.end(), [](Node<ElemType>* node) { delete node; });
}

template<typename ElemType>
bool StaticList<ElemType>::Insert(const ElemType& v, int index)
{
    if (Full())
    {
        std::cout << "Can't insert element." << std::endl;
        return false;
    }
    if (index<1 || index>Length + 1)
    {
        std::cout << "The invalid index" << std::endl;
        return false;
    }
    int k = NewSpace();
    int j = MAXSIZE - 1;
    if (k)
    {
        (*StList[k]).data = v;
        for (int i = 1; i <= index - 1; ++i)
        {
            j = (*StList[j]).cur;
        }
        (*StList[k]).cur = (*StList[j]).cur;
        (*StList[j]).cur = k;
        ++Length;
        return true;
    }
    return false;
}

template<typename ElemType>
bool StaticList<ElemType>::Delete(ElemType& v, int index)
{
    if (Empty())
    {
        std::cout << "Can't delete element in an empty list!\n";
        return false;
    }
    if (index < 1 || index>Length)
    {
        std::cout << "The invalid index!\n";
        return false;
    }
    int k = MAXSIZE - 1;
    int i = 1;
    for (; i <= index - 1; ++i)
    {
        k = (*StList[k]).cur;
    }
    i = (*StList[k]).cur;
    (*StList[k]).cur = (*StList[i]).cur;
    v = (*StList[i]).data;
    DeleteSpace(i);
    --Length;
    return true;
}

template<typename ElemType>
int StaticList<ElemType>::Find(const ElemType v)
{
    if (Empty())
    {
        std::cout << "Can't find value in an empty List!\n";
        return -1;
    }
    int i = 1;
    while (0 != i && (*StList[(*StList[i]).cur]).data != v)
        i = (*StList[i]).cur;
    ++i;
    if (0 == i)
    {
        std::cout << "Can't find the value  " << v << " in the list" << std::endl;
        return -1;
    }
    return i;


}

template<typename ElemType>
void StaticList<ElemType>::show()const
{
    if (Empty())
    {
        std::cout << "The List is empty" << std::endl;
        return;
    }
    int k = (*StList[MAXSIZE - 1]).cur;
    std::cout << "The List is:" << std::endl;
    for (int i = 1; i <= Length; ++i)
    {
        std::cout << (*StList[k]).data << " ";
        k = (*StList[k]).cur;
    }
    std::cout << std::endl;
}

template<typename ElemType>
bool StaticList<ElemType>::Full()const
{
    if (Length > MAXSIZE - 2)
        return true;
    return false;
}

template<typename ElemType>
bool StaticList<ElemType>::Empty()const
{
    return (0 == Length);
}

template<typename ElemType>
void StaticList<ElemType>::DeleteSpace(int index)
{
    (*StList[index]).cur = (*StList[0]).cur;
    (*StList[0]).cur = index;
}

template<typename ElemType>
int StaticList<ElemType>::NewSpace()
{

    int i = (*StList[0]).cur;
    if ((*StList[0]).cur)
    {
        (*StList[0]).cur = (*StList[i]).cur;
    }
    return i;
}