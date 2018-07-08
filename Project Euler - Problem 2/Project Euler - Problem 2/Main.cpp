//***************************************************************************************************************************************************
//
// File Name: Main.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     07/08/2018     Completed problem 2 of Project Euler with expanded capabilities to allow other maximum values to test.
//
//***************************************************************************************************************************************************

#include <iostream>
#include <sstream>
#include <vector>

//***************************************************************************************************************************************************
//
// Method Name: GetUserInputInteger
//
// Description:
//  Returns an integer value a use inputs into the command line. If the value is not an integer type, then an error is produced asking for a valid
//  integer to be entered. Once a valid integer is input by the user, the value is returned.
//
//***************************************************************************************************************************************************
int GetUserInputInteger()
{
   std::string integerString = "";
   int returnInteger = 0;
   bool isValidInteger = false;

   while (isValidInteger == false)
   {
		std::getline(std::cin, integerString);
		std::stringstream stringToIntgerConversion(integerString);

		// Checks for complete conversion to integer and checks for minimum value
		if(stringToIntgerConversion >> returnInteger &&
         !(stringToIntgerConversion >> integerString))
      {
         isValidInteger = true;
      }
      else
      {
         std::cerr << "Invalid type, please enter an integer value: ";
      }
   }

   return returnInteger;
}

//***************************************************************************************************************************************************
//
// Method Name: RetrieveFibonacciNumbers
//
// Description:
//  Add each Fibonacci value into a vector list until the maximum Fibonacci value is met.
//
//***************************************************************************************************************************************************
void RetrieveFibonacciNumbers(int maxValue, std::vector<int>& fibonacciValues)
{
   int firstValue = 1;
   int secondValue = 2;
   int nextValue = 0;

   // Add starting values to the list.
   fibonacciValues.push_back(firstValue);
   fibonacciValues.push_back(secondValue);

   // Add the nest FSibonacci numbers into the list until the max value is reached.
   while (nextValue < maxValue)
   {
      nextValue = firstValue + secondValue;

      firstValue = secondValue;
      secondValue = nextValue;

      if (nextValue < maxValue)
      {
         fibonacciValues.push_back(nextValue);
      }
   }
}

//***************************************************************************************************************************************************
//
// Method Name: GetSumOfEvenFibonacciValues
//
// Description:
//  Iterate through the Fibonacci value vector list and add all even values together. The sum of these values is returned.
//
//***************************************************************************************************************************************************
int GetSumOfEvenFibonacciValues(std::vector<int>& fibonacciValues)
{
   int sumOfEvenValuesInFibonacci = 0;

   for (auto iterator = fibonacciValues.begin(); iterator != fibonacciValues.end(); iterator++)
   {
      if (*iterator % 2 == 0)
      {
         sumOfEvenValuesInFibonacci += *iterator;
      }
   }

   return sumOfEvenValuesInFibonacci;
}

//***************************************************************************************************************************************************
//
// Method Name: main
//
// Description:
//  The entrance of the program for this project. This method handles the prompt of the problem and calls methods to retrieve the user input and
//  computational outputs.
//
//***************************************************************************************************************************************************
int main()
{
   int maxFibonacciNumber = 0;
   int sumOfEvenFibonacciNumbers = 0;
   std::vector<int> fibonacciValues;

   std::cout << "Enter an integer value for the maximum Fibonacci number: ";
   maxFibonacciNumber = GetUserInputInteger();

   RetrieveFibonacciNumbers(maxFibonacciNumber, fibonacciValues);
   sumOfEvenFibonacciNumbers = GetSumOfEvenFibonacciValues(fibonacciValues);

   std::cout << "The sum of even values Fibonacci numbers below " << maxFibonacciNumber << " is: " << sumOfEvenFibonacciNumbers << "\n";

   system("pause");
}