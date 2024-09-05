import tensorflow as tf

tall = [170,180,175,160]
size = [260,270,265,255]

#신발사이즈 추론
tall1 = 170
size1 = 260
a = tf.Variable(0.1)
b=tf.Variable(0.2)

#경사하강법을 통해 가중치 추론하는 도구
#.Adma() run sloely in M1 so use .legacy.Adam()
opt = tf.keras.optimizers.legacy.Adam() #Adam(learning_rate=??) can select learning rate

#손실함수 정의
def lossfunction():
    predict = tall1*a+b
    #.square or ^2 제곱값구하기
    return tf.square(size1 - predict) 

#opt.minimize( lossFunction<위에서 만들어서 대입 , var_list=[a,b] < 업데이트할 변수 목록들)
opt.minimize(lossfunction,var_list=[a,b])
print(a,b)

for i in range(300):
    opt.minimize(lossfunction,var_list=[a,b])
    print(a,b)
print(a.numpy(),b.numpy())
print(a.numpy()*tall+b.numpy())