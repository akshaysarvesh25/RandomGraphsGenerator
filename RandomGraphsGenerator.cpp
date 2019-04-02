/*********************************************************
* Creating a graph with the following characteristics :
* 1. G1 : Average vertex degree is 6
* 2. G2 : Each vertex adjacent to 20% of other vertices
*         randomly chosen.
*********************************************************/

#include <iostream>
#include <math.h>
#include <string.h>

#define NUMBER_OF_VERTICES 5000
#define NUMBER_OF_EDGES_PER_VERTEX_AVG 6

using namespace std;


template <class T>
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

template <class T>
class LinkedList{

  private:
    SingleLinkedListNode<T> *root, *tail;

  public:
    void insert(T val){

      SingleLinkedListNode<T> *tempNode=new SingleLinkedListNode<T>;
      tempNode->data=val;
      tempNode->NextNode=NULL;

      if(root)
      {
        cout<<"Adding new elements"<<endl;
        tail->NextNode=tempNode;
        tail=tempNode;
      }
      else
      {
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
      unsigned int i=0;
      cout<<"\n"<<endl;
      while(tempNode!=NULL)
      {
        cout<<tempNode->data<<"\t";
        tempNode=tempNode->NextNode;
      }
      cout<<endl;
    }

};

int main(){

  LinkedList<int> *SingleLinkedListNodes1 = new LinkedList<int>[10];
  
  SingleLinkedListNodes1[0].insert(3);
  SingleLinkedListNodes1[0].insert(5);
  SingleLinkedListNodes1[0].insert(8);
  SingleLinkedListNodes1[0].insert(8);
  SingleLinkedListNodes1[0].insert(69);
  SingleLinkedListNodes1[1].insert(68);
  SingleLinkedListNodes1[1].insert(76);
  SingleLinkedListNodes1[0].display();
  SingleLinkedListNodes1[1].display();

}
