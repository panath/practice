#include<stdio.h>
#include <iostream>

using namespace std;

/*Counts the lenght of the string*/ 
int string_length(char*);
/*Reverses a string in place*/
void reverse(char*);
 
main() 
{
   char string[100];
 
   printf("Enter a string\n");
   gets(string);
 
   cout << "string length is " << string_length(string) << endl;
   reverse(string);
 
   printf("Reverse of entered string is \"%s\".\n", string);
 
   return 0;
}

/**
 * Reverses a string in place
 @param string the string to reverse
 @return 
*/
void reverse(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = string_length(string);
   begin  = string;
   end    = string;

   for (c = 0; c < length - 1; c++)
       end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end--   = *begin;
      *begin++ = temp;
   }
}

/**
 * Counts the lenght of the string
 @param char pointer to the string
 @return an integer counting the number of words in a string
*/
int string_length(char *pointer)
{
   int c = 0; 
   while (*pointer++)
     c++;
 
   return c;
}
