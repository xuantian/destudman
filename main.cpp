
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
struct stu
{
    int num;//ѧ��
    char name[20];//����
    double score[3];//����
    double sums;//�ܳɼ�
    double avers;//aver�ɼ�
};
int search(struct stu s[],int n ,int x);//����ѧ��ѧ�Ų���ѧ������Ϣ�����ҵ��򷵻ظ�ѧ�����±꣬���򷵻�-1��
void cal(struct stu s[]);//�������ѧ�����ܳɼ���ƽ���ɼ�
void aver(struct stu s[],int n);//������Ƶ�ƽ���ɼ���
void sort(struct stu s[],int n);//��ѧ����ƽ���ɼ���������
void max(struct stu s[],int n);//�ҳ�������ã�ƽ���ɼ���ߣ���ѧ����Ϣ��
void output(struct stu s[],int n);//���ѧ������Ϣ��
void showMenu();//��ʾ�˵���
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
        cout<<"������ѡ��"<<endl;
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
            cout<<"������ѧ��"<<endl;
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
            cout << "�������"<<endl;
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
    cout<<"������õ�ͬѧ"<< endl;
            cout <<"ѧ��\t" <<"����\t" << "����\t"<<"��ѧ\t"<<"Ӣ��\t" <<"�ܳɼ�\t" <<"ƽ���ɼ�\t" << endl;
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
            cout <<"ѧ��\t" <<"����\t" << "����\t"<<"��ѧ\t"<<"Ӣ��\t" <<"�ܳɼ�\t" <<"ƽ���ɼ�\t" << endl;
            cout <<s[i].num<<"\t" <<s[i].name<< s[i].score[0]<<"\t"<< s[i].score[1]<<"\t"<< s[i].score[2]<<"\t"<< s[i].sums<<"\t" << s[i].avers<<"\t" << endl;
        }
        else
        {
            cout << "�������"<<endl;
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
     cout <<"ѧ��\t" <<"����\t" << "����\t\t"<<"��ѧ\t"<<"Ӣ��\t" <<"�ܳɼ�\t" <<"ƽ���ɼ�\t" << endl;
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
    cout <<"������1~6�ڵ�����"<<endl;
    cout << "1.���ѧ������Ϣ" << endl;
    cout << "2.������Ƶ�ƽ���ɼ�" << endl;
    cout << "3.��ѯָ��ѧ�ŵ�ѧ����Ϣ" << endl;
    cout << "4.������õ�ѧ����Ϣ" << endl;
    cout << "5.��ѧ����ƽ���ɼ���������" << endl;
    cout << "6.����" << endl;
    for( j = 0; j < 40; ++j)
        cout << "*";
    cout << endl;
}
void output(struct stu s[],int n)
{
    int i;
    cout <<"ѧ��\t" <<"����\t" << "����\t\t"<<"��ѧ\t"<<"Ӣ��\t" <<"�ܳɼ�\t" <<"ƽ���ɼ�\t" << endl;
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
    cout << "����ƽ����\t"<<"��ѧƽ����\t"<<"Ӣ��ƽ����\t" << endl;
    cout << as[0]<<"\t\t"<<as[1]<<"\t\t"<<as[2]<<"\t\t" << endl;

}

