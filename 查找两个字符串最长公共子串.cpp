#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    while(cin >> str1 >> str2)
    {
        if(str1.size() > str2.size())
            swap(str1,str2);
        string ans;
        for(int i = 0;i < str1.size();i++)
        {
            for(int j = i;j < str1.size();j++)
            {
                string temp = str1.substr(i,j - i + 1);
                if(str2.find(temp) == string::npos)
                    break;
                else if(ans.size() < temp.size())
                {
                    ans = temp;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
