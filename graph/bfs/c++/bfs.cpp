#include <iostream>
#include <vector>

using namespace std;
using namespace std;

// class representing node
namespace bfs {
  class Node 
  {
    public:
      int value;
      Node* parent;
      std::string nodeType;
      std::vector<Node*> edges;
      bool visited;

   public:
    Node(int value, std::string nodeType): value(value), nodeType(nodeType) {visited = false;};

    void addEdge(Node* node)
    {
      this -> edges.push_back(node);
    }

    bool equals(Node* node)
    {
      return node -> value  == this -> value;
    }

    void connect(Node* node)
    {
      this -> edges.push_back(node);
      node -> edges.push_back(this);
    }

  };
  
}
int main()
{
  bfs::Node* node = new bfs::Node(3, "STRIN");
  cout << node -> value << endl;
  return 0;
}

