#include <stdio.h>
/**
 * @brief - Convert quantities from metric system to imperial system based on user options.
 *        - The function begins by printing the following menu on the console:
 *            1. meters to yards, 2. grams to ounces, 3. exit
 *        - Read the user's choice by reading one of the integers 1,2,3; assume that the user's inputs are one of these.
 *        - On receiving input 3 from the user, print 'exiting' and exit from the program.
 *        - On receiving an input 1 or an input 2 from the user, read a 'double' number from the user 
 *          and convert it into yards or ounces using the following formulae:
 *            1 meter ~ 1.0936 yards
 *            1 gram ~ 0.0353 ounces 
 *        - After printing the converted quantites go back to printing the menu and repeating the above steps. 
 *        
 * Example: 
 *        - A possible run due to the function-call 'metricToImperial()' is given below:
            1. meters to yards, 2. grams to ounces, 3. exit 
            1
            10
            10.936000 yards
            1. meters to yards, 2. grams to ounces, 3. exit 
            1
            20
            21.872000 yards
            1. meters to yards, 2. grams to ounces, 3. exit 
            2
            20
            0.706000 ounces
            1. meters to yards, 2. grams to ounces, 3. exit 
            3
            exiting
 *    
 */
void metricToImperial()
{
  printf("1. meters to yards, 2. grams to ounces, 3. exit\n"); 
  int n; 
  scanf(" %d",&n); 
  if(n!=3)
  {
    double u; 
    scanf(" %lf",&u);
    if(n==1)
    {
      printf("%lf yards\n",(u*1.0936));
    } 
    else
    {
      printf("%lf yards\n",(u*0.0353));
    }
    metricToImperial();
  }
  else
  printf("exiting\n");
}
/**
 * @brief - Perform simple arithmetic operations on the parameter 'balance' depending on 
 *          the options entered by the user.
 *        - The function begins by printing the 'balance' and then asks for an option from the user.
 *        - The option entered by the user could be one of the following characters:
 *          '+', '-', 'e', 'c'.
 *        - On receiveing an option 'e', the function does not ask as for any more 
 *          options to be entered and returns 'e'.
 *        - On receiving one of '+', '-' as an option, the function waits for the user 
 *          to enter an integer 'n' and performs the corresponding operation between 'balance' and 'n'.
 *        - On receiving the option 'c', cancel the last operation and continues from there;
 *          stop if there are no operations before the current one. 
 *        - On receiving any options other than 'e', the function continues to wait for the user to
 *          enter the next option.
 *        
 * Example: 
 *        - A possible run due to the function-call 'calculator(0)' is given below:
            Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            +  
            10
            Balance: 30
            e
 *     - Another possible run due to the function-call 'calculator(0)' is given below:
            Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            -
            5
            Balance: 15
            c
            Balance: 20
            +  
            10
            Balance: 30
            c
            Balance: 20
            c
            Balance: 10
            e
 */
char calculator(int balance)
{
  printf("Balance: %d\n", balance);
  char c;
  int n; 
  scanf(" %c", &c); 
  if (c == '+' || c == '-'||c=='c') 
  {
    
    if (c == '+') 
    {
      scanf("%d", &n);
      balance += n; 
      if(calculator(balance)=='c')
      calculator(balance-n);
    }
     
    else if (c == '-') 
    {
      scanf("%d", &n);
      balance -= n; 
      if(calculator(balance)=='c')
      calculator(balance+n);
    } 
    else if(c=='c')
    {
    return 'c';
    } 
  }
  else
  { 
    return 'e';
  }
} 
int main()
{
  printf("1. metricToImperial()  2. calculator(0) \n");
  printf("Which function do you want to test? Enter 1,2 accordingly.\n");
  char c;
  int option;
  scanf(" %d",&option);

  if (option == 1)
  {
    metricToImperial();
  }
  if(option == 2)
  {
    calculator (0);
  }
  return 0;
}