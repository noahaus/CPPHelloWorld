#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

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

// creating a vector of stucts to hold fastq data
struct seq {
    string id;
    string sequence;
};


void printStruct(const seq& s) {
    std::cout << "ID: " << s.id << std::endl;
    std::cout << "Sequence: " << s.sequence << std::endl;
}

bool shared(string sub, vector<seq> strings){
    bool isShared = true;
    int current = 0;
    for(seq record: strings){
        if(current == 0){
            current++;
            continue;
        }

        //return the value as boolean
        isShared = record.sequence.find(sub) != std::string::npos;
        if(isShared == false){
            return false;
        }
    }

    return true;
}



int main(int argc, char* argv[]){

    // STEP 1: LOAD IN FASTA
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; 
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

    //initialize a struct to take in the data, then load in the vector
    struct seq record;
    vector<seq> fasta = {};
    int line_counter = 0;
    int file_length = 0;

    //get size of the file
    while(getline(inputFile,line)){
        file_length++;
    }

    //test to see if loop worked
    //cout << file_length << endl;
    inputFile.close();
    inputFile.open(argv[1]);

    // read the line and either count a new record, or add the substring to the map, or update the number of times we see the substring
     while (getline(inputFile, line)) {
        line_counter++;
        if(line[0] == '>'){
            if(line_counter != 1){
                fasta.insert(fasta.end(),record);
            }
            record = {"",""};
            record.id = line;
            continue;
        }
        else {
            record.sequence.erase(std::remove(record.sequence.begin(), record.sequence.end(), '\r'), record.sequence.cend());
            record.sequence += line;
            //cout << record.id << endl << record.sequence << endl << endl;
            if(line_counter == file_length){
                fasta.insert(fasta.end(),record);
            }
        }
    }


// can we find the common substring in a group of strings?
string first_seq = fasta[0].sequence;
string lcs = "";
bool isShared = false;

//inital values for the first substring
int first_index = 0;
int substr_len = 2;

//max values as we go through the string
int max_index = first_index;
int max_len = substr_len;

//loop through the first sequence until we find the longest substring
while(first_index + substr_len < first_seq.length()){
    //intialize and then check if the substring is in the other seqs
    lcs = first_seq.substr(first_index,substr_len);
    //cout << first_index << " " << substr_len << endl;
    //cout << lcs << endl;
    isShared = shared(lcs, fasta);


    if(isShared){
        if(substr_len > max_len){
            max_index = first_index;
            max_len = substr_len;
        }

        substr_len++;
    }

    else {
        first_index++;
        substr_len = 2;
    }

}

cout << first_seq.substr(max_index,max_len) << endl;

}