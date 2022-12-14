/*
<------------------------------------------------------------------------------------------------------------>
Team Members:
1 Pavas Garg 2021A7PS2587H
2 Saksham Bajaj 2021A7PS1315H
3 M Sai Karthik 2021A7PS0097H
4 Kolasani Amit Vishnu 2021A7PS0151H
<------------------------------------------------------------------------------------------------------------>
*/

/*
<------------------------------------------------------------------------------------------------------------>
Example of Valid Proof

Enter the number of lines in proof rule: 20

((a>b)^(d+f))/P
~(a^(s>r))/P
((a>b)+d)/P
(a>b)/^e1/1
(((a>b)+d)+~w)/+i1/3
((a>b)>~(s+f))/P
~(s+f)/>e/6/4
(~(s+f)+~(a>f))/+i1/7
(d+f)/^e2/1
((d+f)^~(s+f))/^i/9/7
~b/P
~a/MT/4/11
((a^f)>(g+j))/P
~(g+j)/P
~(a^f)/MT/13/14
(((d+f)>(e^g))+(d+f))/+i2/9
((a>(b^c))^((h+f)>(d+~z)))/P
(a>(b^c))/^e1/17
((h+f)>(d+~z))/^e2/17
(~b^((h+f)>(d+~z)))/^i/11/19

<------------------------------------------------------------------------------------------------------------>
*/

#include <iostream>
using namespace std;

/*
<------------------------------------------------------------------------------------------------------------>
Linked List Implementation
<------------------------------------------------------------------------------------------------------------>
*/

/// This class is used for creating nodes of the Linked List.
/// @see LinkedList
///
/// > Each node has a **char** data and a **next** pointer which points to the next node of the given
/// > LinkedList . 
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///  Node* next;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// ###Node()
/// > This constructor is the default constructor which sets data to '0' and next points to **NULL**.
/// 
/// ###Node(char data)
/// > This constructor sets the data to the char recieved as function parameter and next points to **NULL**.

class Node{
    public:
        char data;
        Node* next;
        Node(){
            data = '0';
            next = NULL;
        }
        Node(char data){
            this->data = data;
            this->next = NULL;
        }

};

/// This class is used to create a *Linked List* which stores data of **char** datatype.
/// ###LinkedList()
/// > This constructor is used to set the head pointer to **NULL**.
///
/// ###insertNode(char data)
/// > This function accepts **data** as function parameter and links this **newNode** to the last 
/// > of linked list by iterating over the list until it reaches the end.
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Node* newNode = new Node(data);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// > Time Complexity of this function is O(n).
/// > 
/// > Space Complexity of this function is O(1).
///
/// ###deleteLastNode()
/// > This function is used to delete the last node of the given linked list by making the next
/// > pointer of second last node to **NULL** so the link between second last and last node breaks.
/// > - Time Complexity of this function is O(n).
///
/// ###printLL()
/// > This function is used to print the given linked list by iterating over the nodes until the next
/// > pointer of any node points to **NULL**.
/// > - Time Complexity of this function is O(n).
///
/// ###size()
/// > This function returns an integer which gives the number of nodes in the given linked list.
/// >
/// > - Time Complexity of this function is O(n).
///
/// ###lastNode()
/// > This functions return a **char** value which is the data of the last node in the linked list.
/// > - Time Complexity of this function is O(n).

class LinkedList{
    Node* head;
    public:
         LinkedList(){
             head = NULL;
         }
         // Insert Function
         void insertNode(char data){
             Node* newNode = new Node(data);
             if(head == NULL){
                 head = newNode;
                 return;
             }
             Node* temp = head;
             while(temp->next != NULL){
                 temp = temp->next;
             }
             temp->next = newNode;
         }
         // Delete Function 
         void deleteLastNode(){
             Node* temp = head;
             if(head == NULL){
                 return;
             }
             if(temp->next == NULL){
                 head = NULL;
                 return;
             }
             while(temp->next != NULL && temp->next->next != NULL){
                 temp = temp->next;
             }
             temp->next = NULL;
             return;
         }
         // Print Function
         void printLL(){
             Node* temp = head;
             if(head == NULL){
                 cout<<"Empty Linked List";
                 return;
             }
             while(temp->next != NULL){
                 cout<<temp->data<<" ";
                 temp = temp->next;
             }
             cout<<temp->data<<endl;
             return;
         }
         //Size Function
         int size(){
             Node* temp = head;
             int sizeOfLL = 0;
             if(head == NULL){
                 return sizeOfLL;
             }
             while(temp != NULL){
                 sizeOfLL++;
                 temp = temp->next;
             }
             return sizeOfLL;
         }
         // LastNode function
         char lastNode(){
             Node* temp = head;
             if(head == NULL){
                 return '0';
             }
             while(temp->next != NULL){
                 temp = temp->next;
             }
             return temp->data;

         }
};
/*
<------------------------------------------------------------------------------------------------------------>
Stack implementation
<------------------------------------------------------------------------------------------------------------>
*/

