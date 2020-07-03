#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        int flag = 0;//标记双引号
        int count = 1;//记录字符数
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] == ' ' && flag == 0)
            {
                count++;
            }
            if(str[i] == '"')
            {
                flag ^= 1;
            }
        }
        cout << count << endl;
        flag = 0;
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] != ' ')
                cout << str[i];
            if(str[i] == ' ' && flag == 0)
                cout << endl;
            if(str[i] == '"')
                flag ^= 1;
        }
        cout << endl;
    }
}