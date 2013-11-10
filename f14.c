#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){//file_name string

  FILE *fp;
  char string[100], c;
  int count = 0, len, pos;

  if( argc !=3 ){
    printf("%s\n", "numar insuficient de argumente" );
    return 1;
  }

  if( ( fp = fopen(argv[1],"r") ) == NULL ){
    perror("Nu am putut deschide fisierul : ");
    return 2;
  }

  strcpy( string, argv[2] );// put name in string
  len = strlen(string);
  pos = 0;

  while( ( c = (char)fgetc(fp) ) != EOF ){
    if(c == string[pos]){
      if(pos==len-1){
        count++;
        pos=0;
      }
      else
        pos++;
    }
    else
      pos=0;
  }
  printf("%s %d %s\n","stringul a aparut de",count,"ori" );
  fclose(fp);
  return 0;
}