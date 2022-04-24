# 트리
## 트리 (vs. 그래프)

- 트리는 그래프의 한 종류
- 방향 있음
- loop, 사이클 없음
- 한 개의 루트 노드만이 존재
- 루트 노드를 제외한 노드는 1개의 부모 노드를 가짐
- N개의 노드를 가진 트리는 항상 N-1개의 간선 가짐
- 임의의 두 노드 간의 경로는 유일

## [문제1. 839C Journey](https://codeforces.com/problemset/problem/839/C)

- 기댓값 구하기  
    <img src="https://user-images.githubusercontent.com/101321313/164987606-9ea0795a-9b20-4b5a-8d30-0395ed32733d.png" width="50%" height="50%">
    
- 그냥 child 기대값들 더하고 child 개수로 나눠주면 되는데, ‼️문제에서 주어진 경로는 parent-child가 아니다.‼️ 따라서 dfs를 한 번 돌면서 parent를 찾아야한다.
- 따라서 입력을 읽으면서 양쪽 노드에 모두 인접 리스트에 추가해주고, 한 번 dfs를 돌면서 parent를 적어주자.
- ⚠️ 항상 나눌때는 0으로 나누진 않는 지 확인하자.

## [문제2. 1336A Linova and Kingdom](https://codeforces.com/problemset/problem/1336/A)

### 문제

- There are 𝑛 cities and 𝑛−1 two-way roads connecting pairs of cities in the kingdom. From any city, you can reach any other city by walking through some roads. The cities are numbered from 11
 to 𝑛, and the city 11 is the capital of the kingdom. So, the kingdom has a tree structure. → 트리!

### 해결

- 직관적으로 생각해보면, 리프 노드에서 industry city가 되는 것이 당연히 좋을 것 같다.
- 하지만 항상 그런 건 아니다. 예를 들어 아래와 같은 경우, 1번을 선택(industry city로 선택)하면 -1+4=+3의 이득이지만, 2번을 선택하면 +1만 얻을 수 있다.  
    <img src="https://user-images.githubusercontent.com/101321313/164987614-891b316e-42f2-476e-97b6-ec5138c6c0d2.png" width="30%" height="30%">
    
- 하지만 확실한 건, 선택은 아래부터 해야 한다는 것이다!  
    <img src="https://user-images.githubusercontent.com/101321313/164987621-a6b263a7-1965-4369-aca9-4ce8ab88d8c7.png" width="30%" height="30%">
    
    - 1을 선택할바엔 무조건 내려서 2번을 선택하는 것이 더 좋기 때문이다.
    - 이게 가능한 이유는 각 도시마다 happiness가 모두 동일하기 때문.
    - 따라서 특정 노드를 선택했을 때 얻을 수 있는 이익을 `[루트까지의 거리]-[자기 아래 개수]`로 구할 수가 있다. 항상 아래부터 채워지기 때문에..
    - 예를 들어 위에서 1번을 고른다면 루트까지의 거리 2, 자기 아래 개수 5, 따라서 -3을 얻는다.
