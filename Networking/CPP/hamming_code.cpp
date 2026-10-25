#include <stdio.h>
#include <string.h>
int main() {
    char data_str[5];
    int data[5], code[8], recv[8];

    printf("Enter 4-bit data (e.g., 1011): ");
    scanf("%s", data_str);

    // Convert char to int array for math operations
    for(int i = 0; i < 4; i++) {
        data[i] = data_str[i] - '0';
    }

    /*
       Mapping Data to Hamming Positions:
       Pos 1: P1 (Parity)
       Pos 2: P2 (Parity)
       Pos 3: D1 (Data[0])
       Pos 4: P3 (Parity)
       Pos 5: D2 (Data[1])
       Pos 6: D3 (Data[2])
       Pos 7: D4 (Data[3])
    */
    code[3] = data[0];
    code[5] = data[1];
    code[6] = data[2];
    code[7] = data[3];

    // Calculate Even Parity bits
    code[1] = code[3] ^ code[5] ^ code[7];
    code[2] = code[3] ^ code[6] ^ code[7];
    code[4] = code[5] ^ code[6] ^ code[7];

    printf("Encoded Hamming Code: ");
    for(int i = 1; i <= 7; i++) printf("%d", code[i]);
    printf("\n\n");

    // --- Error Detection Logic ---
    char recv_str[8];
    printf("Enter received 7-bit code (to check for errors): ");
    scanf("%s", recv_str);

    for(int i = 1; i <= 7; i++) {
        recv[i] = recv_str[i-1] - '0';
    }

    // Recalculate Parity Checkers (Syndromes)
    int s1 = recv[1] ^ recv[3] ^ recv[5] ^ recv[7];
    int s2 = recv[2] ^ recv[3] ^ recv[6] ^ recv[7];
    int s3 = recv[4] ^ recv[5] ^ recv[6] ^ recv[7];

    // Calculate error position (Binary to Decimal conversion)
    int error_pos = (s3 * 4) + (s2 * 2) + (s1 * 1);

    if(error_pos == 0) {
        printf("Result: No error detected.\n");
    } else {
        printf("Result: Error detected at position %d\n", error_pos);
        
        // Correct the bit
        recv[error_pos] = (recv[error_pos] == 0) ? 1 : 0;
        
        printf("Corrected Codeword: ");
        for(int i = 1; i <= 7; i++) printf("%d", recv[i]);
        
        printf("\nOriginal Decoded Data: %d%d%d%d\n", recv[3], recv[5], recv[6], recv[7]);
    }

    return 0;
}
