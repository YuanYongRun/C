/*
对象模型和this指针
成员变量和成员函数分开存储
只有非静态成员变才属于类的对象
*/

#include<iostream>
#include<string>
using namespace std;


class person1
{

};

void test01()
{
    person1 p;
    //空对象会分配一个字节空间，主要是占内存位置，每个空对象都有一个独一无二的空间
    cout<<"sizeof(p)="<<sizeof(p)<<endl;
}

class person2
{
    int m_A;
    static int m_B;
};

void test02()
{
    person2 p;
    // 只有非静态成员属于类的对象
    cout<<"sizeof(p)="<<sizeof(p)<<endl;
}




/*
this指针的用途：
                1.当形参和成员变量同名时，可以this指针区分，无需定义
                2.在类的非静态成员函数返回对象本身,可以用return *this.
*/

class person3
{
    public:
            int age;
            person3(int age)
            {
                this->age = age;   //解决名称冲突  若没有this,会输出一个奇怪的数字
            }

};

void test03()
{
    person3 p1(18);
    cout<<"p1的年龄是"<<p1.age<<endl;
}


class person4
{
public:
        int age ;
        person4(int Age):age(Age){}
        void Person4AddAge(person4 & p)
        {
            this->age += p.age;
        }
        // 返回的是引用，就是原数据   如果返回的就是值，不再是原先对象，而是拷贝构造函数
        person4 & AddAge(person4 & p)
        {
            this->age += p.age;
            return *this;
        }
};

void test04()
{
    person4 p1(18);
    person4 p2(20);
    p1.Person4AddAge(p2);
    cout<<"两者相加后的年龄为"<<p1.age<<endl;
    p1.AddAge(p2);
    cout<<"两者相加后的年龄为"<<p1.age<<endl;
}


/*
空指针访问成员函数
C++中空指针是可以调用成员函数的，但是要注意有没有用到this指针
如果用到this指针，需要加以判断保证代码的健壮性
*/

class person5
{
public:
        int m_age;
        person5(int age):m_age(age){}
        void showclassName()
        {
            cout<<"this is person5 class"<<endl;
        }
        void showperson5Age()
        {
            cout<<"age="<<this->m_age<<endl;
        }
};

void test05()
{
    person5 *p = nullptr;
    p->showclassName();
    // p->showperson5Age();     出现崩溃，传入的指针是nullptr,this没有具体的指向对象
}

/*
const修饰成员函数
常函数:成员函数后加const
       常函数不可以修改成员属性
       成员属性声明时加关键字mutable后，在常函数中可以修改
常对象:
       声明对象前加const
       常对象只能调用常函数
*/

class person6
{
public:
        int m_A;
        mutable int m_B;   //特殊变量,即便是在常函数中,也可以修改这个值
        person6(int a,int b):m_A(a),m_B(b){}
        person6()
        {
            this->m_A = 0;
            this->m_B = 0;
        }
        void showPerson6() const
        {   
                // m_A =  100;   报错
                m_B = 300;  //正常
                cout<<"调用成员常函数"<<endl;
        }   

        ~ person6()
        {
            cout<<"析构函数的调用"<<endl;
        }

        void func()
        {
            cout<<"这只是个测试"<<endl;
        }
};

void test06()
{
    person6 p1(18,20);
    cout<<"person6的数据为:"<<p1.m_A<<" "<<p1.m_B<<endl;
    p1.showPerson6();
    cout<<"person6的数据为:"<<p1.m_A<<" "<<p1.m_B<<endl;
    
}

//常对象
void test07()
{
    const person6 p;
    // p.m_A=100 报错
    p.m_B = 700;
    cout<<"m_B = "<<p.m_B<<endl;
    p.showPerson6();
    cout<<"m_B = "<<p.m_B<<endl;
    // p.func(); 报错，常对象只能调用常函数
}



int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
    system("pause");
}