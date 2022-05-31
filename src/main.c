#include <stdio.h>
#include <stdlib.h>
#include "../gen/generate.h"


int main(int argc, char* argv[]){
    system("clear");
    int choice;
    printf("\n\t\t\tWelcome to ATM system\n");
    printf("\n1) Create new account\n");
    printf("2) Log in to your account\n");
    printf("choose: ");
    scanf("%d",&choice);
    gen(choice);
}