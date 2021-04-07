import shutil
from pathlib import Path
from random import randint


def worst_case():
    shutil.rmtree("./worst", ignore_errors=True)
    for sz in range(1, 101):
        path = f"./worst/sz{sz:03d}/"
        Path(path).mkdir(parents=True, exist_ok=True)

        num = range(1, sz+1)

        file_name = f"t0sz{sz:03d}.in.txt"
        with open(path + file_name, "w") as file:
            file.write(f"{sz}\n{' '.join(str(n) for n in num)}")
            file.close()


def random():
    shutil.rmtree("./random", ignore_errors=True)
    for sz in range(1, 101):
        path = f"./random/sz{sz:03d}/"
        Path(path).mkdir(parents=True, exist_ok=True)
        for t in range(10):
            num = [randint(1, 100) for _ in range(sz)]

            file_name = f"t{t}sz{sz:03d}.in.txt"
            with open(path + file_name, "w") as file:
                file.write(f"{sz}\n{' '.join(str(n) for n in num)}")
                file.close()


if __name__ == "__main__":
    worst_case()
    random()
