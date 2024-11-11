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
ll x1, y, x2, y2;
double ds;
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
double close(vp v, ll size, ll d)
{
    double mn = d;
    sort(all(v), comp);
    for (ll i = 0; i < size; ++i)
        for (ll j = i + 1; j < size and (double)(v[j].ss - v[i].ss) < mn; j++)
            if (dis(v[i], v[j]) < mn)
                mn = dis(v[i], v[j]);

    return mn;
}
double closestPath(vp v, ll l, ll r)
{
    if(r-l<=2)
    {
        double mn = DBL_MAX;
        for (ll i = l; i < r ; i++)
            for (ll j = i + 1; j < r; j++)
                if (dis(v[i], v[j]) < mn)
                {
                    mn = dis(v[i], v[j]);
                    ds = mn;
                    x1 = v[i].ff;
                    y = v[i].ss;
                    x2 = v[j].ff;
                    y2 = v[j].ss;
                }
        return mn;
    }
    ll mid = (r + l) / 2;
    double d1 = closestPath(v, l, mid);
    double d2 = closestPath(v, mid + 1, r);
    double d = min(d1, d2);
    ds = d;
    vp strip(r - l + 1);
    ll cnt = 0;
    for (ll i = 0; i <= (r-l); i++)
        if (abs(v[i].ff - v[mid].ff) < d)
            strip[cnt++] = v[i];
    double d3 = close(strip, cnt,d);
    return min(d3, d);
}
void solve()
{
    vp v(6);
    v[0] = make_pair(2, 3); v[1] = make_pair(12,30);
    v[2] = make_pair(40, 50); v[3] = make_pair(5, 1);
    v[4] = make_pair(12, 10); v[5] = make_pair(3, 4);
    cout << "Pairs: " << nl;
    for (auto i: v)
        cout<< i.ff << sp << i.ss << nl;
    sort(all(v));
    cout << closestPath(v, 0, 5) << nl;
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

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
public:
    int x, y;
};

int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
float min(float x, float y)
{
    return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}
float closestUtil(Point P[], int n)
{

    if (n <= 3)
        return bruteForce(P, n);


    int mid = n / 2;
    Point midPoint = P[mid];

   
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    
    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}


float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestUtil(P, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}

// This code is contributed by rathbhupendra
