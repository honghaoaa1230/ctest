a = 9
y = 0
x = 0
arr = [6,6]
# while(x < a*a):
#     if ((x == 0) & (x == 40)):
#         print('*',end="")
#         y = y + 1
#         continue

#     if ((x == 9) & (x == 48)):
#         print('*')
#         continue

#     if (y == 3):
arr[0,0] = "*"
arr[0,6] = "*"
arr[6,0] = "*"
arr[6,6] = "*"
while(x < 7):
    while(y < 7):
        if(arr[x,y] != ""):
            continue
        arr[x,y]

