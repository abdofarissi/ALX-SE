import matplotlib.pyplot as plt
import numpy as np

a1 = 1
b1 = 0.5
t = np.linspace(-2, 2, 100)
x = a1 * t
y = b1 * t

plt.plot(x, y, label="M₁ : $y = \\frac{b_1}{a_1} x$", color='blue')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True, linestyle='--', alpha=0.7)
plt.axis('equal')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Trajectoire de M₁')
plt.legend()
plt.show()