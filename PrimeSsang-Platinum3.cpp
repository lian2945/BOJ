#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> Prime(2001, true); //Prime Bool형에 vector
class resets { //class 선언
public:
	resets(); //생성자 Constructor
	vector<bool> visited; //방문한지 안한지 확인하는 Bool형에 vector
	vector<int> sides[1001]; //변 연결되어 있는 vector EX) 1, 2 sides[1].push_back(2)
	vector<int> linkedline; //실제로 연결시킨 vector
};

resets::resets(void) //생성자 선언
{
	visited.resize(1001, false); //다 false로 바꾸기
	linkedline.resize(1001, 0); //다 연결 없애기
}

void Primes(void) //에라토스테네스의 체를 이용해서 Prime구하기
{
	for (int i = 2;i*i <= 2000;i++) 
	{
		if (Prime[i])
		{
			for (int j = i * i;j <= 2000;j += i)
			{
				Prime[j] = false;
			}
		}
	}
}

bool dfs(int n, resets *a) //dfs를 이용하여, 이분매칭하기
{
	for (int i = 0;i < a->sides[n].size();i++)
	{
		int tmp = a->sides[n][i];
		if (a->visited[tmp]) continue;
		a->visited[tmp] = true;
		if (a->linkedline[tmp] == 0 || dfs(a->linkedline[tmp], a))
		{
			a->linkedline[tmp] = n;
			return true;
		}
	}
	return false;
}

int main(void)
{
	vector<int> index; //그냥 값 받는 vector
	vector<int> Flist; //첫번째 값과 소수가 되는 값들의 vector
	vector<int> Okay; //실제로 이분매칭이 되는 소수를 담은 vector
	int n, cnt=0; //n은 갯수
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	index.resize(n);
	Primes();
	for (int i = 0;i < n;i++)
	{
		cin >> index[i];
		if (i != 0 && Prime[index[i] + index[0]]) Flist.push_back(index[i]); //소수이면 Flist에 넣기
	}
	for (int Fl : Flist)
	{
		cnt = 0;
		resets *a = new resets();
		a->sides[Fl].push_back(index[0]); //두개의 노드 다 연결하기
		a->sides[index[0]].push_back(Fl);
		for (int i = 1;i < n;i++)
		{
			if (index[i] == Fl) continue;
			for (int j = 1;j < n;j++)
			{
				if (index[j] == Fl) continue;
				if (Prime[index[i] + index[j]])
				{
					a->sides[index[i]].push_back(index[j]);
					a->sides[index[j]].push_back(index[i]);
				}
			}
		}
        //위 코드는 노드를 연결하는 것.(소수인것들 끼리)
		for (int i = 0;i < n;i++)
		{
			fill(a->visited.begin(), a->visited.end(), false);
			if(dfs(index[i], a)) cnt++;
		}
		if (cnt == n) Okay.push_back(Fl); //매칭된게 입력받은 갯수보다 같으면 Okay에 넣기
	}
	if (Okay.empty()) cout << -1; //okay가 없으면 -1을 출력
	else //있으면 sort해서 출력
	{
		sort(Okay.begin(), Okay.end());
		for (int i : Okay)
		{
			cout << i << " ";
		}
	}
	return 0;
}