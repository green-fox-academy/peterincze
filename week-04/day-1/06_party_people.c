#include <stdio.h>
#include <stdlib.h>



int main()
{
    // Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys.
    int a=0;
    int b=0;
    printf("Your girls number is: ");
    scanf("%d", &a);
    printf("Your boys number is: ");
    scanf("%d", &b);

// It should print "The party is excellent!" if the the number of girls and
// boys are equal and there are more people coming than 20
    if(a==b && a+b>20){
        printf("The party is excellent!\n");
    }

// It should print "Quite cool party!"
// if there are more than 20 people coming but the girl - boy ratio is not 1-1
    else if(a+b>20 && (a>b || b>a)){
        printf("The party quite cool!\n");
    }

// It should print: "Average party..."
// if there are less people coming than 20
    else if(a+b<=20 && a!=0 && b!=0){
        printf("Average party...\n");
    }
// It should print: "Sausage party"
// if no girls are coming, regardless the count of the people
    else if(a==0){
        printf("Sausage party\n");
    }
    return 0;
}