/// > This class is for implementing the Stack data structure using a LinkedList.
///
/// ###push(data)
/// > This function takes a char data and pushes it to the stack internally which is the node of the
/// > linked list.
/// 
/// ###pop()
/// > This function is used to delete the top element of the stack internally which is deleting the last node
/// > of the linked list by calling deleteLastNode() function of the linked list.
///
/// ###size()
/// > This function return the size of the linked list by calling the size function of the linked list.
///
/// ###top()
/// > This function returns a char datatype which is the value of top element of the stack internally it
/// > calls the lastNode() function of the linked list.

class Stack{
    LinkedList ll;
    public:
    void push(char data){
        ll.insertNode(data);
        return;
    }
    void pop(){
        ll.deleteLastNode();
        return;
    }
    int size(){
        return ll.size();
    }
    char top(){
        return ll.lastNode();
    }

};

/*
<------------------------------------------------------------------------------------------------------------>
Conjunction Introduction
<------------------------------------------------------------------------------------------------------------>
*/

bool conjunctionIntroduction(string proof,string proofLines[])
{
    int indexOfSlashInProof = proof.find('/');
    int indexOfConjunction = indexOfSlashInProof + 2;

    // making strings for left part before the '^' and right part after '^'
    string leftPart;
    string rightPart;

    // making stack for storing the proof of conjunctionIntroduction
    Stack stack;
    if (indexOfConjunction < proof.length())
    {
        // means this is and introduction rule
        for(int i=1;i<indexOfConjunction-3;i++){
            // push the proof in reverse order in stack
            stack.push(proof[indexOfConjunction-2-i-1]);
        }

        /* now leftPart is before the ^ symbol, This has time complexity as O(n) only as we are iterating once over every element if k elements are inside ( and ) then we only iterate for remaining n-k elements in else so overall n only */

        int count = 0;
        int stackOriginalSize = stack.size();
        int noOfOpeningBrackets = 0;
        int flag = 0;

        while(stack.top() != '^' || noOfOpeningBrackets != 0){
            if(stack.top() == '(' || noOfOpeningBrackets != 0){
                while(stack.top() != ')'){
                    if(stack.top() == '('){
                        noOfOpeningBrackets++;
                    }
                    leftPart += stack.top();
                    count++;
                    stack.pop();
                }
                leftPart += stack.top();
                count++;
                stack.pop();
                noOfOpeningBrackets--;
            }
            else{
                leftPart += stack.top();
                count++;
                stack.pop();
            }
            if(count > stackOriginalSize){
                return false;
            }
        }

        // now poping out the ^ symbol
        stack.pop();

        // now for the right part pop out until stack is not empty
         while(stack.size() != 0){
            
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    rightPart += stack.top();
                    stack.pop();
                }
                rightPart += stack.top();
                stack.pop();
            }
            else{
                rightPart += stack.top();
                stack.pop();
            }
        }

        // now we need to find the index where line numbers are present
    
        /* as the line number can be two digit also so store them as strings initially then 
        convert to integer
        */

        char slash = proof[indexOfConjunction+1];
        int x = indexOfConjunction+2;
        string stringlineNumber1;
        string stringlineNumber2;

        while(proof[x] != slash){
            stringlineNumber1 += proof[x];
            x++;
        }
        x++;
        while(x<proof.length()){
            stringlineNumber2 += proof[x];
            x++;
        }

        // if double digit line number is present in the proof line
        int line1 = stoi(stringlineNumber1);
        int line2 = stoi(stringlineNumber2);

        // Now both left and right part should be present in premise
        int indexOfSlash1 = proofLines[line1-1].find('/');
        string leftPartOriginal;
        for(int i=0;i<indexOfSlash1;i++){
            leftPartOriginal += proofLines[line1-1][i];
        }

        int indexOfSlash2 = proofLines[line2-1].find('/');
        string rightPartOriginal;
        for(int i=0;i<indexOfSlash2;i++){
            rightPartOriginal += proofLines[line2-1][i];
        }

        if ((leftPartOriginal == leftPart) && (rightPartOriginal == rightPart))
        {
            return true;
        }
    }
    return false;
}

