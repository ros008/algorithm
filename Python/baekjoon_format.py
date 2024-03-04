# 공백을 기준으로 구분된 데이터를 입력 받을 때
data = list(map(int, input().split()));

# 공백을 기준으로 구분된 데이터가 많지 않다면
a, b, c = map(int, input().split());

# 파일 입출력
import sys
sys.stdin = open("input.txt", "r");

# 공백으로 구분된 2개의 숫자 입력 받기
N, M = map(int, sys.stdin.readline().split());

# 2차원 리스트 입력 받기
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# N x M 크기의 이차원 리스트 초기화 및 입력받기
visited = [[False]*m for _ in range(n)]
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

# 문자열 입력 받기
data = sys.stdin.readline().rstrip()

# 여러줄 입력, 몇 줄이 입력될지 아는 경우
N = int(input)

for i in range(N):
    A, B = map(int, input().split())
    
    print(A + B)
    
# 여러줄 입력, 몇 줄이 입력될지 모르는 경우
while True:
    try:
        A, B = map(int, input().split())
        
        print(A + B)
    except:
        break
    
# 출력 시
answer = 5
print(f"정답은 {answer} 입니다.")

result = [1, 2, 3]
print(result)
for i in range(len(result)):
    print(result[i], end=' ')
print(*result)



