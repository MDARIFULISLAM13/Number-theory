#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int lm = 1e7 + 123;
bitset<lm> ip;
vector<int> p(lm, 0);

// Truncatable prime চেক করা
bool isTruncatablePrime(int n)
{
    int divisor = 10;
    while (divisor <= n)
    {
        if (!ip[n % divisor])
        {
            return false;
        }
        divisor *= 10;
    }
    return true;
}

// Sieve of Eratosthenes
void sieve(int n)
{
    ip[2] = true;
    for (int i = 3; i <= n; i += 2)
    {
        ip[i] = true;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (ip[i])
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                ip[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (ip[i])
        {
            int temp = i;
            bool hasZero = false;

            // Check if the number has digit 0
            while (temp > 0)
            {
                if (temp % 10 == 0)
                {
                    hasZero = true;
                    break;
                }
                temp /= 10;
            }

            // যদি 0 না থাকে এবং truncatable prime হয়
            if (!hasZero && isTruncatablePrime(i))
            {
                p[i] = p[i - 1] + 1;
            }
            else
            {
                p[i] = p[i - 1];
            }
        }
        else
        {
            p[i] = p[i - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(lm);

    int t;
    cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        cout << p[v] << endl;
    }
    return 0;
}
