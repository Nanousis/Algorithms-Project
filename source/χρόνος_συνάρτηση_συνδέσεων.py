import matplotlib.pyplot as plt
import numpy as np

x = [78, 6594, 11850]
y = [0.000711, 203.096087, 1002.218258]
x1 = np.linspace(0, 12000, 120000)
y1 = (x1**3)/1660685254

plt.plot(x, y, marker='o', markersize=8, markerfacecolor='red', label="Χρόνος συνάρτηση συνδέσεων")
plt.plot(x1, y1, label="x^3")
# Set the tick labels for the x and y axes
plt.xticks(x)
plt.yticks(y)

plt.title("Διάγραμμα Χρόνου Εκτέλεσης Συνάρτηση Συνδέσεων")
plt.xlabel("Αριθμός Συνδέσεων")
plt.ylabel("Χρόνος σε second")
plt.legend()

plt.show()