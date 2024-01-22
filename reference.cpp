#include<iostream>
using namespace std;

/*
引用的基本使用: 语法:数据类型 &别名 =  原名
作用:给变量起别名
注意使用选项:  1.引用必须初始化    int &b ; 错误，必须初始化
2.引用在初始化后,不可改变
*/

void test01()
{
    int a = 10;
    int &b = a;
    cout<<"a的数据为:"<<a<<endl;
    cout<<"b的数据为"<<b<<endl;
    b = 20;
    cout<<"修改后的数据:"<<endl;   // 输出的是20，因为b和a都是操控同一块内存
    cout<<"a的数据为"<<a<<endl;
    cout<<"b的数据为"<<b<<endl;
}

void test02()
{
    int a = 10;
    int c = 20;
    int &b = a;
    // 引用一旦初始化，就不能改变
    // b = &c;     //错误
    cout<<b<<endl;
}

/*
引用做函数参数
作用: 函数传参时，利用引用的技术让形参修饰实参
优点:简化指针修改实参
*/

// 1.值传递: 形参不会修饰实参
void myswap1(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 2.地址传递 :形参会修饰实参
void myswap2(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//3.引用传递:形参也会修饰实参
void myswap3(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 引用做函数返回值 

int & test03()
{
    int a = 10;  // 不要返回局部变量
    return a;
}

int & test04()
{
    static int b =20;
    return b;
    
}


//  引用的本质:一个指针变量 

void func1(int &ref)   // 发现是引用，转换为 int * const ref = &a
{
    ref = 100;     // ref是引用，转换为 *ref = 100;
}

// 常量引用:防止形参修改实参  const int & 
void test05()
{
    int a =100;
    // int &ref = 10;  // 错误,引用必须加一块合法的空间
    int &ref1 = a;    //正确
    cout<<"无const的ref1="<<ref1<<endl;
    const int & ref2 = 10;  // 正确，编译器会将代码翻译成int temp = 10;const int & ref2 = temp
    // ref2 = 20;    加入const之后不允许修改了，只是可读
    cout<<"有const的ref2="<<ref2<<endl;

}

void show_value(const int &ref)
{
    // ref = 20;   直接报错,因为有const
    cout<<"ref="<<ref<<endl;
}
int main()
{
    test01();
    test02();
    int a1 = 20;
    int a2 =30;
    cout<<"交换后:"<<endl;
    cout<<"通过值传递后的数据:"<<endl;
    myswap1(a1,a2);
        cout<<"a1="<<a1<<endl;
    cout<<"a2="<<a2<<endl;
    cout<<"通过地址传递后的数据:"<<endl;
    myswap2(&a1,&a2);
    cout<<"a1="<<a1<<endl;
    cout<<"a2="<<a2<<endl;
    cout<<"通过引用传递后的数据:"<<endl;
    myswap3(a1,a2);
    cout<<"a1="<<a1<<endl;
    cout<<"a2="<<a2<<endl;

    // int &ref = test03();  //返回局部变量会报错
    // cout<<ref<<endl;
    int &ref =test04();
    cout<<"test04返回值为:"<<ref<<endl;
    test04() = 1000;  //如果函数的返回值是引用，这个函数是可以作为左值调用的
    cout<<"ref的值为:"<<ref<<endl;

    int a3 =1;
    cout<<"初始a3的值为:"<<a3<<endl;
    func1(a3);
    cout<<"经过func1函数后的a3的值为:"<<a3<<endl;

     test05();

     show_value(27);
    system("pause");
}