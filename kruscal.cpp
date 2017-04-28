#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAXN 1000

struct Edge{
	int from,to,weight;
};

bool operator < (const Edge &a, const Edge &b) {
	return a.weight > b.weight;
}

int n, cnt;
int g[MAXN][MAXN];
int parent[MAXN];
int weight = 0;
priority_queue <Edge> q;

void init(){
	memset(g, 0, sizeof(g));
	for (int i = 0; i < MAXN; i++) {
		parent[i] = i;
	}
}

int find(int x){
	int r = x;
	while (parent[r] != r){
		r = parent[r];
	}
	int i = x, j;
	while (parent[i] != r){
		j = parent[i];
		parent[i] = r;
		i = j;
	}
	return r;
}

void mix(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if (fx != fy){
		parent[fy] = fx;
	}
}

void kruscal () {
	while (!q.empty()){
		Edge e = q.top();
		q.pop();
		// printf("%d %d : %d\n", e.from, e.to, e.weight);
		if (find(e.from) != find(e.to)){
			weight += e.weight;
			printf("%d\n", e.weight);
			mix(e.from, e.to);
		}
	}
}

int main () {
	init();
	cin >> n >> cnt;
	for (int i = 0; i < cnt; i++){
		int a, b, w;
		cin >> a >> b >> w;
		// cout << a << " " << b << " " << w << endl;
		Edge e;
		e.from = a;
		e.to = b;
		e.weight = w;
		q.push(e);
	}
	kruscal();
	printf("%d\n", weight);
	return 0;
}

