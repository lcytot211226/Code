#include<bits/stdc++.h>
using namespace std;
int n,j;
vector<int>g[1000000];
int ensure[1000000];
vector<int>key;
struct node
{
    int value;
    int point;
};

void find_last_joint(int v)
{
    ensure[v]=1;
    int len=g[v].size();
    if(len==3)
    {
        j=v;
    }
    for(int k=0,p;k<len;k++)
    {
        p=g[v][k];
        if(ensure[p]==0)
            find_last_joint(p);
    }
}

node search0(node v)
{
    //cout<<v.point<<endl;
    ensure[v.point]=1;
    int len=g[v.point].size();
    if(len==1)
    {
        v.point=-1;
        return v;
    }
    else if(len==3)
    {
        return v;
    }
    for(int k=0;k<len;k++)
    {
        if(ensure[g[v.point][k]]==0)
        {
            v.point=g[v.point][k];
            v.value+=1;
            return search0(v);
        }
    }
}

bool comp(vector <int> ans)
{
    int u=0;
    //for(int k=1;k<ans.size()-1;k++)
    //    cout<<key[k];
    //cout<<endl;
    for(int k=0;k<ans.size();k++)
    {

        if(ans[k]!=key[k+1])
        {
            u=1; break;
        }
    }
    if(u==0) return true;
    return false;
}

int main()
{
    cin>>n;
    for(int k=0,x,y;k<n-1;k++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int k=0;k<n;k++) ensure[k]=0;
    find_last_joint(0);
    //cout<<j;

    for(int k=0;k<n;k++) ensure[k]=0;

    while(1)
    {
        node v;
        v.point=j;
        v.value=1;
        ensure[v.point]=1;
        int u=0;
        for(int k=0;k<g[v.point].size();k++)
        {
            int p=g[v.point][k],t;
            //cout<<p<<endl;
            if(ensure[p]==0)
            {
                t=v.point;
                v.point=p;
                node temp=search0(v);
                v.point=t;
                if(temp.point==-1)
                    key.push_back(temp.value);
                else
                {
                    j=temp.point;
                    u=1;
                }
            }
            //cout<<endl;
        }
        if(u==0)
            break;

    }
    //for(int k=0;k<key.size();k++)
    //    cout<<key[k]<<" ";
    //cout<<endl;
    int ans_n;
    vector<int>ans;
    cin>>ans_n;
    for(int k=0,t;k<ans_n;k++)
    {
        scanf("%d",&t);
        ans.push_back(t);
    }
    if(key.size()-2!=ans_n)
    {
        cout<<"NO"; return 0;
    }
    //00
    if(comp(ans)) {cout<<"YES"; return 0;}
    //10
    swap(key[0],key[1]);
    if(comp(ans)) {cout<<"YES"; return 0;}
    //11
    swap(key[ans_n+1],key[ans_n]);
    if(comp(ans)) {cout<<"YES"; return 0;}
    //01
    swap(key[0],key[1]);
    if(comp(ans)) {cout<<"YES"; return 0;}

    //reverse
    reverse(key.begin(),key.end());

    if(comp(ans)) {cout<<"YES"; return 0;}
    //10
    swap(key[0],key[1]);
    if(comp(ans)) {cout<<"YES"; return 0;}
    //11
    swap(key[ans_n+1],key[ans_n]);
    if(comp(ans)) {cout<<"YES"; return 0;}
    //01
    swap(key[0],key[1]);
    if(comp(ans)) {cout<<"YES"; return 0;}

    cout<<"NO";
}
