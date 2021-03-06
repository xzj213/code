#include<queue>
#include<cstdio>
#include<vector>
#define	mp	make_pair
#define	pb	push_back
#define	rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef	vector<int>	vi;
typedef	pair<int,int> pii;
const int INF=1<<29;
const double EPS=1e-9;
template<class T> struct Edge{
	int u,v;
	T w;
	Edge(){}
	Edge(int U,int V,T W):u(U),v(V),w(W){}
	bool operator<(const Edge &e)const{ return w<e.w; }
};
template<class T>
struct AdjList:public vector< vector< Edge<T> > >{
	AdjList(){}
	AdjList(int n,const vector< Edge<T> > &v=vector< Edge<T> >()):vector< vector< Edge<T> > >(n,v){}
	template<class U> AdjList(U b,U e):vector< vector< Edge<T> > >(b,e){}
};
bool checkEvenCycle(const AdjList<int> &adj){
	int n=adj.size();
	rep(u,n)rep(i,adj[u].size()){
		if(adj[u][i].w<0){
			printf("%d %d %d\n",2,u,adj[u][i].v);
			return false;
		}
	}
	return true;
}
bool checkOddCycle(const AdjList<int> &adj){
	int n=adj.size();
	rep(u0,n){
		vi d[2],parent[2];
		rep(i,2){
			d[i].assign(n,INF);
			parent[i].assign(n,-1);
		}
		d[0][u0]=0;

		int ans=-1;
		priority_queue< pair<int,pii> > pq;	pq.push(mp(0,pii(0,u0)));
		while(!pq.empty()){
			pair<int,pii> a=pq.top();	pq.pop();
			int flg=a.second.first,u=a.second.second;
			if(d[flg][u]<-a.first)	continue;
			if(flg==1 && u==u0){ ans=d[flg][u]; break; }

			rep(i,adj[u].size()){
				int v=adj[u][i].v,w=adj[u][i].w;
				if(d[flg][u]+w<d[!flg][v]){
					d[!flg][v]=d[flg][u]+w;
					pq.push(mp(-d[!flg][v],mp(!flg,v)));
					parent[!flg][v]=u;
				}
			}
		}
		if(~ans && ans<1000){
			vi path;
			for(int flg=1,u=u0;;u=parent[flg][u],flg=!flg){
				path.pb(u);
				if(flg==0 && u==u0)	break;
			}
			int p0,p1;
			vi seen(n,-1);
			rep(i,path.size()){
				int u=path[i];
				if(~seen[u]){
					p0=seen[u];
					p1=i;
					break;
				}
				seen[u]=i;
			}
			int cnt=p1-1-(p0-1);
			printf("%d ",cnt);
			for(int i=p0;i<p1;i++)	printf("%d ",path[i]); putchar('\n');
			return false;
		}
	}
	return true;
}
int main(){
	freopen("genius.in", "r", stdin);
	freopen("genius.out", "w", stdout);
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		int f[500];
		rep(u,n){
			double tmp;	scanf("%lf",&tmp);
			f[u]=(int)(1000*tmp+EPS);
		}
		AdjList<int> adj(n);
		rep(i,m){
			int u,v; scanf("%d%d",&u,&v);
			adj[u].pb(Edge<int>(u,v,1000-(f[u]+f[v])));
			adj[v].pb(Edge<int>(v,u,1000-(f[v]+f[u])));
		}

		if(checkEvenCycle(adj) && checkOddCycle(adj)) puts("0");
	}
	return 0;
}

