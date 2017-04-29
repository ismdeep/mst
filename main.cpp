#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N 1000

struct Edge{
	int l,r,w;
};

bool cmp_edge (Edge a, Edge b) {
	return a.w < b.w;
}

int g[N][N];
int n, cnt;
Edge e[N*N];
int parent[N];
int weight = 0;

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

void init(){
	for (int i = 0; i < N; i++){
		parent[i] = i;
	}
	memset(g, 0, sizeof(g));
}

void kruscal (){
	sort(e, e + cnt, cmp_edge);
	for (int i = 0; i < cnt; i++) {
		if (find(e[i].l) != find(e[i].r)){
			weight += e[i].w;
			printf("%d %d : %d\n", e[i].l, e[i].r, e[i].w);
			mix(e[i].l, e[i].r);
		}
	}
	printf("%d\n", weight);
}

int main () 
{
	init();
	cin >> n >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = w;
		e[i].l = a;
		e[i].r = b;
		e[i].w = w;
	}
	kruscal();
	return 0;
}
