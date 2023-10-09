/*
Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
*/

#include <iostream>
#include <vector>
#include <algorithm> // for copy.
#include <iterator> // for back_inserter
#include <string>
using namespace std;

void permute(vector<string> original, vector<string> append = {} ){
    vector<string> append_copy;
    copy(append.begin(), append.end(), back_inserter(append_copy));

    // simple cases
    if(original.size() == 1){
        for (string x : original)
            cout<<x<<" ";
        cout<<endl;

    }

    else if(original.size() == 2){
        string temp_str = "";
        temp_str = original[0];
        original[0] = original[1];
        original[1] = temp_str;

        for (string x : original)
            cout<<x<<" ";
        cout<<endl;

    }

    // elevated base case
    else if(original.size() == 3){
        vector<string> original_copy;
        copy(original.begin(), original.end(), back_inserter(original_copy));

        for(int i = 0; i < original.size();i++){
            if(i == 0){
                for (string x : append)
                    cout<<x<<" ";

                for (string x : original)
                    cout<<x<<" ";
                cout<<endl;

                string temp_str = "";
                temp_str = original[1];
                original[1] = original[2];
                original[2] = temp_str;

                for (string x : append)
                    cout<<x<<" ";

                for (string x : original)
                    cout<<x<<" ";
                cout<<endl;
            }

            else{

                string temp_str = "";
                temp_str = original[0];
                original[0] = original[i];
                original[i] = temp_str;

                for (string x : append)
                    cout<<x<<" ";

                for (string x : original)
                    cout<<x<<" ";
                cout<<endl;

                temp_str = "";
                temp_str = original[1];
                original[1] = original[2];
                original[2] = temp_str;

                for (string x : append)
                    cout<<x<<" ";

                for (string x : original)
                    cout<<x<<" ";
                cout<<endl;


            }

            original = original_copy;
        }
        
    }


    // where the recursion happens
    else if(original.size() > 3){

        for(int i = 0; i < original.size();i++){
            if(i == 0){
                vector<string> left_side = std::vector<string>(original.begin(), original.begin() + 1);
                //first.insert(first.end(), second.begin(), second.end());
                append.insert(append.end(),left_side.begin(), left_side.end());
                vector<string> right_side = std::vector<string>(original.begin() + 1, original.end());
                permute(right_side,append);
                append = append_copy;
                }
            
            else{
                string temp_str = "";
                temp_str = original[0];
                original[0] = original[i];
                original[i] = temp_str;

                vector<string> left_side = std::vector<string>(original.begin(), original.begin() + 1);
                append.insert(append.end(),left_side.begin(), left_side.end());
                vector<string> right_side = std::vector<string>(original.begin() + 1, original.end());
                permute(right_side,append);
                append = append_copy;
            }

             

        }
    }
}

int main(){

    string s = "dogcatcatcodecatdog";
    vector<string> words = {"1", "2", "3", "4", "5", "6", "7"};
    permute(words);

    return 0;
}