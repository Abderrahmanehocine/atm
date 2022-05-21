#ifndef MAN_LOG_H
#define MAN_LOG_H

#pragma pack(1)

#define MAX_LINE_SIZE 500
#define MAX_LINE 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../signUp/acc.h"

struct information{
  char name[30];
  char email[35];
  char phone_number[15];
  char password[25];
}information;

//Functions:
void log_in();

#endif