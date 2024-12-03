import pathlib

with open(pathlib.Path(__file__).parent.joinpath("input.txt"), "r", encoding="utf-8") as file:
    lines = file.readlines()

column_1 = []
column_2 = []

for line in lines:
    columns = line.split("   ")
    column_1.append(int(columns[0]))
    column_2.append(int(columns[1]))

column_1.sort()
column_2.sort()

cont_column = {}
after = None
for i in column_2:
    if i == after:
        continue
    else:
        cont_column[i] = column_2.count(i)
        after = i

result = 0
for j in column_1:
    try:
        result += cont_column[j] * j
    except KeyError:
        continue

print(result)