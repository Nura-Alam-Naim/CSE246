//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
const ll N = 1e6 + 1;
int minM(vl &v, int i, int j)
{
    if (i + 1 == j)
        return 0;
    ll cnt = LLONG_MAX;
    for (ll k = i + 1; k < j; k++)
    {
        ll curr = minM(v, i, k) +
                   minM(v, k, j) + v[i] * v[k] * v[j];
        cnt = min(curr, cnt);
    }
    return cnt;
}
ll MCM(vl &v)
{
    ll n = v.size();
    return minM(v, 0, n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vl v(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    cout << MCM(v);
    return 0;
}


