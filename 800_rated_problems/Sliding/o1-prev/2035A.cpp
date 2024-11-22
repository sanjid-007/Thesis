#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m,r,c;
        scanf("%lld%lld%lld%lld",&n,&m,&r,&c);
        ll N = n * m;
        ll i = (r -1) * m + c;
        ll delta = (m - (i % m)) % m;
        ll Start = i + 1 + delta;
        ll number_m = 0;
        if(Start <= N)
            number_m = ((N - Start) / m) + 1;
        ll total_movements = N - i;
        ll total_distance = number_m * m + (total_movements - number_m) * 1;
        printf("%lld\n", total_distance);
    }
    return 0;
}
