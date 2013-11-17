#include <stdio.h>
#include <string.h>
#include <dirent.h>

int unless(const char *path){
    if( strcmp(path, "..")!=0 && strcmp(path, ".")!=0 )
        return 1;
    return 0;
}

int listdir(const char *path, int depth) {
    struct dirent *entry;
    DIR *dp;
    int i;
    char *stupidc;
    strcpy(stupidc, "/");
    strcat(path, stupidc);
    dp = opendir(path);
    if (dp == NULL) {
        // perror("opendir");
    return -1;
    }

    while(entry = readdir(dp)){
        for( i=0; i<depth;i++)
            printf(" ");

        if(unless(entry->d_name)!=0 )
            printf("%s\n", entry->d_name);
        // puts(entry->d_name);
        
        if( entry->d_type == DT_DIR && unless(entry->d_name)!=0 )
            listdir(entry->d_name, depth+1);
    }
    closedir(dp);
    return 0;
}
 
int main(int argc, char **argv) {
    if (argc == 1)
        listdir(".", 0);
    else
        listdir(argv[1], 0);

  return 0;
}