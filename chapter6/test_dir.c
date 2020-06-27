#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DIR *dir = opendir("./");
    struct dirent *dentry;
    while((dentry = readdir(dir)) != NULL) {
        printf("%-50s %d\n", dentry->d_name, dentry->d_reclen);

    }
    return 0;
}
