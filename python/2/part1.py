import pathlib

with open(pathlib.Path(__file__).parent.joinpath("input.txt"), "r", encoding="utf-8") as file:
    lines = file.readlines()

result = 0
for line in lines:
    line = line.rstrip("\n")
    numbs_list = line.rsplit(" ")
    j = 0
    while int(numbs_list[0 + j]) == int(numbs_list[1 +j]):
        j += 1
    is_ascendent =  int(numbs_list[0+j]) < int(numbs_list[1+j])
    for n, numb in enumerate(numbs_list):
        try:
            if is_ascendent:
                if int(numbs_list[n+1]) < int(numb):
                    break
            else:
                if int(numbs_list[n+1]) > int(numb):
                    break
            if  abs(int(numbs_list[n+1]) - int(numb)) > 3 or abs(int(numbs_list[n+1]) - int(numb)) == 0:
                break
        except IndexError:
            pass
    else:
        result += 1

print(result)