#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "../man/signUp/acc.h"
#include "../mem/clear_memory.h"
#include "../man/logIn/log.h"

#define PATH_SIZE 1024

// generate data of user and create the account
static bool gen_account(struct info* temp){
    // if temp == NULL means there is no data of the user
    if(temp == NULL) return false;

    // check_email return true means the email is in the correct form
    if(check_email(temp->email)){
        insert_folder_name(temp);
    }
    // else means the email is not in the correct form
    else return false;

    // create the directory of the user
    char path[PATH_SIZE]={"../man/logIn/accounts/"};
    strcat(path,temp->folder_name);
    mkdir(path,0777);
    strcat(path,"/");
    strcat(path,temp->email);
    strcat(path,".txt");
    
    // create the file contain the information of the user
    FILE* new = fopen(path,"w");
    fprintf(new,"name = %s\n", temp->name);
    fprintf(new,"email = %s\n",temp->email);
    fprintf(new,"phone_number = %s\n", temp->phone_number);
    fprintf(new,"password = %s\n", temp->password);
    fclose(new);
    // return true means the account created successfuly
    return true;
}

// generate all the program files and functions
static void gen(int choice){
    system("clear"); 
    // if the user want to create an account
    if(choice == 1 ){
        struct info* temp = NULL; 
        again:
        // temp store the address of the struct created in the create_account function
        temp = create_account();

        // if the gen_account function retuen false means there is a mistake 
        if(gen_account(temp) == false ){
         printf("\nPlease, sign up again\n"); 
         sleep(2);
         system("clear");
         // the user must sign up again
         goto again; 
        } 

        // else means the account has been created 
        // clear the address stored in the memory 
        clear(temp);
    }
    // else if the user create an account or want to log in
    log_in();
}

// start the app _main function
int main(int argc, char* argv[]){
    system("clear");
    int choice;
    printf("\n\t\t\tWelcome to ATM system\n");
    printf("\n1) Create new account\n");
    printf("2) Log in to your account\n");
    printf("choose: ");
    scanf("%d",&choice);
    gen(choice);
}