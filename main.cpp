// Lab2
// Name: Shu Sian Lyu
// A simplest C++ program that will demonstrate
// iteration vs recursion.

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int SORT_MAX_SIZE = 16;    // To hold a constant maximum validate input

/* This recursive function checks if the element in the array is prime.
 Pre: n    // To hold the element
      i    // To hold the divisor
 Post:
 Return: true or false
 */
bool isPrime(int n, int i = 2){
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    if(n % i == 0)
        return false;
    if(i * i > n)
        return true;
    return isPrime(n, i + 1);
}

/* Helper function: This iterative function tests whether
 every element of the array is a Prime number.
 Pre: *arr   // To hold an integer array
      n      // To hold the size of the array
 Post:
 Return: true or false
 */
bool IsArrayPrimeIter(int *arr, int n){
    cout << "Entering <IsArrayPrimeIter>\n";
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            // To check whether each element of the array is equal to 0
            // If yes then terminate the function and return false.
            cout << "Leaving <IsArrayPrimeIter>\n";
            return false;
        }
        for (int j = 2; j * j <= arr[i];j++){
            // the j hold the divisor
            if(arr[i] % j == 0){   // To check whether the element of the array is Prime
                cout << "Leaving <IsArrayPrimeIter>\n";
                return false;
            }
        }
    }
    cout << "Leaving <IsArrayPrimeIter>\n";
    return true;
}

/* Helper function: This recursive function tests whether
 every element of the array is a Prime number.
 Pre: *arr   // To hold an integer array
      n      // To hold the size of the array
 Post:
 Return: true or false
*/
bool IsArrayPrimeRecur(int *arr, int n){
    cout << "Entering <IsArrayPrimeRecur>\n";
    if(n == 0){
        cout << "Leaving <IsArrayPrimeRecur>\n";
        return true;
    }
    if(isPrime(arr[n - 1])){
        bool returnValue = IsArrayPrimeIter(arr, n-1);
        cout << "Leaving <IsArrayPrimeRecur>\n";
        //return IsArrayPrimeRecur(arr, n - 1);
        return returnValue;
    }
    return false;
}

int main(){
    // Asking the user for the number of elements
    cout << "Enter the number of elements of the array(not to exceed maximum = 16):\n";
    int n;    // To hold the size of the array
    cin >> n;

    if(n > SORT_MAX_SIZE){
        // If the input n exceeded max = 16 then terminate the program
        cout << "INVALID INPUT!! ABORTING\n";
        EXIT_FAILURE;
    }
    
    // Allocating the memory
    int *arr = new int[n];
    
    // Prompt the user to enter the elements to an array
    cout<<"Enter the array elements[input range : (1 to 99, both inclusive)]: \n";
    for (int i = 0; i < n; ++i) {
        // Get the input into the array
        cin >> arr[i];
        if(arr[i] > 99 || arr[i] < 1){
            // If the element is exceeded 99 or less than 1 then terminate the program
            cout<<"INVALID INPUT!! ABORTING...";
            EXIT_FAILURE;
        }
    }
    cout << endl;
    //Make a call to the prime iterative function
    if(IsArrayPrimeIter(arr,n))
        cout<<"Prime Array using iteration\n";
    else
        cout<<"Not a Prime Array using iteration\n";
    
    cout << "\n";
    
    //Make a call to the prime recursive function
    if(IsArrayPrimeRecur(arr,n))
        cout<<"Prime Array using recursion\n\n";
    else
        cout<<"Not a Prime Array using recursion\n\n";

    // freeing the memory
    delete[] arr;

    return 0;
}

