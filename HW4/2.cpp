#include<bits/stdc++.h>
using namespace std;
typedef long long int Int;
struct node
{
	int vertice;
	Int value;
};
struct cmp
{
	bool operator()(node a, node b)
	{
		if(a.value==-1 && b.value!=-1)
			return false;
		else if(a.value!=-1 && b.value==-1)
			return true;
		else
			return a.value>b.value;
	}
};
int n,m;
vector <node> graph[200000];
void shortest_path0(int start,Int *path)
{
	priority_queue <node, vector<node>, cmp > pq;
	for(int k=0;k<n;k++) path[k]=(k==start)?0:-1;
	node temp;
	temp.vertice=start;
	temp.value  =0;
	pq.push(temp);
	int v,w,u;
	while(pq.size()>0)
	{
		temp=pq.top();
		pq.pop();
		v=temp.vertice;
		for(int k=0;k<graph[v].size();k++)
		{
			w=graph[v][k].value;
			u=graph[v][k].vertice;
			//v -> u
			//path[v] + w <path[u]
			if(path[v]==-1 || w==-1) continue;
			else if( (path[u]==-1) || (path[v]+w<path[u]))
			{
				path[u]=path[v]+w;
				temp.value=path[u];
				temp.vertice=u;
				pq.push(temp);
			}
		}
	}
    return;
}
void shortest_path1(Int *path)
{
	priority_queue <node, vector<node>, cmp > pq;
	node temp;
	for(int k=0;k<n;k++)
	{
		temp.vertice=k;
		temp.value  =path[k];
		pq.push(temp);
	}
	int enable[200000]={0};
	int v,w,u;
	while(pq.size()>0)
	{
		temp=pq.top();
		pq.pop();
		v=temp.vertice;
		//cout<<v<<" ";
		enable[v]=1;
		for(int k=0;k<graph[v].size();k++)
		{
			w=graph[v][k].value;
			u=graph[v][k].vertice;
			//v -> u
			//path[v] + w <path[u]
			if(path[v]==-1 || w==-1) continue;
			else if( (path[u]==-1) || (path[v]+w<path[u]))
			{
				path[u]=path[v]+w;
				temp.value=path[u];
				temp.vertice=u;
				if(enable[u]==0)
					pq.push(temp);
			}
		}
	}
	
    return;
}
int main()
{
    int T,T0,query;
    Int *path[2];
    path[0]=new Int[200000]; path[1]=new Int[200000];
    node temp_node;
    scanf("%d %d",&T,&T0);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&query);
        for(int k=0,t0,t1,t2;k<m;k++)
        {
            scanf("%d %d %d",&t0,&t1,&t2);
            t0--; t1--;
            temp_node.vertice= t0;
            temp_node.value  = t2;
            graph[t1].push_back(temp_node);
        }
        if(query==2)
        {
            shortest_path0(0,path[0]);
            shortest_path0(n-1,path[1]);
            
            for(int k=0;k<n;k++)
            {
            	if(path[0][k]==-1 || path[1][k]==-1)
            		path[0][k]=-1;
            	else
            		path[0][k]=path[0][k]+path[1][k];
			}
            shortest_path1(path[0]);
            
            for(int k=0;k<n;k++)
                cout<<path[0][k]<<" ";
            cout<<endl;
        }
        else
        {
        	 shortest_path0(0,path[0]);
        	 for(int k=0;k<n;k++)
                cout<<path[0][k]<<" ";
            cout<<endl;
		}
		for(int k=0;k<n;k++)
			graph[k].clear();
    }
    delete path[0];
    delete path[1];
}
