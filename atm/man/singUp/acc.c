#include "acc.h"

struct info* create_account(){
    struct info* new = (struct info*)malloc(sizeof(struct info));
    char pass[30],conf[30];
    printf("Create new account:\n\n");

    printf("Name: ");
    scanf("\n");
    scanf("%[^\n]",new->name);

    printf("Email: ");
    scanf("\n");
    scanf("%[^\n]",new->email);

    printf("Phone number: ");
    scanf("\n");
    scanf("%[^\n]",new->phone_number);

    retry:
    printf("Password: ");
    scanf("\n");
    scanf("%[^\n]",pass);
    printf("Confirme password: ");
    scanf("\n");
    scanf("%[^\n]",conf);
    if(strcmp(pass,conf) != 0){
        printf("\nPlease enter a same password\n");
        goto retry;
    }

    strcpy(new->password,pass);
    new->next = NULL;
    return new;
}

int get_pos(struct info* temp){
    char* result = strchr(temp->email, '@');
    int pos = result - temp->email;
    return pos;
}

bool find_char(struct info* temp){
    if(strchr(temp->email, '@')) return true;
    return false;
}

void insert_folder_name(struct info* temp){
    int pos = get_pos(temp);
    char folderName[pos];
    strncpy(folderName, temp->email, pos);
    folderName[pos] = '\0';
    temp->folder_name = folderName;
}