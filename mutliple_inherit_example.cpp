#include<iostream>
#include<string>
using namespace std;


// 实现一个多态的类

class Abstractcacula
{
public:
        int num1;
        int num2;
    virtual int  getresult()
    {
        return 0;
    }
};


class ADDcaculator:public Abstractcacula
{
public:
        int getresult()
        {
            return num1+num2;
        }
};


class surpluscaculator:public Abstractcacula
{
    public:
    int getresult()
    {
        return num1-num2;
    }
};

void test01()
{
    // 多态使用条件：父类的指针或引用指向子类的对象
    Abstractcacula * abc = new ADDcaculator;
    abc->num1 = 100;
    abc ->num2 = 200;
    cout<<abc->getresult()<<endl;
    // 用完及时销毁
    delete abc;
}


/*
纯虚函数和抽象类
纯虚函数:
            virtual 返回值类型 函数名(参数列表) = 0;
当类中有了纯虚函数，这个类被称为抽象类
特点:
    无法实例化对象
    子类必须重写抽象类的纯虚函数
*/


class Base
{
public:
        virtual void func() =0; //纯虚函数
};

class Son:public Base
{
public:
        void func()
        {
            cout<<"Son_func()的调用"<<endl;
        }
};

void test02()
{
    Base * base = new Son;
    base->func();
}



// 多态案例制作饮品
// 要求:利用多态技术实现，提供抽象制作饮品基类，提供子类制作茶喝咖啡
class AbstractDrinking
{
public:
        virtual void Boil() = 0;
        virtual void Brew() = 0;
        virtual void PourIncup() = 0;
        virtual void putsonmething() = 0;
        virtual void makeDrink()
        {
            Boil();
            Brew();
            PourIncup();
            putsonmething();        
        }
};

// 制作咖啡
class coffee:public AbstractDrinking
{
public:
        void Boil()
        {
            cout<<"煮农夫山泉"<<endl;
        }
        void Brew()
        {
            cout<<"冲泡咖啡"<<endl;
        }
        void PourIncup()
        {
            cout<<"导入水杯"<<endl;
        }
        void putsonmething()
        {
            cout<<"加入糖和牛奶"<<endl;
        }
};

void dowork(AbstractDrinking * abs)
{
    abs->makeDrink();
    delete abs;
}

void test03()
{
    dowork(new coffee);
}

/*
虚析构和纯虚构
多态使用的时候，如果子类中有属性开辟到堆区，那么父类指针在调用时无法调用子类的析构代码
解决方式:将父类的析构函数改为虚析构或纯析构

共性:
可以解决父类指针释放子类对象
都需要具体的函数进行实现
区别:
    如果是纯虚析构，该类属于抽象类，无法实例化对象
虚析构； virtual ~类名(){}
纯虚析构； virtual ~类名() = 0
*/

class Animal
{
public:
        virtual void speak() = 0;
        Animal()
        {
            cout<<"Animal构造函数"<<endl;
        }
        virtual ~Animal()
        {
            cout<<"Animal析构函数"<<endl;
        }
};

class Cat: public Animal
{
public:
        string *m_name;
        Cat(string name)
        {
            m_name = new string(name);
        }

        void speak()
        {
            cout<<*m_name<<"在说话"<<endl;
        }
        ~ Cat()
        {
            if(m_name !=nullptr)
            {
                cout<<"Cat析构函数调用"<<endl;
                delete m_name;
                m_name = nullptr;
            }
        }
};

void test04()
{
    Animal * anima = new Cat("小花");
    anima->speak();
    delete anima;
}


int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    system("pause");
}