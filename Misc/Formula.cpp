Some properties of bitwise operations:
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b

Addition:
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)

Subtraction:
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))


1. log_b(mn) = log_b(m) + log_b(n)
2. log_b(m/n) = log_b(m) - log_b(n)
3. log_b(m^r) = r * log_b(m)
4. log_b(1) = 0

5. log_b(b) = 1
6. log_b(m) = log_q(m) / log_q(b)

