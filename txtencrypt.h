int txtencrypt();
extern struct Encryption *Xor;

typedef struct{
const char *filename;
int onoff:1;
const char *text;
const char *key;
const char *fileout;
 }Encryption;


