#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(void)
{
    string Index, Command;
    int n=0;
    deque<char> FirstDeque, SecondDeque;
    cin >> Index;
    for(char c : Index)
    {
        FirstDeque.push_back(c);
    }
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> Command;
        if(Command=="L")
        {
            if(!FirstDeque.empty())
            {
                SecondDeque.push_back(FirstDeque.back());
                FirstDeque.pop_back();
            }
        }
        else if(Command=="D")
        {
            if(!SecondDeque.empty())
            {
                FirstDeque.push_back(SecondDeque.back());
                SecondDeque.pop_back();
            }
        }
        else if(Command=="B")
        {
            if(!FirstDeque.empty())
            {
                FirstDeque.pop_back();
            }
        }
        else
        {
            if(Command!="P")
            {
                FirstDeque.push_back(Command[0]);   
            }
            else{
                i--;
                continue;
            }
        }
    }
    while(!FirstDeque.empty())
    {
        cout << FirstDeque.front();
        FirstDeque.pop_front();
    }
    while(!SecondDeque.empty())
    {
        cout << SecondDeque.back();
        SecondDeque.pop_back();
    }
    return 0;
}