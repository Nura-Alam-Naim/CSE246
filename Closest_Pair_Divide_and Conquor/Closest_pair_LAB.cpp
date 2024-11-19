//|ADMIRAL_AUDITORE|//
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll, ll> > vp;
#define nl "\n"
#define sp ' '
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
ll N = 10000;   // dont use 1000000
vp closed(2);
double min(double a, double b)
{
    return (a < b) ? a : b;
}
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.ss < b.ss;
}
double dis(pair<ll, ll> a, pair<ll, ll> b)
{
    return (double)sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}
double brute(vp &v)
{
    double mn = DBL_MAX;
    for (ll i = 0; i < (ll)v.size(); i++)
        for (ll j = i + 1; j <(ll) v.size(); j++)
            if (mn > dis(v[i], v[j]))
            {
                mn = dis(v[i], v[j]);
                closed[0] = v[i];
                closed[1] = v[j];
            }
    return mn;
}
double close(vp &v, double mnn)
{
    double mn = mnn;
    for (ll i = 0; i < (ll)v.size(); i++)
        for (ll j = i + 1; j < min(i + 10, (ll)v.size()); j++)
            if (mn > dis(v[i], v[j]))
            {
                mn = dis(v[i], v[j]);
                closed[0] = v[i];
                closed[1] = v[j];
            }
    return mn;
}
double ClosestPair(vp &v)
{
    ll n = v.size();
    if (n <= 3)
        return brute(v);
    vp l(v.begin(), v.begin() + n / 2);
    vp r(v.begin() + n / 2 + 1, v.end());
    double mn = min(ClosestPair(l), ClosestPair(r));
    vp strip;
    for (auto it : v)
        if (fabs(it.ff - v[n / 2].ff) < mn)
            strip.push_back(it);
    sort(all(strip), comp);
    double d3 = close(strip, mn);
    return min(d3, mn);
}
void solve()
{    // vp v = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    vp v(N), a(N);
    for (ll i = 0; i < N;i++)
    {
        v[i] = make_pair((ll)rand(), (ll)rand());
        a[i]=v[i];
    }
    clock_t start=clock();
    brute(a);
    start = clock() - start;
    cout << "Runtime in naive algorithm: " << fixed << setprecision(6) << (double)((double)start/CLOCKS_PER_SEC) << " seconds"<< nl;
    clock_t s = clock();
    sort(all(v));
    double mn = ClosestPair(v);
    s = clock() - s;
    cout << "Runtime in ClosestPath algorithm: " << fixed << setprecision(6) << (double)((double)s/CLOCKS_PER_SEC) << " seconds"<< nl;
    cout << "Closest Distance: " << fixed << setprecision(6) << mn << nl;
    cout << "Closest pairs are (x,y): " << nl;
    for (auto i : closed)
        cout << i.ff << sp << i.ss << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin>>tc;
    while (tc--)
        solve();
}
