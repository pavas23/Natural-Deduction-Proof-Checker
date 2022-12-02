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

bool conjunctionIntroduction(string proof, string premises[], string proofLines[])
{
    int indexOfConjunctionSymbol = proof.find('^');
    int indexOfConjunction = proof.find('i');
    // making strings for left part before the '^' and right part after '^'
    string leftPart;
    string rightPart;
    // making stack for storing the proof of conjunctionIntroduction
    Stack stack;
    if (indexOfConjunctionSymbol < proof.length())
    {
        // means this is and introduction rule
        for(int i=1;i<indexOfConjunction-3;i++){
            // push the proof in reverse order in stack
            stack.push(proof[indexOfConjunction-2-i-1]);
        }
        // now leftPart is before the ^ symbol
        while(stack.top() != '^'){
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    leftPart += stack.top();
                    stack.pop();
                }
                leftPart += stack.top();
                stack.pop();
            }
            else{
                leftPart += stack.top();
                stack.pop();
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
        int line1 = proof[indexOfConjunction + 2];
        int line2 = proof[indexOfConjunction + 4];
        /* as line1 and line2 are initially characters so typecast to int and subtract 48 which is ascii value of 0 */
        line1 = int(line1) - 48;
        line2 = int(line2) - 48;
        
        // Now both left and right part should be present in premise
        if ((premises[line1 - 1] == leftPart) && (premises[line2 - 1] == rightPart))
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

bool disjunctionIntroduction(string proof, string premises[], string proofLines[])
{
    int indexOfDisjunctionSymbol = proof.find('+');
    int indexOfDisjunction = proof.find('i');
    // making strings for left part before the '^' and right part after '^'
    string leftPart;
    string rightPart;
    // making stack for storing the proof of conjunctionIntroduction
    Stack stack;
    if (indexOfDisjunctionSymbol < proof.length())
    {
        // means this is and introduction rule
        for(int i=1;i<indexOfDisjunction-3;i++){
            // push the proof in reverse order in stack
            stack.push(proof[indexOfDisjunction-2-i-1]);
        }
        // now leftPart is before the ^ symbol
        while(stack.top() != '+'){
            if(stack.top() == '('){
                while(stack.top() != ')'){
                    leftPart += stack.top();
                    stack.pop();
                }
                leftPart += stack.top();
                stack.pop();
            }
            else{
                leftPart += stack.top();
                stack.pop();
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

        // checking wheter it is i1 or i2
        int typeOfDisjunctionIntroduction = proof[indexOfDisjunction+1];
        typeOfDisjunctionIntroduction = int(typeOfDisjunctionIntroduction)-48;

        // now we need to find the index where line numbers are present
        int line1 = proof[indexOfDisjunction + 3];
        /* as line1 and line2 are initially characters so typecast to int and subtract 48 which is ascii value of 0 */
        line1 = int(line1) - 48;
        
        // Now both left and right part should be present in premise
        if(typeOfDisjunctionIntroduction == 1){
            if(leftPart == premises[line1-1]){
                return true;
            }
            return false;
        }
        else if(typeOfDisjunctionIntroduction == 2){
            if(rightPart == premises[line1-1]){
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

bool conjunctionElimination(string proof,string premises[],string proofLines[]){

    int indexOfConjunctionSymbol = proof.find('^');
    // TODO fix when there is e in the formula itself it will crash there
    int indexOfConjunctionElimination = proof.find('e');

    // storing the result in string

    string result;
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

    int lineNumber = proof[indexOfConjunctionElimination+3];
    lineNumber = int(lineNumber)-48;

    cout<<"The line number is "<<lineNumber<<endl;
    // matching the result from proofLines

    string conjunctionLine = proofLines[lineNumber-1];

    int indexOfConjunctionSymbol1 = conjunctionLine.find('^');
    int indexOfSlash = conjunctionLine.find('/');


    // making strings for left part before the '^' and right part after '^'
    string leftPart;
    string rightPart;

    cout<<"The conjunction line is "<<conjunctionLine<<endl;

    // making stack for storing the proof of conjunctionIntroduction
    for(int i=1;i<indexOfConjunctionSymbol1;i++){
        leftPart += conjunctionLine[i];
    }

    for(int i=indexOfConjunctionSymbol1+1;i<indexOfSlash-1;i++){
        rightPart += conjunctionLine[i];
    }

    cout<<"after left and right part"<<endl;

    cout<<"The left part is "<<leftPart<<endl;
    cout<<"The right part is "<<rightPart<<endl;

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



int main(void)
{
    int n;
    cout << "Enter the number of lines in proof rule: ";
    cin >> n;
    cout << "Enter the " << n << " lines of proof" << endl;

    // taking input from the user
    string proofLines[n];
    for (int i = 0; i < n; i++)
    {
        // cin >> ws is used for taking in account the white spaces in input stream.
        getline(cin >> ws, proofLines[i]);
    }

    // now we will store all the premises in the array of strings.
    string premises[n]; // making of max n size
    int noOfPremises;
    for (int i = 0; i < n; i++)
    {
        int indexOfP = proofLines[i].find('P');
        if (indexOfP < proofLines[i].length())
        {
            // so this statement is a premise
            noOfPremises++;
                for (int j = 0; j < indexOfP - 1; j++)
                {
                    premises[i] += proofLines[i][j];
                }
        }
    }

    // for printing the premises
    cout<<"The premises are:"<<endl;
    for(int i=0;i<noOfPremises;i++){
        cout<<premises[i]<<endl;
    }

    cout << conjunctionElimination(proofLines[2], premises, proofLines);
    return 0;
}

