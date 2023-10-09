#include <iostream>
#include <vector>
#include<algorithm> // for copy.
#include<iterator> // for back_inserter
using namespace std;


void permutations(int n){
   std::vector<int> v(n);
   
    //test to see if it worked
    for(int i = 0;i< v.size();i++){
        v[i] = (i+1);
        cout << v[i] << " ";
    }
        cout << endl<< endl;
    
    vector<int> v_clone;
    copy(v.begin(), v.end(), back_inserter(v_clone));
    int permute_num = 0;

    //steady_index = 0; //this is where the number stays the same, while the others loop through
    //pivot_index = 1; //this is the index where things get swapped, to be iterated through
    //permutation_num = 1;
    int temp = 0;
    for(int i = 0;i < v.size();i++){ //this is the loop that changes the steady index
        //cout << "locking steady point" << endl;
        temp = v_clone[0];
        v_clone[0] = v_clone[i];
        v_clone[i] = temp;
        for (int x : v_clone)
            cout<<x<<" ";
            permute_num++;
        cout << endl;
        
        for(int j = 0;j < v.size();j++){
            if(j == 0){
                //cout << "pivot can't switch with the steady point" << endl;
                continue;
            }

            else{
                
                for(int k = 0; k < v.size();k++){
                    if(k == 0){
                        //cout << "the switcher cant swap with the steady point" << endl;
                        continue;
                    }

                    if(k == j){
                        //cout << "the switcher cant swap with the pivot point" << endl;
                        continue;
                    }

                    if(k < j){
                        //cout << "already have made this switch" << endl;
                        continue;
                    }



                    else{ //swap
                        //cout << "switching the numbers" << endl;
                        temp = v_clone[j];
                        v_clone[j] = v_clone[k];
                        v_clone[k] = temp;
                        
                        v_clone = v;                

                    }
                }

                

            }
        }

        v_clone = v;

    }

    
    cout << permute_num << endl;

}

int main(){
    permutations(6);
    return 0;
}