all:Cryptogramy.o banner.o encrypt.o txtencrypt.o Cryptogramy

Cryptogramy.o:Cryptogramy.c encrypt.h banner.h txtencrypt.h
	gcc -ggdb -g -c Cryptogramy.c 

banner.o:banner.c banner.h
	gcc -ggdb -g -c banner.c

encrypt.o:encrypt.c encrypt.h
	gcc -ggdb -g -c encrypt.c

txtencrypt.o:txtencrypt.c txtencrypt.h
	gcc -ggdb -g -c txtencrypt.c txtencrypt.h

Cryptogramy:Cryptogramy.o encrypt.o banner.o txtencrypt.o
	gcc -ggdb -g Cryptogramy.o encrypt.o banner.o txtencrypt.o -o Cryptogramy


