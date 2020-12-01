/* Finds the Mean, Standatd deviation, variance and Coefficient of Variation of a file
*Author: Stathis Kapnidis
*Date Created: 1/12/2020
*Last Modified:1/12/2020
*TODO: Add mode and median
*/

#include <stdio.h>
#include <math.h>
void main(int argc, char *argv[])
{ //Take the name of the file passed and open it. Declare and initialise variables
    char *name = argv[1];
    FILE * input = fopen(name,"r");
    int count = 0;
    float mean=0,variance=0,standard_deviation=0, measurements=0,median =0;

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

        //Finding the median
    if(count%2==0)
    {
        fseek(input,(count/2), SEEK_SET);
        median += fscanf(input,"%f",&measurements);
        median += fscanf(input,"%f",&measurements);
        median = median/2;
    }
    else
    {
        fseek(input,2/*(int)((count/2)+1)*/, SEEK_SET);
        fscanf(input,"%f",&measurements);
        median += measurements;
    }
       

    printf("Mean = %.3f\nVariance = %.3f\nStandard Deviation = %.3f\nCoefficient of Variation = %.3f\nMedian = %.3f\n",mean,variance,standard_deviation,standard_deviation/mean,median);
    fclose(input);

}