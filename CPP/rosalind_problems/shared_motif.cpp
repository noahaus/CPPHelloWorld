#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

/*
Starting here:

>Rosalind_1
GATTACA
>Rosalind_2
TAGACCA
>Rosalind_3
ATACA

I think we can assume that the least we can start is with 2-mers
Step 1 - calculate all 2-mers, keep locations of the 2-mers that are shared between the sequences 
Step 2 - extend the nucleotides by 1, 
*/

//https://favtutor.com/blogs/cpp-dictionary - For Working with Maps in C++



int main(int argc, char* argv[]){
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; //why should this be return 1 tho? The 
    }

    // the variable type for a file
    std::ifstream inputFile;
    std::string line;

    // standard open a file
    inputFile.open(argv[1]);


    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    
    map<string, int> k_mer;

    int current_record = 0;
    int kmer_len = 2;
    bool no_improvement = true;
    int motif_num = -1;
    string candidate_lcs = "";
    string actual_lcs = "";

    // we keep updating the kmer map until we get no improvement in length
    while (no_improvement){

    // read the line and either count a new record, or add the substring to the map, or update the number of times we see the substring
     while (getline(inputFile, line)) {
        if(line[0] == '>'){
            cout << "new record" << endl;
            current_record++;
            continue;
        }
        else {
            for(int i = 0; i < line.length()-2;i++){  
                //does the 2-mer exist?
                if(k_mer[line.substr(i,kmer_len)] == 0){
                    cout << "adding to the dictionary" << endl;
                    k_mer[line.substr(i,kmer_len)] = 1;
                    continue;
                }
                // 2-mer exist, but has it been recorded already?
                else {
                    if(k_mer[line.substr(i,kmer_len)] == current_record){
                        continue;
                    }

                    else{
                        cout << "adding to two_mer" << endl;
                        k_mer[line.substr(i,kmer_len)] = k_mer[line.substr(i,kmer_len)] + 1;
                    }
                }              
                
            }
        }
    }

    //after doing the logic above, we need to go through and find if there exists a substring in each record.
    //we will only know that if we go through every record and record the number of times the substring occurs
    //at the end, we can assess if there was a substring that was in every sequence or if the last lcs was the best we could do
    for (auto element :k_mer){

//element.first represents key
    cout<<element.first<<" appears ";

//element.second represents value
    cout<<element.second<< " times " << endl;

    // first we need to see in this set what the most common lcs is? 
    // record the number and the current lcs
    if(element.second > motif_num){
        motif_num = element.second;
        candidate_lcs = element.first;
    }

    // second we need to see if the motif_num at the end of the analysis is the same as the number of sequences.
    // if it is, we need to update the lcs
    // if not, our current lcs should not be updated, and we break out of the loop
    
}

if(motif_num == current_record){
        actual_lcs = candidate_lcs;
    }
    else {
        no_improvement = false;
    }

    //lets update the program as we go
    //the kmer length needs to increment
    //current_record should reset
    //the current map needs to be emptied to allow the next group
    kmer_len++;
    current_record = 0;
    k_mer.clear();
    motif_num = 0;

    }

    //print the actual lcs
    // This doesn't work - need to go back to the drawing board
    cout << actual_lcs << endl;
    return 0;

}

