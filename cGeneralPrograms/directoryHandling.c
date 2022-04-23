#include <stdio.h>
#include <dirent.h>
int main()
{
    struct dirent* dep; // dep => directory entry pointer
    /*
    struct dirent {
        ino_t          d_ino;       // inode number
        off_t          d_off;       // offset to the next dirent
        unsigned short d_reclen;    // length of this record
        unsigned char  d_type;      // type of file; not supported by all file system types
        char           d_name[256]; // filename
    };
    */
    DIR* current = opendir(".");
    /*
    The opendir() function shall open a directory stream corresponding to the directory named by the dirname argument.
    The directory stream is positioned at the first entry.
    */
    while ((dep = readdir(current)) != NULL)
    {
        printf("%s\n", dep -> d_name);
    }
    closedir(current);
}