/*
<------------------------------------------------------------------------------------------------------------>
Disjunction Introduction
<------------------------------------------------------------------------------------------------------------>
*/

bool disjunctionIntroduction(string proof,string proofLines[])
{
    int indexOfSlashInProof = proof.find('/');
    int indexOfDisjunction = indexOfSlashInProof+2;

    // making strings for left part before the '+' and right part after '+'
    string leftPart;
    string rightPart;

    // making stack for storing the proof of disjunctionIntroduction
    Stack stack;
    if (indexOfDisjunction < proof.length())
    {
        // means this is or introduction rule
        for(int i=1;i<indexOfDisjunction-3;i++){
            // push the proof in reverse order in stack
            stack.push(proof[indexOfDisjunction-2-i-1]);
        }

        // now leftPart is before the + symbol

        int count = 0;
        int stackOriginalSize = stack.size();
        int noOfOpeningBrackets = 0;
        int flag = 0;

        while(stack.top() != '+' || noOfOpeningBrackets != 0){
            if(stack.top() == '(' || noOfOpeningBrackets != 0){
                while(stack.top() != ')'){
                    if(stack.top() == '('){
                        noOfOpeningBrackets++;
                    }
                    leftPart += stack.top();
                    count++;
                    stack.pop();
                }
                leftPart += stack.top();
                count++;
                stack.pop();
                noOfOpeningBrackets--;
            }
            else{
                leftPart += stack.top();
                count++;
                stack.pop();
            }
            if(count > stackOriginalSize){
                return false;
            }
        }

        // now poping out the + symbol
        stack.pop();

        // now for the right part pop out until stack is not empty
         while(stack.size() != 0){
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    rightPart += stack.top();
                    stack.pop();
                }
                rightPart += stack.top();
                stack.pop();
            }
            else{
                rightPart += stack.top();
                stack.pop();
            }
        }


        // checking wheter it is i1 or i2
        int typeOfDisjunctionIntroduction = proof[indexOfDisjunction+1];
        typeOfDisjunctionIntroduction = int(typeOfDisjunctionIntroduction)-48;

        // now we need to find the index where line numbers are present

        /* as the line number can be two digit also so store them as strings initially then 
        convert to integer */

        char slash = proof[indexOfDisjunction+2];
        int x = indexOfDisjunction+3;
        string stringlineNumber;

        while(x<proof.length()){
            stringlineNumber += proof[x];
            x++;
        }

        // if double digit line number is present in the proof line
        int line1 = stoi(stringlineNumber);

        string givenLine = proofLines[line1-1];
        int indexOfSlashInGivenLine = givenLine.find('/');
        string givenPart;

        for(int i=0;i<indexOfSlashInGivenLine;i++){
                givenPart += givenLine[i];
        } 

        // Now both left and right part should be present in premise
        if(typeOfDisjunctionIntroduction == 1){
            if(leftPart == givenPart){
                return true;
            }
            return false;
        }
        else if(typeOfDisjunctionIntroduction == 2){
            if(rightPart == givenPart){
                return true;
            }
            return false;
        }
    }
    return false;
}

/*
<------------------------------------------------------------------------------------------------------------>
Conjunction Elimination
<------------------------------------------------------------------------------------------------------------>
*/

