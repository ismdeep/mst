#include <stdio.h>

int main(){
	int v_cnt, e_cnt;
	scanf("%d%d", &v_cnt, &e_cnt);
	printf("digraph G {\n");
	printf(" size =\"100,10\";\n");
	for (int i = 0; i < e_cnt; i++){
		int a, b, val;
		scanf("%d%d%d", &a, &b, &val);
		printf("    %d -> %d [ label=\"%d\" arrowhead=\"none\" ];\n", a, b, val);
	}
	printf("}\n");
	return 0;
}
