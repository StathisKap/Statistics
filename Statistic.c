/* Finds the Mean, Standatd deviation, variance, median and Coefficient of Variation of a file
*Author: Stathis Kapnidis
*Date Created: 1/12/2020
*Last Modified:1/12/2020
*TODO: Add mode
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{ //Take the name of the file passed and open it. Declare and initialise variables
    char *name = argv[1];
    FILE * input = fopen(name,"r");
    int count = 0;
    float mean=0,variance=0,standard_deviation=0, measurements=0,median =0, mode=0,measurements2 =0;

        //Scan the file for all the values and find the mean
    while(EOF && fscanf(input, "%f", &measurements)==1)
    {
        mean +=measurements;
        count++;
    }
    mean = mean / count;
        //Go back to the top of the file
   fseek(input, 0, SEEK_SET);
        //Go through all the values again and find the variance this time using the mean
    while(EOF && fscanf(input, "%f", &measurements)==1)
    {
        variance += pow((measurements - mean),2);
        
    }
    variance = variance/(count-1);
        //Find the standard deviation using the square root of the variance.
    standard_deviation = sqrt(variance);
    
        //Reset Position
    fseek(input, 0, SEEK_SET);

        //Find the median
    if(count%2==0)
    {       //If the lines are even, then add the 2 middle values and find the average
        for(int i = 0; i<((count/2)-1);i++)
        {
            fscanf(input,"%f",&measurements);
        }
        for(int i =0; i<2;i++)
        {
            fscanf(input,"%f",&measurements);
            median += measurements; 
        }
        median = median/2; 
    }
    else        //If they are odd, just give the middle value
    {
        for(int i = 0; i<((count/2)+1);i++)
        {
            fscanf(input,"%f",&measurements);
        }
        median += measurements; 
    }
        //Reset Position
    fseek(input, 0, SEEK_SET);

        //Finding the mode
        int i = 0, j = 0, maxOccurances = 0;
    for (i = 0; i < count; ++i) {
        int occurances= 0;
        fscanf(input,"%f",&measurements);
      
      for (j = 0; j < count; ++j) {  
        fscanf(input,"%f",&measurements2);
        if (measurements2 == measurements)
        ++occurances;
      }
      
      if (occurances > maxOccurances) {
         maxOccurances = occurances;
         mode = measurements;
      }
   }

    printf("Mean = %.3f\nVariance = %.3f\nStandard Deviation = %.3f\nCoefficient of Variation = %.3f\nMedian = %.3f\nMode = %.3f\n",mean,variance,standard_deviation,standard_deviation/mean,median,mode);
    fclose(input);

}