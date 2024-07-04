#pandassms 엑셀형식의 파일 다룰 떄 쓰는 라이브러리
import pandas as pd

#첫 행은 제목 행, 각 행마다 제목행과 값들이 매치되어 저장됨
data = pd.read_csv('/Users/youngki/study/deep learning study/python3.8.18/gpascore.csv')

#.isnull()은 빈칸을 찾고 .sum()으로 개수 확인
#print(data.isnull().sum())
#.dropna()는 빈칸인 데이터를 없애줌
data = data.dropna()

#data에서 열 확인하는 방법 -> data['열 이름']
#.min()최소값, .max() 최대값, .count() 열에있는 개수 세어줌
#print(data['gpa'])

#.values >> 값으로 저장해줌
admit = data['admit'].values
lendata = []

#.iterrow() -> pandas의 데이터프레임에 사용할 수 있는 메서드 한 줄씩출력할 수 있다
#python의 for문은 두가지 반복변수를 쓸 수 있다
for i, rows in data.iterrows() :
    #.append를 사용해 학습데이터 추가
    lendata.append([rows['gre'],rows['gpa'],rows['rank']])

#print(lendata) #lendata 제대로 형성됐는지 확인

#파이썬에서 행렬 벡터연산할 때 많이 쓰는 라이브러리
import numpy as np
import tensorflow as tf 

#영어점수와 학점을 가지고 학교 붙을 확률 계산

#keras 는 딥러닝 도와주는 도구
#Sequential 은 신경망 레이어들 쉽게 만들어줌
#.Dense()는 노드개수와 활성함수(sigmoid,tanh,relu,softmax,leakRelu)
#sigmoid -> 결과가 0과1사이, tanh는 -1~+1
model = tf.keras.models.Sequential([
    tf.keras.layers.Dense(64, activation='tanh'),
    tf.keras.layers.Dense(128, activation='tanh'),
    tf.keras.layers.Dense(1, activation='sigmoid'),
   ]) 

#compile()
#optimizer -> c learning rate 조정해주는 함수
#loss function -> 손실함수. 최소제곱 등 binary_crossentropy는 확률 러닝할 때 쓰는 로스함수
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

#learning
#model.fit()의 첫 입력변수는 학습데이터, 두번째 입력변수는 실제 정답 세번째 epochs는 학습횟수
model.fit(np.array(lendata), np.array(admit), epochs=1000)

#예측
#.predict() 안에 학습데이터와 같은 개수의 입력값을 가지는 데이터들 집어넣으면 확률 예측해줌
predict = model.predict([[750, 3.70, 3], [400, 2.2, 1]])
print(predict)

# 요약
# 1.모델만들고
# 2.데이터집어넣고
# 3.새로운데이터 예측
# 딥러닝은 연구과정 실험을 통해 성능향싱이 중요
# 핛습이 제대로 되지 않은 경우 정확도가 75->52프로로 떨어지고 예측도 못함
# 이럴 땐 다시 돌려주면 됨