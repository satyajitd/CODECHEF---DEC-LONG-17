#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll min_m(ll x, ll y, ll z)
{
  return (x <= y)? ((x <= z)? x : z) : ((y <= z)? y : z);
}

ll max_m(ll x, ll y, ll z)
{
  return (x <= y)? ((y <= z)? z : y) : ((x <= z)? z : x);
}

ll solution(ll x, ll y, ll z, ll a, ll b, ll c)
{
    ll mn = min_m(x,y,z);
    ll mx = max_m(x,y,z);
    ll sum = x+y+z;
    ll mid = sum -(mn + mx);

    // only A
    ll cost = sum*a;

    // case : C operation - 1
    ll cost1 = c;
    ll mn1 = mn-1; ll mx1 = mx-1; ll mid1 = mid -1;
    // C-1 && B-0
    ll sum1 =sum-3;
    cost1 += (sum1*a);
    if(cost1<=cost)
        cost = cost1;
    //C-1 && B - limit
    ll limit;
    cost1 = c;
    if((mn1 == mid1 && mid1!=mx1) || (mn1!=mid1 && mid1!=mx1))
        limit = (sum1/2 <= (sum1-mx1) ? sum1/2 : (sum1-mx1));
    else
        limit = sum1/2;
    sum1 -=(limit*2);
    cost1 += (limit*b);
    if(sum1!=0)
        cost1 += (sum1*a);
    if(cost1<=cost)
        cost = cost1;
    // case : C operation - mn
    cost1 = mn*c;
    mn1 = 0; mx1 = mx-mn; mid1 = mid-mn;
    sum1 = mn1 + mx1 + mid1;
    if(mx1 == 0 && mid1 ==0)
    {
        if(cost1<=cost)
            cost = cost1;
    }
    else
    {
        // C - mn && B - 0
        cost1+=(sum1*a);
        if(cost1<=cost)
            cost = cost1;
        // C - mn && B - limit
        cost1 = mn*c;
        if((mn1 == mid1 && mid1!=mx1) || (mn1!=mid1 && mid1!=mx1))
            limit = (sum1/2 <= (sum1-mx1) ? sum1/2 : (sum1-mx1));
        else
            limit = sum1/2;
        sum1 -=(limit*2);
        cost1 += (limit*b);
        if(sum1!=0)
            cost1 += (sum1*a);
        if(cost1<=cost)
            cost = cost1;
    }
    // C - abs(mx - (mn+mid))
    if(abs(mx-(mn+mid))<mn)
    {
        cost1 = c*abs(mx-(mn+mid));
        sum1 = sum -(3*abs(mx-(mn+mid)));
        // B - 0
        cost1+=(sum1*a);
        if(cost1<=cost)
            cost = cost1;
        // B - limit
        cost1 = c*abs(mx-(mn+mid));
        mn1 = mn - abs(mx-(mn+mid)); mx1 = mx-abs(mx-(mn+mid)); mid1 = mid-abs(mx-(mn+mid));
        if((mn1 == mid1 && mid1!=mx1) || (mn1!=mid1 && mid1!=mx1))
            limit = (sum1/2 <= (sum1-mx1) ? sum1/2 : (sum1-mx1));
        else
            limit = sum1/2;
        sum1 -=(limit*2);
        cost1 += (limit*b);
        if(sum1!=0)
            cost1 += (sum1*a);
        if(cost1<=cost)
            cost = cost1;
    }
    // B - 1
    sum1 = sum - 2;
    cost1 = b;
    if(sum1!=0)
        cost1+=(sum1*a);
    if(cost1<=cost)
        cost = cost1;
    //B - limit
    if((mn == mid && mid!=mx) || (mn!=mid && mid!=mx))
        limit = (sum/2 <= (sum-mx) ? sum/2 : (sum-mx));
    else
        limit = sum/2;

    cost1 = limit*b;
    sum1 = sum - (limit*2);
    if(sum1!=0)
        cost1+=(sum1*a);
    if(cost1<=cost)
        cost = cost1;
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0; cin>>t;
    while(t--)
    {
        int x,y,z,a,b,c;
        cin>>x>>y>>z>>a>>b>>c;
        cout<<solution(x,y,z,a,b,c)<<endl;
    }
    return 0;
}
