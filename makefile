all:Cryptogramy.o banner.o Xor.o txtencrypt.o Cryptogramy

Cryptogramy.o:Cryptogramy.c Xor.h banner.h txtencrypt.h
	gcc -ggdb -g -c Cryptogramy.c 

banner.o:banner.c banner.h
	gcc -ggdb -g -c banner.c

Xor.o:Xor.c Xor.h
	gcc -ggdb -g -c Xor.c

txtencrypt.o:txtencrypt.c txtencrypt.h
	gcc -ggdb -g -c txtencrypt.c txtencrypt.h

Cryptogramy:Cryptogramy.o Xor.o banner.o txtencrypt.o
	gcc -ggdb -g Cryptogramy.o Xor.o banner.o txtencrypt.o -o Cryptogramy


