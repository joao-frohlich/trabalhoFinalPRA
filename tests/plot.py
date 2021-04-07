import matplotlib.pyplot as plt
import seaborn as sns


plt.rcParams.update({'font.size': 20})  # font size
fig_size = (19.2, 12)


def make_plot(title, avl, b):
    path = "plot/"

    plt.figure(figsize=fig_size, constrained_layout=True)
    sns.set_style("darkgrid")

    plt.plot(avl, label="AVL")
    plt.plot(b, label="B")

    plt.title(title)
    plt.ylabel('Esforço Computacional')
    plt.xlabel('Tamanho da entrada')

    plt.legend()
    plt.savefig(path + title + ".png")


def get_data_worst():
    avl = [0]
    b = [0]
    for sz in range(1, 101):
        path = f"./worst/sz{sz:03d}/"
        file_name = f"t0sz{sz:03d}.out.txt"
        with open(path + file_name, "r") as file:
            avl.append(int(file.readline()))
            b.append(int(file.readline()))
            file.close()
    return avl, b


def get_data_random():
    avl = [0]
    b = [0]
    for sz in range(1, 101):
        path = f"./random/sz{sz:03d}/"
        avl_sum, b_sum = 0, 0
        for t in range(10):
            file_name = f"t{t}sz{sz:03d}.out.txt"
            with open(path + file_name, "r") as file:
                avl_sum += int(file.readline())
                b_sum += int(file.readline())
                file.close()
        avl.append(avl_sum / 10)
        b.append(b_sum / 10)
    return avl, b


if __name__ == "__main__":
    avl_data, b_data = get_data_worst()
    make_plot("Worst Case", avl_data, b_data)

    avl_data, b_data = get_data_random()
    make_plot("Random Case", avl_data, b_data)
