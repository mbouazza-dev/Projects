
### Oriented graph processing library

**written in python**

Implementation of a non-oriented graph with the help of a dictionary: the keys
are the vertices, and the values are the vertices adjacent to a given vertex.
Loops are allowed. Weights are not allowed.

The simplest representation is used: an edge {u, v} will be present.
twice in the dictionary: v is in the set of neighbors of u, and u
is in all of v.'s neighbors.

 - Creation of arcs for an oriented graph
   
 - Addition of vertex for an oriented graph

 - Functions allowing elementary operations on an oriented graph (remove
   arc, return the number of vertices, return the number of loops, ....)

