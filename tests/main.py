from subprocess import call

import gen
import tester
import plot


def run():
    call("gcc ../*.c", shell=True)

    gen.worst_case()
    tester.worst_case()
    avl_data, b_data = plot.get_data_worst()
    plot.make_plot("Worst Case", avl_data, b_data)

    gen.random()
    tester.random()
    avl_data, b_data = plot.get_data_random()
    plot.make_plot("Random Case", avl_data, b_data)


if __name__ == "__main__":
    run()
