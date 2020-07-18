#include<bits/stdc++.h>

using namespace std;

int required;
vector<long long> v;
long long pows[11][18];
long long pow(long long a, long long b)
{
    if (a == 0)
        return 0;
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 != 0)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
long long getmaxelement(long long pref, int ind, int num)
{
    long long te = 1;
    for (int i = 0; i < ind; i++)
    {
        pref += 9 * te;
        te *= 10;
    }
    return pref;
}
long long getminimumdigitpow(long long pref, int ind, int num)
{
    long long sum = 0;
    for (int i = num; i > num - ind; i--)
        pref /= 10;
    for (int i = num - ind; i >= 0; i--, pref /= 10)
        sum += pows[(int)(pref % 10)][num];
    return sum;
}
long long getmaxdigitpow(long long pref, int ind, int num)
{
    long long sum = 0;
    for (int i = num; i > num - ind; i--)
    {
        sum += pows[9][num];
        pref /= 10;
    }
    for (int i = num - ind; i >= 0; i--, pref /= 10)
        sum += pows[(int)(pref % 10)][num];
    return sum;
}
void GENERATE(long long pref, int ind, int num)
{
    if (v.size() >= required)
        return;
    if (pref > getmaxdigitpow(pref, ind, num))
        return;
    if (getmaxelement(pref, ind, num) < getminimumdigitpow(pref, ind, num))
        return;
     if (ind > 0)
        for (int i = 0; i <= 9; i++)
            GENERATE(pref + i * pows[10][ind - 1], ind - 1, num);
    else if (getmaxelement(pref, ind, num) == pref)
        if (pref != 0 && pref != 1)
            v.push_back(pref);
}
int main()
{
    for (int i = 0; i < 18; i++)
        for (int j = 0; j <= 10; j++)
            pows[j][i] = pow(j, i);
    int numdigits = 1;
    required=30;
    v.push_back(1L);
    while (required > v.size())
    {
        GENERATE(0, numdigits, numdigits);
        numdigits++;
    }
    for (int i = 0; i < required; i++)
        cout << v[i] << endl;
}