import numpy as np
import os
import pandas as pd
import matplotlib.pyplot as plt

path = os.path.dirname(__file__)
csv_file_path = os.path.join(path,"iris.csv")
df = pd.read_csv(csv_file_path)
y = df.iloc[0:100,4].values
y=np.where(y=='Iris-setosa',0,1)
X = df.iloc[0:100,[0,2]].values

# X[][] > 두 번의 인덱싱을 거쳐 데이터 추출 method1
# X[ , ] > 한 번에 2차원데이터의 행열에 접근 > numpy메서드 method2
#method 1 으로 1열데이터 추출 > first_column = [row[0] for row in X]
# .std() 넘파이에서 배열의 표준편차 계산

X_std = np.copy(X)
X_std[:,0] = (X[:,0] - X[:,0].mean()) / X[:,0].std()
X_std[:,1] = (X[:,1] - X[:,1].mean()) / X[:,1].std()