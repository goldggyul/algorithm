# DP
- 일단 내 뒤는 어케되든 앞만 보면서 달려가기..

## [문제 1. Cut Ribbon](https://codeforces.com/problemset/problem/189/A)

- 어쨌든 마지막(지금 잘라야하는) 조각은 a/b/c겠지
- 그럼 마지막 전에는 어떻게든 그 때의 최고의 답이 있을거고...
- 못 자르는 경우만 잘 따져놓으면 됨 → 못 자르는 부분은 -1을 저장해두기

## [문제2. Boredom](https://codeforces.com/problemset/problem/455/A)

- 자료형 주의!
- 포인트는 연속한 값 2개는 못 고른다는 것
    - 예: 4,6은 고를 수 있어도 5,6은 고를 수 없다.
- 전체 배열을 정렬해야한다.
- `i`를 선택하지 않은 최댓값/ `i`를 선택한 최댓값 배열로 두 가지를 구한다.
    - 만약 `i-1` 과 `i`이 같은 값이라면, `i-1`을 선택했을 때 `i`도 무조건 선택해야 한다.
    - 만약 `i-1`이 `i`와 연속된 값이라면, `i-1`을 선택했다면 `i`를 선택하면 안된다.

## [문제3. Flipping Game](https://codeforces.com/problemset/problem/327/A)

- 주의! 무조건 하나는 뒤집어야 한다.
- 이 문제는 조건 상 n이 100이므로 n^3(그냥 다 뒤집어보기)으로 그냥 풀어도 되지만.. n이 더 커도 풀 수 있게 해보자.
- 뒤집으면 0→1, 1→0이 되므로 0을 뒤집으면 +1을 얻고, 1을 뒤집으면 -1을 얻는다. 즉, 0→1, 1→-1로 바꾼 배열을 이용하면 뒤집은 뒤 몇을 얻을 지 알 수 있다.
    - 만약 `0 1 1 0 0 1 0 1 1`이 주어졌다고 해보자.
    - 0→1, 1→-1로 바꾸면 `1 -1 -1 1 1 -1 1 -1 -1`이다.
    - 그럼 이 때 `최대 구간합`이 2이므로, 최대 +2를 얻을 수 있음을 알 수 있다.
- 즉, 최대 구간합을 구하면 된다! 앞에서 구했던 대로 prefix sum을 이용해도 되고, 다른 방법을 이용할 수도 있다. 다른 방법을 알아보자.
- `i까지의 최대합`을 구해보자. 이 때 주의할 건 꼭 i를 포함해야한다. 하나는 무조건 뒤집어야 하기 때문이다.
    - `D[i-1]`가 `A[i-1]`까지의 최대합이다. 그러면 `D[i]`는? `D[i-1]+A[i]` vs `A[i]`중 큰 값이다. 즉, 내 앞까지의 최대합이 더 크다면 이어서 합하고, 그게 아니라면 새로 시작하는 것?

## [문제4. 706C Hard problem](https://codeforces.com/problemset/problem/706/C)

- 항상 특정 지점에서 생각해보자..
- i-1번째 문자열은? 뒤집거나 안뒤집거나!
- i번째 문자열 역시 뒤집거나 안뒤집거나!
- 그럼 original i-1 / reverse i-1 vs. original i를 비교해서 더 작은 cost가 original i의 cost가 되고, original i-1 / reverse i-1 vs. reverse i를 비교해서 더 작은 cost가 reverse i의 cost가 되는 것
    - 물론 이 때 불가능하면 -1을 출력하고 리턴
- 그럼 항상 4개의 문자열과 두 개의 배열이 필요하다.
- 코드만 보면 뭐가 많아서 복잡해보이지만 찬찬히 비교하면서 `그 전이 불가능할때`는 나도 불가능하다는 것을 주의하며.. 천천히 생각해보면 된다!
- -1을 실패값으로하여 min(a,b)할 때 -1이 있으면 min으로 잡혀서.. 실패값을 큰 값으로 했으면 간단해질것
- 비용은 최대 10^9고, 문자열은 최대 10^5이므로, 다 뒤집는다고 치면 최대 10^14, long long은 최대 9*10^18이므로 맥스값을 10^14+1로 하면 된다

## [문제5. 607A Chain Reaction](https://codeforces.com/problemset/problem/607/A)

### 문제

- n개의 비콘, 각각의 비콘은 위치 ai, power bi
- 비콘은 오른쪽에서부터 키고, power bi까지는 파괴된다.
- 이 때 오른쪽에 비콘 하나를 추가해서, 최소로 파괴될 수 있는 비콘의 수?

---

- 즉, 오른쪽에 비콘 하나를 추가한다는 뜻은, 맨 처음 시작하는 비콘을 선택할 수 있다는 의미이다. 물론 그 오른쪽은 다 파괴될 것이다.

### 해결

- 따라서 각 비콘별로 **자신이 가장 오른쪽에서 켜젔을 때, 살아있는 비콘은 최대 몇개인가?** 를 계산하면 된다.

<img src="https://user-images.githubusercontent.com/101321313/164976782-463aa1fc-005b-4f6d-a8a8-6601af147296.png" width="50%" height="50%"/>

- 이 때 자신이 가장 오른쪽일 때 살아있는 비콘의 최대 개수는, 자신이 켜져서 파괴된 것을 제외하고 살아있는 가장 오른쪽 비콘에서의 최대 개수 + 1이다.
- 문제는 이 때 파괴된 것을 제외하고 가장 오른쪽을 구할 때, N의 시간복잡도로 구해선 안된다.
- 비콘의 개수가 100,000개이므로 logN에 가장 오른쪽 비콘을 찾아야한다. 따라서 이분 탐색으로 구해야한다.

---

### 이분 탐색 upper bound 찾기

- 아래 블로그를 참고하여 공부
- [링크1](https://lotuslee.tistory.com/60)
- [링크2](https://st-lab.tistory.com/269)

---

- 이 때 upper를 이용하든 bound를 이용하든 풀 수 있다.
- upper bound를 이용할 땐, key를 파괴되지 않는 마지막 위치로 두고, lower bound를 이용할 땐, key를 파괴되는 마지막 위치로 두면 된다.