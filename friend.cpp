#include<iostream>
#include<string>
using namespace std;

/*
友元:
作用:让一个函数或者类，访问另外一个类的成员
*/

class Buildings;
class goodGay2;

class goodGay2
{
public:
        void visit(Buildings *b);
};

class Buildings
{   
    friend class goodGay1;//2.类做友元
    friend void goodGay(Buildings & building);  //1.全局函数做友元
    friend void goodGay2::visit(Buildings * b);
public:
        string m_sittingroom;
private:    
        string m_bedroom;
public:
        Buildings()
        {
            m_sittingroom = "客厅";
            m_bedroom = "卧室";
        }
};


void goodGay2::visit(Buildings *b)
{
    cout<<"正在访问"<<b->m_bedroom<<endl;
    cout<<"正在访问"<<b->m_sittingroom<<endl;
}

class goodGay1
{
public:
        Buildings * building;
        goodGay1 ()
        {
            building = new Buildings;
        }
        void vist()
        {
            cout<<"好基友正在访问"<<building->m_bedroom<<endl;
            cout<<"好基友正在访问"<<building->m_sittingroom<<endl;
        }
};



//全局函数
void goodGay(Buildings &building)
{
    cout<<"好基友正在访问"<<building.m_bedroom<<endl;
    cout<<"好基友正在访问"<<building.m_sittingroom<<endl;
}


void test01()  
{   
    Buildings b1;
    goodGay(b1);
}

void test02()
{
    goodGay1 g;
    g.vist();
}


void test03()
{
    Buildings * b = new Buildings;
    goodGay2 gg;
    gg.visit(b);
}

int main()
{
    // test01();
    // test02();
    test03();
    system("pause");
}
