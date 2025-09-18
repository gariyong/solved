# 문제 : https://www.acmicpc.net/problem/9466
# 제목 : 텀 프로젝트

mport sys

sys.setrecursionlimit(10**6)

def dfs(idx):
    global cnt
    visit[idx] = True
    stack.add(idx)
    next_node = graph[idx]
    
    if not visit[next_node]:
        dfs(next_node)
    elif next_node in stack:
        while next_node != idx:
            cnt += 1
            visit[next_node] = True
            next_node = graph[next_node]
        cnt += 1
        visit[idx] = True
    
    stack.remove(idx)

T = int(input())

for _ in range(T):
    n = int(input())
    
    graph = [0] + list(map(int,input().split()))
    visit = [False] * (n + 1)
    cnt = 0
    
    for i in range(1, n + 1):
        if not visit[i]:
            stack = set()
            dfs(i)
    
    print(n - cnt)