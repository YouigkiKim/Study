
# 원본 파일을 읽습니다.
with open('/Users/youngki/study/Ailab/Project/presentation/raw_data/waypoint_result.txt', 'r') as file:
    lines = file.readlines()
    for i in range(0, len(lines), 2):
        pose_lines.append(lines[i].replace('pose ', '').strip() + '\n')
        next_lines.append(lines[i+1].replace('next ', '').strip() + '\n')

# pose 데이터를 파일에 씁니다.