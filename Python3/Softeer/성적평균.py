# n명의 학생과 k개의 구간 각 구간마다 평균출력
# 출력값은 소수점 2자리까지

n,k = input().split()
n=int(n)
k=int(k)
score_str=input().split()
# 1. list comprehension(리스트 내포)를 사용해 str을 모두 int로 변환
score =[float(i) for i in score_str]
# 2. map함수사용
#   map 함수 사용시 map객체로 반환되므로 list로 변환해주는 list()함수 사용
score2 = list(map(float, score_str))
K=[]

# K구성방법1
for i in range(k):
    r=input().split()
    r=[int(j) for j in r]
    #행렬을 .append하면 행렬이 그대로 추가됨
    K.append(r)
# K구성방법2 > 여러 함수와 메서드를 겹쳐 한줄로 처리 가능
for i in range(k):
    K.append(list(map(int,input().split())))

# 평균값출력1
for i in range(k):
    sum1=0
    for j in range(K[i][0]-1,K[i][1]):
        sum1=sum1+score[j]
    #소수점2째자리에서 반올림 round(값,자릿수)
    print(round(sum1/(K[i][1]-K[i][0]+1),2))
    #소수점 지정자리수까지 포매팅 문제에서는 2번째자리까지 표기
    print("{:.2f}".format((sum1/(K[i][1]-K[i][0]+1))))

# 평균값 출력2 한줄로 축소
for i in range(k):
    #"{:,2f}".format >> 소수점2째자리까지 표기
    #score[K[i][0]-1:K[i][1]] 는 변수지정을 해도 되나 1줄로 축약가능을 표현하기 위해 아래와같이표현
    #메모리의 사용과 중복연산의 trade off 관계. 이는 데이터셋의 크기와 연산량을 비교해 적절히 선택
    print("{:.2f}".format(sum(score[K[i][0]-1:K[i][1]])/len(score[K[i][0]-1:K[i][1]])))

#파이썬에서 고차 행렬 출력방법 
print(K[1][0])
print(K)
