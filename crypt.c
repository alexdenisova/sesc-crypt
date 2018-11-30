#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <setjmp.h>


void checkPassword()
{
    char *password = NULL;
    char *hash = NULL;

    scanf("%ms",&password);  
    scanf("%ms",&hash); 
    
    //crypt password
    char *cryptPassword = crypt(password, "4r");
    if(cryptPassword != NULL) {
        if(strcmp(cryptPassword, hash) == 0) {
            printf("allow\n");
        } else {
            printf("deny\n");
        }
        free(password);
        free(hash);
    } else {
      printf("Error\n");
    }
}

int main(){
       checkPassword();
    }
    return 0;
}
