#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    //  定义指针
    int *p;
    // 让指针记录a的值
    p = &a;
    cout<<"p指针的地址:"<<&p<<endl;
    cout<<"a的地址:"<<&a<<endl;
    // 使用指针的解引用方式来找到指针指向的内容
    cout<<"p指针所指向的值为:"<<*p<<endl;
    cout<<"p指针占用的字节大小:"<<sizeof(p)<<endl;
    cout<<"a的值:"<<a<<endl;
    
    //  空指针:指向内存编号为0的空间 空指针是不可以被访问   作用:初始化
    int *p1 = nullptr;
    cout<<"空指针地址:"<<&p1<<endl;

    // 野指针:指向非法内存空间  在程序中尽量避免野指针
    int *p2 = (int*) 0x11001;
    cout<<"p2指针的变量为:"<<*p2<<endl;

    /*
        const修饰指针:
        1.const修饰指针—— 常量指针
        2.const修饰常量—— 指针常量
    */
    //  常量指针: 可以改变指针的指向,但是不可以修改指向的值  eg: const int *p
    const int *p3 = &a;
    cout<<"p3的值为:"<<*p3<<endl;
    // *p3 = 20;   无法修改指向的值
    int b = 20;
    p3 = &b;
    cout<<"p3的值为:"<<*p3<<endl;

    //  指针常量：可以改变指向的值，但是不可以修改指针的指向  eg; int * const p
    int * const p4 = &a;
    cout<<"修改前的p4的值为:"<<*p4<<endl;
    *p4 = 30;
    // p4 = &b;  无法修改指向指向

    // 常量指针常量 const int * const p 无法修改指向及其值
    cout<<"修改后p4的值为:"<<*p4<<endl;

    // 通过指针访问数组
    int arr[10]={1,2,3,4,5,6,7,8,9,20};
    int *ar = arr;
    // cout<<"第一个元素为:"<<*ar<<endl;
    // ar++;   //让指针偏移四个字节
    // cout<<"第二个元素为:"<<*ar<<endl;
    // 利用指针进行遍历
    for(int i =0;i<10;i++)
    {
        cout<<"第"<<i<<"个元素为:"<<*(ar++)<<endl;
    }
    // 如何将数组传入函数
    //  void bubblesort(int *arr,int len)  利用指针来接收地址  或者是int arr[]
    system("pause");
}