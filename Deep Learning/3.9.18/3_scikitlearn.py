from matplotlib.colors import ListedColormap
import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets
from sklearn.svm import SVC

# 데이터셋 불러오기
iris = datasets.load_iris()
X = iris.data[:,[2,3]]
y = iris.target

# 학습데이터, 테스트데이터 나누기
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.3, random_state=1, stratify = y)

# 표준화
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
sc.fit(X_train)
X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_test)

# 퍼셉트론 instance지정
from sklearn.linear_model import Perceptron
ppn = Perceptron(eta0 = 0.1, random_state=1)
# 학습
ppn.fit(X_train_std, y_train)
# 예측
y_pred = ppn.predict(X_test_std)
# 정확도 계산
from sklearn.metrics import accuracy_score
print('accuracy: %.3f' %accuracy_score(y_test, y_pred))
print('accuracy: %.3f' %ppn.score(X_test_std, y_test))


# 그래프 그리기
def plot_decision_regions(X, y, classifier,test_idx=None, resolution = 0.02):
    markers = ('o','s','^','v','<')
    colors = ('red', 'blue', 'lightgreen', 'gray', 'cyan')
    cmap = ListedColormap(colors[:len(np.unique(y))])

    x1_min, x1_max = X[:,0].min() - 1, X[:,0].max()+1
    x2_min, x2_max = X[:,1].min() -1, X[:,1].max()+1
    xx1, xx2 = np.meshgrid(np.arange(x1_min, x1_max, resolution),
                           np.arange(x2_min, x2_max, resolution))
                           
    lab = classifier.predict(np.array([xx1.ravel(), xx2.ravel()]).T)
    lab = lab.reshape(xx1.shape)
    plt.contourf(xx1, xx2, lab, alpha=0.3, cmap = cmap)
    plt.xlim(xx1.min(), xx1.max())
    plt.ylim(xx2.min(), xx2.max())
    
    # enumerate(list) > 반복가능 객체의 인덱스, 값 추출
    '''
    np.unique()함수를 통해 y의 고유값(꽃의 종류)를 추출한 후 
    for문을 사용해 각 꽃의 종류마다 plt.scatter에 산점도를 그림
    '''
    for idx, cl in enumerate(np.unique(y)):
        plt.scatter(x = X[y == cl,0],
                     y=X[y == cl, 1],
                     alpha = 0.8,
                     c=colors[idx],
                     marker=markers[idx],
                     label=f'Class {cl}',
                     edgecolor = 'black')
    if test_idx:
        X_test, y_test = X[test_idx,:], y[test_idx]

        plt.scatter(X_test[:,0], X_test[:,1],
                    c='none', edgecolor='black', alpha=1.0,
                    linewidth=1, marker='o',
                    s=100, label='Test set')

X_combined_std = np.vstack((X_train_std, X_test_std))
y_combined = np.hstack((y_train, y_test))
# plot_decision_regions(X=X_combined_std,
#                       y=y_combined,
#                       classifier=ppn,
#                       test_idx=range(105,150))

# plt.xlabel('Petla length [standardized]')
# plt.ylabel('Petal width [Standardized]')
# plt.legend(loc = 'upper left')
# plt.tight_layout()
# plt.show()

print('accuracy: %.3f'%ppn.score(X_test_std, y_test))


#로지스틱을 사용한 이진분류모델
class LogisticRegressionGD:
    def __init__(self, eta=0.01, n_iter=50, random_state=1):
        self.eta = eta
        self.n_iter=n_iter
        self.random_state = random_state

    def fit(self, X, y):
        rgen = np.random.RandomState(self.random_state)
        self.w_ = rgen.normal(loc=0.0, scale=0.01, size=X.shape[1])
        self.b_ = np.float_(0.)
        self.losses_ = []
        for i in range(self.n_iter):
            net_input = self.net_input(X)
            output = self.activation(net_input)
            errors = (y-output)
            self.w_ += self.eta * 2.0 * X.T.dot(errors) / X.shape[0]
            self.b_ += self.eta * 2.0 * errors.mean()
            loss = (-y.dot(np.log(output))
                    - ((1-y).dot(np.log(1-output)))
                    / X.shape[0])
            self.losses_.append(loss)
        return self
    
    def net_input(self, X):
        return np.dot(X, self.w_) + self.b_
    
    def activation(self, z):
        return 1./(1.+np.exp(-np.clip(z, -250, 250)))
    
    def predict(self, X):
        return np.where(self.activation(self.net_input(X)) >= 0.5, 1, 0)

