#include<bits/stdc++.h>
using namespace std;
int p[200010];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void unite(int x,int y){
    int f1=find(x),f2=find(y);
    if(f1!=f2) p[f1]=f2;
}
struct edge{
    int u,v,l;
}a[200010];
bool cmp(edge x,edge y){
    return x.l<y.l;
}
int n,m,k;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        a[i]={x,y,l};
    }
    int cnt=0,ans=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(cnt==n-1) break;
        int f1=find(a[i].u),f2=find(a[i].v);
        if(f1!=f2){
            unite(a[i].u,a[i].v);
			ans=0;
            ans+=a[i].l;
			
            cnt++;
        }
    }
    if(cnt==n-1){
        cout<<ans<<"\n";
        return 0;
    }
    else{
        cout<<-1<<"\n";
        return 0;
    }
    return 0;
}