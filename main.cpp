
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
struct stu
{
    int num;//学号
    char name[20];//姓名
    double score[3];//分数
    double sums;//总成绩
    double avers;//aver成绩
};
int search(struct stu s[],int n ,int x);//根据学生学号查找学生的信息，若找到则返回该学生的下标，否则返回-1。
void cal(struct stu s[]);//计算各个学生的总成绩和平均成绩
void aver(struct stu s[],int n);//计算各科的平均成绩。
void sort(struct stu s[],int n);//按学生的平均成绩降序排序。
void max(struct stu s[],int n);//找出考得最好（平均成绩最高）的学生信息。
void output(struct stu s[],int n);//输出学生的信息。
void showMenu();//显示菜单。
int main(int argc, char* argv[])
{
    int x,z;
    struct stu ad[5]= {{1601,"LiLi",{51,62,55}},
        {1602,"WangTao",{62,73,52}},
        {1603,"ZhaoYi",{73,66,76}},
        {1604,"LiuFang",{84,88,76}},
        {1605,"ShenBin",{95,90,88}}
    };
    cal(ad);
    while(1)
    {
        showMenu();
        cout<<"请输入选项"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
            output(ad,5);
            break;
        case 2:
            aver(ad,5);
            break;
        case 3:
            cout<<"请输入学号"<<endl;
            cin>>z;
            search(ad,5,z);
            break;
        case 4:
            max(ad,5);
            break;
        case 5:sort(ad,5);break;
        case 6:
            exit(0);
        default:
            cout << "输入错误"<<endl;
        }
    }

}
void max(struct stu s[],int n)
{
    int i,k;
    for(i=0; i<n-1; i++)
    {
        if(s[i].avers<s[i+1].avers)
        {
            k=i+1;
        }
        else
            k=i;

    }
    cout<<"考得最好的同学"<< endl;
            cout <<"学号\t" <<"姓名\t" << "语文\t"<<"数学\t"<<"英语\t" <<"总成绩\t" <<"平均成绩\t" << endl;
            cout <<s[k].num<<"\t" <<s[k].name<< s[k].score[0]<<"\t"<< s[k].score[1]<<"\t"<< s[k].score[2]<<"\t"<< s[k].sums<<"\t" << s[k].avers<<"\t" << endl;
}
void cal(struct stu s[])
{
    int i,j;
    for(i=0; i<5; i++)
    {
        s[i].sums=0;
        s[i].avers=0;
        for(j=0; j<3; j++)
        {
            s[i].sums+=s[i].score[j];
        }
        s[i].avers=s[i].sums/3;
    }
}
int search(struct stu s[],int n ,int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(s[i].num==x)
        {
            cout <<"学号\t" <<"姓名\t" << "语文\t"<<"数学\t"<<"英语\t" <<"总成绩\t" <<"平均成绩\t" << endl;
            cout <<s[i].num<<"\t" <<s[i].name<< s[i].score[0]<<"\t"<< s[i].score[1]<<"\t"<< s[i].score[2]<<"\t"<< s[i].sums<<"\t" << s[i].avers<<"\t" << endl;
        }
        else
        {
            cout << "输入错误"<<endl;
            break;
        }

    }
}
void sort(struct stu s[],int n)
{
    int i,j;
    struct stu p,temp[5];
    for(i=0;i<n;i++)
        temp[i]=s[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(temp[j].avers>temp[i].avers)
                {
                    p=temp[i];
                    temp[i]=temp[j];
                    temp[j]=p;
                }
            }
    }
     cout <<"学号\t" <<"姓名\t" << "语文\t\t"<<"数学\t"<<"英语\t" <<"总成绩\t" <<"平均成绩\t" << endl;
    for(i=0; i<n; i++)
    {
        cout <<temp[i].num<<"\t" <<temp[i].name<<"\t\t" << temp[i].score[0]<<"\t"<< temp[i].score[1]<<"\t"<< temp[i].score[2]<<"\t"<< temp[i].sums<<"\t" << temp[i].avers<<"\t" << endl;
    }
}
void showMenu()
{
	int j;
    for(j = 0; j < 40; ++j)
        cout << "*";
    cout << endl;
    cout <<"请输入1~6内的数字"<<endl;
    cout << "1.输出学生的信息" << endl;
    cout << "2.计算各科的平均成绩" << endl;
    cout << "3.查询指定学号的学生信息" << endl;
    cout << "4.考得最好的学生信息" << endl;
    cout << "5.按学生的平均成绩降序排序" << endl;
    cout << "6.结束" << endl;
    for( j = 0; j < 40; ++j)
        cout << "*";
    cout << endl;
}
void output(struct stu s[],int n)
{
    int i;
    cout <<"学号\t" <<"姓名\t" << "语文\t\t"<<"数学\t"<<"英语\t" <<"总成绩\t" <<"平均成绩\t" << endl;
    for(i=0; i<n; i++)
    {
        cout <<s[i].num<<"\t" <<s[i].name<<"\t\t" << s[i].score[0]<<"\t"<< s[i].score[1]<<"\t"<< s[i].score[2]<<"\t"<< s[i].sums<<"\t" << s[i].avers<<"\t" << endl;
    }
}
void aver(struct stu s[],int n)
{
    int i,j;
    int as[3]= {0};
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            as[i]+=s[j].score[i];
        }
        as[i]=as[i]/n;
    }
    cout << "语文平均分\t"<<"数学平均分\t"<<"英语平均分\t" << endl;
    cout << as[0]<<"\t\t"<<as[1]<<"\t\t"<<as[2]<<"\t\t" << endl;

}

