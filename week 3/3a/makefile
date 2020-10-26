server: polyimp.o polymain.o
	gcc -o server polymain.o polyimp.o
polyimp.o: polyimp.c poly.h
	gcc -c polyimp.c poly.h
polymain.o: poly.h polymain.c
	gcc -c poly.h  polymain.c