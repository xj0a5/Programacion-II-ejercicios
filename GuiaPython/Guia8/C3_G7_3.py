""""Guia 7, ejercicio 3 inciso d) Log(z)"""
import numpy as np
import matplotlib.pyplot as plt

# 1. Crear la grilla del plano complejo (x, y)
x = np.linspace(-5, 5, 400)
y = np.linspace(-5, 5, 400)
X, Y = np.meshgrid(x, y)
Z = X + 1j * Y

# 2. Calcular el Argumento Principal (la parte imaginaria de Log z)
Arg_Z = np.angle(Z)

# 3. Levantar el lienzo 3D
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# 4. Graficar la superficie
# Usamos el mapa de colores 'twilight' porque es cíclico (ideal para ángulos)
surf = ax.plot_surface(X, Y, Arg_Z, cmap='twilight', edgecolor='none', alpha=0.9)

# 5. Configurar etiquetas
ax.set_title("Parte imaginaria de Log(z): El salto en el eje real negativo")
ax.set_xlabel("Eje Real (x)")
ax.set_ylabel("Eje Imaginario (y)")
ax.set_zlabel("Ángulo Arg(z)")

plt.show()