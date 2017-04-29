#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAXN 1000
#define INF 0x3fffffff
#define used 1
#define not_used 0


int n, cnt;
int g[MAXN][MAXN];
int node[MAXN];

void init() {
    memset(g, 0, sizeof(g));
    memset(node, 0, sizeof(node));
}

void dfs(int start) {
    printf("%d\n", start);
    node[start] = used;
    for (int i = n-1; i >= 0; i--){
        if (0 != g[i][start] && not_used == node[i]){
            dfs(i);
        }
    }
}

int main () {
    init();
    cin >> n >> cnt;
    for (int i = 0; i < cnt; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = w;
        g[b][a] = w;
    }
    dfs(0);
    return 0;
}