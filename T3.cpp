#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[2000010],A[12][10010];
struct edge{
	int x,y,l;
}a[2000010];
int p[2000010],sum;
int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
void unite(int x,int y){
	int f1=find(x),f2=find(y);
	if(f2!=f1) p[f2]=f1; 
	return;
}
bool cmp(edge x,edge y){
	return x.l<y.l;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].l;
		sum+=a[i].l;
	}
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
        }
    }
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		int f1=find(a[i].x),f2=find(a[i].y);
		if(f1!=f2){
			unite(f1,f2);
			ans=0;
			ans+=a[i].l;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	if(cnt==n-1) cout<<ans;
	return 0;
} 
