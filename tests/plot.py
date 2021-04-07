import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

plt.rcParams.update({'font.size': 20})  # font size
fig_size = (19.2, 12)


def make_plot(title, avl, b):
    path = "plot/"

    plt.figure(figsize=fig_size, constrained_layout=True)
    sns.set_style("darkgrid")

    sns.lineplot(x="Sz", y="Avl", data=avl, label="AVL")
    sns.lineplot(x="Sz", y="B", data=b, label="B")

    plt.title(title)
    plt.ylabel('Esforço Computacional')
    plt.xlabel('Tamanho da entrada')

    plt.xticks(np.arange(0, 101, 10))

    plt.savefig(path + title + ".png")


def get_data_worst():
    avl = []
    b = []
    for sz in range(1, 101):
        path = f"./worst/sz{sz:03d}/"
        file_name = f"t0sz{sz:03d}.out.txt"
        with open(path + file_name, "r") as file:
            avl.append([sz, int(file.readline())])
            b.append([sz, int(file.readline())])
            file.close()
    avl = pd.DataFrame(avl, columns=["Sz", "Avl"])
    b = pd.DataFrame(b, columns=["Sz", "B"])
    return avl, b


def get_data_random():
    avl = []
    b = []
    for sz in range(1, 101):
        path = f"./random/sz{sz:03d}/"
        for t in range(10):
            file_name = f"t{t}sz{sz:03d}.out.txt"
            with open(path + file_name, "r") as file:
                avl.append([sz, int(file.readline())])
                b.append([sz, int(file.readline())])
                file.close()
    avl = pd.DataFrame(avl, columns=["Sz", "Avl"])
    b = pd.DataFrame(b, columns=["Sz", "B"])
    return avl, b


if __name__ == "__main__":
    avl_data, b_data = get_data_worst()
    make_plot("Worst Case", avl_data, b_data)

    avl_data, b_data = get_data_random()
    make_plot("Random Case", avl_data, b_data)
