/*This is generate header files to generate all the files and the functions in this system
 - In this header file I declare the function gen which takes an int parametere the choice of the user and-
   the function call other function depending by the choice int
 - All the other functions are static means I use it only in generate.c file (Private functions)*/

#ifndef GEN_GENERATE_H
#define GEN_GENERATE_H

#define PATH_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../man/singUp/acc.h"
#include "../mem/clear_memory.h"
#include "../man/logIn/log.h"

// Functions:
void gen(int choice);
static void gen_account(struct info* temp);

#endif