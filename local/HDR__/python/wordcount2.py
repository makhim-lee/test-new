fin = open("lyrics.txt", "r")
words = fin.read().strip()
fin.close()

wordCount = {}
for word in words:
    if word in wordCount.keys():
        wordCount[word] += 1
    else:
        wordCount[word] = 1
    

    
for word, count in wordCount.items() :
    print(f"{word} in {count}")    







