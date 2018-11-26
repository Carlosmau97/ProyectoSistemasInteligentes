class Queue
{
    // Array is used to implement a Queue
    constructor()
    {
        this.items = [];
    }

    enqueue(element)
    {
      // adding element to the queue
      this.items.push(element);
    }

    dequeue()
    {
      // removing element from the queue
      // returns underflow when called
      // on empty queue
      if(this.isEmpty())
          return "Underflow";
      return this.items.shift();
      }

      front()
      {
        // returns the Front element of
        // the queue without removing it.
        if(this.isEmpty())
          return "No elements in Queue";
        return this.items[0];
      }

      isEmpty()
      {
        // return true if the queue is empty.
        return this.items.length == 0;
      }

      printQueue()
      {
        var str = "";
        for(var i = 0; i < this.items.length; i++)
          str += this.items[i] +" ";
        return str;
      }
} // Queue class

//EMPIEZA CLASE PARA GRAFOS
class Graph {
    // defining vertex array and
    // adjacent list
    constructor(noOfVertices)
    {
        this.noOfVertices = noOfVertices;
        this.AdjList = new Map();
    }

    addVertex(v)
    {
      // initialize the adjacent list with a
      // null array
      this.AdjList.set(v, []);
    }

    addEdge(v, w)
    {
      // get the list for vertex v and put the
      // vertex w denoting edge betweeen v and w
      this.AdjList.get(v).push(w);

      // Since graph is undirected,
      // add an edge from w to v also
      this.AdjList.get(w).push(v);
    }

    printGraph()
    {
      // get all the vertices
      var get_keys = this.AdjList.keys();

      // iterate over the vertices
      for (var i of get_keys)
      {
        // great the corresponding adjacency list
        // for the vertex
        var get_values = this.AdjList.get(i);
        var conc = "";

        // iterate over the adjacency list
        // concatenate the values into a string
        for (var j of get_values)
          conc += j + " ";

          // print the vertex and its adjacency list
          console.log(i + " -> " + conc);
        }
      }

      // function to performs BFS
      bfs(startingNode, finnishNode)
      {
        // create a visited array
        var visited = [];
        for (var i = 0; i < this.noOfVertices; i++)
          visited[i] = false;

        // Create an object for queue
        var q = new Queue();

        // add the starting node to the queue
        visited[startingNode] = true;
        q.enqueue(startingNode);

        // loop until queue is element
        while (!q.isEmpty() && getQueueElement!=finnishNode){
          // get the element from the queue
          var getQueueElement = q.dequeue();

          // passing the current vertex to callback funtion
          console.log(getQueueElement);

          // get the adjacent list for current vertex
          var get_List = this.AdjList.get(getQueueElement);

          // loop through the list and add the elemnet to the
          // queue if it is not processed yet
          for (var i in get_List) {
            var neigh = get_List[i];
            var visitado=document.getElementById(neigh);

            if (!visited[neigh]) {
                visited[neigh] = true;
                q.enqueue(neigh);
                visitado.style.background="blue";
            }
            else{
              visitado.style.background='green';
            }

            if(neigh==finnishNode || neigh==startingNode){
              visitado.style.background='purple'
            }
          }
        }
      }

      dfs(startingNode, finnishNode)
      {

        var visited = [];
        for (var i = 0; i < this.noOfVertices; i++)
          visited[i] = false;

        this.DFSUtil(startingNode, visited, finnishNode);
      }

      // Recursive function which process and explore
      // all the adjacent vertex of the vertex with which it is called
      DFSUtil(vert, visited, finnishNode)
      {
        if(vert==finnishNode){return 0;}

        visited[vert] = true;
        console.log(vert);

        var get_neighbours = this.AdjList.get(vert);

        for (var i in get_neighbours) {
          var get_elem = get_neighbours[i];
          if (!visited[get_elem]){
            this.DFSUtil(get_elem, visited,finnishNode);
          }
        }
      }
}   //FIN DE LA CLASE



var g = new Graph(39);
var vertices = [ 'D1S', 'D1204', 'D1205',
  'D1206', 'D1207', 'D1208','D1209','D1210','D1211',
  'D1V0','D1V1','D1V2','D1V3','D1V4','D1V5','D1V6',
  'D1V7','D1V8','D1V9','D1V10', 'D2S', 'D2205', 'D2206',
  'D2207', 'D2207', 'D2208', 'D2209', 'D2210', 'D2211',
  'D2212','D2V0','D2V1','D2V2','D2V3','D2V4','D2V5','D2V6',
  'D2V7','D2V8','D2V9'];

// adding vertices
for (var i = 0; i < vertices.length; i++) {
    g.addVertex(vertices[i]);
}

// D1
g.addEdge('D1S', 'D1V2');
g.addEdge('D1V2', 'D1V1');
g.addEdge('D1V1', 'D1208');
g.addEdge('D1V1', 'D1207');
g.addEdge('D1V1', 'D1V0');
g.addEdge('D1V0', 'D1206');
g.addEdge('D1V0', 'D1205');
g.addEdge('D1V0', 'D1204');
g.addEdge('D1V2', 'D1V3');
g.addEdge('D1V3', 'D1V4');
g.addEdge('D1V4', 'D1V5');
g.addEdge('D1V5', 'D1209');
g.addEdge('D1V5', 'D1V6');
g.addEdge('D1V6', 'D1V7');
g.addEdge('D1V7', 'D1211');
g.addEdge('D1V7', 'D1V8');
g.addEdge('D1V8', 'D1V9');
g.addEdge('D1V9', 'D1V10');
g.addEdge('D1V10', 'D1210');

// EDIFICIO D2
g.addEdge('D2S', 'D2V7');
g.addEdge('D2205', 'D2V6');
g.addEdge('D2206', 'D2V4');
g.addEdge('D2207', 'D2V3');
g.addEdge('D2208', 'D2V1');
g.addEdge('D2209', 'D2V0');
g.addEdge('D2210', 'D2V0');
g.addEdge('D2211', 'D2V0');
g.addEdge('D2212', 'D2V0');
g.addEdge('D2212', 'D2V1');
g.addEdge('D2V0', 'D2V1');
g.addEdge('D2V1', 'D2V2');
g.addEdge('D2V2', 'D2V3');
g.addEdge('D2V3', 'D2V4');
g.addEdge('D2V4', 'D2V5');
g.addEdge('D2V5', 'D2V6');
g.addEdge('D2V7', 'D2V5');
g.addEdge('D2V7', 'D2V8');
g.addEdge('D2V8', 'D2V9');

g.printGraph();

/*Seleccionar inicio y fin*/

function anchura(){
  var nodoSelect=document.getElementById("first").innerHTML;
  var nodoSelect2=document.getElementById("last").innerHTML;

  console.log("BFS");
  g.bfs(nodoSelect,nodoSelect2);
}

function profundidad(){
  var nodoSelect=document.getElementById("first").innerHTML;
  var nodoSelect2=document.getElementById("last").innerHTML;

  console.log("DFS");
  g.dfs(nodoSelect,nodoSelect2);
}
