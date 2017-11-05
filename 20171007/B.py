if __name__ == "__main__":
    s = raw_input()
    a, b, c, d = map(int, s.split(" "))
    print(1728*a + 144*b + 12 * c + d)