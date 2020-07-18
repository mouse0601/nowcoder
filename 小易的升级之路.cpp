#include<iostream>
#include<vector>
using namespace std;
int function(int a,int b)
{
    while((a-b)!=0)
    {
        if(a > b)
            a = a - b;
        else b = b - a;
    }
    return a;
}
int main()
{
    int a,n;
    
    while(cin >> n >> a)
    {
        vector<int> b(n,0);//注意数组空间的分配
        int num;
        for(int i = 0;i < n;i++)
        {
            cin >>  b[i];
        }
        for(int i = 0;i < n;i++)
        {
            if(a > b[i])
                a += b[i];
            else{
                num = function(a,b[i]);
                a += num;
            }
        }
        cout << a << endl;
    }
}
