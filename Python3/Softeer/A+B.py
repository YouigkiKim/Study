# 문제 : T개의 케이스 조건을 입력받아 Case #n: A+B출력하기
# A B의 input은 A B 
# n은 1부터 시작

T=int(input())
A=[]
B=[]

for i in range(T):
    case = input()
    a,b = case.split()
    A.append(int(a))
    B.append(int(b))
    
for i in range(T):
    print('Case #{}:'.format(i+1),A[i]+B[i])

# 정리
# 빈 리스트를 만들어 입력값을 처리한 후 리스트에 추가하는 문제
# 문제의 출력에서 print를 여러가지 할 때 ,를 사용하면 자동으로 띄어쓰기됨
# .append, .format, .split()의 메서드를 활용해 텍스트 처리 메서드로 해결