bool conjunctionElimination(string proof,string proofLines[]){

    int indexOfSlashInProof = proof.find('/');

    // storing the result in string
    string result;

    int indexOfConjunctionSymbol = indexOfSlashInProof+1;
    int indexOfConjunctionElimination = indexOfSlashInProof+2;

    if(indexOfConjunctionElimination < proof.length()){
        // means this is conjunction elimination rule
        for(int i=0;i<indexOfConjunctionSymbol-1;i++){
            result += proof[i];
        }
    }

    // finding the type of elimination 1 or 2
    int typeOfConjunctionElimination = proof[indexOfConjunctionElimination+1];
    typeOfConjunctionElimination = int(typeOfConjunctionElimination) - 48;

    // finding the line number

    /* as the line number can be two digit also so store them as strings initially then 
    convert to integer */

    char slash = proof[indexOfConjunctionElimination+2];
    int x = indexOfConjunctionElimination+3;
    string stringlineNumber;

    while(x<proof.length()){
        stringlineNumber += proof[x];
        x++;
    }

    // if double digit line number is present in the proof line
    int lineNumber = stoi(stringlineNumber);

    // matching the result from proofLines
    string conjunctionLine = proofLines[lineNumber-1];

    int indexOfSlash = conjunctionLine.find('/');

    // making strings for left part before the '^' and right part after '^'
    string leftPart;
    string rightPart;

    // making object of stack class
    Stack stack;

    for(int i = 1;i<indexOfSlash-1;i++){
        stack.push(conjunctionLine[indexOfSlash-1-i]);
    }

    int count = 0;
    int stackOriginalSize = stack.size();
    int noOfOpeningBrackets = 0;
    int flag = 0;

    while(stack.top() != '^' || noOfOpeningBrackets != 0){
        if(stack.top() == '(' || noOfOpeningBrackets != 0){
            while(stack.top() != ')'){
                if(stack.top() == '('){
                    noOfOpeningBrackets++;
                }
                leftPart += stack.top();
                count++;
                stack.pop();
            }
            leftPart += stack.top();
            count++;
            stack.pop();
            noOfOpeningBrackets--;
        }
        else{
            leftPart += stack.top();
            count++;
            stack.pop();
        }
        if(count > stackOriginalSize){
            return false;
        }
    }


    // now removing the ^ symbol
    stack.pop();

    while(stack.size() != 0){
        if(stack.top() == '('){
            while(stack.top() != ')'){
                rightPart += stack.top();
                stack.pop();
            }
            rightPart += stack.top();
            stack.pop();
        }
        else{
            rightPart += stack.top();
            stack.pop();
        }
    }

    if(typeOfConjunctionElimination == 1){
        if(leftPart == result){
            return true;
        }
        return false;
    }
    else if(typeOfConjunctionElimination == 2){
        if(rightPart == result){
            return true;
        }
        return false;
    }
    return false;
}


/*
<------------------------------------------------------------------------------------------------------------>
Implication Elimination
<------------------------------------------------------------------------------------------------------------>
*/

