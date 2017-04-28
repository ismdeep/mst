/**
  * prim algorithm
  *
  * author : ismdeep
  * 
  */
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <time.h>
using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
#define NOT_USED 0
#define USED 1

struct Edge{
	int from,to,weight;
};

int n, cnt; // n:点个数 cnt:边条数
int g[MAXN][MAXN];
int ans[MAXN][MAXN];
int node[MAXN];
int weight;

bool operator < (const Edge &a, const Edge &b) {
	return a.weight > b.weight;
}

void init(){
	memset(g   , 0       , sizeof(g)    );
	memset(ans , 0       , sizeof(ans)  );
	memset(node, NOT_USED, sizeof(node) );
	weight = 0;
}

void prim(int start_index){
	node[start_index] = USED;
	priority_queue <Edge> q;
	for (int i = 0; i < n; i++) {
		if (0 != g[start_index][i]) {
			Edge e;
			e.from = start_index;
			e.to = i;
			e.weight = g[start_index][i];
			q.push(e);
		}
	}
	while (!q.empty()) {
		Edge tmp = q.top();
		q.pop();
		if (NOT_USED == node[tmp.from] || NOT_USED == node[tmp.to]){
			node[tmp.from] = USED;
			node[tmp.to] = USED;
			weight += tmp.weight;
			printf("    %d -> %d [ label=\"%d\" arrowhead=\"none\" ];\n", tmp.from, tmp.to, tmp.weight);
			for (int i = 0; i < n; i++){
				if (NOT_USED == node[i] && 0 != g[i][tmp.to]) {
					Edge add;
					add.from = tmp.to;
					add.to = i;
					add.weight = g[i][tmp.to];
					q.push(add);
				}
			}
		}
	}
}

int main(){
	cin >> n >> cnt;
	for (int i = 0; i < cnt; i++){
		int a, b, val;
		cin >> a >> b >> val;
		g[a][b] = val;
		g[b][a] = val;
	}
	printf("digraph G {\n");
	prim(0);
	printf("B[label=\"%d\"];\n", weight);
	printf("}\n");
	
	return 0;
}
