# Awesome_Robotics_Club_Kaushik-kumar_240532
The code is based on Dijkstra Pathfinding Optimization . 
In this code , I initialise 5 10*10   matrix
1)	Maingrid:-In this I store the input given by user . this is an character array.
2)	Grid:- In this I store the values of correspoending  symbols. That is given in question 

	
Symbol	Meaning	Cost
S	Start	0
G	Goal	0
.	Free tile	1
#	Wall (impassable)	-1
~	Mud(slow)	3
^	Hill (very slow)	5
It is an interger array.

3)	Distancegrid :- It is also an integer array. It contain the  least cost to reach that point.
Initially all the element are intialised with infinity. After that if I found any route to reach that point at least cost then I update the value.

4)	Parent :- It is an struct array , struct contains two values that is a coordinate of a point. Value at any point is the coordinate of the point from which I reached to this point in order to minimize the cost .
5)	Visited :- It is an int array , that contain value either 0 or 1. If I visit the particular block then it become 1. Initially all block are intiallised  with 0.



Running of code 
Initially all distancegrid is infinity and visited is 0.

Initially I visited the first box and give distancegrid =0 for it.

As I visited a point convert corresponding box  visited array to 1.

Then I move in all 4 direction to discover new way to reach other points .

 If I reached a point with distancegrid , that is more than  value previous distancegrid + grid value of visited point then , parent of new point is previous point   and distancegrid of new point is modified  that is the minimum of the twos that we compared .
 
 If if I reached a point with distancegrid , that is less than previous distancegrid + grid value of visited point then nothing will change. 

 
As we visit all the points of grid one by one the distance grid , parent , visited , updated everytime if condition is satisfied .
Finally we have main two structure one is distancegrid and other is parent . 

Using distance grid I can get the  minimum cost to reach any point. 

Using parent I get the last point of a path . and using recursion I get the the whole path.



INPUT FORMAT

Input contain 10 lines and each lines contain 10 characters separated by space.

Example of INPUT:-

S . . . . ~ . . ^ .

# # # . . ~ # . ^ .

. . . # . . # . . .

. ~ ~ # . . . . . .

. . . . . # # # # .

^ ^ . . . . . . ~ .

# . . . . # ~ ~ ~ .

. . # # . . . . . .

. . . . . ^ ^ ^ ^ G

. # # # # # # . . .

OUTPUT FORMAT

Output gives minimum cost and path to that point using coordinate of all points on path.

 Example of OUTPUT:--   MINIMUM COST TO REACH END POINT : 16
 
PATH USED BY ROBOT : (0, 0) ->(0, 1) ->(0, 2) ->(0, 3) ->(0, 4) ->(1, 4) ->(2, 4) ->(2, 5) ->(3, 5) ->(3, 6) ->(3, 7) ->(3, 8) ->(3, 9) ->(4, 9) ->(5, 9) ->(6, 9) ->(7, 9) ->(8, 9)

