#include<iostream>
#include<string>
using namespace std;
int main()
{
    int num;//歌曲数目
    string cmd;//操作字符
    while(cin >> num >> cmd)
    {
        int order_first = 1;//页面显示的第一首位置
        int order_now = 1;//光标位置
        if(num > 4)//歌曲数大于4的情况
        {
            for(int i = 0;i < cmd.size();i++)
            {
                 if(cmd[i] == 'U')
                 {
                      if(order_now == 1)//光标在第一首歌
                      {
                          order_first = num - 3;//页面翻页到最后一页
                          order_now = num;//光标指最后一首歌
                      }
                      else if(order_now == order_first)
                      {
                           order_first--;
                           order_now--;//光标和页面首歌一起动
                       }
                       else if(order_first < order_now)
                           order_now--;//只有光标移动
                  }
                  else if(cmd[i] == 'D')
                  {
                       if(order_now == num)//光标在最后一首歌
                       {
                            order_first = 1;
                            order_now = 1;//光标和页面同时变换到第一页的第一首
                        }
                        else if(order_now == (order_first + 3))//判断光标是否在页面内
                        {
                             order_first++;
                             order_now++;
                        }
                        else if(order_first < (order_now + 3))
                         order_now++;
                    }
               }
               for(int i = 0;i < 4;i++)//输出页面
               {
                     int flag = order_first + i;
                     if(i < 3)
                         cout << flag << ' ';
                     else cout << flag << endl;
                }
                cout << order_now << endl;
            }
            else {//歌曲小于4首的情况
                for(int i = 0;i < cmd.size();i++)
                {
                    //光标移动
                    if(cmd[i] == 'U')
                    {
                        if(order_now == 1)
                        {
                            order_now = num;
                        }
                        else order_now--;
                    }
                    else if(cmd[i] == 'D')
                    {
                        if(order_now == num)
                            order_now = 1;
                        else order_now++;
                    }
                }
                //页面不变
                 for(int i = 0;i < num;i++)
               {
                     int flag = order_first + i;
                     if(i < num - 1)
                         cout << flag << ' ';
                     else cout << flag << endl;
                }
                cout << order_now << endl;
            }
     }
}
