import os
import pandas as pd
# pandas에서 파일 불러오기
path = os.path.dirname(__file__)
csv_file_path = os.path.join(path,"iris.csv")
df = pd.read_csv(csv_file_path)


# matplotlib으로 0열, 1열특성을 사용해 매핑하기
import matplotlib.pyplot as plt
import numpy as np
y = df.iloc[0:100,4].values
y=np.where(y=='Iris-setosa',0,1)
X = df.iloc[0:100,[0,2]].values
plt.scatter(X[:50,0],X[:50,1],color='red',marker='o',label='Setosa')
plt.scatter(X[50:100,0],X[50:100,1],color='blue',marker='s',label='Versicolor')
plt.xlabel('Sepal length [cm]')
plt.ylabel('Petal length [cm]')
plt.legend(loc='upper left')
plt.show()

import numpy as np

#단일 퍼셉트론의 동작 > 이진분류
class Perceptron:
    def __init__(self, eta=0.01, n_iter=50, random_state=1):
        self.eta=eta
        self.n_iter=n_iter
        self.random_state=random_state

    def fit(self, X, y): #X feature y target
        rgen = np.random.RandomState(self.random_state) #난수생성 > 대칭성꺠기, 과적합방지, 학습속도개선, 재현가능성(시드값기준으로)
        # .normal(평균, 표준편차, 난수 개수)
        # .shape > numpy의 메서드, 차원을 return 2차원에서 1차원의 1행의 크기를 나타내므로 1차원
        self.w_=rgen.normal(loc=0.0, scale=0.01, size=X.shape[1]) #size > 특성의 개수
       
        self.b_ = np.float_(0.) #부동소수점으로 표현하기위해 np.float_(0.) 메서드 사용
        
        self.errors_=[]
        #_은 반복변수 없이 단순반복을 위해
        for _ in range(self.n_iter):
            errors=0
            for xi, target in zip(X,y): #X는 각 featuredml 배열, y는 target
                update = self.eta*(target - self.predict(xi))
                self.w_ += update * xi
                self.b_ += update
                errors += int(update != 0.0)
            self.errors_.append(errors)
        return self
    
    def net_input(self,X):
        return np.dot(X, self.w_) + self.b_ # w*X+b > 예상값
    
    def predict(self, X):
        return np.where(self.net_input(X) > 0.0, 1, 0) # net_input이 임계값보다 클 경우 1출력
    
ppn = Perceptron(eta=0.1,n_iter=10)
ppn.fit(X,y)
plt.plot(range(1,len(ppn.errors_)+1),ppn.errors_,marker='o' )
plt.xlabel('Epochs')
plt.ylabel('Number of updates')
plt.show()

from matplotlib.colors import ListedColormap

# x,y,축 범위 설정 후 경계를 기준으로 다른 색으로 표시하기
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


# plot_decision_regions함수를 사용해 plot생성
plot_decision_regions(X, y, classifier=ppn)
plt.xlabel('Sepal length [cm]')
plt.ylabel('Petal length [cm]')
plt.show()


# Adaline
class Adaline:
    def __init__(self, eta=0.01, n_iter=50, random_state=1):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state

    def fit(self, X, y):
        rgen  = np.random.RandomState(self.random_state)
        self.w_ = rgen.normal(loc=0.0, scale=0.01, size=X.shape[0])
        self.b_ = np.float_(0.)
        self.losses_ = []
        for i in range(self.n_iter):
            net_input = self.net_input(X)
            output= self.activation(net_input)
            errors = (y - output)
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

fig, ax = plt.subplots(nrows = 1, ncols=2, figsize=(10,4))
ada1 = Adaline(n_iter=15, eta=0.1).fit(X,y)
ax[0].plot(range(1, len(ada1.losses_)+1), np.log10(ada1.losses_), marker = 'o')
ax[0].set_xlable = 'Epochs'
ax[0].set_ylabel('log(MSE)')
ax[0].wt_title('Adaline - Learning rate 0.1')
ada2 = Adaline(n_iter = 15, eta = 0.0001).fit(X,y)
ax[1].plot(range(1, len(ada2.losses_) +1), ada2.losses_, marker = 'o')
ax[1].set_xlabel('Epochs')
ax[1].set_ylabel('MSE')
ax[1].set_title('Adaline - Learning rate 0.0001')
plt.show()