# 파일을 읽고 pose와 next를 분리하는 Python 스크립트
pose_lines = []
next_lines = []

# 원본 파일을 읽습니다.
with open('/Users/youngki/study/Ailab/Project/presentation/raw_data/resasdaf.txt', 'r') as file:
    lines = file.readlines()
    for i in range(0, len(lines), 2):
        pose_lines.append(lines[i].replace('pose', '').strip() + '\n')
        next_lines.append(lines[i+1].replace('next ', '').strip() + '\n')

# pose 데이터를 파일에 씁니다.
with open('pose_interpolation.txt', 'w') as pose_file:
    pose_file.writelines(pose_lines)

# next 데이터를 파일에 씁니다.
with open('next_interpolation.txt', 'w') as next_file:
    next_file.writelines(next_lines)