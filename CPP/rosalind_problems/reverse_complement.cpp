#include <iostream>
#include <string>

using namespace std;

/*
In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.

The reverse complement of a DNA string s
 is the string sc
 formed by reversing the symbols of s
, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").

Given: A DNA string s
 of length at most 1000 bp.

Return: The reverse complement sc
 of s
.

Sample Dataset
AAAACCCGGT
Sample Output
ACCGGGTTTT
*/
void reverse_comp(string seq){
    string reverse_complement = seq;
    int seq_length = reverse_complement.length();
    char current_nuc = ' ';
    int j = 0;

    for(int i = seq_length-1; i >= 0; i--){
        current_nuc = seq[i];
        switch(current_nuc){
            case 'A':
                current_nuc = 'T';
                break;
            case 'T':
                current_nuc = 'A';
                break;
            case 'C':
                current_nuc = 'G';
                break;
            case 'G':
                current_nuc = 'C';
                break;
        }

        reverse_complement[j] = current_nuc;
        j++;
    }

    cout << reverse_complement << endl;
}

int main(){
    reverse_comp("GCTGTTTTCTGGGTAGACGTGTGTCGGTTCGTATCGTTATCTCGTGATTCTCCCGAACGGAGGGTACCGTTAGGCACTGAAGAGTAGGACATACAGGCGGGGACGCCCACCCGCCGGCTGGCCCGCTTAGTGGTTTCCCGCTGTACAGGGTACGCGTGATTGGTCTTCCGCGCTCACTTGGGATATCCCGGAGAACTCTGAGCGCGCCTATACAGATGATAATGAACACGTTTTAACGAGATGTTCATTCCGCATATAAATTCCATATTCAGCTAGATGTCACCGTTTATGGCTGGCTATACTTAGGACTGGCCCACTGGGCCCAGAGGAAAAGCGACTGGGCAGCAGTTGGCACACGGTATAGACGTGCTACGTGTCGCACTAGCCTCGATCCTGTCCAAATAAATTCAGCATTTGACCGTCGGACCACTAGGACTATTTTAAATGTCTAGTTCGATACACGTCCATGGCCGGTGAATCTTCCTTCGTATTATACGTGTGTGCGCCGCGCCATCCGGGTCTAACTAGCTGGGTGGGCGTAATTTCTCTTAATAGTTGTCCTGCATGTGTGGTGCTACCTGAGACCGCCGGTGCCACCCGGAACCTCACGACTTAACGGTATATTCCTACTTTGATCCGCTTTAATAGGCTACTGCCAAAAGAAGGCGATAAGACGTGAATAGTGTGGTGGGCACCTCCAGGGCACAGGATTTCCTCTTCACAGTTTACTGCAATTGGGGGGACATATGGGCGCATGGAGGTCCCGGGTCCGACTCAAGTTGTTTTCCGCACACACGTACTCCGGCTGTAAGGTTATACACTGATAGGCAGGGTGGGGTCGGGTACACATTTTTGAGACGGGGAATCAGACTGAGTACCCGTTTCTCTCTGCTCTGTTATGCCAAGCAGTCGAAAATGGATAATGGTTTGTTGGCGACATGCCCTAGCGCCGCTACTCTTGATTATTTCCAAAGGAGGAAGCCTAGAAAGA");
    return 0;
}