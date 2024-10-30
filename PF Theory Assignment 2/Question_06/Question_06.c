
// Name  : Arslan Rashid
// Roll no : 24k - 0776
// Instructor : Sir Farooque

#include<stdio.h>
int match_sticks(int n)
{
    if (n%5==0) 
	{
        return -1;
    }
	else
	{
        return n%5;
    }
}
int main()
{ 
    int n;
	printf("Enter the number of matchstickses: ");
	scanf("%d", &n);
	match_sticks(n);
	int result=match_sticks(n);
    if (result==-1) 
	{
        printf("Return -1");
    }
	else
	{
        printf("A should pick %d matchsticksstick(s).\n", result);
    }
}
