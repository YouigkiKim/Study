# '''
# ~~
# ~~~
# '''
# 여러줄 주석처리하기

#들여쓰기
n=10
if n%2==0: #%나머지연산자, if, else문에서 뒤에 : 붙이기
    print('even')
    print('짝수')
else :
    print('0dd')
    print('홀수')

#input
print('hi','hello')
name = input('input your name')
print('안녕하세요',name,'님')

#method 앞의 것을 수정하는 연산자. ex) .split('.d') << ,기준으로 놔둠 초기값 공백
text = input('날짜 입력 yyyy.mm.dd')
y,m,d=text.split('.')
y=int(y)
m=int(m)
d=int(d)
print(text,y,m,d)

#맵을 써서 한줄로 줄이기
y,m,d = map(int,input('yyyy.mm.dd입력').split('.'))


y,m,d = map(int,input('yyyy.mm.dd입력').split('.'))
#map(함수,집합 형태-iterable 객체)
a,b,c=map(int,['1','2','3'])
print(a,b,c,a+b+c)


#숫자와 문자 같이 출력하기
x=3
y=5
#(1)숫자와 문자를 함께 출력하기
print(str(x)+'과'+str(y)+'의 합은 '+str(x+y)+'이다.')
#(2)숫자와 문자 함께 출력하기 (2) end=''
print(x,end='')
print('과',end='')
print(str(y)+'의 합은')
#(3)format()사용하기
print('{}과 {}의 합은 {}이다'.format(x,y,x+y))

#python 연산자 및 우선순위
# 산술 > 관계 > 논리
#산술 **지수 *곱 /나누기 //몫 %나머지
#관계 < <= > >= == !=
#논리 not x , x and y , x or y
print(2*5>2+5 and not 3*3>10)

#주요 연산공식
#반올림 round(a) rount(a,b)  소수b자리까지 반올림
print(round(3.33))
print(round(3.66))
print(round(3.66,1))
#제곱 : pow(a,b) = **
#나눗셈 : divmod(7,2) => 7나누기 2를 한 후 몫과 나머지 반환
a,b = divmod(7,2) #a=몫 b=나머지
#최대 최소 max(), min()

#문자열
#문자열다루기
text='abc'
print(text)
print(text[0])
print(text[1])
print(text[2])
print(text[0:3])
print(text[-3:-1])

#문자열 메서드
text = 'abcde'
#1. 출력 지정 : format(a,b,c,...)
k='abc{}'
print(k.format(text))

#2. 대체하기 : replace(a,b)
print(text.replace('abc','KKK'))

#3. 자르기 : split(a)
text2='a/b/c a.b.c'
print(text2.split('.'))
print(text2.split())
print(text2.split('/'))

#4. 합치기 : .join() 앞의 문자를 ()안의 텍스트 사이사이에 넣어줌
print('/'.join(text))
#결과 : a/b/c/d/e

#5. 개수확인하기 : .count('찾고싶은문자') 찾고싶은 문자의 개수 알려줌
print(text.count('a'))

#6. 제거하기 : strip() / lstrip() / rstrip()
#lstrip 왼쪽 자르기 rstrip 오른쪽만 제거 중간값은 제거 불가
text3 = '**abc***de***'
print(text3.strip('*'))
print(text3.lstrip('*'))
print(text3.rstrip('*'))

#7. 인덱스 번호찾기 : find() / rfind() / index() / rindex() // 왼쪽부터/오른쪽부터
text4 = 'abc abc'
print(text4.find('a'))
print(text4.rfind('a'))
print(text4.index('a'))
print(text4.rindex('a'))

#8. 확인하기 : true or false 반환
# isalpha() / isdigit() / isalnum() / isupper() / islower()
# 알파벳만    / 숫자만      / 알파벳or숫자/ 대문자      / 소문자

#9. 대소문자 만들기 : upper() / lower()
text5 = 'ABCde'
print(text5.upper())
print(text5.lower())

#10. 0 codnrl : zfiil()
y='2020'
m='3'
d='1'
print(y.zfiil(4))
print(m.zfiil(2))
print(d.zfiil(2))


#제어문
# if 문
num = 10
if num>0:
    print('{}은 10입니다.'.format(num))

# while 문 특정 조건을 만족할 때 반복실행
a=0
while a<10:
    print(a)
    a=a+1
#while문 특징 : 조건문에 숫자만 있는경우 양수는 true 음수는 false. 양수면 while문 동작
    
text = 'yes'
while text == 'yes':
    text=input('yes입력 시 반복')
print('종료')

text=input('e또는 E 입력 시 종료')
while text != 'e'and text != 'E':
    text = input('e 또는 E 입력 시 종료')
print('종료')

# for 문 : for 변수 in 열거형 :
# range() 함수 range(a) 0~a-1까지 1씩 증가, r(ange(a,b) a~b-1 까지 1씩 증가, range(a,b,c) a~b-1 까지 c씩 증가
# 0~4
print(list(range(5)))
# 1~10
print(list(range(1,11)))
# 3 6 9
print(list(range(3,9+1,3)))
#10 5 0 -5 -10
print(list(range(10,-11,-5)))

#for문 + range()
n=int(input('n'))
for i in range(n,-1,-1):
    print(i)

# continue break pass
# continue 해당 단계 건너뛰기 / break 반복문 멈추기 / pass 아무것도 안하기 << 제어문 안쪽을 비워두면 에러가 뜸 비어도 오류 안뜨게 하기 위함


#리스트
#메서드
# .index('') 위치 찾기/ .append('') 맨 끝에 추가하기 
# .insert(int,'') int위치에 ''넣기 / .remove('str') del ls[index] /
# '' in ls true or false '' 있냐 없냐 / len() 전체 개수 / ls.count('a') a개수찾기
# .sort() 오름차순 정렬  / .sort(reverse = True) 내림차순 정렬 / .reverse() 역순 정렬 / 
lsalpha = ['a','b','c','d','e']
print(lsalpha.index('c'))