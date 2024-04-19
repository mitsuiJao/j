import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 1000)
df = pd.DataFrame({"x":x, "f(x)":np.sqrt(x), "g(x)": np.sin(x)})

df.plot(x="x", y=["f(x)", "g(x)"], title="graph", xlabel="x", ylabel="y")
plt.grid()
plt.axes().set_aspect("equal")

plt.show()

