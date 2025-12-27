#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long c[20000010];
struct edge{
	long long x,y,l;
}a[20000010];
bool vis[20000010];
long long p[20000010],ans=1e18;
long long find(long long x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
void unite(long long x,long long y){
	long long f1=find(x),f2=find(y);
	if(f2!=f1) p[f2]=f1; 
	return;
}
bool cmp(edge x,edge y){
	return x.l<y.l;
}
void dfs(long long now,long long num,long long cost){
    if(now>n+k){
        for(int i=1;i<=n+k+1;i++) p[i]=i;
        long long cnt=0,sum=cost;
        num=num+n;
        for(int i=1;i<=m;i++){
            int u=a[i].x,v=a[i].y,l=a[i].l;
            if(u>n&&!vis[u]) continue;
            if(find(u)!=find(v)){
                unite(u,v);
                cnt++;
                sum+=l;
                if(cnt==num-1) break;
            }
        }
        if(cnt==num-1) ans=min(ans,sum);
        return;
    }
    vis[now]=1;
    dfs(now+1,num+1,cost+c[now]);
    vis[now]=0;
    dfs(now+1,num,cost);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(long long i=1;i<=n+k;i++) p[i]=i;
    for(long long i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].l;
	}
    for(long long j=n+1;j<=n+k;j++){
        cin>>c[j];
        for(long long i=1,w;i<=n;i++){
            cin>>w;
            a[++m]={j,i,w};
        }
    }
    sort(a+1,a+m+1,cmp);
    dfs(n+1,0,0);
    cout<<ans;
    return 0;
}