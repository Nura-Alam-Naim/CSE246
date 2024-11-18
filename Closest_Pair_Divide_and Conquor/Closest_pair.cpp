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
const ll N = 1e6 + 1;
vp closed(2);
double min(double a, double b)
{
    return (a < b) ? a : b;
}
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.ss < b.ss;
}
double dis(pair<ll, ll> a, pair<ll, ll> b)
{
    return (double)sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}
double close(vp v, ll size, double d)
{
    double mn = d;
    sort(all(v), comp);
    for (ll i = 0; i < size; i++)
        for (ll j = i + 1; j < size; j++)
            if (dis(v[i], v[j]) < mn)
            {
                mn = dis(v[i], v[j]);
                closed[0] = v[i];
                closed[1] = v[j];
            }
    return mn;
}
double brute(vp &v)
{
    double mn = DBL_MAX;
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = i + 1; j < v.size(); j++)
        {
            if (mn > dis(v[i], v[j]))
            {
                mn = dis(v[i], v[j]);
                closed[0] = v[i];
                closed[1] = v[j];
            }
        }
    }
    return mn;
}
double closestPath(vp v, ll l, ll r)
{
    if(r-l<=2)
        return brute(v);
    ll mid = (r + l) / 2;
    double d1 = closestPath(v, l, mid);
    double d2 = closestPath(v, mid + 1, r);
    double d = min(d1, d2);
    vp strip(r - l + 1);
    ll cnt = 0;
    for (ll i = 0; i <= (r-l); i++)
        if (fabs(v[i].ff - v[mid].ff) < d)
            strip[cnt++] = v[i];
    double d3 = close(strip, cnt,d);
    return min(d3, d);
}
void solve()
{
    //vp v = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    //cout << "Pairs: " << nl;
    vp v(6);
    v[0] = make_pair(2, 3);
    v[1] = make_pair(12, 30);
    v[2] = make_pair(40, 50);
    v[3] = make_pair(5, 1);
    v[4] = make_pair(12, 10);
    v[5] = make_pair(3, 4);
    sort(all(v));
    cout << "Closest Distance: "<<fixed<<setprecision(6)<<closestPath(v, 0, 5) << nl;
    cout << "Closest pairs are (x,y): " << nl;
    for (auto i : closed)
        cout << i.ff << sp << i.ss << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin>>tc;
    while (tc--)
        solve();
}
