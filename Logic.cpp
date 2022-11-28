#include<iostream>
using namespace std;

int main(void){
    int n;
    cout<<"Enter the number of lines in proof rule: ";
    cin>>n;
    cout<<"Enter the "<<n<<" lines of proof"<<endl;

    // taking input from the user
    string proofLines[n];
    for(int i=0;i<n;i++){
        getline(cin >> ws,proofLines[i]);
    }
    
    return 0;
}

