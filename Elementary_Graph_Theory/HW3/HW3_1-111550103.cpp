#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int Int;
struct bridge
{
    int p0,p1;
    Int cost;
};

bool cmp(bridge p,bridge q)
{
    return p.cost<q.cost;
}

int a[100000],ensure[100000];
vector <bridge> b;
vector <int> en[100001];

int main()
{
    int q,n,m;
    cin>>q;
    b.reserve(200000);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        int min_v,min_c=1000000000;
        for(int k=0;k<n;k++)
        {
            scanf("%d",&a[k]);
            if(min_c>a[k])
            {
                min_c=a[k];
                min_v=k;
            }
        }
        bridge temp;
        for(int k=0;k<n;k++)
        {
            if(min_v!=k)
            {
                temp.p0=min_v;
                temp.p1=k;
                temp.cost=min_c+a[k];
                b.push_back(temp);
            }
        }

        for(int k=0;k<m;k++)
        {
            scanf("%d %d %d",&temp.p0,&temp.p1,&temp.cost);
            temp.p0--; temp.p1--;
            b.push_back(temp);
        }

        sort(b.begin(),b.end(),cmp);

        Int total=0,w=1;
        for(int k=0;k<n;k++) ensure[k]=0;
        for(int k=0,v0,v1;k<b.size() && en[1].size()<n;k++)
        {

            //b[k]
            v0=b[k].p0; v1=b[k].p1;
            /*
            cout<<v0+1<<" "<<v1+1<<" "<<b[k].cost<<" "<<total<<endl;
            for(int t=1;t<=w;t++)
            {
                cout<<t<<":";
                for(int i=0;i<en[t].size();i++)
                    cout<<en[t][i]+1<<" ";
                cout<<endl;
            }
            cout<<endl;
            */
            if(ensure[v0]==0 || ensure[v1]==0)
            {
                if(ensure[v0]==ensure[v1])
                {
                    ensure[v0]=w;
                    ensure[v1]=w;
                    en[w].push_back(v0);
                    en[w].push_back(v1);
                    w++;
                }
                else
                {
                    if(ensure[v0]==0)
                    {
                        ensure[v0]=ensure[v1];
                        en[ensure[v1]].push_back(v0);
                    }
                    if(ensure[v1]==0)
                    {
                        ensure[v1]=ensure[v0];
                        en[ensure[v0]].push_back(v1);
                    }
                }
                total+=b[k].cost;
            }
            else if(ensure[v0]!=ensure[v1])
            {
                int r_min,r_max;
                if(ensure[v0]>ensure[v1])
                {
                    r_min=ensure[v1];
                    r_max=ensure[v0];
                }
                else
                {
                    r_min=ensure[v0];
                    r_max=ensure[v1];
                }
                for(int t=0;t<en[r_max].size();t++)
                    ensure[en[r_max][t]]=r_min;
                en[r_min].insert(en[r_min].end(),en[r_max].begin(),en[r_max].end());
                en[r_max].clear();
                total+=b[k].cost;
            }
        }
        cout<<total<<endl;
        for(int k=1;k<w;k++)
            en[k].clear();
        b.clear();
    }
}
