#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*
The Second Nucleic Acid
Problem
An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.

Given a DNA string t
 corresponding to a coding strand, its transcribed RNA string u
 is formed by replacing all occurrences of 'T' in t
 with 'U' in u
.

Given: A DNA string t
 having length at most 1000 nt.

Return: The transcribed RNA string of t
.

Sample Dataset
GATGGAACTTGACTACGTAAATT
Sample Output
GAUGGAACUUGACUACGUAAAUU
*/

void transcribe(string seq){
    string transcribed_seq = seq;
    char current_nuc = ' ';
    char transcribed_nuc = ' ';
    
    for(int i = 0; i < transcribed_seq.length();i++){
        current_nuc = transcribed_seq[i];
        if(current_nuc == 'T'){
            transcribed_seq[i] = 'U';
        } 
        else{
            continue;
        }
    }

    cout << transcribed_seq << endl;




}

int main(){
    transcribe("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");
    return 0;

}