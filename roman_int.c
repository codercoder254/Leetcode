//@a.d.a.n_noa😇
#include <stdio.h>


#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

//function to get user input
char* getInput()
{
    static char input[20];
    printf("Enter a Roman numeral: ");
    scanf("%s", input);
        return input;
    
}

    //function to convert Roman numeral to integer
int romanToInt(char *s)
{
    
        int total = 0;
        int prev_value = 0;
        for(int i = 0; s[i] != '\0'; i++)//example of XIV = 14
        {
            int value = 0;

        switch(s[i])
        {
            case 'I': value = I; break;
            case 'V': value = V; break;
            case 'X': value = X; break;
            case 'L': value = L; break;
            case 'C': value = C; break;
            case 'D': value = D; break;
            case 'M': value = M; break;
            default:
             printf("Invalid Roman numeral character: %c\n", s[i]); return -1;
        }

       if(value > prev_value)
        {
            total += value - 2 *prev_value; //adjust for previous addition
        }
        else
        {
            total += value;
        }
        prev_value = value;
    
   
    }
        return total;

}





int main()
{
    char *romanNumeral = getInput();
    int result = romanToInt(romanNumeral);
    if(result != -1)
    {
        printf("The integer value is: %d\n", result);
    }
    return 0;

}
