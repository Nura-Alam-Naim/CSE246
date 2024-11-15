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
const ll N = 5e3 + 1;
ll H = 0;
ll L = 0;
ll H_partition(vl &v, ll l, ll h)
{
    ll pivot = v[l];
    ll i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (v[i] <= pivot);
        do
        {
            j--;
        } while (v[j] > pivot);

        if (i < j)
        {
            swap(v[i], v[j]);
            H++;
        }
            
    } while (i < j);

    swap(v[l], v[j]);
    H++;
    return j;
}
void H_quickSort(vl &v, ll l, ll h)
{
    if (l < h)
    {
        ll j = H_partition(v, l, h);
        H_quickSort(v, l, j);
        H_quickSort(v, j + 1, h);
    }
}
ll L_partition(vl &v, ll l, ll r)
{
    ll pivot = v[r];
    ll i = l - 1;
    for (ll j = l; j <= r - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
            L++;
        }
    }
    swap(v[i + 1], v[r]);
    L++;
    return i + 1;
}
void L_quickSort(vl &v, ll l, ll r)
{
    if (l < r)
    {
        ll pi = L_partition(v, l, r);
        L_quickSort(v, l, pi - 1);
        L_quickSort(v, pi + 1, r);
    }
}
void solve()
{
    vl a(N), b(N);
    for (ll i = 0; i < N;i++)
        a[i] = rand();
    for (ll i = 0; i < N;i++)
        b[i] = a[i];
    H_quickSort(a, 0, N);
    L_quickSort(b, 0, N-1);
    cout << "Number of Interchange in Hoare's partition: " << H << nl;
    cout << "Number of Interchange in Lomuto's partition partition: " << L << nl;
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