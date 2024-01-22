#include<iostream>
#include<string>
using namespace std;

/*
菱形继承
两个派生类继承同一个基类
某个类同时继承两个派生类
*/

class animal
{
public:
        int m_Age;
};


class sheep:public animal{};   // 羊类
class camel:public animal{};   // 驼类

class alpaca:public sheep,public camel{};  //羊驼类

void test01()
{
    alpaca ex;
    // ex.m_Age=18;  编译器不明确给继承过来的m_Age进行赋值
    ex.sheep::m_Age = 18;
    ex.camel::m_Age = 19;
    // 当出现菱形继承，两个父类拥有相同的数据，需要加以区分
    cout<<"sheep—_m_Age = "<<ex.sheep::m_Age<<endl;
    cout<<"camel—_m_Age = "<<ex.camel::m_Age<<endl;
}

// 利用虚继承就可以   //底层实现:通过虚基类继承，继承的是指针
class sheep_1:virtual public animal{};
class camel_1:virtual public animal{};
class alpaca_1:public sheep_1,public camel_1{};

void test02()
{
    alpaca_1 al;
    al.m_Age = 28;
    cout<<"m_Age = "<<al.m_Age<<endl;
    cout<<"m-Age="<<al.sheep_1::m_Age<<endl;
    cout<<"m_Age = "<<al.camel_1::m_Age<<endl;
}


/*
多态:    当父类的指针或引用指向子类的对象时，发生多态
静态多态:函数重载和运算操作符重载属于静态多态，复用函数名
        1.要有继承关系  2.子类复写父类的虚函数
        2.父类的指针或引用执行子类的对象 
动态动态:派生类和虚基类实现运算多态
区别:
    静态多态的函数地址早绑定 —— 编译阶段确定的函数地址
    动态多态的函数地址玩绑定 —— 运行阶段确定的函数地址
*/


class Speak
{
public:
        void virtual speak()
        {
            cout<<"说话"<<endl;
        }
};

class Cat : public Speak
{
public:
        void speak()
        {
            cout<<"喵喵喵"<<endl;
        }

};

void dospeake(Speak & s)    // 地址早绑定     利用父类的引用指向子类的对象
{
    s.speak();
}


void test03()
{   
    Speak s;
    dospeake(s);
    Cat c;
    dospeake(c);
}


int main()
{
    // test01();
    // test02();
    test03();  // 运行结果是说话，想要执行喵喵喵，我们需要采用动态多态，在void speak()前加入virtual
    system("pause");
}