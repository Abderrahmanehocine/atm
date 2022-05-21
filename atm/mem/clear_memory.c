#include "clear_memory.h"

void clear(struct info* head){
    if(head->next == NULL) return;
    clear(head->next);
    free(head);
}