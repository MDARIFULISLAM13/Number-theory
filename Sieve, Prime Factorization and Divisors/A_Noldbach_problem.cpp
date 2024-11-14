/**
 *
 * Author : Md.Ariful Islam
 * Date : 14-11-2024
 * time : 23:46:10
 * Problem Name : A_Noldbach_problem
 *
 **/
#ifdef __GNUC__
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl "\n";
#define ft float
#define du double
#define ull unsigned long long
#define vec vector<ll>
const int lm = 1e7 + 123;
bitset<lm> ip;
vector<int> p;
void arif(int n)
{
    p.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        ip[i] = true;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (ip[i] == true)
        {
            for (int j = i * i; j <= n; j += i * 2)
            {
                ip[j] = false;
            }
        }
    }
    ip[2] = true;
    for (int i = 3; i <= n; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(1100);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < p.size() && (p[i] + p[i + 1] + 1) <= n; i++)
    {
        int x = p[i] + p[i + 1] + 1;
        if (ip[x])
        {
            cnt++;
        }
    }
    int k;
    cin >> k;
    if (cnt >= k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}