#include<iostream>
#include<string>
using namespace std;

class Base
{
    public:
            int m_A;
    protected:
            int m_B;
    private:
            int m_C;
};

class son:public Base
{
public:
        int m_D;
};

void test01()
{
    cout<<"sizeof(son)="<<sizeof(son)<<endl;
    // 父类中非静态的成员属性都会被子类继承下去，私有成员只是被隐藏了，但是继承下去了
}

//继承中析构和构造顺序
class Base1
{
public:
        Base1()
        {
            cout<<"Base1的构造函数调用"<<endl;
        }

        ~ Base1()
        {
            cout<<"Base1的析构函数调用"<<endl;
        }
};

class Son :public Base1
{
public:
        Son()
        {
            cout<<"Son的构造函数调用"<<endl;
        }

        ~ Son()
        {
            cout<<"Son的析构函数调用"<<endl;
        }
};

void test02()
{
    Son S;  //先构造父类，在构造子类; 先析构子类，后析构父类
}


//继承中同名成员的处理方式
class Base2
{
public:
        int m_A;
        Base2():m_A(100){}
        void func()
        {
            cout<<"Base2-func()调用"<<endl;
        }

};

class Son2:public Base2
{
public:
        int m_A;
        Son2():m_A(200){}
        void func()
        {
            cout<<"Son2-func()的调用"<<endl;
        }
};

void test03()
{
    Son2 s;
    cout<<"Son2中m_A="<<s.m_A<<endl;
    cout<<"Base2中m_A="<<s.Base2::m_A<<endl;
    //同名成员函数
    // 如果子类中出现了和父类同名的成员函数,子类的同名成员会隐藏掉父类的所有同名成员的函数 ,若想要访问父类的作用域，加上作用域
    s.func();   //调用的是子类的
    s.Base2::func();

}


// 同名静态成员处理  （需要进行初始化)   和处理非静态成员处理方式一致


class Base3
{
public:
        static int m_A;
};

int Base3::m_A = 100;


class Son3:public Base3
{
public:
        static int m_A;

};
int Son3:: m_A = 200;

void test04()
{
    Son3 s;
    //1. 通过对象进行访问
    cout<<"Son3_m_A="<<s.m_A<<endl;
    cout<<"Base3下的m_A="<<s.Base3::m_A<<endl;
    //2.通过类名进行访问
    cout<<"Son3下m_A ="<<Son3::m_A<<endl;
    cout<<"Base3下m_A="<<Son3::Base3::m_A<<endl;

}

// 多继承语法  class 子类:继承方式 父类1,继承方式 父类2 ....
class base_1
{
public:
        int m_A;
        base_1()
        {
            m_A = 100;
        }
};

class base_2
{
public:
        int m_A;
        base_2()
        {
            m_A = 2000;
        }

};

// 子类继承base_1和base_2
class son_1:public base_1,public base_2
{
public:
        int m_c;
        int m_d;
        son_1()
        {
            m_c =0;
            m_d = 0;
        }
};

void test05()
{
    son_1 s;
    cout<<"sizeof(son)="<<sizeof(son_1)<<endl;
    // cout<<"m_A="<<s.m_A<<endl;   出现二义性
    cout<<"m_A="<<s.base_1::m_A<<endl;
    cout<<"m_A="<<s.base_2::m_A<<endl;

}



int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    system("pause");
}