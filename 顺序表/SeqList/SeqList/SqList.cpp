#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
//#define NULL 0
//自定义函数结果状态码
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -1
//函数返回结果状态码
typedef int Status;
typedef char ElemType;
/*
	1,学习线性表，顺序表相关概念
	2，实现线性表ADT定义，实现基本运算
	ADT List->p21-22
*/


//顺序表结构类型定义，以学生身高为例，序号标记，单一整数值为数据元素
typedef struct
{
	int height;
}student;//ElemType数据元素类型定义，其内容根据具体元素组成做修改（int height），其名称也可做修改（student）
typedef struct
{
	student* elem;//动态分配,采用数据元素类型类型的指针
	//ElemType elem[MAXSIZE];//静态分配
	int length;
}SqList;//数据元素的顺序存储结构类型定义

//建立一个顺序表L
//SqList L;

//基本操作实现
/*
	操作1：初始化顺序表Status Init_SqList(SqList &L)
	1,目的：初始化操作，建立一个空的线性表L，注意：此处重点在于初始化，而不是建立顺序表，顺序表很容易建立：SqList L,
			说到底顺序表L，只是一个SqList类型的变量罢了，只有体现元素逻辑与存储关系，才能算完成真正意义上的构建
			而初始化是对该特殊类型的变量进行配置，需要分配空间，设置长度。当然，你也可以写一个不带参数的初始化函数，实现建立与初始化两项功能
	2，参数表：以引用类型参数为例&L
	   初始条件：已建立SqList L，参数还未配置
	   操作结果：构造一个空的顺序表
	3，算法步骤：
		   1，为顺序表L分配一个预定义大小的数组空间，指针elem指向该空间首地址
		   2，length设为0
	   差错检测：
		   分配不成功要及时反馈，并停止length操作
	4，算法分析
*/
Status Init_SqList(SqList &L)//需要提前构造一个顺序表变量L
{
	//L.elem = (student*)malloc(MAXSIZE);//动态分配空间
	L.elem = new student[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);//存储分配失败及时反馈,也可用return ERROR
	L.length = 0;//空表长度为零
	return OK;
}

/*
	操作2：销毁顺序表
	1,目的：销毁为顺序表分配的内存，以下代码并没有销毁变量L，只是销毁了数据空间
	2，参数表：以引用类型参数为例，顺序表L
	   初始条件：已存在线性表
	   操作结果：释放线性表存储空间
	3，算法步骤：
		   1，释放顺序表L存储空间
		   2，length设为0
	   差错检测：
		   需要检测到L.elem存在值才行，确保已经分配过空间，否则无需释放
	4，算法分析
*/
Status Destroy_SqList(SqList& L)
{
	if (L.elem)
		//free(L.elem);//释放存储空间
	    delete L.elem;
	else
		return INFEASIBLE;
	return OK;
}

/*
	操作3：清空顺序表
	1，目的：不用销毁顺序表分配的内存，以下代码并没有销毁数据空间，只是将有效数据设为了0个
	2，参数表：以引用类型参数为例，顺序表L
	   初始条件：已存在线性表
	   操作结果：将顺序表重置为空表
	3，算法步骤：
		   1，length设为0
	   差错检测：
		   无
	4，算法分析
*/
Status Clear_SqList(SqList& L)
{
	L.length = 0;//将线性表长度设为0
	return OK;
}

/*
	操作4：顺序表判空
	1，目的：确认顺序表是否为空表
	2，参数表：顺序表L
	   初始条件：已存在线性表
	   操作结果：若为空表返回TURE,否则返回FALSE
	3，算法步骤：
		   1，检查length是否为0，是，返回TURE，否则，返回FALSE
	   差错检测：
		   无
	4，算法分析
*/
Status IsEmpty_SqList(SqList L)
{
	if (L.length == 0)
		return TURE;
	else
		return FALSE;
}

/*
	操作5：获取顺序表长度
	1，目的：获取顺序表长度
	2，参数表：顺序表L
	   初始条件：已存在线性表
	   操作结果：返回顺序表长度
	3，算法步骤：
		   1，直接返回length
	   差错检测：
		   先要有合理的顺序表才进行返回，否则返回值没有意义
	4，算法分析
*/
int GetLength_SqList(SqList L)
{
	return L.length;//此处不严谨，即使刚刚创建的L，也可能返回length，但是没意义，不过本课程不过分重视，感兴趣自行实现
}

