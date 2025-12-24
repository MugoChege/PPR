def reverse_number(number, base = 10):
    negative = (number < 0)

    number = (number * -1) if (number < 0) else (number * 1)

    nh = number
    out = 0
    i = 1

    while (nh > 0):
        out *= i
        mod = nh % base
        out += mod
        nh -= mod
        nh //= base
        i = 10

    if (negative):
        out *= -1

    return out
    
print(reverse_number(120))
