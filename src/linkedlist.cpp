//Elizabeth Bell

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <sys/time.h>
using namespace std;

//This will be the nodes for the linked list
struct Node {
  int data;
  Node* next;
};

//This will be the first node
void initNode(struct Node *head, int n) {
  head-> data = n;
  head-> next = NULL;
}
  
//This will add a new node to the linked list
void addNode(struct Node *head, int n) {
  //This creates the node to be added
  Node *newNode = new Node;
  newNode-> data = n;
  newNode-> next = NULL;
  
  //This will add the node at the end of the list
  Node *current = head;
  while(current) {
    if(current-> next == NULL) {
      current-> next = newNode;
      return;
    }
    current = current-> next;
  }
}

//This will search the linked list for an integer
void searchList(struct Node *head, int n) {
  Node *current = head;
  
  while(current) {
    if(current-> data == n) {
      //cout << "Number found\n";
      return;
    }
    if(current-> next == NULL) {
      //cout << "Number not found\n";
      return;
    }
    else {
      current = current-> next;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Incorrect number of arguments\n";
  }
  else {
    //converts the arguments to ints so i can use them
    int argOne = atoi(argv[1]);
    int argTwo = atoi(argv[2]);
    int i;
    srand(time(NULL));
    int num;
    clock_t start;
    double dur;
    
    //creates the first node inthe linked list
    Node *list = new Node;
    initNode(list, (rand()%100+1));
    //cout << "made the first node\n";
    
    //generates the numbers and puts them in the list
    for(i=0; i<argOne; i++){
      //num = rand()%100+1;
      addNode(list, (rand()%100+1));
    }
    //cout << "made the list\n";
    
    //This will search for the numbers in the list
    start = clock();
    for(i=0; i<argTwo; i++){
      //num = rand()%100+1;
      searchList(list, (rand()%100+1));
    }
    dur = (clock()-start) / (double) CLOCKS_PER_SEC;
    cout << "Time: " << dur << "\n";
  }
}