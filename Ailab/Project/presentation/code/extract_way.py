import re

# 입력 파일 경로
input_file_path = '/Users/youngki/Downloads/waypoint_xyyaw_1m.txt'
# 출력 파일 경로
output_file_path = '/Users/youngki/Downloads/waypoint_xyyaw_opt_output.txt'

with open(input_file_path, 'r') as infile, open(output_file_path, 'w') as outfile:
    for line in infile:
        match = re.search(r'Location\(x=([-\d.]+), y=([-\d.]+), z=[-\d.]+\), Rotation\(pitch=[-\d.]+, yaw=([-\d.]+), roll=[-\d.]+\)', line)
        if match:
            x, y, yaw = match.groups()
            # 각 행의 마지막 숫자(opt)를 추출합니다.
            opt_match = re.search(r'(\d+)$', line)
            opt = opt_match.group(1) if opt_match else '0'
            # x y yaw opt 형식으로 출력합니다.
            outfile.write(f"{x} {y} {yaw} {opt}\n")

print(f"처리 완료. 결과는 '{output_file_path}'에 저장되었습니다.")