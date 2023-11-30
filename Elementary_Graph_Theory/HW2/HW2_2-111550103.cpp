#include<bits/stdc++.h>
using namespace std;

vector < int > g[300000];
int n,ensure[300000]={0};

int f(queue <int> q)
{
    queue <int> temp;
    int u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        ensure[u]=1;
        for(vector<int>::iterator it=g[u].begin();it!=g[u].end();it++)
        {
            if(ensure[*it]==0)
                temp.push(*it);
        }
    }
    if(temp.empty()) return u;
    else return f(temp);
}

int h(queue <int> q)
{
    queue <int> temp;
    int u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        ensure[u]=1;
        for(vector<int>::iterator it=g[u].begin();it!=g[u].end();it++)
        {
            if(ensure[*it]==0)
                temp.push(*it);
        }
    }
    if(temp.empty()) return 0;
    else return h(temp)+1;
}

int main()
{
    cin>>n;
    for(int k=0,x,y;k<n-1;k++)
    {
        scanf("%d %d",&x,&y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue <int> q;
    int v;

    for(int k=0;k<n;k++) ensure[k]=0;
    q.push(0);
    v=f(q);
    q.pop();

    for(int k=0;k<n;k++) ensure[k]=0;
    q.push(v);
    cout<<h(q);
    q.pop();
}
