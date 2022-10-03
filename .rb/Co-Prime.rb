puts "Masukkan Bilangan Pertama: " # Keluaran perintah masukkan bil 1/ask for first number
m = gets.chomp.to_i # membaca input user untuk bil 1 ke m/input your first number to m variable
puts "Masukkan Bilangan Kedua: " # keluaran perintah masukkan bil 2/ask for second number
n = gets.chomp.to_i # membaca input user untuk bil 2 ke n/input your second number to m variable
if m < n # percabangan jika m lebih kecil dari n/condition if m is less than n
    m, n = n, m
end
r = m % n # r adalah m modulus n/r value is modulus of m with n
until r == 0 # perulangan sampai r sama dengan 0/looping until r value is 0
    m, n = n, r
    r = m % n
end
unless n != 1 # percabangan untuk menentukan status bilangan/condition to tell the number is coprime or not
    puts "Bilangan Pertama dan Kedua Relatif Prima" # keluaran status relatif prima/number is prime relative (coprime)
else
    puts "Bilangan Pertama dan Kedua Bukan Relatif Prima" # keluaran status bukan relatif prima/number is not prime relative (not coprime)
end

# Reference: https://www.geeksforgeeks.org/check-two-numbers-co-prime-not/