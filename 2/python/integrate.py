import sympy

x = sympy.Symbol("x")
y = sympy.Symbol("y")

result = sympy.integrate(4*x**2 + x + 5)
print(result)
