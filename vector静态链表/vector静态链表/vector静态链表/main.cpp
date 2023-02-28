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
    std::cout << "原始的静态链表如下：" << std::endl;
    SL.show();
    SL.Insert(100, 2);//此处测试可修改为用户输入
    std::cout << "在静态链表中第2个位置插入100后结果如下：" << std::endl;
    SL.show();
    int m;
    int delete_index = 5;//此处可修改
    SL.Delete(m, delete_index);
    std::cout << "删除的对应" << delete_index << "处的值为：" << m << std::endl;
    std::cout << "删除后的静态链表如下：" << std::endl;
    SL.show();

    int find_val = 2;//此处可修改
    int index = SL.Find(find_val);
    std::cout << "查找到" << find_val << "在列表中的位置为:" << index << std::endl;
    return 0;
}