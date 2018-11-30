#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>

int main()
{
  char *password = NULL;
  char *hash = NULL;
    
  scanf("%ms",&password);
  scanf("%ms",&hash);

  char *cryptPassword = crypt(password, "00");
  if(cryptPassword == NULL){
    printf("Error\n");
    }else{
      if(strcmp(cryptPassword, hash) == 0) {
        printf("allow\n");
      } else {
        printf("deny\n");
    }
  }
  free(password);
  free(hash);
  return 0;
}
