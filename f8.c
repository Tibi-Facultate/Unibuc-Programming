#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[]){//file_name string

  FILE *fs, *fd;
  char string[100], buffer[512];
  int count = 0;

  if( argc !=3 ){
    printf("%s\n", "numar insuficient de argumente" );
    return 1;
  }

  if( ( fs = fopen(argv[1],"r") ) == NULL || ( fd = fopen(argv[2],"w") ) == NULL ){
    perror("Nu am putut deschide fisierul : ");
    return 2;
  }

  while( !feof(fs) ){
    if( fgets(buffer, 512, fs) != NULL)
      fputs(buffer, fd);
  }

  fclose(fs);
  fclose(fd);
  return 0;
}