import pathlib

def find_word(matriz, row, col, word):
    directions = [
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0),
        (1, 1),
        (1, -1),
        (-1, 1),
        (-1, -1)
    ]
    cont = 0
    n = len(matriz)
    m = len(matriz[0])
    lenght = len(word)

    for dr, dc in directions:
        r, c = row, col
        for i in range(lenght):
            if not (0 <= r < n and 0 <= c < m and matriz[r][c] == word[i]):
                break
            r += dr
            c += dc
        else:
            cont += 1

    return cont


with open(pathlib.Path(__file__).parent.joinpath("input.txt"), "r", encoding="utf-8") as file:
        matriz = [line.strip() for line in file if line.strip()]

word = "XMAS"
result = 0

for i in range(len(matriz)):
    for j in range(len(matriz[i])):
        if matriz[i][j] == word[0]:
            result += find_word(matriz, i, j, word)

print(result)
