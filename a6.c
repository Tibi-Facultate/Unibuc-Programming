#include <stdio.h>
#include <stdlib.h>

int is_space(char t){
  if(t==' '|| t=='\n' || t== '\t' || t=='\n' || t=='\v' || t=='\r' || t=='\f')
    return 1;
  return 0;
}

int main(int argc, char const *argv[])
{
  FILE *fin, *fout;
  char c;
  int count=0;
  if(argc!=2){
    printf("%s\n", "One argument required");
    exit(0);
  }
  if( (fin = fopen(argv[1],"r")) == NULL || (fout = fopen(argv[1],"r+")) == NULL ){
    perror("Problem opening file, exiting...\n");
    exit(1);
  }
  rewind(fout);

  while( ( c = (char)fgetc(fin) ) != EOF ){
    if(is_space(c)){
      count++;
      if( count== 1 )
        fprintf(fout, "%c", ' ');
    }
    else{
      count=0;
      fprintf(fout, "%c", c);
    }
  }

  fclose(fin);
  fclose(fout);
  return 0;
}