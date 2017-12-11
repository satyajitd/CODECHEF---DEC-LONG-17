#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0; cin>>t;
    while(t--)
    {
        int n=0; cin>>n;
        int ar[n];
        int frq[1000001];
        for(int i=0; i<1000001; i++)
            frq[i]=0;

        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
            ++frq[ar[i]];
        }

        if(n==1)
        {
            cout<<0<<endl;
            cout<<ar[0]<<endl;
            continue;
        }
        else if(n==2)
        {
            if(ar[0] == ar[1])
            {
                cout<<0<<endl;
                cout<<ar[0]<<" "<<ar[1]<<endl;
                continue;
            }
        }
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(frq[ar[i]]>1)
            {
                flag=1; break;
            }
        }
        if(flag==0)
        {
            int temp =ar[0];
            for(int i=0; i<n-1; i++)
                ar[i]=ar[i+1];
            ar[n-1]=temp;
            cout<<n<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<ar[i];
                if(i!= n-1)
                    cout<<" ";
            }
            cout<<endl;
            continue;
        }

        int res[n];
        for(int i=0; i<n; i++)
            res[i]=0;

        vector< pair <int, int> > f1, f2;

        for(int i=0;i<n; i++)
        {
            if(frq[ar[i]]==2)
                f2.push_back(make_pair(ar[i], i));
            if(frq[ar[i]]==1)
                f1.push_back(make_pair(ar[i], i));
        }

        sort(f2.begin(), f2.end());
        sort(f1.begin(), f1.end());
        if(n%2 == 0)
        {
            if(f2.size() %4 ==0)
            {
                for(int i=0; i<f2.size(); i+=4)
                {
                    res[f2[i].second]=f2[i+2].first;
                    res[f2[i+2].second]=f2[i].first;
                    res[f2[i+1].second]=f2[i+3].first;
                    res[f2[i+3].second]=f2[i+1].first;
                }
                for(int i=0; i<f1.size(); i+=2)
                {
                    res[f1[i].second]=f1[i+1].first;
                    res[f1[i+1].second]=f1[i].first;
                }
            }
            else
            {
                for(int i=0; i<f2.size(); i+=4)
                {
                    if(i == f2.size()-2)
                        break;
                    res[f2[i].second]=f2[i+2].first;
                    res[f2[i+2].second]=f2[i].first;
                    res[f2[i+1].second]=f2[i+3].first;
                    res[f2[i+3].second]=f2[i+1].first;
                }
                if(f1.size()==0)
                {
                    res[f2[f2.size()-2].second]=res[f2[0].second];
                    res[f2[f2.size()-1].second]=res[f2[1].second];
                    res[f2[0].second] = f2[f2.size()-2].first;
                    res[f2[1].second] = f2[f2.size()-1].first;
                }
                else if(f1.size() > 0)
                {
                    res[f1[0].second] = f2[f2.size()-2].first;
                    res[f1[1].second] = f2[f2.size()-1].first;
                    res[f2[f2.size()-1].second] = f1[1].first;
                    res[f2[f2.size()-2].second] = f1[0].first;

                    for(int i=2; i<f1.size(); i+=2)
                    {
                        res[f1[i].second]=f1[i+1].first;
                        res[f1[i+1].second]=f1[i].first;
                    }
                }
            }
            cout<<n<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<res[i];
                if(i!=n-1)
                    cout<<" ";
            }
            cout<<endl;
        }
        else
        {
            if(f2.size()%4 == 0)
            {
                for(int i=0; i<f2.size(); i+=4)
                {
                    if(i == f2.size()-4)
                        break;
                    res[f2[i].second]=f2[i+2].first;
                    res[f2[i+2].second]=f2[i].first;
                    res[f2[i+1].second]=f2[i+3].first;
                    res[f2[i+3].second]=f2[i+1].first;
                }

                res[f2[f2.size()-4].second] = f2[f2.size()-2].first;
                res[f2[f2.size()-3].second] = f2[f2.size()-1].first;
                res[f2[f2.size()-2].second] = f1[0].first;
                res[f1[0].second] = f2[f2.size()-4].first;
                res[f2[f2.size()-1].second] = f2[f2.size()-3].first;

                for(int i=1; i<f1.size(); i+=2)
                {
                    res[f1[i].second]=f1[i+1].first;
                    res[f1[i+1].second]=f1[i].first;
                }
                cout<<n<<endl;
                for(int i=0; i<n; i++)
                {
                    cout<<res[i];
                    if(i!=n-1)
                        cout<<" ";
                }
                cout<<endl;
            }
            else
            {
                if(f2.size() == 2 && f1.size()==1)
                {
                    res[f1[0].second] = f2[0].first;
                    res[f2[0].second] = f1[0].first;
                    res[f2[1].second] = f2[1].first;

                    cout<<n-1<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cout<<res[i];
                        if(i!=n-1)
                            cout<<" ";
                    }
                    cout<<endl;
                }
                else if(f1.size() > 1)
                {
                    for(int i=0; i<f2.size(); i+=4)
                    {
                        if(i == f2.size()-2)
                            break;
                        res[f2[i].second]=f2[i+2].first;
                        res[f2[i+2].second]=f2[i].first;
                        res[f2[i+1].second]=f2[i+3].first;
                        res[f2[i+3].second]=f2[i+1].first;
                    }

                    res[f1[0].second] = f2[f2.size()-2].first;
                    res[f2[f2.size()-2].second] = f1[1].first;
                    res[f1[1].second] = f2[f2.size()-1].first;
                    res[f2[f2.size()-1].second] = f1[2].first;
                    res[f1[2].second] = f1[0].first;

                    for(int i=3; i<f1.size(); i+=2)
                    {
                        res[f1[i].second]=f1[i+1].first;
                        res[f1[i+1].second]=f1[i].first;
                    }
                    cout<<n<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cout<<res[i];
                        if(i!=n-1)
                            cout<<" ";
                    }
                    cout<<endl;
                }
                else if(f2.size()>2 && f1.size()==1)
                {
                    for(int i=0; i<f2.size(); i+=4)
                    {
                        if(i == f2.size()-6)
                            break;
                        res[f2[i].second]=f2[i+2].first;
                        res[f2[i+2].second]=f2[i].first;
                        res[f2[i+1].second]=f2[i+3].first;
                        res[f2[i+3].second]=f2[i+1].first;
                    }
                    res[f2[f2.size()-4].second] = f2[f2.size()-6].first;
                    res[f2[f2.size()-3].second] = f2[f2.size()-5].first;
                    res[f2[f2.size()-6].second] = f2[f2.size()-2].first;
                    res[f2[f2.size()-5].second] = f2[f2.size()-1].first;
                    res[f2[f2.size()-2].second] = f2[f2.size()-4].first;
                    res[f2[f2.size()-1].second] = f1[0].first;
                    res[f1[0].second] = f2[f2.size()-3].first;

                    cout<<n<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cout<<res[i];
                        if(i!=n-1)
                            cout<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
