import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
#matplotlib.use('TkAgg')
import japanize_matplotlib

m = int(input('元本の金額（万円）は？'))
p = int(input('期間（年）は？'))
r1 = float(input('預貯金1の年利（%）は？'))
r3 = float(input('預貯金2の年利（%）は？'))
r2 = float(input('債券1の年利（%）は？'))
r4 = float(input('債券2の年利（%）は？'))

sum1 = m
sum2 = m
list1 = [m]
list2 = [m]
sum3 = m
sum4 = m
list3 = [m]
list4 = [m]

for i in range(1, p+1):
	sum1 = sum1 * (1 + r1 / 100)
	list1.append(sum1)
	sum2 += sum2 + (r2/100)
	list2.append(sum2)
	sum3 = sum3 * (1 + r3 / 100)
	list3.append(sum3)
	sum4 += sum4 + (r4/100)
	list4.append(sum4)

df = pd.DataFrame({
    '預貯金1（複利）': list1,
    '預貯金2（複利）': list3,
    '債券1（単利）': list2,
    '債券2（単利）': list4
})
df.plot(title= '預貯金（複利）と債券（単利）の可視化', xlabel='経過年数', ylabel='総額', kind='bar')
print(list1)
print(list2)
print(list3)
print(list4)
#plt.ylim(min(list2), max(list1))
plt.show()
