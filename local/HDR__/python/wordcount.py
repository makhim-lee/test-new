fin = open("lyrics.txt", "r")
lyrics = fin.readlines()
fin.close()

wordCount = {}
for line in lyrics:
    for word in line.strip().split() :
        if word in wordCount.keys() :
            wordCount[word] += 1
        else :
            wordCount[word] = 1
    
for word, count in wordCount.items() :
    print(f"{word} in {count}")    







