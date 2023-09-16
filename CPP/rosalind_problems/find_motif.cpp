#include <string>
#include <iostream>

using namespace std;

void motif_finder(string seq, string motif){
    cout << motif << endl;
    string current_subseq = "";
    string motif_positions = "";

    for(int i = 0; i < seq.length() - motif.length() + 1; i++){
        current_subseq = seq.substr(i,motif.length());
        cout << "current subsequence: " << current_subseq << endl;
        if(current_subseq == motif){
            cout << "success" << endl;
            motif_positions = motif_positions + to_string(i+1) + " ";
        }

    }

    cout << motif_positions << endl;
    
}

int main(){
    motif_finder("CATTGATTATTGATTCAGGACTGGATTGATTCATTGATTAAAGATTGATTATTGATTCTAACATTGATTGAGATTGATTATTGATTAATTGATTTTTCTTAAGATTATTGATTGATTGATTCACACACAATTGATTGATTGATTATTGATTGAACTGCTATTGATTGGTATTGATTCAGTTGAATTGATTAAATTGATTCTAGCCATTGATTAGAATTGATTCAATTGATTCATTGATTGATTGATTATTGATTTATTGATTTACGCACAATTGATTTCTATTGATTAATTGATTCCCCCGATTGATTCATCATTGATTTGGCATTGATTATTGATTGTATTGATTTGGGCTATTGATTAGGATTGATTGAGATTGATTTGGACATTGATTATCATTGATTCATTGATTATTGATTATTGATTACCCTGTCCGGATTGATTAATTGATTATTGATTATTGATTTCGCCTACAACTTATTGATTATTGATTATAATGAATTGATTGTTTATTGATTTATTGATTATTGATTCGTTTCAGGCTGCGGAAAAGACAATTGATTGCTAGTGTGATTGATTATTGATTATATTGATTGATTGATTAACATTGATTTCAATTGATTCAGATTGATTGATTGATTCTATTGATTTATTGATTGATTGATTAATTGATTTCATTGATTAATTGATTTCATTGATTCTAGATTGATTCGATTGATTAATTGATTCTCGGATTGATTATTGATTTTTACTGCTCGGGGACGTCGCATTGATTATTGATTTGATTGATTATTGATTACATTGATTGTAAATTGATTGATAAAGATTGATTCTCATTGATTGATTGATTCATTGATTATATTGATTTAGAACGAAACTAATTGATTATTGATTGTGATTGATTATTGATT","ATTGATTAT");
    return 0;
}