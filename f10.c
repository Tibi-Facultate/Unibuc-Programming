#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){//file_name string

  FILE *fs, *fd;
  char string[100], buffer[512];
  int count = 0;

  if( argc <2 ){
    printf("%s\n", "numar insuficient de argumente" );
    return 1;
  }
  if( ( fd = fopen(argv[argc-1],"w") ) == NULL ){
    perror("Nu am putut deschide fisierul de output : ");
    return 2;
  }


  for(int i=1;i<argc-1;i++){    
    if( ( fs = fopen(argv[i],"r") ) == NULL ){
      perror("Nu am putut deschide fisierul de input : ");
      return 2;
    }

    while( !feof(fs) ){
      if( fgets(buffer, 512, fs) != NULL)
        fputs(buffer, fd);
    }
    fclose(fs);
  }
  fclose(fd);
  return 0;
}