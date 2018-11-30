#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <setjmp.h>

jmp_buf  env;

void checkPassword()
{
    char *password = NULL;
    char *hash = NULL;
   
    printf("Enter a password: \n");
    scanf("%ms",&password);  
    
    printf("Enter a hash: \n");
    scanf("%ms",&hash); 
    
    //crypt password
    char *cryptPassword = crypt(password, "salt");
    if(cryptPassword != NULL) {
        if(strcmp(cryptPassword, hash) == 0) 
        {
            printf("Allow");
        } else {
            printf("Deny");
        }
        free(password);
        free(hash);
    } else {
        longjmp (env, 42);
    }
}

int main()
{
    if(setjmp (env)) {
       printf("Error");
    } else {
       checkPassword();
    }
   
    return 256;
}
