#include"txtencrypt.h"
#include"banner.h"
#include<stdio.h>
//#include"encrypt.h"
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void print_usage(){
printf("Error, please select either file or text\nusage: -f <file> | -t <\"text\"> \n");
exit(2);
};

void print_usage2(){
printf("Error, please only select one mode of encryption\n -x: Xor | -b: Base64");
exit(2);
};

void print_usage3(){
printf("Error, please only select mode of encryption first\n -x: Xor | -b: Base64\n");
exit(2);
};


int main(int argc,char *argv[]){
	
char* Xorcmp = "-x";
char* bascmp = "-b";

if(argc < 4){
printf("not enough arguments\n");
print_usage();
exit(2);
};

int test1;
int test2;
test1 = strcmp(argv[1],Xorcmp);
test2 = strcmp(argv[1],bascmp);

if(test1!=0&test2!=0){
	print_usage3();
exit(2);
};

Encryption *Xor = NULL;// struct declared locally and malloc'd in switch function
Encryption *Base64 = NULL; //struct declared locally and malloc'd in switch function
 
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

//switch through opts to turn on type of encryption with on/off intsi(flags) in structs.

while((c=getopt(argc, argv,"x b f:t:o:"))!=EOF){
  if(argc < 1){
    print_usage();
 };
//----------------encryption case's----------
  
  switch (c){
    case 'x':
      printf("Xor selected...\n");
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
       xflag++;     
       bflag++;
     }
       break;

    case 'b':
       printf("base64 selected...");
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
     printf("file selected...\n");
    if(fflag){
   print_usage();
    }else{
    fflag++;
    tflag++;}          
          if(Xor->onoff=1){  
          Xor->filename = strdup(optarg);
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
//-----------encrypt based on set flags and arguments----------------

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
