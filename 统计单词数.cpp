#include<iostream>
#include<string>
using namespace std;

void transform(string &s)
{
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == ' ')
            continue;
        if(s[i] <= 90)
            s[i] = s[i] + 'a' - 'A';
    }
}

bool match(string w,string s,int i)
{
    int j;
    for(j = 0;j < w.size();j++)
    {
        if(w[j] != s[i])
            break;
        i++;
    }
    if(j == w.size() && (s[i] == ' ' || i == s.size()))
        return true;
    else return false;
}
int main()
{
    string word;
    string sentence;
    getline(cin,word);
    getline(cin,sentence);
    transform(word);
    transform(sentence);
    int first = -1,count = 0;
    for(int i = 0;i < sentence.size();i++)
    {
        if(sentence[i] == word[0] && (i == 0 ||sentence[i - 1] == ' '))
        {
            if(match(word,sentence,i))
            {
                count++;
                if(first == -1)
                    first = i;
                i += word.size() - 1;
            }
        }
    }
    if(first == -1)
        cout << -1 << endl;
    else cout << count << " " << first << endl;
    return 0;
}
