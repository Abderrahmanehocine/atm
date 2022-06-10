#ifndef MAN_ACC_h
#define MAN_ACC_h

#pragma once

#include <stdbool.h>

struct info{
    char name[30];
    char email[35];
    char phone_number[15];
    char password[25];
    char folder_name[1024];
    struct info* next;
};


//Functions: 
struct info* create_account();
bool check_email(const char* email);
int get_pos(const char* email);
void insert_folder_name(struct info* temp);


#endif