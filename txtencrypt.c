#include <stdio.h>
#include "txtencrypt.h"
#include <stdlib.h>
#include<string.h>

int txtencrypt(Encryption *Xor){


char *msg;
FILE *output;
int i;
printf("1\n");
fflush(stdin);
printf("%s\n", Xor->fileout);         
fflush(stdin);

if(Xor->fileout != NULL){
if ((output = fopen(Xor->fileout,"w")) == NULL) {
fprintf(stderr, "Can not open write file: %s\n", Xor->fileout);
exit(1);}}
else{
if ((output = fopen("output.txt","w")) == NULL) {
fprintf(stderr, "Can not open write file: %s\n", "output.txt");
exit(1);}}

for (i = 0; i < strlen(Xor->text); i++){
char temp;

temp = Xor->text[i] ^ 39;

    fprintf(output, "%c", temp);
}

printf("Text in: %s\n", Xor->text);
printf("File out: %s", Xor->fileout);
printf("\n");
printf("encryption/decryption complete\n");
}

