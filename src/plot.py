git #!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

def plot(matrice):
"""Plot solution of the ..."""

   x = np.linspace(-2, 2, 1000)

    # Parsing the results
    // TODO
   M = np.loadtxt(matrice, dtype=np.float64)
   M = np.multiply(M, M)

	# Defining the legend
   plt.legend(plt.plot(x, M), ["i=%d" % i for i in range(n + 1)])

	# Defining the title
   plt.title("Numerical solutions of the hermite polynomials")

	# Editing the legend
   plt.xlabel("z axis")
   plt.ylabel("n index")

   # Save as png file in plot directory
   plt.savefig('plot.png')