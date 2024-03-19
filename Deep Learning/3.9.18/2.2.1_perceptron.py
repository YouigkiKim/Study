import numpy as np

#단일 퍼셉트론의 동작 > 이진분류
class Pereptron:
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