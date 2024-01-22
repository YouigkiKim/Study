#3.8.18버전
import tensorflow as tf
#tensor >> 행렬의 형태라고 생각하면 될듯?
#.constant 상수설정, 값 변경 불가
tensor = tf.constant([3,3,4,5]) #리스트 형식을 빌려 여러가지 숫자 첨가
tensor2 = tf.constant ([2,4,6,4])
print(tensor)
print(tensor+tensor2)

#tensor 4칙연산 => 행렬연산
#.add(), .subtract(), .divide(),
# .multiply() << 엘리먼트끼리 곱, .matmul() << 행렬곱

zeross = tf.zeros(10)
zerosss = tf.zeros([2,2])
zerossss = tf.zeros([2,2,3]) #3개의 데이터를 담은 2*2행렬
print(zeross)
print(zerosss)
print(zerossss)
print(zerossss.shape) #.shape 데이터의 차원 보여줌 3차원 2,2,3 행렬 3개자료리스트 2개로 묶은게 2개있다.

#.cast() 자료형 변환

w = tf.Variable(1.0) #변수, 딥러닝에서 weight 대문자 V
print(w.numpy()) #.numpy를 통해 변수 쓰거나 변경
w.assign(2) #.assign >> 변수 수정
print(w.numpy())