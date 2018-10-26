#include <vector>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

class Node
{
  public:
    int value;
    vector<Node*> edges;

  public:
    Node(int value){
      this -> value = value;
    }
};

ostream& operator<<(ostream& os,  Node& node)
{
  os << "Node(" << node.value << ")";
  return os;
};


class Graph
{
  public:
    map<int, Node*> graph;
    vector<Node*> nodes;
    map<int, vector<int> >* data;

  Graph(map<int, vector<int> >* data)
   {
    this -> data = data;
   }  
  
  auto printNodes()
  {
    for(auto node: this -> nodes)
    {
      cout << *node << endl; 
    }
  }

  
  void createGraph()
  {
    // here we gonna createa  graph;
    // lets create  local iterator
    map<int, vector<int> >::iterator itr;
    for(itr = this -> data -> begin(); itr != this -> data -> end(); ++itr )
    {
      auto value = itr -> first;
      // lets check if it has a nodeN
      Node* parentNode;
      if (this -> graph.count(value) > 0) {
        // that means we already have a parentNode
        parentNode = graph[value];
      } else {
        parentNode = new Node(value);
        nodes.push_back(parentNode);
        graph[value] = parentNode;
      }
      // go over the edges
      auto edges = itr -> second;
      for(auto& child: edges) // pass by reference and not copy
      {
        // get the node if avaialble
        Node* node;
        if (this -> graph.count(child) > 0) {
          node = graph[child];
          
        } else {
          node = new Node(child);
          nodes.push_back(node);
          graph[child] = node;
        }
        parentNode -> edges.push_back(node);
        node -> edges.push_back(parentNode);
      }
    }
  }
};

int main()
{
  Node* node = new Node(3);
  map<int, vector<int> >* data = new map<int, vector<int> >;
  (*data)[2].push_back(3);
  (*data)[2].push_back(4);
  (*data)[2].push_back(5);
  
  (*data)[1].push_back(2);
  (*data)[1].push_back(4);


  Graph* graph = new Graph(data);
  graph -> createGraph();

  
  
}
