import matplotlib.pyplot as plt

# 파일에서 데이터를 읽어옵니다.
input_file_path = '/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_xyyaw_opt_output.txt'
input_file_path2 = '/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_lla_opt_output.txt'
input_file_path3 = '/Users/youngki/Downloads/global_plan_route.txt'
x_values = []
y_values = []

with open(input_file_path3, 'r') as file:
    for line in file:
        parts = line.split()
        if len(parts) >= 2:
            x_values.append(float(parts[0]))
            y_values.append(float(parts[1]))
x_values2 = []
y_values2 = []

with open(input_file_path2, 'r') as file:
    for line in file:
        parts = line.split()
        if len(parts) >= 2:
            x_values2.append(float(parts[0]))
            y_values2.append(-float(parts[1]))

# 데이터를 플로팅합니다.
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, marker='o', linestyle='-')


plt.title('XY Plot from Waypoints')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)

plt.figure(figsize=(10, 6))

plt.plot(x_values2, y_values2, marker='o', linestyle='-')

plt.title('XY Plot from Waypoints')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.show()

