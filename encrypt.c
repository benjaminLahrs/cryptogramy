#include <stdio.h>
#include <string.h>
#include "encrypt.h"
#include "txtencrypt.h"
#include <stdlib.h>

int encrypt(Encryption *Xor, int *fflag, int *tflag){

  printf("got to encrypt\n");

char *msg = malloc(5000 * sizeof(char));
FILE *fpointer = malloc(5000 * sizeof(char));;
FILE *output = malloc(5000 * sizeof(char));


printf("b\n");

fflush(stdout);

//printf("%s\n",(*Xor).filename);
if(Xor->filename){
printf("filename =:%s<-\n", Xor->filename);
fflush(stdout);}


//fflush(stdin);
if(!Xor->filename){
printf("no input file \n");
}else{ 
  if((fpointer = fopen(Xor->filename,"r")) == NULL) {
fprintf(stderr, "Can not open read file: %s\n",(*Xor).filename);
exit(1);
}
printf("file %s opened sucsessfuly\n", Xor->filename);
};

printf("hello\n");
fflush(stdout);

  if(Xor->fileout){
printf("save file given\n");
printf("%s",Xor->fileout);
  if((output = fopen((*Xor).fileout,"w")) == NULL) {
fprintf(stderr, "Can not open write file1: %s\n",(*Xor).fileout);
exit(1);}
};

printf("fileout:%s \n",Xor->fileout);
fflush(stdout);

  if(!Xor->fileout){
printf("fileout negative useing default 'output.txt'\n");
  if ((output = fopen("output.txt","w")) == NULL) {
fprintf(stderr, "Can not open write file2: %s\n", "output.txt");
exit(1);}};


printf("at for loop\n%s\n",Xor->text);
fflush(stdout);

if((*Xor).text){
int i;
for (i = 0; i < strlen((*Xor).text); i++){
  char uptriangle = 32;
 char *ptr = &uptriangle; 
  char text = (char*)malloc(sizeof(char));
  
 
  text  = (*Xor).text[i] ^ 39;
    
  
if(Xor->fileout){
fprintf(output,"%c", text);
}else{
printf("%c", text);
};
};
}else{


printf("at while loop\n");
fflush(stdout);  
while((fscanf(fpointer, "%c",msg))!=-1){
char text;
text  = *msg ^ 39;
if(Xor->fileout){
fprintf(output,"%c", text);

}else{
printf("%c", text);};
};

}
printf("\n\nFile in:  %s\n",((*Xor).filename));
    
if((*Xor).fileout != NULL){
  printf("File out: %s\n", (*Xor).fileout);
  }else{
  printf("File out: output.txt\n");}

printf("encryption/decryption complete\n");

};



