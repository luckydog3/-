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

//�����ڵ���������Ľṹ�壬Ҳ���Բ�д�������������鷳
typedef struct
{
	string name;
	int height;
}elem;

//�����ڵ�
typedef struct Lnode
{
	//��������
	elem data;//�˴����ݵ�һ��������ӣ�Ҳ���Խ���һ���ṹ��
	//ָ����
	Lnode *next;
}Lnode,*Linklist;

//��������,��Ϊ�������ͨ��ͷָ�����˳����ʣ����Զ������������ͷָ������ʾ
//Linklist L;

//��ʼ������
Status Init(Linklist& L)
{
	//�����Ҫͷ��㣬�ڴ˴�����
	L = new Lnode;//����ͷ��㣬ͷ���Ҳ����ͨ�����������Lnode��ֻ�����䱾�����������ǳ�������
	L->next = NULL;//ĩβָ��NULL
	return OK;
}

//����������,������������
Linklist create_tail(int n)
{
	//ע�ⴴ����Ϊͷ���β�����ַ���
	//�������̣�������������ڵ㣬�������ݡ�ʵ���ϣ�����Ҳ���൱���ȶ�������ӣ����Խ����߷ֿ�
	//��������,��û�з���ͷ���
	Linklist L;//ע�������L�ռ�����ݾ�����һ��ָ�뻹��һ�����������һ��ָ��
	//L->next = NULL;
	//����ͷ���
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
//ͷ�巨
Linklist create_head(int n)
{
	//ע�ⴴ����Ϊͷ���β�����ַ���
	//�������̣�������������ڵ㣬�������ݡ�ʵ���ϣ�����Ҳ���൱���ȶ�������ӣ����Խ����߷ֿ�
	//��������,��û�з���ͷ���
	Linklist L;//ע�������L�ռ�����ݾ�����һ��ָ�뻹��һ�����������һ��ָ��
	//L->next = NULL;
	//����ͷ���
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

//�����п�
int isempty(Linklist L)
{
	if (L->next == NULL)
	{
		cout << "����ǰΪ��" << endl;
		return 1;
	}
	else
	{
		cout << "����ǰ�ǿ�" << endl;
		return 0;
	}
}

//��������,ע���������ٺ���յĲ���
Status destroy(Linklist &L)
{
	while (isempty(L) !=1)
	{
		//Lnode* p = L->next;//���ַ�����Ȼ����ͷ���,������������
		//L->next = p->next;
		Lnode* p = L;//���ַ�����ͬͷ���һ�����٣����Ǵ˴�Lͷָ����Ȼ���ڣ��ϸ���˵Ҳ��Ҫ����
		L = p->next;
		delete p;
	}
	cout << "����ռ�������" << endl;
	return OK;

}

//���
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

//����ȡֵ
elem get(Linklist L, int i)
{
	elem store;
	int n = 1;
	Lnode* p = L->next;
	//���ж�һ�£�ȡֵλ���Ƿ����1~length
	if (i<1 || i>length(L))
	{
		exit(ERROR);
		cout << "�������λ�ò��Ϸ�" << endl;
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

//��ֵ����
int locate()
{

}


int main()
{
	Linklist L;
	L = create_head(3);
	//cout << isempty(L) << endl;
	//cout <<"������Ϊ" << length(L) << endl;
	//destroy(L);
	
	cout << get(L,2).name<<"\t"<< get(L, 2).height << endl;
	

	
	//Lnode *p;//������ָ��==Linklist p����Ϊ�����������ʱ����Ҫһ����λ��ǣ����������ָ�벻���ƶ������Ը���һ���ɲ����Ķ�λָ����б�Ҫ
	//ע�⣬�˴���δ����ͷ��㣬����Ҫ��Ҫͷ��㣬�����ڳ�ʼ��������
	//�ع�,Ϊʲô��Ҫͷ��㣬Ϊʲô��Ҫ�ڵ�ָ��p,��p31
	system("pause");
	return 0;
}