## 입력부분 1: printPoly 함수 구현 
def printPoly(p_x) :
	term = len(p_x) - 1	# 최고차항 숫자 = 배열길이-1
	polyStr = "P(x) = "
	
	#여기부터 작성하기
	for coef in p_x:
		if coef == 0 :
			term = term - 1
			continue
		if polyStr != 'P(x)=' and coef > 0:
			polyStr += '+'
		
		if term == 1:
			polyStr += str(coef) + 'x'
		else:
			polyStr +=str(coef) + 'x^'+ str(term)
			term = term - 1
	#여기까지 작성하기

	return polyStr

## 전역 변수 선언 부분 ## 
px = [7, -4, 0, 5]			# = 7x^3 -4x^2 +0x^1 +5x^0 

## 메인 코드 부분 ## 
pStr = printPoly(px)
print(pStr)