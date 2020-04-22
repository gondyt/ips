#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt
import json

zmin =  -20
zmax = 20 
xmin = -10
xmax = 10


def plot(f):
	plt.imshow(np.loadtxt(f, dtype=np.float64), interpolation='bilinear', cmap="Blues")
	plt.title("Densité nucléaire")
	plt.xlabel("z (de %d fm à %d fm)" % (zmin, zmax))
	plt.ylabel("x (de %d fm à %d fm)" % (xmin, xmax))
	plt.show()

# on lit sur l'entree standart
import sys
plot(sys.stdin)
