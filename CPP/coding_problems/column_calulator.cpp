/*
Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example, given 1, return "A". Given 27, return "AA".
*/
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int column_num = 87; //initialize the number
    string column_id = "";
    std::map<int,int> map;
    int character_num = 65;


    for(int i = 1; i < 27;i++){
        map[i] = character_num;
        character_num++;
        //cout << i << " " << map[i] << endl;
    }
    

    while(column_num > 0){
        if(column_num >= 27){
            column_id = column_id + "A";
            column_num -= 26;
        }

        
        else {
            column_id = column_id + char(map[column_num]);
            column_num = 0; 
        }
    }

    cout << column_id << endl;
    return 0;
}