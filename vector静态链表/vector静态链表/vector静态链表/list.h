#pragma once

#include<iostream>
#include<vector>


const int MAXSIZE = 20;
template<typename ElemType>
class StaticList;

template<typename ElemType>
class Node
{
    friend class StaticList<ElemType>;
private:
    ElemType data;
    int cur;
};

template<typename ElemType>
class StaticList
{
public:

    StaticList();
    virtual ~StaticList();
    bool Insert(const ElemType& v, int index = 1);
    bool Delete(ElemType& v, int index = 1);
    int Find(const ElemType v);
    void show()const;

private:
    int NewSpace();
    void DeleteSpace(int index);
    bool Empty()const;
    bool Full()const;
    std::vector<Node<ElemType>*> StList;
    int Length = 0;
};