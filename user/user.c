#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

static bool set_logIn_time(const char* user_path){
 char path[PATH_MAX_SIZE];
 strcpy(path,user_path);
 strcat(path,"/logIn.txt");
 // open the file 
 FILE* user = fopen(path,"a");
 if(user == NULL) return 0;
// set the time in the file
 time_t now = time(NULL);
 char* s_now = ctime(&now);
 fprintf(user,"%s",s_now);
 return 1;
}

void user_account(struct info* data, const char* folder_path){
    system("clear");
    set_logIn_time(folder_path);
    printf("==========   Welcome to your account %s  ==========\n\n",data->name);
}
