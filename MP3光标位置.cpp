#include<iostream>
#include<string>
using namespace std;
int main()
{
    int num;//������Ŀ
    string cmd;//�����ַ�
    while(cin >> num >> cmd)
    {
        int order_first = 1;//ҳ����ʾ�ĵ�һ��λ��
        int order_now = 1;//���λ��
        if(num > 4)//����������4�����
        {
            for(int i = 0;i < cmd.size();i++)
            {
                 if(cmd[i] == 'U')
                 {
                      if(order_now == 1)//����ڵ�һ�׸�
                      {
                          order_first = num - 3;//ҳ�淭ҳ�����һҳ
                          order_now = num;//���ָ���һ�׸�
                      }
                      else if(order_now == order_first)
                      {
                           order_first--;
                           order_now--;//����ҳ���׸�һ��
                       }
                       else if(order_first < order_now)
                           order_now--;//ֻ�й���ƶ�
                  }
                  else if(cmd[i] == 'D')
                  {
                       if(order_now == num)//��������һ�׸�
                       {
                            order_first = 1;
                            order_now = 1;//����ҳ��ͬʱ�任����һҳ�ĵ�һ��
                        }
                        else if(order_now == (order_first + 3))//�жϹ���Ƿ���ҳ����
                        {
                             order_first++;
                             order_now++;
                        }
                        else if(order_first < (order_now + 3))
                         order_now++;
                    }
               }
               for(int i = 0;i < 4;i++)//���ҳ��
               {
                     int flag = order_first + i;
                     if(i < 3)
                         cout << flag << ' ';
                     else cout << flag << endl;
                }
                cout << order_now << endl;
            }
            else {//����С��4�׵����
                for(int i = 0;i < cmd.size();i++)
                {
                    //����ƶ�
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
                //ҳ�治��
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
