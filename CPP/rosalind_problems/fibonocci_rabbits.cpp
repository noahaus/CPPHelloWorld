#include <string>
#include <iostream>
#include <vector>

using namespace std;


int fibo(int months, int offspring){

    int results[40] = {};

    int i = 0;
    int sum = 0;

    while(i <= months){
    if(i == 0){
        results[i] = i;
    }

    else if(i > 0 && i < 3){
        results[i] = 1;
    }

    else if(i == 3){
        results[i] = results[i-1] + offspring;
    }

    else{
        results[i] = results[i-1] + results[i-2] + offspring;
    }

    i++;
}

    for(auto num: results){
            cout << num << ", ";
            sum+=num;
        }
    
    return sum;
}

int main(){
    int result = fibo(36,3) - 1;
    


    cout << result << endl;
}