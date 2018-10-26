#include <vector>
#include <iostream>
#include <iterator>
#include <map>
#include <deque>

using namespace std;

class Node
{
public:
  int value;
  bool visited;
  Node *parent;
  vector<Node *> edges;

public:
  Node(int value)
  {
    this->visited = false;
    this->value = value;
    this->parent = NULL;
  }

  auto setVisibility(bool flag)
  {
    this->visited = flag;
  }
};

ostream &operator<<(ostream &os, Node &node)
{
  os << "Node(" << node.value << ")";
  return os;
};

class Graph
{
public:
  map<int, Node *> graph;
  vector<Node *> nodes;
  map<int, vector<int>> *data;

  Graph(map<int, vector<int>> *data)
  {
    this->data = data;
  }

  void createGraph()
  {
    // here we gonna createa  graph;
    // lets create  local iterator
    map<int, vector<int>>::iterator itr;
    for (itr = this->data->begin(); itr != this->data->end(); ++itr)
    {
      auto value = itr->first;
      // lets check if it has a nodeN
      Node *parentNode;
      if (this->graph.count(value) > 0)
      {
        // that means we already have a parentNode
        parentNode = graph[value];
      }
      else
      {
        parentNode = new Node(value);
        nodes.push_back(parentNode);
        graph[value] = parentNode;
      }
      // go over the edges
      auto edges = itr->second;
      for (auto &child : edges) // pass by reference and not copy
      {
        // get the node if avaialble
        Node *node;
        if (this->graph.count(child) > 0)
        {
          node = graph[child];
        }
        else
        {
          node = new Node(child);
          nodes.push_back(node);
          graph[child] = node;
        }
        parentNode->edges.push_back(node);
        node->edges.push_back(parentNode);
      }
    }
  }
};

auto traverse(Graph &graph, int start, int end)
{
  auto startNode = graph.graph[start];
  auto endNode = graph.graph[end];

  deque<Node *> queue;

  // put the start Node in the queue
  queue.push_back(startNode);

  while (queue.size() > 0)
  {
    auto currentNode = queue.front();
    // delete from the queue
    currentNode->setVisibility(true);
    queue.erase(queue.begin());

    if (currentNode->value == endNode->value)
    {
      return currentNode;
    }

    // loop around the edges
    for (Node *node : currentNode->edges)
    {
      if (!(node->visited))
      {
        // point child to parent
        node->parent = currentNode;
        queue.push_back(node);
      }
    }
  }
  return new Node(-1);
}


// utils
auto traceParent(Node *node)
{
  vector<int> *path = new vector<int>;
  while (node->parent)
  {
    node = node->parent;
    (*path).push_back(node->value);
  }
  return path;
}

auto printPath(vector<int> &path)
{
  for (auto p : path)
  {
    cout << p << endl;
  }
}


int main()
{

  map<int, vector<int>> *data = new map<int, vector<int>>;
  (*data)[2].push_back(3);
  (*data)[2].push_back(4);
  (*data)[2].push_back(5);

  (*data)[1].push_back(2);
  (*data)[1].push_back(4);

  Graph *graph = new Graph(data);
  graph->createGraph();
  auto n = traverse(*graph, 1, 3);
  auto path = traceParent(n);
  printPath(*path);
}
