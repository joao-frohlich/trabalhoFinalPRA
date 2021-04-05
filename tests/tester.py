from subprocess import call


def worst_case():
    for sz in range(1, 101):
        path = f"./worst/sz{sz:03d}/"
        file_name = f"t0sz{sz:03d}"
        call(f"./a.out < {path + file_name}.in.txt > {path + file_name}.out.txt", shell=True)


def random():
    for sz in range(1, 101):
        path = f"./random/sz{sz:03d}/"
        for t in range(10):
            file_name = f"t{t}sz{sz:03d}"
            call(f"./a.out < {path + file_name}.in.txt > {path + file_name}.out.txt", shell=True)


if __name__ == "__main__":
    call("gcc ../*.c", shell=True)
    worst_case()
    random()
