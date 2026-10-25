#include <stdio.h>
#include <string.h>

void crc_xor(char *temp, char *gen) {
    for (int j = 1; j < strlen(gen); j++) {
        temp[j] = (temp[j] == gen[j]) ? '0' : '1';
    }
}

void calculate_crc(char *data, char *gen) {
    int data_len = strlen(data);
    int gen_len = strlen(gen);
    char temp[20], remainder[20];
    
    // Copy first part of data into temp
    strncpy(temp, data, gen_len);

    for (int i = 0; i < data_len; i++) {
        if (temp[0] == '1') {
            crc_xor(temp, gen);
        }
        
        // Shift bits: Move next bit from data into temp
        for (int j = 0; j < gen_len - 1; j++) {
            temp[j] = temp[j + 1];
        }
        
        if (i + gen_len < data_len + gen_len - 1)
            temp[gen_len - 1] = data[i + gen_len];
        else
            temp[gen_len - 1] = '0';
    }
    
    strncpy(remainder, temp, gen_len - 1);
    remainder[gen_len - 1] = '\0';
    printf("CRC Remainder: %s\n", remainder);
    printf("Final Codeword: %s%s\n", data, remainder);
}

int main() {
    char data[] = "1101";
    char gen[] = "1011"; // Generator polynomial
    printf("Data: %s, Generator: %s\n", data, gen);
    calculate_crc(data, gen);
    return 0;
}
