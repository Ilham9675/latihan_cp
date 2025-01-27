

data = ""
jum = 0
while data == "":
    data = input('')
    if data == "end":
        break
    x1 = data.split(":")
    cek = 0
    green = 1
    blue = 1
    red = 1
    for x2 in x1[1].split(";"):
        for x3 in x2.split(","):
            x4 = x3.split(" ")
            if x4[2] == "red":
                temp = x4[1]
                red = max(red,int(temp))
                # if int(temp) > 12:
                #     cek = 1
            if x4[2] == "green":
                temp = x4[1]
                green = max(green,int(temp))
                # if int(temp) > 13:
                #     cek = 1
            if x4[2] == "blue":
                temp = x4[1]
                blue = max(blue,int(temp))
                # if int(temp) > 14:
                #     cek = 1
    jum += (red * green * blue)
    # if cek == 0:
    #     y1 = x1[0].split(" ")
    #     jum += int(y1[1])
    data = ""

print(jum)