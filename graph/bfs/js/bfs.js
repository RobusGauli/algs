const data = require('../data.json');
// represent he actor and movie in a node

const ACTOR_TYPE = 'ACTOR_TYPE';
const MOVIE_TYPE = 'MOVIE_TYPE';

class Node {
  constructor(value, nodeType) {
    this.nodeType = nodeType;
    this.value = value;
    // for storing edges
    this.edges = [];
    // store parent node
    this.parent = null;
    // check weather the node has been visited or not
    this.visited = false;
  }

}


function get(obj, key) {
  return obj[key];
}
class Graph {
  constructor() {
    // store all the nodes
    this.nodes = [];
    // store the key val map of node and its value
    this.graph = {}

  }

  getActorNode(actor) {
    if (Object.prototype.hasOwnProperty.call(this.graph, actor)) {
      return {
        error: false,
        node: get(this.graph, actor)
      }
    }
    return {
      error: true
    }
  }

  createGraphFromData(data) {
    const { movies } = data;
    for (let movie of movies) {
      // get the title of the movie
      const { title } = movie;
      // create a node of the title
      const movieNode = new Node(title, MOVIE_TYPE);
      // push to the nodes array
      this.nodes.push(movieNode);
      // put it ot the mao
      this.graph[title] = movieNode;
      // get the actors of the movie
      const { actors } = movie;

      for (let actor of actors) {
        // try to get the actor node if available
        let { error, node } = this.getActorNode(actor);
        let actorNode = null;
        if (error) {
          // create a actor node
          actorNode = new Node(actor, ACTOR_TYPE);
          // put that into the nodes
          this.nodes.push(actorNode);
          // into the map
          this.graph[actor] = actorNode;
        } else {
          actorNode = node;
        }
        // now put the actorNode into movie
        movieNode.edges.push(actorNode);
        // also put movie into the actor Node 
        actorNode.edges.push(movieNode);
      }
    }
  }
}


function traverse(graph, start, end) {
  const { node: startNode } = graph.getActorNode(start);
  const { node: endNode } = graph.getActorNode(end);
  
  
  const queue = [];
  queue.push(startNode);
  startNode.visited = true;
  while(queue.length) {
    
    const node = queue.shift();
      // check to see if it matches the end Node
      if (node.value === endNode.value) return node;
      
      node.edges.forEach(childNode => {
        if (!childNode.visited) {
          childNode.visited = true;
          queue.push(childNode);
          // point the child node to its parent
          childNode.parent = node;
        }
      })
    
  }
  
}

function traceBackToRoot(node) {
  const path = [];
  let currentNode = node;
  while(currentNode) {
    path.push(currentNode.value);
    currentNode = currentNode.parent;
  }
  return path;
}

function main() {
  let graph = new Graph();
  // create a graph from the give json data
  graph.createGraphFromData(data);
  // traverse using the breadth first search algorithm
  // by finding the relationship in between two actors
  const start = 1;
  const end = 9;
  
  const targetNode = traverse(graph, start, end);
  // trace back the parent to get the path
  const path = traceBackToRoot(targetNode);
  console.log(path);
}

main();
