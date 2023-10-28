#include <bits/stdc++.h>
using namespace std;
vector<int> mainvec;
vector<int> mainvec1;
vector<int> visited(3000001);
int inp;
int count1 = 0;
void bfs()
{
    for (int j = 0; j < 100001; j++)
    {
        auto nowvec = mainvec;
        for (int i : nowvec)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                if (i == inp)
                {
                    cout << count1;
                    return;
                }
                else
                {
                    if (visited[i-1] == 0)
                        mainvec1.push_back(i-1);
                    if (visited[i + 1] == 0)
                        mainvec1.push_back(i+1);

                    if (visited[i *2] == 0 && i *2 <100001)
                        mainvec1.push_back(i*2);
                }
            }
        }
        mainvec = mainvec1;
        count1++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;
    cin >> inp;
    if (a > inp)
    {
        cout << a- inp;
        return 0;
    }
    mainvec.push_back(a);
    bfs();
    return 0;
}