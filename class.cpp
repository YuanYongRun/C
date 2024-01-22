/*
类和对象
C++面相对象三大特性:封装，继承，多态
*/

/*
封装
意义:将属性作为一个整体，表现生活中的事物   将属性和行为加以权限控制
语法: class 类名 {访问权限:属性 行为}
类中的属性和行为称为成员  
属性称为成员属性和成员变量    行为称为成员函数和成员方法
*/

#include<iostream>
#include<string>
using namespace std;

//设计一个圆类，求圆的周长
class Circle
{
    //访问权限:公共权限
public:
    int m_r; //半径   属性
    //获取圆的周长   行为
    double caculateZc()
    {
        return 2*3.14*m_r;
    }

};


//设计一个学生类
class Student
{
    public:
    string m_name;
    string m_id;
    //行为:
    void showStudent()
    {
        cout<<"姓名:"<<m_name<<" "<<"学号:"<<m_id<<endl;
    }
    //进行赋值
    void set_data(string name,string id)
    {
        m_name = name;
        m_id = id;
    }
};


void test01()
{
    Circle c1;  //通过圆类创建具体的对象  
    c1.m_r = 10; // 给他的属性进行赋值
    cout<<"圆的周长为:"<<c1.caculateZc()<<endl;
}

void test02()
{
    Student s1;
    s1.set_data("johh","456");
    s1.showStudent();
}




/*
2.访问权限:
pulic 成员可以在类内访问，类外也可以访问
protected 成员在类内可以访问，类外不可以访问   子类也可以访问父类中的保护成员
private 成员可以在类内访问，在类外不可以访问   子类不可以访问父类的私有成员
*/

class Person
{
public:
    string name;
protected:
    string m_car;
private:
    int m_password;
public:
    void func()
    {
        m_car = "宝马";
        name = "Galaxy";
        m_password = 1;
    }
};

void test03()
{
    Person p;
    p.func();
    cout<<"人的名字为:"<<p.name<<endl;
    p.name = "Galaxy1"; 
    cout<<"人的名字为:"<<p.name<<endl;
    // cout<<"人的车辆类型"<<p.m_car<<endl;   类外不可以访问
}


/*
struct 和 class 的区别
1.struct默认权限是public
2.class默认权限 是private
*/

class C1
{
    int m_A;
};

struct C2
{
    int m_B;
};

void test04()
{
    C1 c1;
    C2 c2;
    // c1.m_A = 12;   报错  因为默认的权限是private
    c2.m_B=14;
    // cout<<"c1的数据为:"<c1.m_A<<endl;
    cout<<"c2的数据为"<<c2.m_B<<endl;
}

/*
成员属性私有化
优点1:将成员属性设置为私有，可以自己控制读写权限
优点2:对于写权限，我们可以检测数据有效性
*/

class person
{
private:
        string m_name;   // 可读可写
        int m_age = 18;     //只读
        string m_lover;  //只写
public:
        // 设置名字
        void setname(string name)
        {
            m_name = name;
        }
        // 获取名字
        string getname()
        {
            return m_name;
        }
        //获取年龄
        int getage()
        {
            return m_age;
        }
        //设置m_lover
        void setlover(string name)
        {
            m_lover = name;
        }

};

void test05()
{
    person p1;
    p1.setname("Galaxy");
    cout<<"p1的名字为:"<<p1.getname()<<endl;
    cout<<"p1的年龄为"<<p1.getage()<<endl;
    p1.setlover("ZhouChuanXiong");  // 只能写，不能读，外界访问不到相关的信息
}

/*
将类中的东西进行份文件编写
1.point.h  (成员函数只需要有声明)
class point
{
    void func1();
}
2.point.cpp(只有成员函数的实现)  一定要有作用域，否则会报错
void point::func1()
{

}

*/

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    system("pause");
}

