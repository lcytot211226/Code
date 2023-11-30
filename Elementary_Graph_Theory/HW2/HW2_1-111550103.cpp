#include<bits/stdc++.h>
using namespace std;
vector <string> a;
int g[20][20]={0};
string m_s;
int m=-1;

void find_path(int p,int total,int n,int *ensure,string s)
{
    //cout<<s<<" "<<total<<endl;
    int u=0;
    for(int k=0;k<n;k++)
    {
        if(p!=k && ensure[k]==0)
        {
            //cout<<" "<<a[k]<<" s="<<a[k].size()<<endl;
            ensure[k]=1;
            find_path(k,total+g[p][k],n,ensure,s+a[k].substr(g[p][k],a[k].size()-g[p][k]));
            ensure[k]=0;
            u=1;
        }
    }
    if(u==0)
    {
        //cout<<s<<" "<<total<<endl<<endl;
        if(total>m)
        {
            m=total;
            m_s=s;
        }
        else if(total==m && s<m_s)
        {
            m=total;
            m_s=s;
        }
    }
    return;
}

void connected()
{
    string b0,b1;
    for(int k=0;k<a.size();k++)
    {
        for(int t=k+1;t<a.size();t++)
        {
            b0=a[k]; b1=a[t];

            int p=0;
            if(b0.size()<b1.size()){string u=b0; b0=b1; b1=u; p=1;}
            //cout<<b0<<" "<<b1<<endl;
            int u=0;
            for(int i=0;i<b0.size()-b1.size()+1;i++)
            {
                //cout<<b1<<" "<<b0.substr(i,b1.size())<<endl;
                if(b1==b0.substr(i,b1.size())){u=1; break;}
            }
            //cout<<u<<endl;
            if(u==1)
            {
                if(p==0)
                {
                    a.erase(a.begin()+t);
                    t--;
                }
                else
                {
                    a.erase(a.begin()+k);
                    k--;
                    break;
                }
            }
        }
    }

    int n=a.size();
    //cout<<"n="<<n<<endl;
    for(int k=0;k<n;k++)
    {
        for(int t=0;t<n;t++)
        {
            if(k==t){continue;}

            for(int i=1;i<a[k].size() && i<a[t].size();i++)
            {
                b0=a[k].substr(a[k].size()-i,i);
                b1=a[t].substr(0,i);
                if(b0==b1)
                    g[k][t]=i;
            }
        }
    }
    //for(vector<string>::iterator it=a.begin();it!=a.end();it++)
    //    cout<<*it<<" ";
    //cout<<endl;

    //graph done
    //cout<<endl;
    int ensure[20]={0};
    for(int k=0;k<n;k++)
    {
        string s=a[k];
        ensure[k]=1;
        find_path(k,0,n,ensure,s);
        ensure[k]=0;
    }


}

int main()
{
    a.reserve(18);
    int n;
    cin>>n;
    string s;
    for(int k=0;k<n;k++)
    {
        cin>>s;
        a.push_back(s);
    }
    connected();
    /*
    for(int k=0;k<a.size();k++)
    {
        for(int t=0;t<a.size();t++)
        {
            if(g[k][t]>=0)
                cout<<" ";
            cout<<g[k][t]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<m_s;
}
/*
11
genshin
impact
start
hee
hee
hee
i
am
a
klee
player
*/
