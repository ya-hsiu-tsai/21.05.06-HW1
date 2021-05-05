all: numQuickMain.c nq.o numMergeMain.c nm.o numRadixMain.c nr.o strQuickMain.c sq.o strMergeMain.c sm.o strRadixMain.c sr.o
		gcc numQuickMain.c nq.o -o numQuick
		gcc numMergeMain.c nm.o -o numMerge
		gcc numRadixMain.c nr.o -o numRadix
		gcc strQuickMain.c sq.o -o strQuick
		gcc strMergeMain.c sm.o -o strMerge
		gcc strRadixMain.c sr.o -o strRadix

nq.o: numQuick.c numQuick.h
		gcc -c numQuick.c -o nq.o

nm.o: numMerge.c numMerge.h
		gcc -c numMerge.c -o nm.o

nr.o: numRadix.c numRadix.h
		gcc -c numRadix.c -o nr.o

sq.o: strQuick.c strQuick.h
		gcc -c strQuick.c -o sq.o

sm.o: strMerge.c strMerge.h
		gcc -c strMerge.c -o sm.o

sr.o: strRadix.c strRadix.h
		gcc -c strRadix.c -o sr.o

clean:
		rm -f nq.o numQuick
		rm -f nm.o numMerge
		rm -f nr.o numRadix
		rm -f sq.o strQuick
		rm -f sm.o strMerge
		rm -f sr.o strRadix
