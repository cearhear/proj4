Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

Benchmarking 
-------------

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 00.00         | 3375 kb        |
| 20            | 00.00         | 3383 kb        |
| 50            | 00.00         | 3356 kb        |
| 100           | 00.00         | 3687 kb        |
| 200           | 00.04         | 4645 kb        |
| 500           | 00.22         | 11253 kb       |
| 1000          | 00.89         | 34809 kb       |
|---------------|---------------|----------------|

Questions
---------
1.) We represented the map as a 2D vector of Node structs. Within the Node struct we stored info about it's edges and weights. 

2.) The processed nodes were removed from the frontier (represented as a multimap), so the complexity wasn't quite as good as the typical O(V+ElogV) when using a min-priority queue. The multimap is slightly slower as it has to rebalance after erasing more often. At the beginning the starting node was put onto the multimap, then if adjacent nodes were not visited yet they were inserted into the map keyed by edge weight or cost. Since we always removed the first item in the multimap, the next lowest edge weight would be checked first.   

3.) The size of the map did not have much effect until N was greater than 100 and then the elapsed time appeared to grow exponentially, however even after N=1,000 the time was still less than 1 second. 
