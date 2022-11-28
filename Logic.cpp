#include<iostream>
using namespace std;

    bool conjunctionIntroduction(string proof,string premises[],string proofLines[]){
        int index = proof.find('^');
        string leftPart;
        string rightPart;
        if(index<proof.length()){
            // means this is and introduction rule
            // for finding the left part
            for(int i=0;i<index;i++){
                leftPart += proof[i];
            }
            int index2 = proof.find('i');
            for(int i=index+1;i<index2-2;i++){
                rightPart += proof[i];
            }
            // now we need to find the index where line numbers are present
            int line1 = proof[index2+2];
            int line2 = proof[index2+4];
            int line3 = int(line1)-48;
            int line4 = int(line2)-48;
            if( (premises[line3-1] == leftPart) && (premises[line4-1] == rightPart) ){
                return true;
            } 
        }
        return false;
    }

int main(void){
    int n;
    cout<<"Enter the number of lines in proof rule: ";
    cin>>n;
    cout<<"Enter the "<<n<<" lines of proof"<<endl;

    // taking input from the user
    string proofLines[n];
    for(int i=0;i<n;i++){
        // cin >> ws is used for taking in account the white spaces in input stream.
        getline(cin >> ws,proofLines[i]);
    }

    // now we will store all the premises in the array of strings.
    string premises[n]; // making of max n size
    int noOfPremises;
    for(int i=0;i<n;i++){
        int index = proofLines[i].find('P');
        if(index < proofLines[i].length()){
            noOfPremises++;
            // so this statement is a premise
            for(int j=0;j<index-1;j++){
                premises[i] += proofLines[i][j];
            }
            }
        }
    
    // // for printing the premises
    // for(int i=0;i<noOfPremises;i++){
    //     cout<<premises[i]<<endl;
    // }

    // function for checking and introduction
    cout<<conjunctionIntroduction(proofLines[2],premises,proofLines);

    return 0;
}

