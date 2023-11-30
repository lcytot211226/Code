#include<bits/stdc++.h>
using namespace std;
vector <int> a[100000];
int ensure[100000]={0};

struct p
{
    int height;
    int parent;
};
p data0[100000];
int f(int node, int prv)
{
    ensure[node]=1;
    int mh=0,h=0,temp;
    for(int k=0;k<a[node].size();k++)
    {
        temp=a[node][k];
        if(ensure[temp]==0)
        {
            h=f(temp,node);
            if(h>mh) mh=h;
        }
    }
    p r;
    r.height=mh;
    r.parent=prv;
    data0[node]=r;
    return mh+1;
}

int main()
{
    int n;
    cin>>n;
    for(int k=0,p0,p1;k<n-1;k++)
    {
        scanf("%d %d",&p0,&p1);
        p0--; p1--;
        a[p0].push_back(p1);
        a[p1].push_back(p0);
    }
    f(0,-1);
    data0[0].parent=-2;
    for(int k=0;k<n;k++)
        printf("%d %d\n",data0[k].height,data0[k].parent+1);
}
