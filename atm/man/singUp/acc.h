#ifndef MAN_ACC_h
#define MAN_ACC_h

#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct info{
    char name[30];
    char email[35];
    char phone_number[15];
    char password[25];
    char* folder_name;
    struct info* next;
};


//Functions: 
struct info* create_account();
bool find_char(struct info* temp);
int get_pos(struct info* temp);
void insert_folder_name(struct info* temp);


#endif