#include<iostream>
using namespace std;
int funtion(int n,int m)
{
    if(n == 1 || m == 1)
    {
        return n+m;
    }
    else return funtion(n-1,m)+funtion(n,m-1);
}
int main()
{
    int m,n;
    while(cin >> m >> n)
    {
        cout << funtion(n,m) << endl;
    }
    return 0;
}