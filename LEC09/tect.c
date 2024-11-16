#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 10001

// Function to convert hex character to integer
int hex_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else if ('a' <= c && c <= 'f') return 10 + (c - 'a');
    else if ('A' <= c && c <= 'F') return 10 + (c - 'A');
    return 0;
}

// Function to convert integer to hex string
void int_to_hex(int num, char *hex_str) {
    if (num == 0) {
        hex_str[0] = '0';
        hex_str[1] = '\0';
        return;
    }
    char temp[20];
    int idx = 0;
    while (num > 0) {
        int rem = num % 16;
        if (rem < 10) temp[idx++] = '0' + rem;
        else temp[idx++] = 'a' + (rem - 10);
        num /= 16;
    }
    // Reverse the string
    for (int i = 0; i < idx; i++) {
        hex_str[i] = temp[idx - i - 1];
    }
    hex_str[idx] = '\0';
}

// Recursive processing function
void process(const char *input, char *output) {
    int len = strlen(input);
    char even[MAX_LEN], odd[MAX_LEN];
    int e = 0, o = 0;
    for(int i = 0; i < len; i++) {
        if(i %2 ==0) even[e++] = input[i];
        else odd[o++] = input[i];
    }
    even[e] = '\0';
    odd[o] = '\0';

    // Sum even
    long sum_e =0;
    for(int i=0;i<strlen(even);i++) sum_e += hex_to_int(even[i]);

    // Sum odd
    long sum_o =0;
    for(int i=0;i<strlen(odd);i++) sum_o += hex_to_int(odd[i]);

    // Convert sums to hex
    char hex_e[20], hex_o[20];
    int_to_hex(sum_e, hex_e);
    int_to_hex(sum_o, hex_o);

    // Process further if length >1
    char final_e[20], final_o[20];
    if(strlen(hex_e) >1) process(hex_e, final_e);
    else {
        strcpy(final_e, hex_e);
    }
    if(strlen(hex_o) >1) process(hex_o, final_o);
    else {
        strcpy(final_o, hex_o);
    }

    // Concatenate even and odd
    sprintf(output, "%s%s", final_e, final_o);
}

int main(){
    char input[MAX_LEN];
    if(fgets(input, MAX_LEN, stdin)==NULL){
        input[0]='\0';
    }
    // Remove newline
    size_t len = strlen(input);
    if(len >0 && input[len-1]=='\n') input[len-1]='\0';

    char result[100];
    process(input, result);
    printf("%s\n", result);
    return 0;
}