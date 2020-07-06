/*
Course: CS302
Author:Preston Porter
Assignment: Homework1

   This program adds a number to every value read from
   standard input and writes the result to standard output.

   The default value to add to every input number is 0.
   This default value can be overridden by
      1.) a value from a configuration file, or by
      2.) an environment variable, or by
      3.) a command line argument.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#define  LINELEN  64

int main(int argc, char *argv[])
{
   // Set the default values.
   int precision=3;
   int columns=3;
  
   
  

   // Override the default value with a value from the configuration file.
   // open the configuration file
   
     
     
    FILE *fp;
   if ( (fp = fopen("filter.cfg", "r")) != NULL )
   {
      // read the first line of the config file
     
         // get an operand from the config file
        fscanf(fp, "%d", &precision);
        fscanf(fp, "%d", &columns);
      
      
   }
   if ((fp = fopen( "filter.cfg", "r")) == NULL) {
	   printf("error file not opened");
   }
  // printf(precision);
   // Override the default value with an environment variable value.
   char *op = getenv( "CS302HW1PRECISION" );  //precision 
   if (op!=NULL)
   {  // get an operand from the environment
      precision = atoi(op);
   }
   printf("hello");
  char *op2 = getenv( "CS302HW1COLUMNS" );  //columns
   if (op2!=NULL)
   {  // get an operand from the environment
      columns = atoi(op2);
   }
  printf("hi");

   // Get a command line argument (if it exists).
   if (argc > 1)   // precision //columns
   {  // get an operand from the command line
      precision = atoi(argv[1]); 
	  
   }
 if (argc > 2)   // precision //columns
   {  //get an operand from the command line
     // incBy = atoi(argv[1]);
	  columns = atoi(argv[2]);
   }
   // Process the stream of input numbers.

  

 
	 
   float x;
   int curCol=0;
   //int i = 0;
	   while (scanf("%f",&x)!=EOF)
	   {
		  
		   curCol++;
         if(x>1000) // if number is 1000 through 10000
         {
         printf("  ");
         }
         if((1000>x)&&(x>100)) // if number is 100 through 1000
         {
         printf("   ");
         }
         if((1000>x)&&(100>x)&&(x>10))//if number is 10 through 99
         {
         printf("    ");
         }
         if((1000>x)&&(100>x)&&(10>x))//if number is less than 10
         {
         printf("     ");
         }
         
		   printf("%.*f",precision, (x));
		   
		   if (curCol >= columns)
		   {
			   
			   printf("\n");
            curCol = 0;
		   }
		   
	   }
   printf("\n");
   printf("the number of columns are set to %d", columns);
   printf("\n");
   printf("the precision is set to %d",precision);
  return 0;
}


