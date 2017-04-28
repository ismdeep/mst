#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;

struct Edge{
	int s,e;
};

#define MAXN 1000
#define INF 0x3f3f3f3f
int g[MAXN][MAXN];

bool operator < (const Edge &a, const Edge &b) {
	return g[ a.s ][ a.e ] 
	     > g[ b.s ][ b.e ];
}

int main () {
	priority_queue <Edge> q;
	int n,c;
	cin >> n >> c;
	for (int i = 0; i < c; i++){
		int a, b, weight;
		cin >> a >> b >> weight;
		g[a][b] = weight;
		g[b][a] = weight;
		Edge e;
		e.s = a;
		e.e = b;
		q.push(e);
	}
	while (!q.empty()){
		int start = q.top().s;
		int end   = q.top().e;
		printf("%d %d : %d\n", start, end, g[start][end]);
		q.pop();
	}
	return 0;
}
