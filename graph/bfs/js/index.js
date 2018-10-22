const data = require('../data.json');

const {
  Graph,
  traverse,
  traceBackToRoot
} = require('./bfs');


(function(start, end){
  let graph = new Graph();
  // create a graph from the give json data
  graph.createGraphFromData(data);
  // traverse using the breadth first search algorithm
  const targetNode = traverse(graph, start, end);
  // trace back the parent to get the path
  const path = [...traceBackToRoot(targetNode)];
  console.log(path);
})(1, 9);

