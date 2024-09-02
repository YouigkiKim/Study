import numpy as np
import matplotlib.pyplot as plt

# Given parameters
sf = 5
offset = 3
theta_0 = np.arctan(offset / sf)

# Define the cubic polynomial l(s)
s = np.linspace(0, sf, 100)
l_s = np.tan(theta_0) * (s - (s**2 / sf) + (s**3 / (3 * sf**2)))

# Plotting the curve
plt.figure(figsize=(10, 6))
plt.plot(s, l_s, label=f'Path Curve with $s_f$ = {sf} and Offset = {offset}')
plt.axhline(y=offset, color='r', linestyle='--', label='Desired Offset')
plt.title('Lateral Offset Curve $l(s)$')
plt.xlabel('s (Longitudinal Distance)')
plt.ylabel('l(s) (Lateral Offset)')
plt.grid(True)
plt.legend()
plt.show()
