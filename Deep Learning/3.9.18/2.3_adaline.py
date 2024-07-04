import numpy as np

#.T = tranpose
#.float_ 64비트 부동소수점 .float32 32비트 부동소수점
#.shape 는 차원의 크기를 차수대로 반환 3x4x5 > (3, 4, 5)

"""
Adaline

'결과값'을 토대로 가중치, 상수 수정, 분류예측, 전체 훈련 데이터셋으로 한번에 가중치계산 
<-> perceptron은 분류 후(계단함수 적용) 가중치, 상수 수정, 각각의 데이터셋마다 가중치계산

__init__, fit, activation, predict, net_input

.fit(self, X, y)
    난수생성기로 w_설정, b_ 64비트 부동소수점 0.0, losses선언
    n_iter의 크기만큼 반복문동작
        예측값 도출, 활성함수 적용(아달린에서 y=x)
        에러 추출
        에러를 토대로 w_, b_ 업데이트
        mse 도출 후 losses_ arr에 업데이트

이외에도 활성함수, y도출함수, 예측함수 선언
"""
# Adaline 학습모델
class Adaline:
    def __init__(self, eta=0.01, n_iter=50, random_state=1):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state

    def fit(self, X, y):
        rgen  = np.random.RandomState(self.random_state)
        self.w_ = rgen.normal( loc=0.0, scale=0.01, size=X.shape[1])
        self.b_ = np.float_(0.)
        self.losses_ = []
        for i in range(self.n_iter):
            net_input = self.net_input(X)
            output= self.activation(net_input)
            errors = (y-output)
            self.w_ += self.eta * 2.0 * X.T.dot(errors) / X.shape[0] 
            self.b_ += self.eta * 2.0 * errors.mean()
            loss = (errors**2).mean()
            self.losses_.append(loss)
        return self
    
    def net_input(self, X):
        return np.dot(X, self.w_) + self.b_
    
    def activation(self, X):
        return X
    
    def predict(self, X):
        return np.where(self.activation(self.net_input(X)) >= 0.5, 1, 0)

#iris에서 2열의 데이터를 특성으로 사용
import os
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap

path = os.path.dirname(__file__)
csv_file_path = os.path.join(path,"iris.csv")
df = pd.read_csv(csv_file_path)
y = df.iloc[0:100,4].values
y=np.where(y=='Iris-setosa',0,1)
X = df.iloc[0:100,[0,2]].values

"""
적절한 학습률 선택의 필요성 시각화
학습률이 너무 큰 경우 발산(plot1)
학습률이 너무 작은경우 수렴이 오래걸림(plot2)
"""
fig, ax = plt.subplots(nrows = 1, ncols=2, figsize=(10,4))
ada1 = Adaline(n_iter=15, eta=0.1).fit(X,y)
ax[0].plot(range(1, len(ada1.losses_)+1), np.log10(ada1.losses_), marker = 'o')
ax[0].set_xlable = 'Epochs'
ax[0].set_ylabel('log(MSE)')
ax[0].set_title('Adaline - Learning rate 0.1')
ada2 = Adaline(n_iter = 15, eta = 0.0001).fit(X,y)
ax[1].plot(range(1, len(ada2.losses_) +1), ada2.losses_, marker = 'o')
ax[1].set_xlabel('Epochs')
ax[1].set_ylabel('MSE')
ax[1].set_title('Adaline - Learning rate 0.0001')
plt.show()

#데이터 표준화
X_std = np.copy(X)
X_std[:,0] = (X[:,0] - X[:,0].mean()) / X[:,0].std()
X_std[:,1] = (X[:,1] - X[:,1].mean()) / X[:,1].std()

