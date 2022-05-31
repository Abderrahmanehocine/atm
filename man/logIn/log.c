#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include "log.h"

bool log_in(){
  char email[60], password[40];
  again:
  system("clear");
  printf("Log in:\n");
  printf("\nEmail: ");
  scanf("%s",email);
  printf("Password: ");
  scanf("%s",password);
    
  if(check_email(email)){
    int pos = get_pos(email);
    char path[PATH_SIZE]={"/home/hcn/Desktop/atm/man/logIn/accounts/"};
    char folderName[pos];
    strncpy(folderName, email, pos);
    folderName[pos] = '\0';
    strcat(path,folderName);

    if(check(path)){
      struct info* temp = (struct info*)malloc(sizeof(struct info));
      temp->folder_name = path;
      check_account(temp, email, password);
      clear(temp);
    }
    else{
      printf("\nEmail invalid, please try again\n");
      sleep(2);
      goto again;
    }
  } 
  else{
    printf("\nPlease try again\n");
    sleep(2);
    goto again;
  }
  return true;
}

// Check for folder/file existence
static bool check(const char *path){
  struct stat buffer;
  return (stat (path,  &buffer) == 0)? true : false; 
}

// thread function to read from spesific lines from files of the users
static void* read_line(void* arg){
 struct threadArg* current = (struct threadArg*)arg;
 char buffer[MAX_LINE_SIZE];
 char* return_str;
 bool keep_reading = true;
 int  current_line = 1;

 do{
    fgets(buffer, sizeof(buffer), current->file_name);

    if(feof(current->file_name)){
      keep_reading = false;
    }
    else if(current_line++ == current->line){
      keep_reading = false;
      return_str = buffer;
      pthread_exit((void*)return_str); // return the string
    }
  } while(keep_reading);

  pthread_exit(NULL); // return NULL
}

static void set_struct_data(struct threadArg* temp, FILE* file, int line_num){
  temp->file_name = file;
  temp->line = line_num;
  temp->next = NULL;
}

bool check_account(struct info* temp, char* email, char* password){

  char fileName[FILE_NAME_SIZE];

  strcpy(fileName,temp->folder_name);
  strcat(fileName,"/");
  strcat(fileName,email);
  strcat(fileName,".txt");

  if(check(fileName)){
   FILE* check = fopen(fileName,"r");
   char* return1, return2;
   pthread_t email, password;
   
   // if check == NULL means the file has not been open
   if(check == NULL) return false;
   
   struct threadArg* temp1 = (struct threadArg* )malloc(sizeof(struct threadArg));
   struct threadArg* temp2 = (struct threadArg* )malloc(sizeof(struct threadArg));
   // set the data of the 2 member of struct created 
   set_struct_data(temp1, check , 2);
   set_struct_data(temp2, check, 4);

   // create 2 thread functions 
   pthread_create(&email, NULL, &read_line, (void*)temp1);
   pthread_create(&password, NULL, &read_line, (void*)temp2);
   // wait the thread to return the values
   pthread_join(email, (void**)&return1);
   pthread_join(password, (void**)&return2);

   printf("\n%s\n",return1);
   printf("%s\n",return2);

   clear_th(temp);
   fclose(check);
   return true;
  }
  return false; 
}