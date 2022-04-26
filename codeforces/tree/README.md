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
    <img src="https://user-images.githubusercontent.com/101321313/164987606-9ea0795a-9b20-4b5a-8d30-0395ed32733d.png" width="70%" height="70%">
    
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

## [문제3. 219D Choosing Capital for Treeland](https://codeforces.com/problemset/problem/219/D)

## 문제

- 한 방향으로 가는 트리
- 한 곳에서 다른 모든 곳으로 방향을 역으로 바꾸서 가게 할 수 있다. 이 때 최대한 적게 바꾸면서 모든 곳에 갈 수 있는 곳을 수도로 지정할 것.
- 이 때 수도 ?

---

- 따라서 각 노드마다 다른 곳에 도달하기 위해 몇 개의 도로를 바꿔야하는 지 구하면 된다.

---

### 해결

- ⚠️ 처음에 틀렸던 건.. 모든 n마다 거꾸로 dfs를 돌렸었다. 하지만 그러면 N^2가 되니까.. 당연히 시간초과!
- 아래 그림에서, 현재 s 노드에서 위, 아래로 도달하기 위해 도로를 몇개씩 바꿔야하는 지 생각해보자.
    
    <img src="https://user-images.githubusercontent.com/101321313/165242776-e4464211-cdbd-4672-bebc-2d92c1be5899.png" width="30%" height="30%">
    
- 각 노드로의 바꿔야 하는 도로의 수가 inverseCnt배열에 있다고 해보자
    - inverseCnt[2]는 2에서 `아래로(child)의 모든 inverseCnt 합` + 0 (도로가 정방향)이다.
    - `아래로의 모든 inverseCnt 합`은 따라서 재귀적으로.. 내려가다 보면 리프 노드에서 0이 된다! 그럼 쭉 구할 수 있다.
    - inverseCnt[3]은 역시 아래 합 + 1 (도로 역방향)으로 해결된다.
- 문제는 나 → child 방향이 아닌, 나 → parent 방향이다. inverseCnt[1]은 어떻게 할까?
    - `위에서의(parent) 모든 inverseCnt 합` + 0(도로가 정방향)으로 역방향으로 구하면 된다.
    - 위에서 구했던 것과 반대로 `위에서의 모든 inverseCnt 합` 은 위로 올라가다보면 루트 노드에서 0이 된다.
    - 나는 여기서 반드시 위 parent의 값은 모두 구해지고 child로 내려가는 순서로 구해지므로 위에서 모든 inverseCnt 합과 내 아래 모든 inverseCnt 합을 빼는 방식으로 구했다.
- 따라서 루트(1로 임의로 둠)에서 모든 곳으로 내려가면서 아래 합을 구하면서 올라오는 dfs한번, 내려가면서 parent방향 합을 구하는 dfs 총 두번 돌면 된다. `bottom-up → top-down!`

## [문제 4. 337D Book of Evil](https://codeforces.com/problemset/problem/337/D)

### 문제

- 문제에서 주어진 데미지를 받는 노드들에 모두 데미지를 줄 수 있는 노드가 몇 개인가?

---

### 해결

- ~~좀 맘에 안들지만 어쨌든 풀었다~~
- 각 노드별로 데미지를 받는 노드와 거리중 가장 먼 것을 기록하면 된다. 문제에서 주어진 데미지 범위보다 거리가 같거나 작아야 그 노드가 정답이다.
- 문제 3과 똑같이 bottom-up → top-down!
    - 처음엔 각 노드 별로 아래에 가장 먼 데미지 노드를 기록하고, 거꾸로 다시 내려오면서 부모값을 업데이트 해주면 된다.
    - 다만 주의할 건, 역시 top down으로 내려올 때인데...
        
        <img src="https://user-images.githubusercontent.com/101321313/165242797-53fde2db-2bd2-4354-a3c7-76aff47c4ccf.png" width="30%" height="30%">
        
    - 노드4의 값을 계산할 때, `노드2에서의 값` + 1을 하면 노드4의 값이 될 것이다.
    - 주의할 건, 이 때 `노드2에서의 값`을 그냥 2의 max 값을 주면 안된다는 것. 그 2의 max값이 bottom-up으로 올라올 때 4에서 올라온 값일 수가 있다. 그러면 당연히 그 값을 또 4에 내려주면 안되기 때문에.. `2->1`, `2->3`, `~~2->4~~`, `2->5`로 `2->4`를 제외한 나머지 값 중 최대값을 내려줘야 한다.
    - 이 때, child값을 업데이트 할 때마다 단순히 하나씩 보면서 최대값을 구하면 시간초과가 난다!
    - 따라서 `부분 최대값`을 이용한다. `나를 제외한 최대값`을 구할 때 많이 이용되는 방법이라고 한다.
        
        <img src="https://user-images.githubusercontent.com/101321313/165242809-5ccb32da-e89c-4c80-9c90-ee5fcffae1ae.png" width="50%" height="50%">
        
        - prefix sum, suffix sum을 구할 때처럼, 앞/뒤에서부터 순서대로 보는데, sum처럼 i까지의 합이 아닌 i까지의 최대값을 구한다.
        - 그렇다면 i를 제외한 최대값은 `max(prefixMax[i-1], suffixMax[i+1])`일 것이다.
        - 예를 들어 위에선 3을 제외한 최대값은 `max(2,6) = 6`이다.
