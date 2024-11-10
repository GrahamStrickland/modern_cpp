#!/usr/bin/env python3
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

matplotlib.rcParams["text.usetex"] = True


def main() -> None:
    X = np.linspace(-np.pi, np.pi)
    Y = np.linspace(-np.pi, np.pi)

    x, y = np.meshgrid(X, Y)

    z = np.sin(x) + np.sin(y)

    fig = plt.figure()
    ax = fig.add_subplot(projection="3d")

    ax.plot_surface(x, y, z)

    ax.set_xlabel("$x$")
    ax.set_ylabel("$y$")
    ax.set_zlabel("$z$")

    ax.set_title("Graph of the function $f(x) = \sin{x} + \cos{y}$")

    plt.show()


if __name__ == "__main__":
    main()
