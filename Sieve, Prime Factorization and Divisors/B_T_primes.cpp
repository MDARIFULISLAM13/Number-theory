/**
 *
 * Author : Md.Ariful Islam
 * Date : 20-08-2024
 * time : 04:53:23
 *
 **/
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
map<long long, bool> m;
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
            for (int j = i + i; j <= n; j += i)
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
void solve(ll v)
{
    int ans = 0;
    ll V = v;
    for (auto i : p)
    {
        if (1ll * i * i > v)
        {
            break;
        }
        if (v % i == 0)
        {
            int cnt = 1;
            while (v % i == 0)
            {
                cnt++;
                v /= i;
            }
            ans += cnt;
        }
    }
    if (ans == 3)
    {
        m[V] = true;
        cout << "YES\n";
    }
    else
    {
        m[V] = false;
        cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);
    int t;
    cin >> t;
    while (t--)
    {
        ll v;

        cin >> v;
        if (m[v])
        {
            if (m[v] == true)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            solve(v);
        }
    }

    return 0;
}