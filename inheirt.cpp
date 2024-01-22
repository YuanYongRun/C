#include<iostream>
#include<string>
using namespace std;

/*
继承:
定义这些类的时候，下级别的成员拥有上一级别的共性，还能拥有自己的特性
利用继承的技术减少重复使用的代码
*/

class Basepage
{
    public:
    void header();
    void fonter();
    void left();
};

// java页面
class java:public Basepage
{
    public:
    void content()
    {
        cout<<"Java视频的下载"<<endl;
    }
};
// 派生类成员来源于从基类继承过来和自己能给添加新成员

// 2.继承方式   公共继承 保护继承 私有继承   父类中的private都不能访问
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// 公共继承
class son1: public Base1
{
public:
        void func()
        {
            m_A =10;  // 在父类中的public成员，到子类依旧是public
            m_B = 10;  // 在父类总的protected 成员，到子类依旧是protected
            // m_C = 20; 子类访问不到父类的私有变量
        }
};

void test01()
{
    son1 s1;
    s1.m_A = 200;
    // s1.m_B = 200;   在son1中
}


// 保护继承
class son2: protected Base1
{
public:
        void func()
        {
            m_A = 100;  //父类中是public,子类变为了protected
            m_B = 200;  // 父类是protected，子类依旧是protected
            // m_C = 300; 访问不到父类的私有变量
        }
};

void test02()
{
    son2 s2;
    // s2.m_A =200;    子类中并不能访问到，因为他是保护权限
}

// 私有继承
class son3:private Base1
{
public:
        void func()
        {
            m_A = 100;    // public -> private
            m_B = 200;    // protected -> private
            // m_C = 200;  
        }
};

void test03()
{
    son3 s1;
    // s1.m_A = 200;   由于是私有继承，类外无法访问
}

class grandson3:public son3
{
public:
        void func()
        {
            // m_A = 100;  由于son3中的m_A为私有变量，故不可以进行访问不到
        }
};


