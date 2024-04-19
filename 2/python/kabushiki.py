import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('tkagg')
import japanize_matplotlib
from numpy import random as rd

m = int(input('元本の金額（万円）は？'))
p = int(input('期間（年）は？'))

sum1 = m
sum2 = m
list1 = [m]
list2 = [m]
for i in range(1, p+1):
	sum1 =  (sum1 * rd.uniform(0.6, 1.4)) + (sum1 * rd.uniform(0, 0.05))
	list1.append(sum1)
	sum2 = (sum2 * rd.uniform(0.9, 1.1)) 
	list2.append(sum2)

df = pd.DataFrame({
    '株式': list1,
    '投資信託': list2
})
df.plot.line(title= '株式と投資信託の可視化', xlabel='経過年数', ylabel='総額', style="o-")
print(list1)
print(list2)
plt.show()
