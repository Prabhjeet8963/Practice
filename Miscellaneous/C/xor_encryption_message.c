#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 'X' 

void createHiddenMessage() {
    char message[] = "I LOVE YOU TOO,hehe";
    FILE *file = fopen("secret_data.bin", "wb");

    if (!file) {
        printf("Error creating file!\n");
        return;
    }
    for (int i = 0; i < strlen(message); i++) {
        char encrypted_char = message[i] ^ KEY;
        fwrite(&encrypted_char, sizeof(char), 1, file);
    }

    fclose(file);
    printf("ERROR! Past Memory Updatation\n"); 
}

void revealMessage() {
    FILE *file = fopen("secret_data.bin", "rb");

    if (!file) {
        printf("System log corrupted!\n"); 
        return;
    }

    printf("\nDecrypting...\n");
    sleep(2);  

    printf("\n DHAPPAAA! \n");
    printf(" Decrypted Message: ");
    
    char ch;
    while (fread(&ch, sizeof(char), 1, file)) {
        printf("%c", ch ^ KEY);
    }

    fclose(file);
    printf(" \n");
}

int main() {
    createHiddenMessage(); 
    sleep(1);  
    revealMessage(); 
    return 0;
}
