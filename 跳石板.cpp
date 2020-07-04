#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//void divisorNum(vector<int> *div,int n);
//记算所有公约数
void divisorNum(vector<int> &div,int n)
{
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            div.push_back(i);
            if(n / i != i)
                div.push_back(n / i);
        }
    }
}

int Jump(int n,int m)
{
    vector<int> stepNum(m + 1,0);
    stepNum[n] = 1;
    for(int i = n;i < m;i++)
    {
        if(stepNum[i] == 0)
            continue;
        vector<int> div;
        divisorNum(div,i);
        for(int j = 0;j < div.size(); j++)
        {
            if((div[j] + i <= m) && (stepNum[div[j] + i] != 0))
                stepNum[div[j] + i] = min(stepNum[i] + 1,stepNum[div[j] + i]);
            else if(div[j] + i <= m)
                stepNum[div[j] + i] = stepNum[i] + 1;
        }
    }
    if(stepNum[m] == 0)
        return -1;
    else
        return stepNum[m] - 1;
}

int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        cout << Jump(N,M);
    }
    return 0;
}
