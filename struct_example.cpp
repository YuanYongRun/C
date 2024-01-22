#include<iostream>
#include<string>
#define N 3
using  namespace std;

struct student
{
    string s_name;
    int num;
};

struct teacher
{
    string name;
    student StuArray[N];
};

// 用指针传递数据
void allocate_space(teacher *t, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << "输入老师的姓名" << endl;
        cin >> t[i].name;
        cout << endl;
        for (int j = 0; j < N; ++j)
        {
            cout << "一次性输入学生的姓名和学号" << endl;
            cin >> t[i].StuArray[j].s_name >> t[i].StuArray[j].num;
            cout << endl;
        }
    }
}

// 值传递
void printdata(teacher *s, int len)
{
    for (int k = 0; k < len; ++k)
    {
        cout << "老师的名字是" << s[k].name << endl;
        cout << "老师带有的学生有:" << endl;
        for (int i = 0; i < N; ++i)
        {
            cout << "学生" << i << ":" << s[k].StuArray[i].s_name << " " << s[k].StuArray[i].num << endl;
        }
    }
}

int main()
{
    teacher t1[1024];
    int n = 0;
    cout << "请输入老师的个数" << endl;
    cin >> n;
    // 利用数组传递输入数据t1
    allocate_space(t1, n);
    // 打印数据t1
    printdata(t1, n);
    system("pause");
}
