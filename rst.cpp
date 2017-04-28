#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
#define NOT_USED 0
#define USED 1

int n, cnt; // n:点个数 cnt:边条数
int g[MAXN][MAXN];
int ans[MAXN][MAXN];
int node[MAXN];
int weight;

void init(){
	memset(g   , 0       , sizeof(g)    );
	memset(ans , 0       , sizeof(ans)  );
	memset(node, NOT_USED, sizeof(node) );
	weight = 0;
}

int get_rand(int left, int right){
	return left + rand() % (right-left+1);
}

void dfs(int node_index){
	// cout << node_index << endl;
	node[node_index] = USED;
	int tmp[MAXN];
	int top_index = -1;
	for (int i = 0; i < n; i++){
		if ( NOT_USED == node[i] && 0 != g[node_index][i]){
			top_index++;
			tmp[top_index] = i;
		}
	}
	if (top_index >= 0){
		// 随机选择
		for (int i = 0; i < 100; i++){
			int left, right;
			left = get_rand(0,top_index);
			right = get_rand(0,top_index);
			int tmp_index = tmp[left];
			tmp[left] = tmp[right];
			tmp[right] = tmp_index;
		}
		
		for (int i = 0; i <= top_index; i++){
			int go_index = tmp[i];
			if ( NOT_USED == node[go_index]){
				printf("    %d -> %d [ label=\"%d\" arrowhead=\"none\" ];\n", node_index, go_index, g[node_index][go_index]);
				weight += g[node_index][go_index];
				dfs(go_index);
			}
		}
	}
}

int main(){
	srand(time(0));
	// input data
	cin >> n >> cnt;
	for (int i = 0; i < cnt; i++){
		int a, b, val;
		cin >> a >> b >> val;
		g[a][b] = val;
		g[b][a] = val;
	}
	printf("digraph G {\n");
	// start from 0
	dfs(0);
	printf("B[label=\"%d\"];\n", weight);
	printf("}\n");
	
	return 0;
}
