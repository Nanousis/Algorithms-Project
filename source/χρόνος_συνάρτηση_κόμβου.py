import matplotlib.pyplot as plt
import numpy as np

x = [34, 4941, 6927]
y = [0.000711, 203.096087, 1002.218258]
x1 = np.linspace(0, 7000, 70000)
y1 = (x1**3)/224083530-(x1**2)*0.00001+x1*0.0001  


plt.plot(x, y, marker='o', markersize=8, markerfacecolor='red', label="Xρόνος συνάρτηση των κόμβων")
plt.plot(x1, y1, label="x^3")
# Set the tick labels for the x and y axes
plt.xticks(x)
plt.yticks(y)

plt.title("Διάγραμμα Χρόνου Εκτέλεσης Συνάρτηση Κόμβων")
plt.xlabel("Αριθμός Κόμβων")
plt.ylabel("Χρόνος σε second")
plt.legend()

plt.show()