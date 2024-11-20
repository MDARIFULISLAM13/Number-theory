/**
 *
 * Author : Md.Ariful Islam
 * Date : 20-11-2024
 * time : 23:22:56
 * Problem Name : linear_sieve
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
#define mem(dp, i) memset(dp, i, sizeof(dp));
const int mx = 1e7; // max limit 4e8;
vector<int> p;
vector<int> ip(mx + 1);
void sieve()
{
    for (int i = 2; i <= mx; ++i)
    {
        if (ip[i] == 0)
        {
            p.push_back(i);
            ip[i] = i;
        }
        for (int j = 0; i * p[j] <= mx; ++j)
        {
            ip[i * p[j]] = p[j];
            if (ip[i] == p[j])
            {
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    for (auto i : p)
    {
        cout << i << endl;
    }
    return 0;
}