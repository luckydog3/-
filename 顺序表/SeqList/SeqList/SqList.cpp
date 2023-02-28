#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
//#define NULL 0
//�Զ��庯�����״̬��
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -1
//�������ؽ��״̬��
typedef int Status;
typedef char ElemType;
/*
	1,ѧϰ���Ա�˳�����ظ���
	2��ʵ�����Ա�ADT���壬ʵ�ֻ�������
	ADT List->p21-22
*/


//˳���ṹ���Ͷ��壬��ѧ�����Ϊ������ű�ǣ���һ����ֵΪ����Ԫ��
typedef struct
{
	int height;
}student;//ElemType����Ԫ�����Ͷ��壬�����ݸ��ݾ���Ԫ��������޸ģ�int height����������Ҳ�����޸ģ�student��
typedef struct
{
	student* elem;//��̬����,��������Ԫ���������͵�ָ��
	//ElemType elem[MAXSIZE];//��̬����
	int length;
}SqList;//����Ԫ�ص�˳��洢�ṹ���Ͷ���

//����һ��˳���L
//SqList L;

//��������ʵ��
/*
	����1����ʼ��˳���Status Init_SqList(SqList &L)
	1,Ŀ�ģ���ʼ������������һ���յ����Ա�L��ע�⣺�˴��ص����ڳ�ʼ���������ǽ���˳���˳�������׽�����SqList L,
			˵����˳���L��ֻ��һ��SqList���͵ı������ˣ�ֻ������Ԫ���߼���洢��ϵ��������������������ϵĹ���
			����ʼ���ǶԸ��������͵ı����������ã���Ҫ����ռ䣬���ó��ȡ���Ȼ����Ҳ����дһ�����������ĳ�ʼ��������ʵ�ֽ������ʼ�������
	2�����������������Ͳ���Ϊ��&L
	   ��ʼ�������ѽ���SqList L��������δ����
	   �������������һ���յ�˳���
	3���㷨���裺
		   1��Ϊ˳���L����һ��Ԥ�����С������ռ䣬ָ��elemָ��ÿռ��׵�ַ
		   2��length��Ϊ0
	   ����⣺
		   ���䲻�ɹ�Ҫ��ʱ��������ֹͣlength����
	4���㷨����
*/
Status Init_SqList(SqList &L)//��Ҫ��ǰ����һ��˳������L
{
	//L.elem = (student*)malloc(MAXSIZE);//��̬����ռ�
	L.elem = new student[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);//�洢����ʧ�ܼ�ʱ����,Ҳ����return ERROR
	L.length = 0;//�ձ���Ϊ��
	return OK;
}

/*
	����2������˳���
	1,Ŀ�ģ�����Ϊ˳��������ڴ棬���´��벢û�����ٱ���L��ֻ�����������ݿռ�
	2�����������������Ͳ���Ϊ����˳���L
	   ��ʼ�������Ѵ������Ա�
	   ����������ͷ����Ա�洢�ռ�
	3���㷨���裺
		   1���ͷ�˳���L�洢�ռ�
		   2��length��Ϊ0
	   ����⣺
		   ��Ҫ��⵽L.elem����ֵ���У�ȷ���Ѿ�������ռ䣬���������ͷ�
	4���㷨����
*/
Status Destroy_SqList(SqList& L)
{
	if (L.elem)
		//free(L.elem);//�ͷŴ洢�ռ�
	    delete L.elem;
	else
		return INFEASIBLE;
	return OK;
}

/*
	����3�����˳���
	1��Ŀ�ģ���������˳��������ڴ棬���´��벢û���������ݿռ䣬ֻ�ǽ���Ч������Ϊ��0��
	2�����������������Ͳ���Ϊ����˳���L
	   ��ʼ�������Ѵ������Ա�
	   �����������˳�������Ϊ�ձ�
	3���㷨���裺
		   1��length��Ϊ0
	   ����⣺
		   ��
	4���㷨����
*/
Status Clear_SqList(SqList& L)
{
	L.length = 0;//�����Ա�����Ϊ0
	return OK;
}

/*
	����4��˳����п�
	1��Ŀ�ģ�ȷ��˳����Ƿ�Ϊ�ձ�
	2��������˳���L
	   ��ʼ�������Ѵ������Ա�
	   �����������Ϊ�ձ���TURE,���򷵻�FALSE
	3���㷨���裺
		   1�����length�Ƿ�Ϊ0���ǣ�����TURE�����򣬷���FALSE
	   ����⣺
		   ��
	4���㷨����
*/
Status IsEmpty_SqList(SqList L)
{
	if (L.length == 0)
		return TURE;
	else
		return FALSE;
}

