#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T,n,k;//数据组数
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        vector<int> num(2*n);
        for(int j = 0;j < 2*n;j++)
        {
            cin >> num[j];
        }
        
        while(k--)
        {
            vector<int> ans(num.begin(),num.end());
            int i =0;
            for(int j =0;j < 2*n;j += 2)
            {
                num[j] = ans[i];
                i++;
            }
            for(int j =1;j < 2*n;j += 2)
            {
                num[j] = ans[i];
                i++;
            }
        }
        for(int j = 0;j < 2*n;j++)
        {
            if(j < 2*n - 1)
                cout << num[j] << ' ' ;
            else cout << num[j]<< endl;
        }
    }
}
