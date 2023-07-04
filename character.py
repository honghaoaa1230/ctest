import numpy as np
import math

while 1:
    row = int(input())
    matrix = np.full((row, row), "-")

    for i in range(matrix.shape[0]):
        matrix[i][i] = "*"

    matrix = np.fliplr(matrix)
    for i in range(matrix.shape[0]):
        matrix[i][i] = "*"
    matrix = np.fliplr(matrix)

    # 遍历数组
    def traversal(matrix):
        for x in range(matrix.shape[0]):
            for y in range(matrix.shape[1]):
                print(matrix[x][y], end=" ")
            print()

    def upperleft(row, col, matrix):
        while row >= 0 and col >= 0:
            matrix[row][col] = "*"
            row -= 1
            col -= 1

    def lowerleft(row, col, matrix):
        while row < matrix.shape[0] and col >= 0:
            matrix[row][col] = "*"
            row += 1
            col -= 1

    def upperright(row, col, matrix):
        while row >= 0 and col < matrix.shape[1]:
            matrix[row][col] = "*"
            row -= 1
            col += 1

    def lowerright(row, col, matrix):
        while row < matrix.shape[0] and col < matrix.shape[1]:
            matrix[row][col] = "*"
            row += 1
            col += 1

    def leftcheck(row, col, matrix):
        while (col - 4) >= 0:
            upperleft(row, col - 4, matrix)
            lowerleft(row, col - 4, matrix)
            col -= 4

    def uppercheck(row, col, matrix):
        while (row - 4) >= 0:
            upperright(row - 4, col, matrix)
            upperleft(row - 4, col, matrix)
            row -= 4

    def rightcheck(row, col, matrix):
        while (col + 4) < matrix.shape[1]:
            upperright(row, col + 4, matrix)
            lowerright(row, col + 4, matrix)
            col += 4

    def lowercheck(row, col, matrix):
        while (row + 4) < matrix.shape[0]:
            lowerleft(row + 4, col, matrix)
            lowerright(row + 4, col, matrix)
            row += 4

    def crosscheck(matrix):
        mid = int(row / 2)

        leftcheck(mid, mid, matrix)
        uppercheck(mid, mid, matrix)
        rightcheck(mid, mid, matrix)
        lowercheck(mid, mid, matrix)

    mid = int(row / 2)

    # if row >= 9:

    #     matrix[mid][mid-4] = '*'
    #     matrix[mid][mid+4] = '*'
    #     matrix[mid+4][mid] = '*'
    #     matrix[mid-4][mid] = '*'

    # if row >= 11:
    #     grow(matrix)
    crosscheck(matrix)
    traversal(matrix)
    print()
    # x1 = np.arange(15).reshape(5,3)
