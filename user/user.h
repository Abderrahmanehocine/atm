#ifndef USER_USER_H
#define USER_USER_H

#include <stdbool.h>
#include "../man/logIn/log.h"
#include "../man/signUp/acc.h"

#define PATH_MAX_SIZE 1024

void user_account(struct info* data, const char* folder_path);
static bool set_logIn_time(const char* user_path);

#endif