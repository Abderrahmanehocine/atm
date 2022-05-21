#include "generate.h"

static void gen_account(struct info* temp){
    if(temp == NULL) return;
    if(find_char(temp)){
        insert_folder_name(temp);
    }
    char path[PATH_SIZE]={"../man/logIn/accounts/"};
    strcat(path,temp->folder_name);
    mkdir(path,0777);
    strcat(path,"/");
    strcat(path,temp->email);
    strcat(path,".txt");
        
    FILE* new = fopen(path,"w");
    fprintf(new,"Name:\n%s\n", temp->name);
    fprintf(new,"Email:\n%s\n",temp->email);
    fprintf(new,"Phone_number:\n%s\n", temp->phone_number);
    fprintf(new,"Password:\n%s", temp->password);
    fclose(new);
}

void gen(int choice){
    system("clear");
    if(choice == 1 ){
        struct info* temp = create_account();
        gen_account(temp);
        clear(temp);
    }
    exit (0);
    system("clear");
    log_in();
}