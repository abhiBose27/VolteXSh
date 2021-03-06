/*#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include "cd.h"
*/

#include "headers.h"

void print_error_cd(char *this, char *dirname)
{
    fprintf(stderr, "%s cannot go to %s\n", this, dirname);
    return;
}
void print_usage_cd()
{
    fprintf(stderr, "Too many arguments: Type 'help' to know more\n");
    return;
}
void cd(int argc, char *argv[])
{
    struct passwd *user;
    int check;
    if (argc == 2)
    {
        check = chdir(argv[1]);
        if (check != 0)
            print_error_cd(argv[0], argv[1]);
    }
    else if (argc == 1)
    {
        user = getpwnam(getlogin());
        check = chdir(user->pw_dir);
        if (check != 0)
            print_error_cd(argv[0], argv[1]);
    }
    else
        print_usage_cd();
}
