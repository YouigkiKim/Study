from matplotlib.colors import ListedColormap
import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets


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

# 사이킷 런에서 로지스틱 회귀 
# convex optimization(볼록 최적화)를 위한 solver
#   'newton-cg', 'lbfgs', 'liblinear', 'sag', 'saga'
''' 각 솔버에 대한 설명
Newton-CG: 뉴턴 방법 기반의 솔버로, 대규모 데이터셋에 적합하며, 정확도가 높지만 계산 비용이 큰 편입니다.
LBFGS (Limited-memory Broyden-Fletcher-Goldfarb-Shanno): 메모리를 적게 사용하는 솔버로, 대규모 데이터셋에 적합하며, 비교적 효율적입니다.
Liblinear: 소규모 데이터셋에 적합한 솔버로, 선형 분류 문제에 주로 사용됩니다.
SAG (Stochastic Average Gradient): 대규모 데이터셋에 적합하며, 빠른 수렴 속도를 제공하지만 미세 조정이 필요할 수 있습니다.
SAGA: SAG의 변형으로, L1 정규화를 지원하며, 일반적으로 더 안정적인 수렴을 제공합니다.
'''
from sklearn.linear_model import LogisticRegression
lr = LogisticRegression(C=100.0, solver = 'lbfgs', multi_class='ovr')
lr.fit(X_train_std, y_train)

X_combined_std = np.vstack((X_train_std, X_test_std))
y_combined = np.hstack((y_train, y_test))

plot_decision_regions(X_combined_std,
                      y_combined,
                      classifier=lr,
                      test_idx=range(105,150))

plt.xlabel('Petal length[standardized]')
plt.ylabel('Petal width [standardized]')
plt.tight_layout()
plt.show()