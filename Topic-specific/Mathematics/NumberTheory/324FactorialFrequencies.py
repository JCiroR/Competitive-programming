def main():
    a = [[0 for x in range(10)] for x in range(368)]
    fact = 1
    string_rep = ""
    for i in range (1, 368):
        fact *= i
        string_rep = str(fact)
        for c in string_rep:
            a[i][int(c)] += 1
    q = int(input())

    while q != 0:
        print("{0}! --".format(q))
        print("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d"%(a[q][0],a[q][1],a[q][2],a[q][3],a[q][4]))
        print("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d"%(a[q][5],a[q][6],a[q][7],a[q][8],a[q][9]))
        q = int(input())

if __name__ == "__main__":
    main()