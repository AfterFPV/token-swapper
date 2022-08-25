#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILENAME 1028


//reformat folder date name
//    08-10-17 Cow Pond w Granddad
//              - to -
//    2017-08-10 Cow Pond w Granddad
//
//    mv-maker part 2
//
//

void do_the_swap(char* buf, int pos1_start, int pos2_start, int size_start) {

    char c;
    int pos1, pos2, size;

    pos1 = pos1_start;
    pos2 = pos2_start;
    size = size_start;

    while (size-- > 0) {
        
        c = buf[pos1];
        buf[pos1++] = buf[pos2];
        buf[pos2++] = c;
    } 
}


void bts_swapper(char* path) {
    
    char delim[] = " - ";
    DIR *d;
    struct dirent *dir;
    char buf[MAX_FILENAME];

    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            strcpy(buf, dir->d_name);

            if (!strstr(buf, "BTS")){
                continue;
            }
            
            do_the_swap(buf, 6, 12, 3);

            printf("mv \"%s\" \"%s\"\n", dir->d_name, buf);
        }

        closedir(d);
    } else {
        printf("err\n");
    }
}

void date_swapper(char * path) {

    char delim[] = "-";
    DIR *d;
    struct dirent *dir;
    char buf[MAX_FILENAME];

    printf("path: %s\n", path);
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            strcpy(buf, dir->d_name);

            if (buf[2] != '-') {
                continue;
            }
            
            do_the_swap(buf, 0, 6, 2);
            do_the_swap(buf, 3, 6, 2);

            printf("mv \"%s\" \"20%s\"\n", dir->d_name, buf);
        }

        closedir(d);
    } else {
        printf("err\n");
    }
}

int main( int argc, char *argv[] )
{
    char dir1[] = "e:\\User - Consolidated\\Videos\\My Movies\\Drone Footage";
    char dir2[] = "e:\\User - Consolidated\\Videos\\My Movies\\Mavic Footage";
    char dir3[] = "g:\\User_2\\User - Consolidated\\Videos\\My Movies\\Drone Footage";
    char dir4[] = "g:\\User_2\\User - Consolidated\\Videos\\My Movies\\Mavic Footage";

    
    

    date_swapper(dir1);
    date_swapper(dir2);
    date_swapper(dir3);
    date_swapper(dir4);
    
    

	return 0;
}
