#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
void List(char *path)
{
    struct dirent* ent = NULL;
    DIR *pDir;
    pDir=opendir(path);
    while (NULL != (ent=readdir(pDir)))
    {
        if (ent->d_reclen==24)
        {
            if (ent->d_type==8)
            {
                printf("Common Files:%s\n", ent->d_name);
            }
            else
            {
                printf("Subdirectory%s\n",ent->d_name);
                List(ent->d_name);
                printf("Return%s\n",ent->d_name);
            }
        }
    }
}
int main(int argc, char *argv[])
{
     List(argv[1]);
     return 0;
}