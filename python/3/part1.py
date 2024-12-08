import pathlib
import re

with open(pathlib.Path(__file__).parent.joinpath("input.txt"), "r", encoding="utf-8") as file:
    lines = file.readlines()

result = 0
pattern = r"(mul\((\d+),(\d+)\))"
for line in lines:
    line = line.rstrip("\n")
    numbs = re.findall(pattern, line)

    for list_n in numbs:
        result += int(list_n[1]) * int(list_n[2])

print(result)
