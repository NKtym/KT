#!/bin/sh

./rpcalc <<EOF
1 2 + 3 *
3 4 ^
1 2 3 * +
1e7 4 +
0x34 0X34 -
1e1
0x1.2p2
0x3p2 0x2p3 +
.1
NAN
NULL
INFINITY INFINITY -
INF INF -
0p2 0p2 + 
EOF