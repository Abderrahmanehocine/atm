#ifndef MAN_LOG_H
#define MAN_LOG_H

#pragma once
#pragma pack(1)

#define MAX_LINE_SIZE 256
#define MAX_LINE 10
#define PATH_SIZE 1024
#define FILE_NAME_SIZE 1024
#define EMAIL_SIZE 250
#define PASSWORD_SIZE 50

#include "../signUp/acc.h"
#include "../../mem/clear_memory.h"

// arguments of the thread function
struct threadArg{
    FILE *file_name;
    int line;
    struct threadArg* next;
};

//Functions:
bool log_in();
static bool check(const char *path);
static void set_struct_data(struct threadArg* temp, FILE* file, int line_num);
bool check_account(struct info* temp, char* email, char* password);
static void* read_line(void* arg);

#endif