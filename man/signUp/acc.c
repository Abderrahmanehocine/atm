#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "acc.h"

struct info* create_account(){
    // create new member of the struct to take information of the user
    struct info* new = (struct info*)malloc(sizeof(struct info));
    char pass[30],conf[30];

    printf("Create new account:\n\n");

    printf("Full name: ");
    scanf("\n");
    scanf("%[^\n]",new->name);
    
    email:
    printf("Email: ");
    scanf("\n");
    scanf("%[^\n]",new->email);
    // if check_email returned false means the email is not in the correct forme
    if(check_email(new->email) == false){
        printf("\n\nPlease, enter a valid email\n");
        goto email;
    }

    printf("Phone number: ");
    scanf("\n");
    scanf("%[^\n]",new->phone_number);

    password:
    printf("Password: ");
    scanf("\n");
    scanf("%[^\n]",pass);
    printf("Confirme password: ");
    scanf("\n");
    scanf("%[^\n]",conf);
    // if password and confirme password are not the same the use must enter the password again
    if(strcmp(pass,conf) != 0){
        printf("\nplease confirme the password, try again\n");
        goto password;
    }

    strcpy(new->password,pass);
    new->next = NULL;

    // return the address of the member of the struct created
    return new;
}

// get the index of the '@' in the email of the user
int get_pos(const char* email){
    char* result = strchr(email, '@');
    //int pos = result - email;
    return result - email;
} 

bool check_email(const char* email){
    // the email must contain '@' and '.' and musn't contain space ' '
    if(strchr(email, '@') && strchr(email, '.') && strchr(email, ' ') == NULL) return true;
    return false;
}

void insert_folder_name(struct info* temp){
    int pos = get_pos(temp->email);
    char folderName[pos];
    strncpy(folderName, temp->email, pos);
    folderName[pos] = '\0';
    strcpy(temp->folder_name,folderName);
} // insert_folder_name()