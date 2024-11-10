# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];
    
    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);
    
    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}
int length(char pwd1[], char pwd2[]) {
    int len1 = strlen(pwd1);
    int len2 = strlen(pwd2);
    if(len1 <= 16 && len1 >=6 && len2 >=6 && len2<=16) return 0;
    else return 1;
}

int compare(char pwd1[], char pwd2[]) {
    int len = strlen(pwd1);
    int flag = 0;
    for(int i = 0;i<=len-1;i++)
    {
        if(pwd1[i] != pwd2[i]) flag =1;
        else continue;
    }
    if(flag)return 1;
    else return 0;
}

int content(char pwd1[]) {
    int check[3] = {0, 0, 0}; 
    for(int i = 0; i < strlen(pwd1); i++) {
        if(pwd1[i] >= 'a' && pwd1[i] <= 'z') {
            check[0] = 1; 
        } else if(pwd1[i] >= 'A' && pwd1[i] <= 'Z') {
            check[1] = 1; 
        } else if(pwd1[i] >= '0' && pwd1[i] <= '9') {
            check[2] = 1; 
        }
    }
    return !(check[0] && check[1] && check[2]); 
}