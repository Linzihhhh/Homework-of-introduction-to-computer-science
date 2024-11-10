#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}

void convert(char *arr[], int count){
    char *t9[] = {
        "(2)1", "(2)2", "(2)3",    // a, b, c
        "(3)1", "(3)2", "(3)3",    // d, e, f
        "(4)1", "(4)2", "(4)3",    // g, h, i
        "(5)1", "(5)2", "(5)3",    // j, k, l
        "(6)1", "(6)2", "(6)3",    // m, n, o
        "(7)1", "(7)2", "(7)3", "(7)4", // p, q, r, s
        "(8)1", "(8)2", "(8)3",    // t, u, v
        "(9)1", "(9)2", "(9)3", "(9)4"  // w, x, y, z
    };
    
    for (int i = 0; i < count; i++) {
        char *str = arr[i];
        int len = strlen(str);
        char strnew[LINE_LEN];
        int k = 0;
        for(int j = 0; j <= len-1;j++)
        {
            if(*(str+j) == ' ')
            {
                strnew[k] = ' ';
                k++;
                continue;
                
            }
            else if(*(str+j) >= 'a' && *(str+j) <= 'z')
            {
                strnew[k] = t9[*(str+j) - 'a'][0];
                k++;
                strnew[k] = t9[*(str+j) - 'a'][1];
                k++;
                strnew[k] = t9[*(str+j) - 'a'][2];
                k++;
                if(t9[*(str+j) - 'a'][3] != '\0')
                {
                    strnew[k] = t9[*(str+j) - 'a'][3];
                    k++;
                }
            }
            else if(*(str+j) >= 'A' && *(str+j) <= 'Z')
            {
                strnew[k] = t9[*(str+j) - 'A'][0];
                k++;
                strnew[k] = t9[*(str+j) - 'A'][1];
                k++;
                strnew[k] = t9[*(str+j) - 'A'][2];
                k++;
                if(t9[*(str+j) - 'A'][3] != '\0')
                {
                    strnew[k] = t9[*(str+j) - 'A'][3];
                    k++;
                }
            }
            else
            {
                strnew[k] = *(str+j);
                k++;
            }
        }
        for(int j = 0 ; j<= k-1;j++)
        {
            *(str+j) = strnew[j];
        }
        str[k] = '\0';
    }
}
