Tobias Perelstein       tperel88
CS214 --- Assignment 2

Overall Algorithm:

My approach to the assignment was to create linked list nodes inside the SorteList object which stored all teh values. I then iterated through the list and used the comparator function to determine the place in which the node is inserted. I keep a reference to the data rather than copying it in each node, so it is the users responsibilty to maintain the data stored at the address they provide a void *

Memory Usage:

I Allocate space for a Node object anytime I create a node, anytime I create a sorted list object, and anytime I create an Iterator object.

Runtime:

All insertions are O(n) since in the worst case n comparisons must be made where n refers to the number of nodes in the list. Removals are O(n) as well because in the worst case, the node is in hte very last node of the linked list.


