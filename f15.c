#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){//file_name string

  FILE *fs;
  char string[100], buffer[512];
  int count = 0;

  if( argc >2 ){
    printf("%s\n", "numar invalid de argumente" );
    return 1;
  }

  if( argc==2 ){
    if( ( fs = fopen(argv[1],"r") ) == NULL ){
      perror("Nu am putut deschide fisierul : ");
      return 2;
    }
    while( !feof(fs) ){
      if( fgets(buffer, 512, fs) != NULL)
        printf("%s", buffer);
    }
    fclose(fs);
  }
  else
    while(fgets(buffer, 512, stdin) != NULL)
      printf("%s", buffer );
  return 0;
}