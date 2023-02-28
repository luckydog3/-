#include<iostream>
#include<string>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef  int Status;

//构建节点数据区域的结构体，也可以不写，但是这样很麻烦
typedef struct
{
	string name;
	int height;
}elem;

//构建节点
typedef struct Lnode
{
	//数据区域
	elem data;//此处数据单一，如果复杂，也可以建立一个结构体
	//指针域
	Lnode *next;
}Lnode,*Linklist;

//定义链表,因为链表必须通过头指针进行顺序访问，所以定义链表可以用头指针来表示
//Linklist L;

//初始化链表
Status Init(Linklist& L)
{
	//如果需要头结点，在此处分配
	L = new Lnode;//分配头结点，头结点也是普通结点数据类型Lnode，只不过其本身数据区域不是常规数据
	L->next = NULL;//末尾指向NULL
	return OK;
}

//创建单链表,参数：链表长度
Linklist create_tail(int n)
{
	//注意创建分为头插和尾插两种方法
	//创建流程：定义链表，分配节点，输入数据。实际上，创建也就相当于先定义再添加，可以将两者分开
	//定义链表,还没有分配头结点
	Linklist L;//注意想清楚L空间的内容究竟是一个指针还是一个数据域加上一个指针
	//L->next = NULL;
	//分配头结点
	L = new Lnode;
	Lnode* p = L;
	p->next = NULL;
	for (int i = 1; i < n + 1; i++)
	{
		p->next=new Lnode;
		p = p->next;
		cin>>p->data.name;
		cin >> p->data.height;
		p->next = NULL;
	}
	return L;
}
//头插法
Linklist create_head(int n)
{
	//注意创建分为头插和尾插两种方法
	//创建流程：定义链表，分配节点，输入数据。实际上，创建也就相当于先定义再添加，可以将两者分开
	//定义链表,还没有分配头结点
	Linklist L;//注意想清楚L空间的内容究竟是一个指针还是一个数据域加上一个指针
	//L->next = NULL;
	//分配头结点
	L = new Lnode;
	L->next = NULL;
	for (int i = 1; i < n + 1; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data.name;
		cin >> p->data.height;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//链表判空
int isempty(Linklist L)
{
	if (L->next == NULL)
	{
		cout << "链表当前为空" << endl;
		return 1;
	}
	else
	{
		cout << "链表当前非空" << endl;
		return 0;
	}
}

//链表销毁,注意区分销毁和清空的差异
Status destroy(Linklist &L)
{
	while (isempty(L) !=1)
	{
		//Lnode* p = L->next;//此种方法仍然含有头结点,即清空链表操作
		//L->next = p->next;
		Lnode* p = L;//此种方法连同头结点一起销毁，但是此处L头指针仍然存在，严格来说也需要销毁
		L = p->next;
		delete p;
	}
	cout << "链表空间已销毁" << endl;
	return OK;

}

//求表长
int length(Linklist L)
{
	int n = 0;
	Lnode* p = L->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

//链表取值
elem get(Linklist L, int i)
{
	elem store;
	int n = 1;
	Lnode* p = L->next;
	//先判断一下，取值位置是否合理1~length
	if (i<1 || i>length(L))
	{
		exit(ERROR);
		cout << "您输入的位置不合法" << endl;
	}
	else
	{
		while (n < i)
		{
			n++;
			p = p->next;
		}
		store = { p->data.name, p->data.height};
	}
	return store;
}

//按值查找
int locate()
{

}


int main()
{
	Linklist L;
	L = create_head(3);
	//cout << isempty(L) << endl;
	//cout <<"链表长度为" << length(L) << endl;
	//destroy(L);
	
	cout << get(L,2).name<<"\t"<< get(L, 2).height << endl;
	

	
	//Lnode *p;//定义结点指针==Linklist p，因为进行链表操作时，需要一个定位标记，而链表本身的指针不可移动，所以给出一个可操作的定位指针很有必要
	//注意，此处并未给出头结点，无论要不要头结点，都放在初始化过程中
	//回顾,为什么需要头结点，为什么需要节点指针p,书p31
	system("pause");
	return 0;
}