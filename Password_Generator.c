#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define PASSWORD_LENGTH 16

char a_z[] = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 
               'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 
               'u' , 'v' , 'w' , 'x' , 'y' , 'z' };

char A_Z[] = { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 
               'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 
               'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' };

char special_characters[] = { '!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' };
char numbers[] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , '0' };

void initialize_password(char* password) {
    struct timeval time;
    gettimeofday(&time, NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); // Seed with milliseconds
    /*define how many lowercase letters will be in the final password*/
    int lowercase_amount = rand() % (7 - 5 + 1) + 5;
    /*define how many uppercase letters will be in the final password*/
    int uppercase_amount = rand() % (5 - 2 + 1) + 2;
    /*define how many numbers will be in the final password*/
    int numbers_amount = rand() % (3 - 1 + 1) + 1;
    /*define how many special chars will be in the final password*/
    int special_amount = PASSWORD_LENGTH - lowercase_amount - uppercase_amount - numbers_amount;

    int i = 0;
    while(i < PASSWORD_LENGTH) {
        int value = rand();
        if(lowercase_amount > 0) {
            password[i] = a_z[value % 26];
            lowercase_amount--;
        }
        else if(uppercase_amount > 0) {
            password[i] = A_Z[value % 26];
            uppercase_amount--;
        }
        else if(special_amount > 0) {
            password[i] = special_characters[value % 10];
            special_amount--;
        }
        else {
            password[i] = numbers[value % 10];
            numbers_amount--;
        }
        i++;
    }
}

void shuffle_password (char* password) {
    int i;
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        int place = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[place];
        password[place] = temp;
    }
}

int main() {
    int i;
    char password[PASSWORD_LENGTH];

    initialize_password(password);
    shuffle_password(password);

    /*Print generated password to the console*/
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        printf("%c", password[i]);
    }
    return 0;
}