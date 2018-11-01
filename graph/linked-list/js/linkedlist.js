const Node = (value, nextNode = null) => ({
  value: value,
  nextNode: nextNode
});

// function to convert array to linked list
function fromList(alist) {
  if (!Array.isArray(alist)) {
    throw new TypeError('Argument must be of type array.');
  }

  if (!alist.length) {
    throw new Error('Array cannot be empty.');
  }

  if (alist.length === 1) {
    return Node(alist[0]);
  }

  return Node(alist[0], fromList(alist.slice(1)))
}

// function to convert linked list to array

function* traverse(node) {
  if (node) {
    yield node.value;
    yield* traverse(node.nextNode);
  }
}


(() => {
  const args = [3, 4, 5, 6, 7, 8, 9];
  const node = fromList(args);
  const traversedList = [...traverse(node)];
  console.log(traversedList);
})();