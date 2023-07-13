#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


void sum(int *arr_list) {
    int i, result=0, arr_length;
    arr_length = sizeof(*arr_list);

    //print out the value of the array when all the elements are added
    for(i = 0; i < arr_length; i++){

        //this syntax will add everything together one element at a time
        result += arr_list[i];
        
    }

    cout << "array sum total: " << result << endl;
    
}

// use vector notation here
void diag(const std::vector<std::vector<int>> &arr){
    int result=0;
    

    for(int i = 0; i < arr.at(0).size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(i==j){
                result += arr.at(i).at(j);
            }
            cout << "matrix diag sum total: " << result << endl;
        }
    }


}


int main() {
    int arr [5] = { 1, 2, 3, 4, 5}; //initializes an array 
    int arr_var;

    // arrays are zero indexed 
    // looks like both calls work
    arr_var = arr[2] ;
    cout << "Using a variable: "<< arr_var << endl;
    cout << "Using the array call directly: " << arr[2] << endl;

    // Let's check how to loop through arrays, 
    // lets look at the function 'sum'
    sum(arr);

    // arrays can also be multidimensional
    // THIS WAS THE HARDEST THING TO LEARN, 
    // granted I did all of this before learning how to properly use pointers


    std::vector<std::vector<int>> mat(3, std::vector<int>(3));
    mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    //size_t arr_row = sizeof(mat) / sizeof(*mat);
    //size_t arr_col = sizeof(*mat) / sizeof(*mat[0]);

    // let's practice this again by using the multidimensional array
    // as input
    diag(mat); 

    return 0; 
}

