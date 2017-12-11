#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ch;
    while(getline(cin, ch))
    {
        int len = ch.length();
        int arr[len];
        for(int i=0; i<len; i++)
        {
            if(ch[i] =='1')
                arr[i]=1;
            else
                arr[i]=0;
        }
        int count_a=0, count_b=0;
        int shots=0; int flag=0;
        for(int i; i<20; i++)
            cin>>arr[i];
        for(int i=0; i<10; i++)
        {
            if(i%2==0)
            {
                count_a+=arr[i]; ++shots;

                int sub1 = count_a -count_b;
                int sub2 = count_b -count_a;
                int m = (10 - shots)/2;
                if(sub1 > m+1)
                {
                    flag=1;
                    cout<<"TEAM-A"<<" "<<shots<<endl;
                    break;
                }
                else if(sub2 > m)
                {
                    flag=1;
                    cout<<"TEAM-B"<<" "<<shots<<endl;
                    break;
                }
            }
            else
            {
                count_b+=arr[i]; ++shots;
                int sub1 = count_a -count_b;
                int sub2 = count_b -count_a;
                int m = (10 - shots)/2;
                if(sub1 > m)
                {
                    flag=1;
                    cout<<"TEAM-A"<<" "<<shots<<endl;
                    break;
                }
                else if(sub2 > m)
                {
                    flag=1;
                    cout<<"TEAM-B"<<" "<<shots<<endl;
                    break;
                }
            }

        }
        if(flag == 1)
            continue;

        if(count_a > count_b)
            {cout<<"TEAM-A"<<" "<<10<<endl; continue;}
        else if(count_b > count_a)
            {cout<<"TEAM-B"<<" "<<10<<endl; continue;}

        shots=10;
        flag=0;
        for(int i=10; i<20; i++)
        {
            if(i%2 == 0)
            {
                count_a+=arr[i]; ++shots;
            }
            else
            {
                count_b+=arr[i]; ++shots;
                if(count_a > count_b)
                {
                    cout<<"TEAM-A"<<" "<<shots<<endl;
                    flag =1; break;
                }
                else if(count_b > count_a)
                {
                    cout<<"TEAM-B"<<" "<<shots<<endl;
                    flag =1; break;
                }
            }

        }
        if(flag == 0)
            cout<<"TIE"<<endl;
    }
    return 0;
}
