#include"txtencrypt.h"
#include"banner.h"
#include<stdio.h>
#include"encrypt.h"
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


//Encryption Xor = {};
//Encryption Base64 = {}; 
//typedef struct{
//unsigned int onoff:1;
//const char *text;
//const char *key;
//const char *filename;
//const char *fileout;
//}Encryption;
 



void print_usage(){
printf("Error, please select either file or text\nusage: -f <file> | -t <\"text\"> \n");
exit(2);
};

void print_usage2(){
printf("Error, please only select one mode of encryption\n -x: Xor | -b: Base64");
exit(2);
};



int main(int argc,char *argv[]){
Encryption *Xor = NULL;// struct declared locally and malloc'd in switch function
Encryption *Base64 = NULL; //struct declared locally and malloc'd in switch function
 

//Xor->onoff = malloc(5* sizeof(int));
//Xor->onoff = 1;
//Xor->fileout = malloc(10 * sizeof(char));
//Xor->filename = NULL;
//Xor->text = malloc(1000*sizeof(char));
//Xor->fileout =NULL;
//Xor->text = NULL;
printf("\n");
int xflag = 0;
int tflag = 0;
int bflag = 0;
int fflag = 0;

char *text = NULL;
char c;
FILE *help;
char *filename = NULL;
char *fileout = NULL;

banner();
//printf("\nusage: -f <file> | -t <\"text\"> \n"); 

//switch through opts to turn on type of encryption with on/off ints in structs.

while((c=getopt(argc, argv,"t:o:f:x b "))!=EOF){
  if(argc < 1){
    print_usage();
 };
//----------------encryption case's----------
  printf("1111\n");
  
  switch (c){
    case 'x':
      printf("x\n");
    if (xflag){
    print_usage2(); 
     }else{
  Xor = malloc(sizeof(Encryption));
  Xor->onoff = malloc(5* sizeof(int));
  Xor->onoff = 1;
  Xor->fileout = malloc(10 * sizeof(char));
  Xor->text = malloc(1000*sizeof(char)); 
  Xor->filename = NULL;
  Xor->fileout =NULL;
  Xor->text = NULL; 
  
       Xor->onoff=1;
       printf("at X switch, Xor.onoff=%i\n",Xor->onoff);
       xflag++;     
       bflag++;
     }
       break;

    case 'b':
     if(bflag){
    print_usage2();
     }else{
  Base64 = malloc(sizeof(Encryption));  
  Base64->onoff = malloc(5* sizeof(int));
  Base64->onoff = 1;
  Base64->fileout = malloc(10 * sizeof(char));
  Base64->text = malloc(1000*sizeof(char));
  Base64->fileout =NULL;
  Base64->text = NULL;
  Base64->filename = NULL;
  
    

       Base64->onoff=1;
      xflag++;
      bflag++;
      }
     break;

     
     //------------------file case's--------------
    case 'f':
     printf("f\n");
     fflush(stdout);
    if(fflag){
   print_usage();
    }else{
printf("got to -F else\n");
    fflag++;
    tflag++;}
          
          if(Xor->onoff=1){  
          Xor->filename = strdup(optarg);
          printf("saved '%s' as Xor.filename\n %s\n",Xor->filename,Xor->filename);
          //Xor->fileout = "output.txt";
          }else{
            if(Base64->onoff){
            Base64->filename = strdup(optarg);
            } 
          }
     break; 
   
  case 't':
     if(tflag){
     print_usage();
     }else{
     fflag++;
     tflag++;
     }
     

          if(Xor->onoff){
          Xor->text = strdup(optarg);
          if (Xor->fileout==NULL){
          //Xor->fileout = "output.txt";
            };
          }else
          { if(Base64->onoff){
            Base64->text = strdup(optarg);
              if(Base64->fileout==NULL){
                //Base64->fileout= "output.txt";
              };
            };
          }
          break;
  
  case 'o':
printf("o\n");
          if(Xor->onoff){
          Xor->fileout = strdup(optarg);
          }else{
              if(Base64->onoff){
              Base64->fileout = strdup(optarg);
              }}    

    break;
  
  default:
  print_usage();
    break;
}
}
printf("after switch\n");

if(Xor->onoff){
 
  encrypt(Xor); 

}/*else 
if(Base.onoff){
  Base64encrypt();
}*/

if(text!=NULL){free(text);}
if(fileout!="output.txt"){free(fileout);}

if(filename!=NULL)
{   free(filename);
}
}
