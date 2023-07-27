#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
The GC-content of a DNA string is given by the percentage of symbols in the string that are 'C' or 'G'. For example, the GC-content of "AGCTATAG" is 37.5%. Note that the reverse complement of any DNA string has the same GC-content.

DNA strings must be labeled when they are consolidated into a database. A commonly used method of string labeling is called FASTA format. In this format, the string is introduced by a line that begins with '>', followed by some labeling information. Subsequent lines contain the string itself; the first line to begin with '>' indicates the label of the next string.

In Rosalind's implementation, a string in FASTA format will be labeled by the ID "Rosalind_xxxx", where "xxxx" denotes a four-digit code between 0000 and 9999.

Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).

Return: The ID of the string having the highest GC-content, followed by the GC-content of that string. Rosalind allows for a default error of 0.001 in all decimal answers unless otherwise stated; please see the note on absolute error below.

Sample Dataset
>Rosalind_6404
CCTGCGGAAGATCGGCACTAGAATAGCCAGAACCGTTTCTCTGAGGCTTCCGGCCTTCCC
TCCCACTAATAATTCTGAGG
>Rosalind_5959
CCATCGGTAGCGCATCCTTAGTCCAATTAAGTCCCTATCCAGGCGCTCCGCCGAAGGTCT
ATATCCATTTGTCAGCAGACACGC
>Rosalind_0808
CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGAC
TGGGAACCTGCGGGCAGTAGGTGGAAT
Sample Output
Rosalind_0808
60.919540
*/

/*
NOTES:

I think this will require a little bit more than basic programming, 
1. read in a FASTA file
2. pair the ids with the sequence information
3. as we read in the ids/sequences, calculate the GC content, keeping track of the largest percentage. 
4. report the output
*/

struct fasta { 
 string id = " "; 
 string seq = "";
 float gc_content = 0.0; 
} record;

float gc_content(string seq){
    int seq_length = seq.length();
    int gc_count = 0;
    float gc_content;

    for(int i = 0; i < seq_length; i++ ){
        if(seq[i] == 'G' || seq[i] == 'C'){
            gc_count++;
        }
        else{
            continue;
        }
    }
    gc_content = (float) gc_count/seq_length;
    
    return gc_content;
} 

//from chatGPT
// we can use this read in from the command line! 
int main(int argc, char* argv[]){
    // read in the FASTA file 
    // From chatGPT:

    // if we do not have two arguments (the program name and the file to add), then return out an error.
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
    int line_num = 0;
    float highest_gc = 0.0;
    string highest_id = "";

    // looping through that file
    while (getline(inputFile, line)) {
        if(line[0] == '>' & line_num == 0){
            record.id = line;
        }
        if(line[0] != '>'){
            record.seq = record.seq + line;
            }
        
        // this is where the sweaty logic will take place
        if(line[0] == '>' & line_num != 0){
            //calculate gc content
            record.gc_content = gc_content(record.seq);
            cout << record.id << endl;
            cout << record.seq << endl;
            cout << record.gc_content << endl;

            if(record.gc_content > highest_gc){
                highest_gc = record.gc_content;
                highest_id = record.id;
            }

            record.id = line;
            record.seq = "";
        }
        line_num++;
    }

    record.gc_content = gc_content(record.seq);
    cout << record.id << endl;
    cout << record.seq << endl;
    cout << record.gc_content << endl;

    if(record.gc_content > highest_gc){
                highest_gc = record.gc_content;
                highest_id = record.id;
            }

    // add logic to find the best gc content.

    inputFile.close();

    cout << highest_id << endl;
    cout << std::fixed << std::setprecision(3) << highest_gc*100.00 << endl;

    return 0;
}