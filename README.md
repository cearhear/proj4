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
