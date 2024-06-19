#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[1001];
bool found[1001];
int SelNode[1001];
bool dfs(int x);
int count;
int main(void)
{
    int N, M, idx, idxv, count=0;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        cin >> idx;
        for(int j=0;j<idx;j++)
        {
            cin >> idxv; 
            arr[i].push_back(idxv);
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            found[j]=0;
        }
        if(dfs(i)) count++;
        else continue;
        for(int j=0;j<=M;j++)
        {
            found[j]=0;
        }
        if(dfs(i)) count++;
    }
    cout << count;
    return 0;
}

bool dfs(int n)
{
    for(int i=0;i<arr[n].size();i++)
    {
        int tmp=arr[n][i];
        if(found[tmp]) continue;
        found[tmp]=true;
        if(SelNode[tmp]==0 || dfs(SelNode[tmp]))
        {
            SelNode[tmp]=n;
            return true;
        }
    }
    return false;
}

//간단한 이분매칭 응용으로 문제를 해결했다.