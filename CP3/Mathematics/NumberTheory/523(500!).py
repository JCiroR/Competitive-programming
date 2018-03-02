from sys import stdin

def main():
    str_rep = ["" for x in range(1002)]
    str_rep[0] = "1"
    fact = 1
    for i in range (1, 1001):
        fact *= i
        str_rep[i] = str(fact)

    for line in stdin:
        q = int(line)
        print("{0}!".format(q))
        print(str_rep[q])


if __name__ == "__main__":
    main()
