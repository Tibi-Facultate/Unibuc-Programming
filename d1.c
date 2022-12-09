#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>

int print_dirs(const char *path, int recursive)
{
    struct dirent *direntp = NULL;
    DIR *dirp = NULL;
    size_t path_len;

    // Verificam parametrii
    if (!path)
        return -1;
    path_len = strlen(path);

    if (!path || !path_len || (path_len > PATH_MAX))
        return -1;

    //Deschidem directorul
    dirp = opendir(path);
    if (dirp == NULL)
        return -1;

    while ((direntp = readdir(dirp)) != NULL)
    {
        // Pentru fiecare director deschis
        struct stat fstat;
        char full_name[PATH_MAX + 1];

        // Verificam daca numele complet al directorului este mai mare decat limita maxima
        if ((path_len + strlen(direntp->d_name) + 1) > PATH_MAX)
            continue;

        strcpy(full_name, path);
        if (full_name[path_len - 1] != '/')
            strcat(full_name, "/");
        strcat(full_name, direntp->d_name);

        // Ignoram directoarele cu . si ..
        if ((strcmp(direntp->d_name, ".") == 0) ||
            (strcmp(direntp->d_name, "..") == 0))
            continue;

        /* Print only if it is really directory. */
        if (stat(full_name, &fstat) < 0)
            continue;
        if (S_ISDIR(fstat.st_mode)) // Verificam daca este director
        {
            printf("%s\n", full_name);
            if (recursive)
                print_dirs(full_name, 1);
        } else if (S_ISREG(fstat.st_mode)) // Verificam daca este fisier
            printf("%s\n", full_name);
    }

    (void)closedir(dirp);
    return 0;
}

int main(int argc, char** argv)
{
    if(argc != 2){
        fprintf(stderr, "Utilizare: ./%s specificator_director\n", argv[0]);
        return 1;
    }

    print_dirs(argv[1], 1);
    return 0;
}
