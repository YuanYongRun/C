#include<iostream>
using namespace std;

//1. 函数的默认参数  
int func(int a,int b = 10,int c = 10)  
{
    return a+b+c;
}
// 如果我们自己传入数据，就会选择用自己的数据，如果没有，就会选择用默认值
// 如果某个位置已经有了默认参数，那么从这个位置以后，从左到右必须有默认值.即 b之后都得有默认值



/*
如果函数声明有默认参数，函数实现就不能有默认参数
*/
// int func2(int a =10,int b =20);  // 函数声明
int func2(int a,int b);
int func2(int a = 10,int b = 20)
{
    return a-b;
}


// 2.函数的占位参数    返回值类型 函数名(数据类型)  无需变量名
void func3(int a ,int)
{
    cout<<"this is a func1"<<endl;
}

// 占位参数还可以使用默认参数
void func4(int a,int  =10)  
{
    cout<<"this is a func2"<<endl;
}

/*
函数重载
作用:函数名可以相同，提高复用性
满足条件: 1.同一个作用域下;  2.函数名称相同;  3.函数参数类型不同或者个数不同或者顺序不同
注意:函数的返回值不可以作为函数重载的条件
*/
void func5()
{
    cout<<"func5的调用"<<endl;
}

void func5(int a)
{
    cout<<"func5的调用"<<endl;
}

void func5(double a)
{
    cout<<"func5的调用"<<endl;
}

void func5(int a ,double b)
{
    cout<<"func5的调用"<<endl;
}

void func5(double a,int b)
{
    cout<<"func5的调用"<<endl;
}

void func5(int a,int b,int c)
{
    cout<<"func5的调用"<<endl;
}

/*注意事项  以下这种使用会出现二义性,报错
void func6(int a,double b)
{
    cout<<"func6的调用"<<endl;
}

int func6(int a,double b)
{
    cout<<"func6的调用"<<endl;
}

*/

//函数重载注意事项
//1.引用作为重载条件
void func7(int &a)
{
    cout<<"func7(int&a)的调用"<<endl;
}

void func7(const int&a)
{
    cout<<"func7(const int &a)的调用"<<endl;
}

//2.函数重载遇到了默认参数
void func8(int a ,int b =10)
{
    cout<<"func8(int a,int b =10)调用"<<endl;
}
void func8(int a)
{
    cout<<"func8(int a)的调用"<<endl;
}

void test01()
{
    int a = func(1);
    int b = func(1,2,3);
    cout<<"func(1)结果:"<<a<<endl;
    cout<<"func(1,2,3):"<<b<<endl;

}



void test02()
{
    int b = func2();
    cout<<b<<endl;
}

void test03()
{
    func3(1,2);
    func4(1);
}

void test04()
{
    func5();
    func5(1);
    func5(2.4);
    func5(1,1.4);
    func5(1.4,1);
    func5(1,2,3);
}


void test05()
{
    func8(10,11);
    // func8(8);  编译器出现二义性了，无法正常运行
}
int main()
{
    // test01();
    // test02();  
    // test03();
    test04();
    int a =10;
    func7(a);
    func7(10);
    test05();
    system("pause");
}