X_train_01_subset = X_train_std[(y_train == 0)| (y_train == 1) ]
y_train_01_subset = y_train[(y_train ==0)| (y_train ==1)]
lrgd = LogisticRegressionGD(eta=0.3, n_iter=1000, random_state=1)
lrgd.fit(X_train_01_subset, y_train_01_subset)
# plot_decision_regions(X=X_train_01_subset,y=y_train_01_subset,classifier=lrgd)
# plt.xlabel('Petal length')
# plt.ylabel('Petal width')
# plt.legend(loc='upper left')
# plt.tight_layout()
# plt.show()


from sklearn.svm import SVC
svm = SVC(kernel='linear', C=1.0, random_state=1)
svm.fit(X_train_std, y_train)
# plot_decision_regions(X_combined_std,
#                       y_combined,
#                       classifier=svm,
#                       test_idx = range(105,150))
# plt.xlabel('Petal length [standardized]')
# plt.ylabel('Petal width [standardized]')
# plt.legend(loc = 'upper left')
# plt.tight_layout()
# plt.show()

#SVM
svm = SVC(kernel='rbf', random_state=1, gamma=0.10, C=10.0)
svm.fit(X_train_std, y_train)
# plot_decision_regions(X_combined_std, y_combined, classifier=svm,
#                       test_idx=range(105,150))
# plt.xlabel('Petal length [std]')
# plt.ylabel('Petal width [std]')
# plt.title('gamma=0.10')
# plt.tight_layout()
# plt.show()

svm = SVC(kernel='rbf', random_state=1, gamma=100, C=10.0)
svm.fit(X_train_std, y_train)
# plot_decision_regions(X_combined_std, y_combined, classifier=svm,
#                       test_idx=range(105,150))
# plt.xlabel('Petal length [std]')
# plt.ylabel('Petal width [std]')
# plt.title('gamma=100')
# plt.tight_layout()
# plt.show()


# 결정트리를 이용한 분류

from sklearn.tree import DecisionTreeClassifier
tree_model = DecisionTreeClassifier(criterion='gini',
                                    max_depth = 4,
                                    random_state=1)
tree_model.fit(X_train,y_train)
X_combined = np.vstack((X_train,X_test))
y_combined = np.hstack((y_train, y_test))
plot_decision_regions(X_combined,
                      y_combined,
                      classifier = tree_model,
                      test_idx = range(105,150))
plt.xlabel('Petal length [cm]')
plt.ylabel('Petal width [cm]')
plt.tight_layout()
plt.show()

from sklearn import tree
feature_names = ['Sepal length', 'Sepal width',
                 'Petal length', 'Sepal width']
tree.plot_tree(tree_model,
               feature_names = feature_names,
               filled=True)
plt.show()
                
#랜덤 포레스트
from sklearn.ensemble import RandomForestClassifier
forest = RandomForestClassifier(n_estimators=25,
                                random_state=1,
                                n_jobs=2)
forest.fit(X_train, y_train)
plot_decision_regions(X_combined,y_combined,
                      classifier=forest, test_idx = range(105,150))
plt.xlabel('Petal length [cm]')
plt.ylabel('Petal width [cm]')
plt.legend(loc='upper left')
plt.show()

from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors=5, p=2,metric='minkowski')
knn.fit(X_train_std, y_train)
plot_decision_regions(X_combined_std,y_combined,classifier=knn, test_idx=range(105,150))
plt.xlabel('Petal length [cm]')
plt.ylabel('Petal width [cm]')
plt.legend(loc='upper left')
plt.tight_layout()
plt.show()