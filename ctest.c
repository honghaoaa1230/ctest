#include <stdio.h>

const char* getNumberWord(int num) {
    const char* words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    const char* negativeWord = "negative";

    if (num >= -10 && num <= 10) {
        if (num < 0) {
            printf("%s ", negativeWord);
            num = -num;
        }
        return words[num];
    } else {
        return "";
    }
}

const char* getSumWord(int sum) {
    const char* sumWords[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                              "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                              "eighteen", "nineteen", "twenty"};

    if (sum >= 0 && sum <= 20)
        return sumWords[sum];
    else if (sum > 20 && sum < 100) {
        int tens = sum / 10;
        int ones = sum % 10;
        const char* tensWords[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        if (ones > 0)
            return tensWords[tens];
        else
            return tensWords[tens];
    } else {
        return "";
    }
}

int main() {
    int num1, num2, sum;

    printf("Please enter two integers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;

    printf("The sum is: ");
    printf("%s + %s = ", getNumberWord(num1), getNumberWord(num2));

    if (sum < 0) {
        printf("%s ", getNumberWord(sum));
    } else {
        printf("%s", getSumWord(sum));
    }

    printf("\n");

    return 0;
}