def plot_decision_regions(X,y,classifier,resolution=0.02):
    #튜플을 사용해 색과 마커의 배열을 고정시키고 불러다씀
    markers=('o','s','^','<')
    colors=('red','blue','lightgreen','gray','cyan')
    # ListedColormap컬러맵 생성하는 메서드
    # np.unique 중복값 제거하고 고유값 반환 [1,1,2,2,3,3,] > [1,2,3]
    # 분류해야되는 가짓수만큼의 컬러맵을 만들기 위해 np.unique사용하고 listedcolormap으로 컬러맵 생성
    cmap = ListedColormap(colors[:len(np.unique(y))])
    # 그래프의 x,y범위 설정하는 코드들 x1은 x축, x2는 y축으로 표현됨
    x1_min, x1_max = X[:, 0].min() - 1,X[:,0].max() +1
    x2_min,x2_max = X[:,1].min()-1, X[:,1].max() +1
    # meshgrid생성, x축과 y축 반환 2차원 시각화할 떄 사용
    xx1,xx2 = np.meshgrid(np.arange(x1_min,x1_max,resolution),np.arange(x2_min,x2_max,resolution))
    # 학습된 모델을 사용하여 예측하기 classifier는 perceptron으로 학습한 최종 인스턴스가 입력됨 > ppn
    lab = classifier.predict(np.array([xx1.ravel(), xx2.ravel()]).T)
    #lab의 배열을 특성들과 동일하게 하기 위해 xx1의 shape를 확인하고 이에 맞게 reshape함
    lab = lab.reshape(xx1.shape)
    # plt.contourf 등고선 그리는 메서드 .meshgrid를 통해 생성된 x,y입력, alpha: 투명도 0~1.0, 
    # cmap(변수) > 컬러맵 지정, cmap(입력값) > 기본 컬러맵
    plt.contourf(xx1,xx2,lab,alpha=0.3,cmap=cmap)
    plt.xlim(xx1.min(),xx1.max())
    plt.ylim(xx2.min(),xx2.max())

    # enumerate > 순회가능한 객체를 순회하며 순차적으로 인덱스와 값 반환
    # 각 카테고리마다 scatter의 속성 부여(색, 마커, 클래스 이름)
    for idx,cl in enumerate(np.unique(y)):
        plt.scatter(x=X[y==cl,0],
                    y=X[y==cl,1],
                    alpha=0.8, #투명도 0.8
                    c=colors[idx], #분류해야 되는 순차적으로 색깔배분
                    marker=markers[idx], #마커도 순서대로 배분
                    # f-문자열을 사용하면 {}안에 변수사용가능
                    label=f'Class{cl}',
                    edgecolor='black')

# 특성이 표준화된 분류표
ada_gd = Adaline(n_iter = 20, eta = 0.5)
ada_gd.fit(X_std, y)
plot_decision_regions(X_std, y, classifier=ada_gd)
plt.title('Adaline - Gradient desent')
plt.xlabel('Sepal length [standardized]')
plt.ylabel('Petal length [Standardized]')
plt.legend(loc = 'upper left')
plt.tight_layout()
plt.show()
#표준화된 데이터의 반복횟수에 따른 MSE > 10회정도에 수렴
plt.plot(range(1, len(ada_gd.losses_)+1), ada_gd.losses_, marker = 'o')
plt.xlabel('Epochs')
plt.ylabel('MSE')
plt.tight_layout()
plt.show()

#확률적 경사하강
class AdalineSDG:
    def __init__(self, eta = 0.01, n_iter = 10, shuffle = True, random_state = None):
        self.eta = eta
        self.n_iter = n_iter
        self.w_initialized = False
        self.shuffle = shuffle
        self.random_state = random_state

    def fit(self, X, y):
        self._initialize_weights(X.shape[1])
        self.losses_=[]
        for i in range(self.n_iter):
            if self.shuffle:
                X, y  =self._shuffle(X,y)
                losses = []
                for xi, target in zip(X,y):
                    losses.append(self._update_weights(xi,target))
                avg_loss = np.mean(losses)
                self.losses_.append(avg_loss)
        return self
    
    def partial_fit(self, X, y):
        if not self.w_initialized:
            self._initialize_weights(X.shape[1])
            if y.ravel().shape[0] > 1:
                for xi, target in zip(X,y):
                    self._update_weights(xi,target)
            else:
                self._update_weights(X,y)
        return self
    
    def _shuffle(self, X, y):
        r = self.rgen.permutation(len(y))
        return X[r], y[r]
    
    def _initialize_weights(self,m):
        self.rgen = np.random.RandomState(self.random_state)
        self.w_ = self.rgen.normal(loc = 0.0, scale = 0.01, size = m)
        self.b_ = np.float_(0.)
        self.w_initialized = True
    
    def _update_weights(self, xi, target):
        output = self.activation(self.net_input(xi))
        error = (target - output)
        self.w_ += self.eta*2.0*xi*(error)
        self.b_ += self.eta*2.0*(error)
        loss = error**2
        return loss
    
    def net_input(self, X):
        return np.dot(X,self.w_) + self.b_
    
    def activation(self, X):
        return X
    
    def predict(self, X):
        return np.where(self.activation(self.net_input(X)) >= 0.5, 1, 0)

ada_sgd = AdalineSDG(n_iter = 15, eta = 0.01, random_state = 1)
ada_sgd.fit(X_std, y)
plot_decision_regions(X_std, y, classifier = ada_sgd)
plt.title('Adaline - Stochastic gradient descent')
plt.xlabel('Sepal length[standardized]')
plt.ylabel('Petal length[standardized]')
plt.legend(loc = 'upper left')
plt.tight_layout()
plt.show()
plt.plot(range(1, len(ada_sgd.losses_)+1), ada_sgd.losses_, marker = 'o')
plt.xlabel('Epochs')
plt.ylabel('Average loss')
plt.tight_layout()
plt.show()