#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void permissions(mode_t st_mode)
{

    printf((S_ISDIR(st_mode)) ? "d" : "-");
    printf((S_ISLNK(st_mode)) ? "l" : "-");
    printf((st_mode & S_IRUSR) ? "r" : "-");
    printf((st_mode & S_IWUSR) ? "w" : "-");
    printf((st_mode & S_IXUSR) ? "x" : "-");
    printf((st_mode & S_IRGRP) ? "r" : "-");
    printf((st_mode & S_IWGRP) ? "w" : "-");
    printf((st_mode & S_IXGRP) ? "x" : "-");
    printf((st_mode & S_IROTH) ? "r" : "-");
    printf((st_mode & S_IWOTH) ? "w" : "-");
    printf((st_mode & S_IXOTH) ? "x" : "-");
}


void list(const char *dir_path)
{
    DIR *d;
    struct dirent *entry;
    struct stat file;
    struct passwd *user;
    struct group *group;
    struct tm *time;
    char buf[100];
    d=opendir(dir_path);
    if(d==NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("permissions\t links \t owner \t group \t size \t last modified \t     NAME\n");

    while((entry=readdir(d))!=NULL)
    {
        char full_buff[1024];

        snprintf(full_buff,sizeof(full_buff),"%s/%s",dir_path,entry->d_name);

        if(stat(full_buff,&file)==-1)
        {
            perror("stat");
            continue;
        }

        permissions(file.st_mode);
        printf("\t");

        printf("%ld\t",(long)file.st_nlink);


        user=getpwuid(file.st_uid);
        if(user!=NULL)
            printf("%s\t",user->pw_name);
        else
            printf("%d\t",file.st_uid);

        group=getgrgid(file.st_gid);
        if(group!=NULL)
            printf("%s\t",group->gr_name);
        else
            printf("%d\t",file.st_gid);

        printf("%lld\t",(long long)file.st_size);
        
        time=localtime(&file.st_atime);
        strftime(buf,sizeof(buf)," %d-%m  %H:%M:%S",time);
        printf("%s\t",buf);



        printf("%s\n",entry->d_name);
    }
    closedir(d);
}

int main(int argc, char *argv[])
{
    const char *dir_path;
    if(argc>1)
        list(argv[1]);
    else
    {
        dir_path=".";
        list(dir_path);
    }
    return 0;
}
