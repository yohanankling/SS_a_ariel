FLAGS= -Wall -g

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec 

loops:
libclassloops.a:basicClassification.o advancedClassificationLoop.o 
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o 

recursives:
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o 

recursived:
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd:
libclassloops.so:basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

mains:main.o libclassrec.a
	gcc $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc $(FLAGS) -o maindloop main.o libclassloops.a -lm

maindrec:main.o libclassrec.so 
	gcc $(FLAGS) -o maindrec main.o libclassrec.a -lm


main.o: main.c NumClass.h
	gcc $(FLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
	gcc -c basicClassification.c 
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -c advancedClassificationRecursion.c




.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains maindloop maindrec