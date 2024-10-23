#include <stdio.h>
#include <ctype.h>

int charChecker(char c){ 
    if(isdigit(c)){
        return 0;
    }else if(c == '+' || c == '-' || c == '/' || c == '*'){ // Check if operator
        return 1;
    }
    return 2; 
}

int main(){
    int j = 0;
    int state = 0;
    char str[50];  
    scanf("%s",str);
    int table[3][3] = {{0,1,2}, {0,2,2}, {2,2,2}}; 
    int total = 0;
    int currentNumber = 0;  
    char lastOperator = '+'; 

    while(str[j] != '\0'){
        int x = charChecker(str[j]);
        int input;
        
        switch(x){
            case 0: // if digit
                input = 0; 
                currentNumber = currentNumber * 10 + (str[j] - '0'); 
                break;
            case 1: // if operator
                input = 1;
                
               
                if (lastOperator == '+') {
                    total += currentNumber;
                } else if (lastOperator == '-') {
                    total -= currentNumber;
                } else if (lastOperator == '*') {
                    total *= currentNumber;
                } else if (lastOperator == '/') {
                    total /= currentNumber;
                }
                
              
                lastOperator = str[j];
                currentNumber = 0;
                break;
            case 2:  // if not operator/digit
                input = 2;
                break;
        }
        
        state = table[state][input];
        
        if(state == 2){
            printf("Not Accepted (dead state) at character '%c'\n", str[j]);
            break;
        }else if(state == 1){
            printf(" (Not yet accepted) at character '%c'\n", str[j]);
        }else{
            printf("Accepted '%c'\n", str[j]);
        }
        
        j++;
    }

 
    if (lastOperator == '+') {
        total += currentNumber;
    } else if (lastOperator == '-') {
        total -= currentNumber;
    } else if (lastOperator == '*') {
        total *= currentNumber;
    } else if (lastOperator == '/') {
        total /= currentNumber;
    }
    
    printf("Total: %d\n", total);
    return 0;
}
