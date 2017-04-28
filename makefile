show:
	gcc show.c -o show
	show < $(data) > tmp.dot
	dot -Tpng tmp.dot -o tmp.png
rst:
	g++ rst.cpp -o rst
	rst < g.data > rst.dot
	dot -Tpng rst.dot -o rst.png
prim:
	g++ prim.cpp -o prim
	prim < g.data > prim.dot
	dot -Tpng prim.dot -o prim.png
pq:
	g++ pq.cpp -o pq
	pq < g.data
clean:
	del prim
	del rst.dot
	del rst.png
	del tmp.dot
	del tmp.gif
	del tmp.png
	del 1.dot
	del 1.png