fin = open("lyrics.txt", "r")

lyrics = fin.readlines()

fin.close()
i = 1
#lines = []
#for line in lyrics:
#    if "dress" in line:
#        lines.append(i)
#    i += 1

lines = [i for i, line in enumerate(lyrics) if "like" in line]

print(lines)




