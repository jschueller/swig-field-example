import openturns as ot

d1 = ot.Uniform(2,5)
d2 = ot.Gumbel(3,4)
print(d1 == d2)
print(d1 != d2)

print('OK')

