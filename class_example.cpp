//设计立方体类，求立方体面积和体积   利用全局函数和成员函数判断两个立方体是否相等

#include<iostream>
#include<math.h>
using namespace std;

class Cube
{
private:
        int m_L;
        int m_H;
        int m_W;
public:
        //设置和获取私有变量
        void set(int L,int H,int W)
        {
            m_L = L;
            m_W = W;
            m_H = H;
        }
        // 获取长度
        int getL()
        {
            return m_L;
        }
        // 获取高度
        int getH()
        {
            return m_H;
        }
        //获取宽度
        int getW()
        {
            return m_W;
        }
        //获取立方体面积
        int calculateS()
        {
            return 2*(m_H*m_L+m_L*m_W+m_W*m_H);
        }
        //获取立方体的体积
        int calculateV()
        {
            return m_H*m_W*m_L;
        }
        //利用成员函数判断两个立方体是否相等
        bool is_equal(Cube & c)
        {
            if(c.getH()==m_H&&c.getL()==m_L&&c.getW()==m_W)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

//利用全局函数进行判断是否相等
bool is_equal(Cube & c1,Cube & c2)
{
    if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void test01()
{
    Cube c1,c2,c3;
    c1.set(1,2,3);
    c2.set(2,3,4);
    c1.set(1,2,3);
    cout<<"全局函数进行判断c1和c2是否相等"<<endl;
    cout<<is_equal(c1,c2)<<endl;
    cout<<"调用成员方法进行判断c1和c2是否相等"<<endl;
    cout<<c1.is_equal(c2)<<endl;
}



//类和类可以嵌套
// 设计一个圆类和点类     
class point
{
private:
        double p_x;
        double p_y;
public:
        void setxy(double x,double y)
        {
            p_x = x;
            p_y = y;
        }
        //获取x坐标
        double getx()
        {
            return p_x;
        }
        //获取y坐标
        double  gety()
        {
            return p_y;
        }
};


class Circle
{
private:
        point m_center;
        double m_R;
public:
        void set_data(double R,point p)
        {
            m_R = R;
            m_center = p;
        }
        //获取半径
        double get_R()
        {
            return m_R;
        }
        //获取圆心
        point get_center()
        {
            return m_center;
        }
        //计算点是否在圆内
        void isIncirlce(point & p)
        {
            double distance;
            distance = pow((m_center.getx()-p.getx()),2)+pow((m_center.gety()-p.gety()),2);
            double R_2 = pow(m_R,2);
            if(distance>R_2)
            {
                cout<<"点在圆外"<<endl;
            }
            else if(distance ==R_2)
            {
                cout<<"点在圆上"<<endl;
            }
            else
            {
                cout<<"点在圆内"<<endl;
            }
        }
};

void test02()
{
    Circle C1;
    point p1,p2;
    p1.setxy(10,12);
    p2.setxy(18,40);
    C1.set_data(10,p1);
    C1.isIncirlce(p2);
}

int main()
{
    // test01();
    test02();
    system("pause");
}