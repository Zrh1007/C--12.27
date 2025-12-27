#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int x,y,l;
}a[200010];
int p[200010],sum;
int find(int x){
	if(p[x]=x) return x;
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
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].l;
		sum+=a[i].l;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		int f1=find(a[i].x),f2=find(a[i].y);
		if(f1!=f2){
			unite(f1,f2);
			ans+=a[i].l;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	if(cnt==n-1) cout<<ans;
	else cout<<"orz";
	return 0;
} 