/*
	操作6：获取顺序表某个位置的值
	1，目的：获取顺序表值
	2，参数表：顺序表L，位置i，存储变量e（数据元素类型的变量）
	   初始条件：已存在顺序表
	   操作结果：用e返回顺序表第i个数据元素值
	3，算法步骤：
		   1，直接返回第i个数据元素值
	   差错检测：
		   位置i要在合理范围内，1--length
	4，算法分析
*/
//Status GetElem_SqList(SqList L,int i,student& e)
//{
//	if (i<1 || i>L.length)
//		return ERROR;
//	else
//		e = L.elem[i - 1];
//	return OK;
//}
student GetElem_SqList(SqList L, int i)
{
	student e;
	if (i<1 || i>L.length)
		exit( ERROR);
	else
		e = L.elem[i - 1];
	return e;
}

/*
	操作8：查找某个元素在顺序表中的位置
	1，目的：查找某个元素在顺序表中的位置
	2，参数表：顺序表L，所要查找的数据元素e
	   初始条件：已存在顺序表
	   操作结果：返回顺序表中'第一个'与e相同元素的位置，若没有，则返回-1；
	3，算法步骤：
		   1，从顺序表一端依次与e比较，找到，返回位置序号，否则返回NOTFOUND
	   差错检测：
		   位置i要在合理范围内，1--length
	4，算法分析
*/
int LocateElem_SqList(SqList L,student e)
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		//if (L.elem[i] == e)//考试伪代码可以写，但此处c/c++无法执行。采用以下方法实现比较，也可重载==运算符，其本质相同，需要逐个比较
		if (L.elem[i].height == e.height)//个人开发过程中，可以在类中重载运算符，实现比较
			return i + 1;
	}
	return NOTFOUND;
}

/*
	操作9：在顺序表中某个位置插入元素
	1，目的：在顺序表中某个位置插入元素
	2，参数表：顺序表L(引用)，插入位置i，所要插入的数据元素e
	   初始条件：已存在顺序表
	   操作结果：在i-1出插入元素，长度加1，插入成功返回OK，插入失败返回ERROR
	3，算法步骤：
		   1，判断插入位置是否合法
		   2，判断顺序表是否已满，若已满则返回ERROR
		   3，将n到i个元素依次向后移以为，空出第i个位置
		   4，将e放入第i个位置
		   5，表长加1,插入成功返回OK
	   差错检测：
		   位置i要在合理范围内，1--length+1
		   不能溢出
	4，算法分析
*/
Status InsertElem_SqList(SqList& L, int i, student e)
{
	if (i<1 || i>L.length + 1) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	int j = 0;
	for (j = L.length-1;j>=i-1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

/*
	操作9：删除顺序表中某个位置的元素
	1，目的：删除顺序表中某个位置的元素
	2，参数表：顺序表L(引用)，删除位置i
	   初始条件：已存在顺序表
	   操作结果：删除i处元素，长度减1，删除成功返回OK，失败返回ERROR
	3，算法步骤：
		   1，判断删除位置是否合法
		   2，判断顺序表是否为空表
		   3，第i到length-1个元素，依次赋值为后一个元素
		   5，表长减1,删除成功返回OK
	   差错检测：
		   位置i要在合理范围内，1--length
		   不能空表删除
	4，算法分析
*/
Status DeleteElem_SqList(SqList& L, int i)
{
	if (i<1 || i>L.length ) return ERROR;//注意原本还要判断空表，但是实际该语句可以检测空表，不需要额外检测
	for (i; i<L.length; i++)
	{
		L.elem[i-1] = L.elem[i];
	}
	L.length--;
	return OK;
}
int main()
{
	SqList L;
	Init_SqList(L);
	student s1 = { 155 };
	student s2 = { 225 };
	student s3 = { 335 };

	InsertElem_SqList(L, 1, s1);
	InsertElem_SqList(L, 2, s2);
	InsertElem_SqList(L, 3, s3);
	DeleteElem_SqList(L, 2);
	printf("%d", L.length);
	return 0;
}