server: tbtimp.o tbtmain.o
	gcc -o server tbtmain.o tbtimp.o
tbtimp.o: tbtimp.c tbt.h
	gcc -c tbtimp.c tbt.h
tbtmain.o: tbt.h tbtmain.c
	gcc -c tbt.h tbtmain.c