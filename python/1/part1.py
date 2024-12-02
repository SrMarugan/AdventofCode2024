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

result_sum = 0
for i in range(len(column_2)):
    result_sum += abs(column_1[i] - column_2[i])

print(result_sum)