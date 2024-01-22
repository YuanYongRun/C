/*
深拷贝和浅拷贝
浅拷贝:简单的赋值拷贝操作(编译器提供)
深拷贝:在堆区申请空间，进行拷贝操作
*/

#include<iostream>
#include<string>
using namespace std;


class Person
{
public:
        int m_age;

        Person()
        {
            cout<<"Person无参构造函数调用"<<endl;
        }

        Person(int age)
        {
            m_age = age;
            cout<<"Person有参构造函数调用"<<endl;
        }

        ~ Person()
        {
            cout<<"Person的析构函数的调用"<<endl;
        }
};


void test01()
{
    Person p1(19);
    cout<<"p1的年龄是"<<p1.m_age<<endl;
    Person p2(p1);   //浅拷贝
    cout<<"p2的年龄是"<<p2.m_age<<endl;
}


class Person1
{
public:
        int m_age = 0;
        int *m_height;

    Person1()
    {
        cout<<"Person1的无参构造"<<endl;
    }
    Person1(int age ,int height)
    {
        m_age = age;
        m_height = new int (height);  //在堆区开辟数据进行操作
    }
    Person1(const Person1 &p)
    {
        cout<<"Person1拷贝构造函数构造"<<endl;
        m_age = p.m_age;
        // m_height = p.m_height      编译器默认实现实现这行代码
        m_height = new int (*p.m_height);
    }
    ~ Person1()
    {
        cout<<"Person1()析构函数的调用"<<endl;
        if(m_height !=nullptr)
        {
            delete m_height;
            m_height = nullptr;
        }
    }
};

//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数

void test02()
{
    Person1 p1(18,120);
    cout<<"p1的年龄"<<p1.m_age<<"身高"<<*p1.m_height<<endl;
    Person1 p2(p1);
    cout<<"p2的年龄"<<p2.m_age<<"身高"<<p2.m_height<<endl;     //  p2通过浅拷贝p1得到，由编译器提供

}


/*
初始化列表:
语法:    构造函数():属性1(值1),属性2(值2),.....  {}
*/

class Person2
{
public:
        int m_A;
        int m_B;
        int m_C;
        //传统初始化操作
        // Person2(int a,int b,int c)
        // {
        //     m_A = a;
        //     m_B = b;
        //     m_C = c;
        // }

        // 初始化列表进行初始化属性
        Person2():m_A(10),m_B(20),m_C(30) {}  // 只能赋值10,20,30，不够压力
        Person2(int a,int b,int c):m_A(a),m_B(b),m_C(c){}   //灵活

};

void test03()
{
    Person2 p1;
    p1 = Person2(12,13,14);
    cout<<"相关数据:"<<p1.m_A<<" "<<p1.m_B<<" "<<p1.m_C;
}

/*
类对象作为类成员
C++中类成员可以是另外一个类的对象，称为该成员的对象成员
class A
{

}

class B   
{
    A a;
}
B类中有对象A作为成员,A为对象成员 那么当创建B对象时，A与B的构造和析构顺序谁先谁后
*/

class Phone
{
public:
        string m_Pname;
        Phone(string name):m_Pname(name)
        {
            cout<<"Phone的构造函数调用"<<endl;
        }
        ~Phone()
        {
            cout<<"Phone的析构函数调用"<<endl;
        }

};


class Person3
{
public:
        string m_name;
        Phone m_phone;
        Person3(string name,const Phone & phone_name):m_name(name),m_phone(phone_name)
        {
            cout<<"Person3的构造函数的调用"<<endl;
        }
        ~Person3()
        {
            cout<<"Person3的析构函数的调用"<<endl;
        }
};

void test04()
{
    Phone p1("HUAWEI");
    Person3 p2("张三",p1);
    cout<<"人物名字:"<<p2.m_name<<"所使用的手机型号"<<p2.m_phone.m_Pname<<endl;
}



int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    system("pause");
}
