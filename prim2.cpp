#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N 1000

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
