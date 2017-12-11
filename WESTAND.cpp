// 10 points
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=0; cin>>t;
    while(t--)
    {
        int k=0; cin>>k;
        vector < pair <int,int> > chef,client;
        vector <int> cost;
        int dish, salary;
        for(int i=0; i<k; i++)
        {
            cin>>dish>>salary;
            chef.push_back(make_pair(dish, salary));
        }
        int n=0; cin>>n;
        int odish, wait;
        for(int i=0; i<n; i++)
        {
            cin>>odish>>wait;
            client.push_back(make_pair(odish,wait));
        }
        float ratio = client[0].first/client[0].second;

        for(int i=0; i<k; i++)
        {
            if(chef[i].first >= ratio)
                cost.push_back(chef[i].second);
        }
        sort(cost.begin(),cost.end());

        if(cost.size()==0)
            cout<<-1<<endl;
        else
            cout<<cost[0]<<endl;
    }
    return 0;
}
