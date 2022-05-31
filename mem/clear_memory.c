#include <stdlib.h>
#include "clear_memory.h"

void clear(struct info *head){
    if(head->next == NULL) return;
    clear(head->next);
    free(head);
}

void clear_th(struct threadArg *head){
    if(head->next == NULL) return;
    clear_th(head->next);
    free(head);
}