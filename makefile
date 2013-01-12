ptd.exe : ptd.c
	gcc ptd.c -o ptd.exe -O3 -std=c99

clean : 
	rm ptd.exe

.PHONY: clean
