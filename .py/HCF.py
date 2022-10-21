m = int(input("Masukkan Bilangan Pertama: "))  # exp: m = 12/ ask first number
n = int(input("Masukkan Bilangan Kedua: "))  # exp: n = 80/ ask second number
if m < n:  # 12 < 80
    m, n = n, m
r = m % n  # r = 80 % 12, r = 8
while r != 0:  # while r value is not 0
    m, n = n, r  # m = n  # m1 = 12, m2 = 8  # n = r  # n1 = 8, n2 = 4
    r = m % n  # r = m % n  # r1 = 12 % 8 = 4, r2 = 8 % 4 = 0
print("FPB dari Bilangan Pertama dan Kedua adalah:", n)  # program print last n value that is n2 = 4 (HCF from 80 and 12)

# Reference: https://www.programiz.com/python-programming/examples/hcf