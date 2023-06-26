def diagonal_right(matrix):
    if not matrix:
        return []
    row = len(matrix)
    col = len(matrix[0])
    col2 = col
    result = []
    for i in range(row):
        for j in range(col2 - 1, -1, -1):
            lst = []
            i1, j1 = i, j
            while i1 <= row - 1 and j1 <= col - 1:
                lst.append(matrix[i1][j1])
                j1 += 1
                i1 += 1
            result.append(lst)

            if i == 0 and j == 0:
                col2 = 1
    return ("the result is : %s" % result, "end")


# print(diagonal_right([[1],[2]]))
# print(diagonal_right([[1]]))
print(diagonal_right([
    [1,2,3,4],
    [5,1,2,3],
    [9,5,1,2]
    ]))

