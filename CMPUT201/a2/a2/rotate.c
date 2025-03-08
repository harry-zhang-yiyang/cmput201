#include <stdio.h>

// count how many digits
int countdigits(int num){
    int count = 0, temp = num;
    while (temp > 0){
        temp /= 10;
        count++;
    }
    return count;
}

// *10
int power(int exp){
    int result = 1;
    for (int i = 0; i < exp; i++){
        result = result*10;
    }
    return result;
}

//rotate
int rotate(int num, int digits){
    int last = num % 10;  //get last number
    int remain = num /10;  //delet last number
    return last * power(digits - 1) + remain;  //new number
}

int main(){
    int num;
    
    if (scanf("%d", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    
    int digits = countdigits(num);
    int newnum = num;
    
    for (int i = 0; i < digits; i++){
        printf("%d\n", newnum);
        newnum = rotate(newnum, digits);
    }
    
    return 0;
}
