import matplotlib.pyplot as plt


x = [34, 4941, 6927]
y = [0.000790, 199.834324, 987.199260]

plt.plot(x, y, marker='o', markersize=8, markerfacecolor='red')
# Set the tick labels for the x and y axes
plt.xticks(x)
plt.yticks(y)

plt.title("Διάγραμμα Χρόνου Εκτέλεσης Συνάρτηση Κόμβων")
plt.xlabel("Αριθμός Κόμβων")
plt.ylabel("Χρόνος σε second")

plt.show()
