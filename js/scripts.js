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


addEdge(v, w, )
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
    while (!q.isEmpty()){
        // get the element from the queue
        var getQueueElement = q.dequeue();

        // passing the current vertex to callback funtion
        //console.log(getQueueElement);

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
                console.log("Reccorrido:",neigh);
                visitado.style.background='blue';
            }


            if(neigh==finnishNode || neigh==startingNode){
              visitado.style.background='purple';
            }

            if(neigh==finnishNode){return 0;}

        }
    }
}
dfs(startingNode, finnishNode)
{

    var visited = [];
    for (var i = 0; i < this.noOfVertices; i++)
        visited[i] = false;

    this.DFSUtil(startingNode, visited, finnishNode,startingNode);


}

// Recursive function which process and explore
// all the adjacent vertex of the vertex with which it is called
DFSUtil(vert, visited, finnishNode,startingNode)
{

  visited[vert] = true;
  console.log(vert);
  var visitado=document.getElementById(vert);

    var get_neighbours = this.AdjList.get(vert);

    for (var i in get_neighbours) {
        var get_elem = get_neighbours[i];
        if (!visited[get_elem]){
            this.DFSUtil(get_elem, visited,finnishNode,startingNode);
        }
        else{
          visitado.style.background='blue';

          if(vert==finnishNode || vert==startingNode){
            visitado.style.background='purple';
          }

          return 0;
        }
      }
}

}   //FIN DE LA CLASE



var g = new Graph(20);
var vertices = [ 'P1','P2','P3','P4',
'D1S', 'D1204', 'D1205',
'D1206', 'D1207', 'D1208','D1209','D1210','D1211',
'D1V0','D1V1','D1V2','D1V3','D1V4','D1V5','D1V6',
'D1V7','D1V8','D1V9','D1V10',

'D2S', 'D2205','D2206', 'D2207', 'D2208',
'D2209','D2210','D2211','D2212','D2V0',
'D2V1','D2V2','D2V3','D2V4','D2V5','D2V6',
'D2V7','D2V8','D2V9',

'D3S','D3201','D3202','D3203','D3204', 'D3205','D3206',
'D3207', 'D3208','D3209','D3210','D3211','D3212',
'D3V0','D3V1','D3V2','D3V3','D3V4','D3V5','D3V6',
'D3V7','D3V8','D3V9',

'D4S', 'D4201', 'D4207', 'D4208','D4209','D4212',
'D4213','D4214','D4215','D4216','D4V0','D4V1',
'D4V2','D4V3','D4V4','D4V5','D4V6','D4V7',
'D4V8','D4V9','D4V10'
];

// adding vertices
for (var i = 0; i < vertices.length; i++) {
    g.addVertex(vertices[i]);
}

 //Conexion Pasillos
g.addEdge('D1V6', 'P1');
g.addEdge('P1', 'P2');
g.addEdge('P1', 'P4');
g.addEdge('P2','D2V6');
g.addEdge('P2','P3');
g.addEdge('P3','D3V5');
g.addEdge('P3', 'P4');
g.addEdge('P4', 'D4V8');

// D1
g.addEdge('D1S', 'D1V2');
g.addEdge('D1V2','D1V1');
g.addEdge('D1V1','D1V0');
g.addEdge('D1V1','D1208');
g.addEdge('D1V1','D1207');
g.addEdge('D1V0','D1204');
g.addEdge('D1V0','D1205');
g.addEdge('D1V0','D1206');
g.addEdge('D1V2','D1V3');
g.addEdge('D1V3','D1V4');
g.addEdge('D1V4','D1V5');
g.addEdge('D1V5','D1209');
g.addEdge('D1V5','D1V6');
g.addEdge('D1V6','D1V7');
g.addEdge('D1V7','D1211');
g.addEdge('D1V7','D1V8');
g.addEdge('D1V8','D1V9');
g.addEdge('D1V9','D1V10');
g.addEdge('D1V10','D1210');


//Conexion D1 - D2
g.addEdge('D1V9','D2V9');

// D2
g.addEdge('D2V9','D2V8');
g.addEdge('D2V8','D2V7');
g.addEdge('D2V7','D2S');
g.addEdge('D2V7','D2V5');
g.addEdge('D2V5','D2V6');
g.addEdge('D2V5','D2V4');
g.addEdge('D2V6','D2205');
g.addEdge('D2V4','D2206');
g.addEdge('D2V4','D2V3');
g.addEdge('D2V3','D2207');
g.addEdge('D2V3','D2V2');
g.addEdge('D2V2','D2V1');
g.addEdge('D2V1','D2208');
g.addEdge('D2V1','D2212');
g.addEdge('D2V1','D2V0');
g.addEdge('D2V0','D2211');
g.addEdge('D2V0','D2210');
g.addEdge('D2V0','D2209');

//D3
g.addEdge('D3V5','D3V4');
g.addEdge('D3V4','D3207');
g.addEdge('D3V4','D3S');
g.addEdge('D3V4','D3212');
g.addEdge('D3V4','D3V3');
g.addEdge('D3V3','D3V2');
g.addEdge('D3V2','D3208');
g.addEdge('D3V2','D3V1');
g.addEdge('D3V1','D3209');
g.addEdge('D3V1','D3211');
g.addEdge('D3V1','D3V0');
g.addEdge('D3V0','D3210');
g.addEdge('D3V5','D3V6');
g.addEdge('D3V6','D3208');
g.addEdge('D3V6','D3205');
g.addEdge('D3V6','D3206');
g.addEdge('D3V6','D3V7');
g.addEdge('D3V7','D3204');
g.addEdge('D3V7','D3203');
g.addEdge('D3V7','D3V8');
g.addEdge('D3V8','D3202');
g.addEdge('D3V8','D3V9');
g.addEdge('D3V9','D3201');

//Conexion D3 - D4
g.addEdge('D3V9','D4V10');

// D4
g.addEdge('D4V10','D4201');
g.addEdge('D4V10','D4V9');
g.addEdge('D4V9','D4V8');
g.addEdge('D4V8','D4S');
g.addEdge('D4V8','D4V7');
g.addEdge('D4V7','D4V6');
g.addEdge('D4V6','D4216');
g.addEdge('D4V6','D4V5');
g.addEdge('D4V5','D4207');
g.addEdge('D4V5','D4V4');
g.addEdge('D4V4','D4215');
g.addEdge('D4V4','D4V3');
g.addEdge('D4V3','D4V2');
g.addEdge('D4V2','D4208');
g.addEdge('D4V2','D4V1');
g.addEdge('D4V1','D4214');
g.addEdge('D4V1','D4V0');
g.addEdge('D4V0','D4213');
g.addEdge('D4V0','D4209');
g.addEdge('D4V0','D4212');

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
