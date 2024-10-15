import pickle

# 피클 파일 경로 설정
file_path = 'result.pkl'

# 피클 파일 열기
with open(file_path, 'rb') as file:
    data = pickle.load(file)

# 로드된 데이터 확인
print(data)