bool implicationElimination(string proof,string proofLines[]){

    int indexOfSlash = proof.find('/');
    int indexOfImplicationSymbol = indexOfSlash+1;

    if(indexOfImplicationSymbol < proof.length()){
        // this means this rule is implies elimination
        string result;
        for(int i=0;i<indexOfImplicationSymbol-1;i++){
            result += proof[i];
        }

        // now finding the index of line numbers
        /* as the line number can be two digit also so store them as strings initially then 
        convert to integer */

        char slash = proof[indexOfImplicationSymbol+2];
        int x = indexOfImplicationSymbol+3;
        string stringlineNumber1;
        string stringlineNumber2;

        while(proof[x] != slash){
            stringlineNumber1 += proof[x];
            x++;
        }
        x++;
        while(x<proof.length()){
            stringlineNumber2 += proof[x];
            x++;
        }

        // if double digit line number is present in the proof line

        int lineNumber1 = stoi(stringlineNumber1);
        int lineNumber2 = stoi(stringlineNumber2);

        // as first line number is the implies statement in the above proof lines
        // and second line number corresponds to the phi in the implies statement

        string impliesStatement  = proofLines[lineNumber1-1];
        
        // finding the left part and right part of the implies statement.
        string leftPart;
        string rightPart;
        int indexOfSlash = impliesStatement.find('/');

        Stack stack;

        //pushing the elements in stack in reverse order
        for(int i=1;i<indexOfSlash-1;i++){
            stack.push(impliesStatement[indexOfSlash-1-i]);
        }

        int count = 0;
        int stackOriginalSize = stack.size();
        int noOfOpeningBrackets = 0;

        while(stack.top() != '>' || noOfOpeningBrackets != 0){
            if(stack.top() == '(' || noOfOpeningBrackets != 0){
                while(stack.top() != ')'){
                    if(stack.top() == '('){
                        noOfOpeningBrackets++;
                    }
                    leftPart += stack.top();
                    count++;
                    stack.pop();
                }
                leftPart += stack.top();
                count++;
                stack.pop();
                noOfOpeningBrackets--;
            }
            else{
                leftPart += stack.top();
                count++;
                stack.pop();
            }
            if(count > stackOriginalSize){
                return false;
            }
        }
        // now removing the > symbol
        stack.pop();

        while(stack.size() != 0){
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    rightPart += stack.top();
                    stack.pop();
                }
                rightPart += stack.top();
                stack.pop();
            }
            else{
                rightPart += stack.top();
                stack.pop();
            }
        }

        // now matching the left part of the implies statement with the statement in the given line number 2
        string givenLeftPart = proofLines[lineNumber2-1];

        // now we need to find the part of the givenLeftPart before the slash
        int indexOfSlashInGivenLeftPart = givenLeftPart.find('/');

        string newGivenLeftPart;
        for(int i=0;i<indexOfSlashInGivenLeftPart;i++){
            newGivenLeftPart += givenLeftPart[i];
        }
        
        if(leftPart == newGivenLeftPart){
            // this means that in p>q, p is given and true
            // now we have to check that result is equal to right part
            if(result == rightPart){
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

/*
<------------------------------------------------------------------------------------------------------------>
Modus Tollens
<------------------------------------------------------------------------------------------------------------>
*/

bool modusTollens(string proof,string proofLines[]){

    // finding the index of MT first
    int indexOfSlashInProof = proof.find('/');
    int indexOfMT = indexOfSlashInProof + 1;

    if(indexOfMT < proof.length()){
        // means this rule is MT
        string result;
        for(int i=0;i<indexOfMT-1;i++){
            result += proof[i];
        }

        // finding the line number now in which premises for MT are present
        char slash = proof[indexOfMT+2];
        int x = indexOfMT+3;
        string stringlineNumber1;
        string stringlineNumber2;

        while(proof[x] != slash){
            stringlineNumber1 += proof[x];
            x++;
        }
        x++;
        while(x<proof.length()){
            stringlineNumber2 += proof[x];
            x++;
        }

        // if double digit line number is present in the proof line
        /* as the line number can be two digit also so store them as strings initially then 
        convert to integer */

        int lineNumber1 = stoi(stringlineNumber1);
        int lineNumber2 = stoi(stringlineNumber2);

        string impliesStatement = proofLines[lineNumber1-1];

        // now we have to find the left and right parts of the implication statement
        int indexOfSlashInImpliesStatement = impliesStatement.find('/');
        Stack stack;
        string leftPart;
        string rightPart;

        // pushing the elements in stack in reverse order
        for(int i=1;i<indexOfSlashInImpliesStatement-1;i++){
            stack.push(impliesStatement[indexOfSlashInImpliesStatement-1-i]);
        }

        int count = 0;
        int stackOriginalSize = stack.size();
        int noOfOpeningBrackets = 0;
        int flag = 0;

        while(stack.top() != '>' || noOfOpeningBrackets != 0){
            if(stack.top() == '(' || noOfOpeningBrackets != 0){
                while(stack.top() != ')'){
                    if(stack.top() == '('){
                        noOfOpeningBrackets++;
                    }
                    leftPart += stack.top();
                    count++;
                    stack.pop();
                }
                leftPart += stack.top();
                count++;
                stack.pop();
                noOfOpeningBrackets--;
            }
            else{
                leftPart += stack.top();
                count++;
                stack.pop();
            }
            if(count > stackOriginalSize){
                return false;
            }
        }


        // now removing the > symbol
        stack.pop();

        while(stack.size() != 0){
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    rightPart += stack.top();
                    stack.pop();
                }
                rightPart += stack.top();
                stack.pop();
            }
            else{
                rightPart += stack.top();
                stack.pop();
            }
        }

        // now finding the ~psi given by lineNumber2
        string negationOfRightPart = proofLines[lineNumber2-1];
        int indexOfSlashInNegationOfRightPart = negationOfRightPart.find('/');

        string newNegationOfRightPart;
        for(int i=0;i<indexOfSlashInNegationOfRightPart;i++){
            newNegationOfRightPart += negationOfRightPart[i];
        }

        string rightPartAfterNegationInImpliesStatement = "~" + rightPart;

        if(newNegationOfRightPart == rightPartAfterNegationInImpliesStatement){

            // now we have to check wheter result matches with negation of left part in implies statement
            string leftPartAfterNegationInImplicationStatement = "~" + leftPart;

            if(leftPartAfterNegationInImplicationStatement == result){
                return true;
            }
            return false;
        }
        return false;

    }
    return false;
}