/*
	����5����ȡ˳�����
	1��Ŀ�ģ���ȡ˳�����
	2��������˳���L
	   ��ʼ�������Ѵ������Ա�
	   �������������˳�����
	3���㷨���裺
		   1��ֱ�ӷ���length
	   ����⣺
		   ��Ҫ�к����˳���Ž��з��أ����򷵻�ֵû������
	4���㷨����
*/
int GetLength_SqList(SqList L)
{
	return L.length;//�˴����Ͻ�����ʹ�ոմ�����L��Ҳ���ܷ���length������û���壬�������γ̲��������ӣ�����Ȥ����ʵ��
}

/*
	����6����ȡ˳���ĳ��λ�õ�ֵ
	1��Ŀ�ģ���ȡ˳���ֵ
	2��������˳���L��λ��i���洢����e������Ԫ�����͵ı�����
	   ��ʼ�������Ѵ���˳���
	   �����������e����˳����i������Ԫ��ֵ
	3���㷨���裺
		   1��ֱ�ӷ��ص�i������Ԫ��ֵ
	   ����⣺
		   λ��iҪ�ں���Χ�ڣ�1--length
	4���㷨����
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
	����8������ĳ��Ԫ����˳����е�λ��
	1��Ŀ�ģ�����ĳ��Ԫ����˳����е�λ��
	2��������˳���L����Ҫ���ҵ�����Ԫ��e
	   ��ʼ�������Ѵ���˳���
	   �������������˳�����'��һ��'��e��ͬԪ�ص�λ�ã���û�У��򷵻�-1��
	3���㷨���裺
		   1����˳���һ��������e�Ƚϣ��ҵ�������λ����ţ����򷵻�NOTFOUND
	   ����⣺
		   λ��iҪ�ں���Χ�ڣ�1--length
	4���㷨����
*/
int LocateElem_SqList(SqList L,student e)
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		//if (L.elem[i] == e)//����α�������д�����˴�c/c++�޷�ִ�С��������·���ʵ�ֱȽϣ�Ҳ������==��������䱾����ͬ����Ҫ����Ƚ�
		if (L.elem[i].height == e.height)//���˿��������У����������������������ʵ�ֱȽ�
			return i + 1;
	}
	return NOTFOUND;
}

/*
	����9����˳�����ĳ��λ�ò���Ԫ��
	1��Ŀ�ģ���˳�����ĳ��λ�ò���Ԫ��
	2��������˳���L(����)������λ��i����Ҫ���������Ԫ��e
	   ��ʼ�������Ѵ���˳���
	   �����������i-1������Ԫ�أ����ȼ�1������ɹ�����OK������ʧ�ܷ���ERROR
	3���㷨���裺
		   1���жϲ���λ���Ƿ�Ϸ�
		   2���ж�˳����Ƿ��������������򷵻�ERROR
		   3����n��i��Ԫ�������������Ϊ���ճ���i��λ��
		   4����e�����i��λ��
		   5������1,����ɹ�����OK
	   ����⣺
		   λ��iҪ�ں���Χ�ڣ�1--length+1
		   �������
	4���㷨����
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
	����9��ɾ��˳�����ĳ��λ�õ�Ԫ��
	1��Ŀ�ģ�ɾ��˳�����ĳ��λ�õ�Ԫ��
	2��������˳���L(����)��ɾ��λ��i
	   ��ʼ�������Ѵ���˳���
	   ���������ɾ��i��Ԫ�أ����ȼ�1��ɾ���ɹ�����OK��ʧ�ܷ���ERROR
	3���㷨���裺
		   1���ж�ɾ��λ���Ƿ�Ϸ�
		   2���ж�˳����Ƿ�Ϊ�ձ�
		   3����i��length-1��Ԫ�أ����θ�ֵΪ��һ��Ԫ��
		   5������1,ɾ���ɹ�����OK
	   ����⣺
		   λ��iҪ�ں���Χ�ڣ�1--length
		   ���ܿձ�ɾ��
	4���㷨����
*/
Status DeleteElem_SqList(SqList& L, int i)
{
	if (i<1 || i>L.length ) return ERROR;//ע��ԭ����Ҫ�жϿձ�����ʵ�ʸ������Լ��ձ�����Ҫ������
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