/* This is the header file of clear_memory used to clear the places allocated in the memory dynamicly to 
avoid memory leaks and other memory problems*/

#ifndef MEM_CLEAR_MEMORY_H
#define MEM_CLEAR_MEMORY_H

#pragma once

#include <stdio.h> 
#include "../man/signUp/acc.h"
#include "../man/logIn/log.h"

// Fnctions declaration:
void clear(struct info *head);
void clear_th(struct threadArg* head);

#endif