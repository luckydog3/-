#include"List.cpp"
int  main()
{
    StaticList<int> SL;
    SL.Insert(2, 1);
    SL.Insert(4, 2);
    SL.Insert(1, 3);
    SL.Insert(9, 4);
    SL.Insert(20, 5);
    SL.Insert(3, 6);
    std::cout << "ԭʼ�ľ�̬�������£�" << std::endl;
    SL.show();
    SL.Insert(100, 2);//�˴����Կ��޸�Ϊ�û�����
    std::cout << "�ھ�̬�����е�2��λ�ò���100�������£�" << std::endl;
    SL.show();
    int m;
    int delete_index = 5;//�˴����޸�
    SL.Delete(m, delete_index);
    std::cout << "ɾ���Ķ�Ӧ" << delete_index << "����ֵΪ��" << m << std::endl;
    std::cout << "ɾ����ľ�̬�������£�" << std::endl;
    SL.show();

    int find_val = 2;//�˴����޸�
    int index = SL.Find(find_val);
    std::cout << "���ҵ�" << find_val << "���б��е�λ��Ϊ:" << index << std::endl;
    return 0;
}