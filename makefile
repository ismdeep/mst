show:
	gcc show.c -o show
	./show < $(data) > tmp.dot
	dot -Tpng tmp.dot -o tmp.png
rst:
	g++ rst.cpp -o rst
	./rst < g.data > rst.dot
	dot -Tpng rst.dot -o rst.png
prim:
	g++ prim.cpp -o prim
	./prim < g.data > prim.dot
	dot -Tpng prim.dot -o prim.png
kruscal:
	g++ kruscal.cpp -o kruscal
	./kruscal < g.data
pq:
	g++ pq.cpp -o pq
	pq < g.data

.PHONY : clean kruscal
clean:
	-rm prim
	-rm rst.dot
	-rm rst.png
	-rm tmp.dot
	-rm tmp.gif
	-rm tmp.png
	-rm 1.dot
	-rm 1.png
	-rm kruscal
