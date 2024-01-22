#include<iostream>
#include<string>
using namespace std;

/*
运算符重载
1.加号运算符重载  定义两个类型相加
对于内置的数据类型，编译器指导如何运算
eg： int a = 10; int b =20; int c = a+b
*/



//对于自定义的数据类型，编译器不知道如何运算
class Person
{
public:
        int m_A;
        int m_B;
        Person(int a,int b):m_A(a),m_B(b){}
        Person()
        {

        }
        // 通过自己写成员函数，实现两个对象的属性相加返回新的对象
        Person & Personadd(Person & p)   
        {
            this->m_A += p.m_A;
            this->m_B+=p.m_B;
            return *this;
        }

        //对成员函数进行操作符+重载
        Person  operator+(Person &p)
        {
            Person temp;
            temp.m_A = this->m_A+p.m_A;
            temp.m_B = this->m_B+p.m_B;
            return temp;
        }
        // 成员函数重载<< 无法实现cout在左侧  void operator<<(cout){}本质是p.operator<<(cout)    即p<<cout

};


//通过全局函数进行重载操作符+
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}


void test01()
{
    Person p1(19,20);
    Person p2(22,40);
    // Person p3 = p1 + p2;   编译器报错
    Person p3 = p1.Personadd(p2);
    cout<<"p3的相关数据"<<p3.m_A<<" "<<p3.m_B<<endl;
    // Person p4 = p1 + p2;
    Person p4 = p1.operator+(p2);  //是上面一行的本质
    cout<<"p4的相关数据"<<p4.m_A<<" "<<p4.m_B<<endl;
    Person p5 = operator+(p1,p2);
    cout<<"p5的相关数据"<<p5.m_A<<" "<<p2.m_B<<endl;
}

// 通过全局函数进行重载操作符<<
ostream & operator<<(ostream &cout,Person &p)
{
    cout<<"m_A="<<p.m_A<<" "<<"m_B="<<p.m_B;
    return cout;
}

void test02()
{
    Person p1(30,47);
    cout<<p1<<endl;
}

// 重载递增运算符 通过重载递增运算符，实现自己的整型数据
class MyInter
{
public:
        MyInter()
        {
            m_num = 0;
        }
private:
        int m_num;
public:
        MyInter & operator++()  //前置递增    返回对同一个数据进行操作，若不进行引用，返回的数值则是一个副本
        {
            m_num++;
            return *this;
        }

        MyInter  operator++(int ) //后置递增   一定要记住局部变量不能返回引用
        {
            //先记录结果
            MyInter temp = *this;
            //后递增
            this->m_num ++;
            //最后记录结果返回
            return temp;
        }
        void showData()
        {
            cout<<"相关数据:"<<this->m_num<<endl;
        }
};



void test03()
{
    MyInter m_1;
    m_1++;
    m_1.showData();
    ++m_1;
    m_1.showData();

}


//赋值运算符重载(如果类中属性指向堆区，做赋值操作深浅拷贝)
class Person1
{
private:
        int * m_age;
public:
        Person1(int age)
        {
            m_age = new int (age);
        }
        ~ Person1()
        {
            if(m_age!=nullptr)
            {
                delete m_age;
                m_age = nullptr;
            }
        }
        int &getage()
        {
            return *m_age;
        }
        void operator=(Person1 & p1)
        {
            //应该判断是否有属性在堆区，如果有，先释放干净
            if(m_age!=nullptr)
            {
                delete m_age;
                m_age = nullptr;
            }
            //进行深拷贝 在堆区开辟数据
            m_age = new int(p1.getage());  

        }
};

void test04()
{
    Person1 p1(19);
    Person1 p2(18);
    cout<<"p1的年龄是"<<p1.getage()<<endl;
    cout<<"p2的年龄是"<<p2.getage()<<endl;
    // p2 = p1;  此处进行了浅拷贝，导致p2和p1同时操作了同一块内存
    // cout<<"p2的年龄是"<<p2.getage()<<endl;
    p2 = p1;
    cout<<"p2的年龄是"<<p2.getage()<<endl;
}



//关系操作符重载    两个自定义类型进行比较
class Person2
{
    public:
    string m_name;
    int  m_age;
    Person2(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    bool operator ==(Person2 &p)
    {
        if(this->m_age ==p.m_age)
        {
            
            if (this->m_name == p.m_name )
            {
                return true;
            }
        }
        else
        {
            return false;
        }

    }
};

void test05()
{
    Person2 p1("tom",18);
    Person2 p2("Tom",18);
    if(p1==p2)
    {
        cout<<"p1和p2相等"<<endl;
    }
    else
    {
        cout<<"不相等"<<endl;
    }
}


/*
函数调用重载()
函数调用运算符号()也可以重载
由于重载使用的方式非常像仿函数的调用，因此称为仿函数
仿函数没有固定写法，非常灵活
*/


class Myprint
{
    public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout<<test<<endl;
    }
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};

void test06()
{
    Myprint myprint;
    myprint("Hello test");
    cout<<"和为"<<myprint(100,200)<<endl;
    //调用匿名函数
    cout<<Myprint()(200,600)<<endl;
}






int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    test06();
    system("pause");
}