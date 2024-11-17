/**
 *
 * Author : Md.Ariful Islam
 * Date : 17-11-2024
 * time : 22:03:38
 * Problem Name : D_Soldier_and_Number_Game
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
const int lm = 5000000 + 123;
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
int dp[lm];
int solve(int n)
{
    int cnt = 0;
    for (int i : p)
    {
        if (1ll * i * i > n)
        {
            break;
        }
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                ++cnt;
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= lm; i++)
    {
        dp[i] = solve(i) + dp[i - 1];
    }
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a] - dp[b] << endl;
    }

    return 0;
}