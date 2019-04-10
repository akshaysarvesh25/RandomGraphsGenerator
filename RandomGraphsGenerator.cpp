/*********************************************************
* Creating a graph with the following characteristics :
* 1. G1 : Average vertex degree is 6
* 2. G2 : Each vertex adjacent to 20% of other vertices
*         randomly chosen.
*
* Procedure:
* 1. The graph is represented as an adjacency list.
* 2. The adjacency list is created using an array of
*    Linked list.
*
*
*********************************************************/

#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
#include <random>
#include <vector>
#include <iomanip>
#include <fstream>


#define NUMBER_OF_VERTICES 5000
#define NUMBER_OF_EDGES_PER_VERTEX_AVG 6
#define PERCENTAGE_VERTICES_NEIGHBORS 1000

#define INSERT_DEBUG_OUTPUT 0
#define DISPLAY_DEBUG_OUTPUT 0
#define DISPLAY_DEBUG_COUNT 1

using namespace std;


template <class T>
struct SingleLinkedListNode{
  T data;
  T weight;
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
        #if INSERT_DEBUG_OUTPUT
        cout<<"Adding new elements"<<endl;
        #endif
        tail->NextNode=tempNode;
        tail=tempNode;
      }
      else
      {
        root=tempNode;
        tail=tempNode;
        tempNode=NULL;
        #if INSERT_DEBUG_OUTPUT
        cout<<"New root added : "<<val<<endl;
        #endif
      }

    }

    void display()
    {
      SingleLinkedListNode<T> *tempNode=new SingleLinkedListNode<T>;
      tempNode=this->root;
      unsigned int i=0;
      //cout<<"\n"<<endl;
      while(tempNode!=NULL)
      {
        cout<<tempNode->data<<" -> ";
        tempNode=tempNode->NextNode;
      }
      cout<<"\n";
    }


    int count()
    {
      SingleLinkedListNode<T> *tempNode=new SingleLinkedListNode<T>;
      tempNode=this->root;
      unsigned int count=0;
      //cout<<"\n"<<endl;
      while(tempNode!=NULL)
      {
        count = count+1;
        tempNode=tempNode->NextNode;
      }
      //cout<<count<<"\n";

      return count;

    }

};



int main(){

  LinkedList<int> *SingleLinkedListNodes1 = new LinkedList<int>[10];

  /* Creating a graph of 5000 nodes as an adjacency list */
  LinkedList<int> *Graph_ = new LinkedList<int>[NUMBER_OF_VERTICES];

  /* Construct a cycle of connected nodes */
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    if(i==(NUMBER_OF_VERTICES-1))
    {
      Graph_[i].insert(0);
      continue;
    }
    Graph_[i].insert(i+1);
  }

  #if DISPLAY_DEBUG_OUTPUT
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    cout<<i<<"->";
    Graph_[i].display();
  }
  #endif

  /* Using current time as seed for random generator */
  srand(time(0));

  /* Add 6 vertices randomly to every vertex */
  for(unsigned int i = 0;i<((NUMBER_OF_VERTICES/2)+200);i++)
  {
    for(unsigned int NV = 0;NV<((NUMBER_OF_EDGES_PER_VERTEX_AVG));NV++)
    {

      if(Graph_[i].count() <= 6)
      {
        int NumbVertices = rand()%NUMBER_OF_VERTICES;
        Graph_[i].insert(NumbVertices);
        Graph_[NumbVertices].insert(i);
      }

    }

  }

  #if DISPLAY_DEBUG_OUTPUT
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    cout<<i<<" -> ";
    Graph_[i].display();
  }
  #endif

  #if DISPLAY_DEBUG_COUNT
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    //cout<<i<<" : ";
    Graph_[i].count();
  }
  #endif


  /* Add 20% of the vertices randomly to every vertex */
  /* Creating a graph of 5000 nodes as an adjacency list */
  LinkedList<int> *Graph_1 = new LinkedList<int>[NUMBER_OF_VERTICES];
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    for(unsigned int NV = 0;NV<(NUMBER_OF_VERTICES);NV++)
    {
      if((rand()%100)<=9)
      {
        Graph_1[i].insert(NV);
        Graph_1[NV].insert(i);
      }

    }

  }

  #if DISPLAY_DEBUG_OUTPUT
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    cout<<i<<" -> ";
    Graph_1[i].display();
  }
  #endif

  std::vector<int> ArrayCount;
  #if DISPLAY_DEBUG_COUNT
  for(unsigned int i = 0;i<NUMBER_OF_VERTICES;i++)
  {
    //cout<<i<<" : ";
    ArrayCount.push_back(Graph_1[i].count());
  }
  #endif

  std::ofstream outfile_TS1;
  //std::ofstream outfile_TS2;

  std::remove("ArrayCount.txt");
  outfile_TS1.open("ArrayCount.txt", std::ios_base::app);
  for(unsigned int i = 0;i<ArrayCount.size();i++)
  {
    outfile_TS1<<std::setprecision(20)<<ArrayCount[i]<< std::endl;
    //std::cout<<"Writing file"<<std::endl;
  }
  outfile_TS1.close();




}
