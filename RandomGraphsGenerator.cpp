#include <iostream>
#include <math.h>
#include <string.h>

#define NUMBER_OF_VERTICES
#define NUMBER_OF_EDGES_PER_VERTEX_AVG 6

using namespace std;


tempNodelate <class T>
struct SingleLinkedListNode{
  T data;
  SingleLinkedListNode *NextNode;

  SingleLinkedListNode(){


  }

  SingleLinkedListNode(T val){

    this->data = val;
  }

  SingleLinkedListNode(T val,SingleLinkedListNode<T> NewNode){

    this->data = val;
    this->NextNode = NewNode;
  }


};

tempNodelate <class T>
class LinkedList{

  private:
    SingleLinkedListNode<T> *root, *tail;

  public:
    void insert(T val){

      SingleLinkedListNode<T> *tempNode=new SingleLinkedListNode<T>;
      tempNode->data=val;
      tempNode->NextNode=NULL;

      if(root){
        cout<<"Adding new elements"<<endl;
        tail->NextNode=tempNode;
        tail=tempNode;
      }
      else {
        root=tempNode;
        tail=tempNode;
        tempNode=NULL;
        cout<<"New root added"<<endl;
      }

    }

    void display()
    {
      SingleLinkedListNode<T> *tempNode=new SingleLinkedListNode<T>;
      tempNode=root;
      while(tempNode!=NULL)
      {
        cout<<tempNode->data<<"\t";
        tempNode=tempNode->NextNode;
      }
    }

};

int main(){

  LinkedList<int> *SingleLinkedListNodes1 = new LinkedList<int>();
  SingleLinkedListNodes1->insert(3);
  SingleLinkedListNodes1->insert(5);
  SingleLinkedListNodes1->insert(8);
  SingleLinkedListNodes1->insert(8);
  SingleLinkedListNodes1->display();

}
