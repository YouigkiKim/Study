import numpy as np
import matplotlib.pyplot as plt

# 파일에서 데이터를 읽어옵니다.
input_file_path = '/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_xyyaw_opt_output.txt'

file1_path = '/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_xyyaw_opt_output.txt'
file2_path = '/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_lla_opt_output.txt'

data1 = []
data2 = []

with open(file1_path, 'r') as file1, open(file2_path, 'r') as file2:
    for line1, line2 in zip(file1, file2):
        parts1 = list(map(float, line1.split()[:2]))  # 첫 번째 파일에서 x, y만 사용
        parts2 = list(map(float, line2.split()[:2]))  # 두 번째 파일에서 latitude, longitude 사용
        data1.append(parts1)
        data2.append(parts2)

data1 = np.array(data1)
data2 = np.array(data2)
e = [[],[]]
error= []
# 두 파일의 각 행마다의 오차를 계산합니다.

for i in range(len(data1)):
    e[0].append(data1[i][0] - data2[i][0])
    e[1].append(data1[i][1] - data2[i][1])
for i in range(len(e[0])):
    error.append(sqrt(e[0]e[]))
# 오차를 플롯합니다.
plt.figure(figsize=(10, 6))
plt.plot(errors, marker='o', linestyle='-')
plt.title('Error between corresponding rows of two files')
plt.xlabel('Index')
plt.ylabel('Error (Euclidean distance)')
plt.grid(True)
plt.show()