
const ACTOR_TYPE = 'ACTOR_TYPE';
const MOVIE_TYPE = 'MOVIE_TYPE';

// utils
const get = (obj, key) => obj[key];


function* traceBackToRoot(node) {
  if (node) {
    yield node.value;
    yield* traceBackToRoot(node.parent);
  }
}
// utils end

function Node({ value, nodeType }) {
  this.value = value;
  this.nodeType = nodeType;
  this.edges = [];
  this.parent = null;
  this.visited = false;
}


Node.prototype = {
  connect: function (node) {
    this.edges.push(node);
    node.edges.push(this);
  }
}


function Graph() {
  // for storing all nodes
  this.nodes = [];
  // key as a movie/actor name and value as its corresponding node
  this.graph = {}
}

Graph.prototype = {
  getActorNode: function (actor) {
    if (Object.prototype.hasOwnProperty.call(this.graph, actor)) {
      return {
        error: false,
        node: get(this.graph, actor)
      }
    }
  },
  getActorNode: function (actor) {
    if (Object.prototype.hasOwnProperty.call(this.graph, actor)) {
      return {
        error: false,
        node: get(this.graph, actor)
      }
    }
    return {
      error: true
    }
  },
  _persist: function (node) {
    const { value } = node;
    if (Object.prototype.hasOwnProperty.call(this.graph, value)) return;

    this.nodes.push(node);
    this.graph[value] = node;
  },
  createGraphFromData: function (data) {
    const { movies = [] } = data;
    movies.forEach(movie => {
      const { title } = movie;
      const movieNode = new Node({
        value: title,
        nodeType: MOVIE_TYPE
      });

      this._persist(movieNode);
      const { actors = [] } = movie;
      actors.forEach(actor => {
        const { node: actorNode = new Node({ value: actor, nodeType: ACTOR_TYPE }) } = this.getActorNode(actor);
        this._persist(actorNode);
        actorNode.connect(movieNode);
      })
    })
  }
}

function traverse(graph, start, end) {
  const { node: startNode } = graph.getActorNode(start);
  const { node: endNode } = graph.getActorNode(end);

  const queue = [];
  queue.push(startNode);
  startNode.visited = true;
  while (queue.length) {

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

module.exports = {
  Graph,
  traverse,
  traceBackToRoot
}


