#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll abs_val(ll num)
{
    ll odd=0; ll even=0;
    while(num)
    {
        ll x = num%10;
        num = ll(num/10);
        if(x%2==0)
            even+=x;
        else
            odd+=x;
    }
    return abs(even-odd);
}

int main()
{
    ll diamond[1000007];

    diamond[0]=0;
    diamond[1]=2; ll col=2;
    for(ll i=2; i<=1000007; i++)
    {
        diamond[i]=0;
        col-=abs_val(i);
        col+=abs_val(2*i -1);
        diamond[i] += (diamond[i-1] + (2*col));
        ll k= abs_val(2*i);
        diamond[i] += k;
        col+=k;
    }
    int t; scanf("%d", &t);
    ll N;
    for(int i=0; i<t; i++)
    {
        scanf("%lld",&N);
        printf("%lld\n", diamond[N]);
    }
    return 0;
}
