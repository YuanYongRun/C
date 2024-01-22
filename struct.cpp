#include<iostream>
#include<string>
using namespace std;

    // 结构体定义和使用 struct 结构体名 {结构体成员}
    //  自定义数据类型    定义结构体不允许省略struct关键字
    struct Student
    {
        int age;
        string name;
        int score;
    };

    // 结构体做函数参数   1.值传递
    void printStudent(Student s)
    {
        cout<<"值传递子函数的姓名:"<<s.name<<"年龄:"<<s.age<<"分数:"<<s.score<<endl;
    }

    // 2.地址传递   加const   例如printStudent(const  Student * s)  目的：防止误操作
    void printStudent(Student *s)
    {
        cout<<"地址传递子函数的姓名:"<<s->name<<"年龄:"<<s->age<<"分数:"<<s->score<<endl;
    }

    //  在定义结构体的同时将变量进行赋值
    struct Student_
    {
          int age;
        string name;
        int score;
    } s3;

int main()
{
    //  通过学生类型进行创建具体对象
    struct Student s1;     // 可用省略关键字struct 
    // 通过点来访问结构体变量的属性
    s1.name ="张三";
    s1.age = 19;
    s1.score = 95;

    Student s2 = {20,"李四",100};   //第二种赋值的方式

    s3.name = "王五";
    s3.age =21;
    s3.score = 99;

    cout<<"s1的内容是"<<s1.age<<" "<<s1.name<<" "<<s1.score<<endl;

    // 结构体数组
    Student stuArray[3] = 
    {
        {
            18,"张三",99
        },
         {
            19,"李三",109
        },
         {
            20,"王三",999
        },
    };
    cout<<"学生数组第二个内容为:"<<stuArray[1].name<<endl;

    //  对结构体数组元素进行赋值,也是可以对其进行修改值
    stuArray[1].name = "王五";
    cout<<"学生数组第二个内容为:"<<stuArray[1].name<<endl;

    // 结构体指针 
    Student *p1 = stuArray;
    // 利用——>通过结构体进行访问结构体属性
    cout<<p1->name<<endl;
    p1++;
    cout<<p1->name<<endl;

    Student *p = &s1;
    // 利用——>通过结构体进行访问结构体属性  (*p).score等价于p->score
    cout<<"姓名:"<<p->name<<",年龄:"<<(*p).age<<endl;

    cout<<"-------------------"<<endl;
    /*
    结构体嵌套结构体
    作用:结构体中的成员可是作为另外一个结构体
    */
   struct student
   {
    string name;
    int score;
    int age;
   };

   struct teacher
   {
    int id;
    string name;
    int age;
    student stu;
   };

    // 创建数据
    teacher t;
    t.name = "王老师";
    t.age = 45;
    t.id = 10086;
    t.stu.name = "李四";
    t.stu.age = 19;
    t.stu.score = 60;
    cout<<"老师的名字:"<<t.name<<"老师所带的学生名字:"<<t.stu.name<<endl;
    //  调用函数进行打印
    printStudent(s1);  
    printStudent(& s2);
    system("pause");
    
}