#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void Print_left(string s,int left_num)
{
    for(int i = 0;i < left_num;i++)
        cout << s[i];
    cout << endl;
}
void Print_right(string s,int left_num)
{
    for(int i = left_num + 1;i < s.size();i++)
        cout << s[i];
    cout << endl;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        int left_num = 0,right_num = 0;
        int flag = 0;
        for(int i = 0;i < s.size();i++)
        {
            
            if(s[i] == '-')
                flag = i;
            if(s[i] == ' ' && flag == 0)
            {
                left_num++;//��������
            }
            else if(s[i] == ' ' && flag != 0)
            {
                right_num++;//��������
            }
        }
        right_num++;
        left_num++;
        //10 ������Ƚ����⣬��������
        if(left_num == right_num)
        {
            int i = 0;
            int count = 0;
            while(s[i] != ' ' && i < flag)
            {
                count++;
                i++;
            }
            if(count == 2)
            {
                if(s[left_num + 1] >= '3' && s[left_num + 1] <= '9')
                {
                    Print_left(s,flag);
                    break;
                }
                else{
                    Print_right(s,flag);
                    break;
                }
            }
            else{
                i = flag + 1;
                count = 0;
                while(s[i] != ' ' && i < s.size())
                {
                    count++;
                    i++;
                }
                if(count == 2)
                {
                    if(s[0] >= '3' && s[0] <= '9')
                    {
                        Print_right(s,flag);
                        break;
                    }
                    else{
                        Print_left(s,flag);
                        break;
                    }
                }
            }
        }

        //������������ȵ������1.����ը 2.��ը�� 
        //����ƶ��һ��
        if(left_num != right_num)
        {
            //����ը
            if(s.find("joker JOKER") != -1)
            {
                cout << "joker JOKER" << endl;
                break;
            }
            
            
            else if(left_num == 4 || right_num == 4){
                if(left_num == 4)
                    Print_left(s, flag);
                else Print_right(s,flag);
                break;
            }
            else {
                cout << "ERROR" << endl;
                break;
            }
        }
        
        //���ӡ����ӡ�˳�ӡ�������ֻ�Ƚ���λ����
        if(s[0] == '2' || s[left_num+1] == '2')
        {
            if(s[0] == '2')
            {
                Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
        else if(s[0] == 'A' || s[left_num+1] == 'A')
        {
            if(s[0] == 'A')
            {
                Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
        else if(s[0] == 'K' || s[left_num+1] == 'K')
        {
            if(s[0] == 'K')
            {
                Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
        else if(s[0] == 'Q' || s[left_num+1] == 'Q')
        {
            if(s[0] == 'Q')
            {
                Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
        else if(s[0] == 'J' || s[left_num+1] == 'J')
        {
            if(s[0] == 'J')
            {
                 Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
        else{
            if(s[0] > s[left_num + 1])
            {
                 Print_left(s,flag);
            }
            else {
                Print_right(s,flag);
            }
        }
    }
    return 0;
}
