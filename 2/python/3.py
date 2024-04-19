import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use('tkagg')
import japanize_matplotlib
m = int(input('元本の金額（万円）は？'))
p = int(input('期間（年）は？'))
r = float(input('年利（%）は？'))

sum = m
list = [sum]
for i in range(1, p+1):
    sum = sum * (1 + r / 100)
    list.append(sum)

df = pd.DataFrame({
    '合計': list
})
df.plot(title='預貯金の可視化', xlabel='経過年数', ylabel='総額', kind='bar')
print(list)
plt.show()