int main(void)
{
    char ans = 'Y';
    while(ans == 'Y' || ans == 'y'){

        cout<<"*************************************************************************"<<endl<<endl;

        cout<<"||=====================================================================||"<<endl;
        cout<<"||                                                                     ||"<<endl;
        cout<<"||                   Natural Deduction Proof Checker                   ||"<<endl;
        cout<<"||                                                                     ||"<<endl;
        cout<<"||=====================================================================||"<<endl;
        cout<<endl<<endl;

        int n=0;
        cout << "Enter the number of lines in proof rule: ";
        cin >> n;
        cout << "Enter the " << n << " lines of proof" << endl<<endl;

        // taking input from the user
        string proofLines[n];
        for (int i = 0; i < n; i++)
        {
            // cin >> ws is used for taking in account the white spaces in input stream.
            getline(cin >> ws, proofLines[i]);
        }

        int index = 0;
        int flag = 0;

        for(int i=0;i<n;i++){
            index = proofLines[i].find('/');
            if(index < proofLines[i].length()){
                    if((index+1 < proofLines[i].length()) && (proofLines[i][index+1] == '^')){
                        // so this is either ^i or ^e
                        if(proofLines[i][index+2] == 'i'){
                            // and intro
                            if(!conjunctionIntroduction(proofLines[i],proofLines)){
                                cout<<endl;
                                cout<<"Invalid Proof!"<<endl;
                                cout<<"Error in line Number "<<i+1<<endl;
                                cout<<"Wrong Conjunction Introduction Used!!"<<endl;
                                flag = 1;
                                break;
                            }
                        }
                        else if( (index+2 < proofLines[i].length()) && (proofLines[i][index+2] == 'e')){
                            // and elimination
                            if(!conjunctionElimination(proofLines[i],proofLines)){
                                cout<<endl;
                                cout<<"Invalid Proof!"<<endl;
                                cout<<"Error in line Number "<<i+1<<endl;
                                cout<<"Wrong Conjunction Elimination Used!!"<<endl;
                                flag = 1;
                                break;
                            }
                        }
                        else{
                            cout<<endl;
                            cout<<"Invalid Proof!"<<endl;
                            cout<<"Error in line Number "<<i+1<<endl;
                            cout<<"Wrong ^ rule Used!!"<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    else if( (index+1 < proofLines[i].length()) && (proofLines[i][index+1] == '+')){
                        // or intro
                        if(!disjunctionIntroduction(proofLines[i],proofLines)){
                            cout<<endl;
                            cout<<"Invalid Proof!"<<endl;
                            cout<<"Error in line Number "<<i+1<<endl;
                            cout<<"Wrong Disjunction Introduction Used!!"<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    else if( (index+1 < proofLines[i].length()) && (proofLines[i][index+1] == '>')){
                        // impl elimination
                        if(!implicationElimination(proofLines[i],proofLines)){
                            cout<<endl;
                            cout<<"Invalid Proof!"<<endl;
                            cout<<"Error in line Number "<<i+1<<endl;
                            cout<<"Wrong Implication Elimination Used!!"<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    else if((index+2 < proofLines[i].length()) && (proofLines[i][index+1] == 'M') && (proofLines[i][index+2] == 'T') ){
                        // MT
                        if(!modusTollens(proofLines[i],proofLines)){
                            cout<<endl;
                            cout<<"Invalid Proof!"<<endl;
                            cout<<"Error in line Number "<<i+1<<endl;
                            cout<<"Wrong Modus Tollens Used!!"<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    else if((index+1 < proofLines[i].length()) && ((proofLines[i][index+1] == 'P') || (proofLines[i][index+1] == 'p'))){
                        // premise
                    }
                    else{
                        cout<<endl; 
                        cout<<"Invalid Proof!"<<endl;
                        cout<<"Error in line Number "<<i+1<<endl;
                        flag = 1;
                        break;
                    } 
            }
            else{
                    cout<<endl; 
                    cout<<"Invalid Proof!"<<endl;
                    cout<<"Error in line Number "<<i+1<<endl;
                    flag = 1;
                    break;
            } 
        
        }

        if(flag == 0){
            cout<<endl;
            cout<<"Valid Proof !!"<<endl;
        }

        cout<<endl;
        cout<<"*************************************************************************"<<endl<<endl;

        cout<<"Do you want to test another proof? (Enter y/Y for yes and any other key to exit) ";
        cin>>ans;

    }
    
    return 0;
}