#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/* Counting DNA Nucleotides

A string is simply an ordered collection of symbols selected from some alphabet and formed into a word; the length of a string is the number of symbols that it contains.

An example of a length 21 DNA string (whose alphabet contains the symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."

Given: A DNA string s
 of length at most 1000 nt.

Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in s
.

Sample Dataset
AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC
Sample Output
20 12 17 21

*/
void nucleotide_count(string seq) {
    //ADD COMMENTS STARTING HERE NEIRA
    cout << "Starting DNA sequence: " << seq << endl;
    char current_nucleotide = ' ';

    int numberA, numberT, numberC, numberG;
    numberA = numberT = numberC = numberG = 0;

    string output = " ";

    for(int i = 0; i < seq.length(); i++){
        current_nucleotide = seq[i];
        switch(current_nucleotide){
            case 'A':
                numberA++;
                break;
            case 'T':
                numberT++;
                break;
            case 'C':
                numberC++;
                break;
            case 'G':
                numberG++;
                break;
        }

    }

    cout <<  to_string(numberA) + " " + to_string(numberC) + " " + to_string(numberG) + " " + to_string(numberT) << endl;

}

int main() {
    string examp = "ATGCTTCAGAAAGGTCTTACG";
    nucleotide_count(examp);
    return 0;
}



