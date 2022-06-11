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
      strcpy(temp->folder_name,path);
      if(check_account(temp, email, password)){
        get_user_data(temp,path);
        user_account(temp,path);
      }
      else{
        printf("\nEmail or password incorrect, please try again\n");
        sleep(2);
        goto again;
      }
      free(temp);
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
  return false;
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
 int  current_line = 1;
  while(fscanf(current->file_name,"%[^\n]",buffer) != EOF) { 
    if(current_line++ == current->line){
      return_str = buffer;
      printf("%s\n",return_str);
      pthread_exit((void*)return_str);	// return the string 
    }
    fscanf(current->file_name,"%*[\n]");
  }
  pthread_exit(NULL);
}


static void set_struct_data(struct threadArg* temp, FILE* file, int line_num){
  temp->file_name = file;
  temp->line = line_num;
  temp->next = NULL;
}

bool check_account(struct info* temp, char* em, char* pass){
  char fileName[FILE_NAME_SIZE];
  strcpy(fileName,temp->folder_name);
  strcat(fileName,"/");
  strcat(fileName,em);
  strcat(fileName,".txt");

  if(check(fileName)){
   FILE* check1 = fopen(fileName,"r");
   FILE* check2 = fopen(fileName,"r");
   // if one of the files not opend we return a false means there is an error
   if(check1 == NULL || check2 == NULL)  return false;

   pthread_t email;
   pthread_t password;
   char* return1;
   char* return2;
   struct threadArg* temp1 = (struct threadArg* )malloc(sizeof(struct threadArg));
   struct threadArg* temp2 = (struct threadArg* )malloc(sizeof(struct threadArg));

   // set the data of the 2 member of struct created 
   set_struct_data(temp1, check1 , 2);
   set_struct_data(temp2, check2, 4);
   // create 2 thread functions 
   pthread_create(&email, NULL, read_line, (void*)temp1);
   pthread_create(&password, NULL, read_line, (void*)temp2);
   // wait the threads to return the values
   pthread_join(email, (void*)&return1);
   pthread_join(password, (void**)&return2);
   // free structure allocated in the memory
   free(temp1);
   free(temp2);
   // close files opened
   fclose(check1);
   fclose(check2);

   if(check_information(temp,return1,return2,em,pass)) return true;
  }
  return false; 
}

// check if the information of the user is the same with the input
static bool check_information(struct info* temp, const char* inEmail, const char* inPass, const char* email, const char* pass){
  if(strcmp(email,inEmail) == 0 && strcmp(pass,inPass) == 0){ 
    strcpy(temp->email,inEmail);
    strcpy(temp->password,inPass);
    return true;
  }
  return false;
}

static bool get_user_data(struct info* temp,const char* folder_path){
  char fileName[FILE_NAME_SIZE];
  strcpy(fileName,folder_path);
  strcat(fileName,"/");
  strcat(fileName,temp->email);
  strcat(fileName,".txt");

  if(check(fileName)){
    FILE* get_name = fopen(fileName,"r");
    FILE* get_phone = fopen(fileName,"r");
    if(get_name == NULL || get_phone == NULL)  return false;

   pthread_t name;
   pthread_t phone_number;
   char* return1;
   char* return2;
   struct threadArg* temp1 = (struct threadArg* )malloc(sizeof(struct threadArg));
   struct threadArg* temp2 = (struct threadArg* )malloc(sizeof(struct threadArg));
   set_struct_data(temp1, get_name , 1);
   set_struct_data(temp2, get_phone, 3);
   pthread_create(&name, NULL, read_line, (void*)temp1);
   pthread_create(&phone_number, NULL, read_line, (void*)temp2);
   // wait the threads to return the values
   pthread_join(name, (void*)&return1);
   pthread_join(phone_number, (void**)&return2);
   free(temp1);
   free(temp2);
   // close files opened
   fclose(get_name);
   fclose(get_phone);
   return true;
  }
  return false;
}