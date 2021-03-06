# Divide and Conquer
:star::star::star::star::star:
## 1. [448C - Painting Fence](https://codeforces.com/problemset/problem/448/C)
- 가로/세로로 칠할 수 있다.
- 따라서 case를 나눠서 생각해보면.. 모두 세로로 칠하면 어떨까? n번만에 칠할 수 있다.
- 따라서 답은 최대 n이고, 더 줄이려면 가로로 칠하는 곳이 있어야 함을 알 수 있다.
- 중간에 어떤 부분을 가로로 칠한다고 생각해보자.. 그럼 당연히 끝까지 칠하는 게 이득이다. -> Greedy idea
- 만약 중간 부분을 가로로 칠했다고 생각해보자.

    <img src="https://user-images.githubusercontent.com/101321313/160262193-541e0e1a-df1c-4809-a745-514fc999d162.png"  width="200" height="170">

- 그럼 그 아래 부분은 어차피 모두 세로로 칠해줘야 한다. -> n번
- 따라서 가로로 칠했다면 그 아래부분까지 모두 가로로 칠해줘야 한다.
- 아래 부분의 `공통적인 부분`을 모두 가로로 칠했다고 해보자. 그럼 윗 부분을 다시 칠하면 되는데.. 그럼 또 작은 울타리들을 칠하면 되므로 똑같은 문제를 푸는 것이다. -> 따라서 재귀로 풀면 된다.
    - 즉 `공통적인 부분`은 최소 높이가 될 것.
    - Recursion Fairy :fairy: ^ ^
- 근데 또 무작정 가로로 다 칠하면 더 많이 칠하게 될 수 있으므로.. 세로(n번) vs 가로로 칠했을 경우의 최솟값을 리턴해주자.

## 2. [768B - Code For 1](https://codeforces.com/problemset/problem/768/B)
- 문제 규칙대로 문자열을 생성 후, l~r 사이의 1의 개수를 구하자.
- 문자열을 만들어서 구해볼까? 하지만 n이 2^50이고.. 문자열의 길이(를 어떻게 구하는 지는 아래에서)가 정말 길어져서 하나씩 구할 수 없다.
- n == 7이라면, 7%2 = 1, 7/2 = 3이므로 3|1|3으로 쪼갤 수 있고, 3에서 또 쪼개면서 시작하면 되므로.. 대략 재귀적이라는 것 쯤은 알 수 있다.
- 근데 문제는 재귀가 얼마나 들어가냐는 것. 이 문제에서는 l-r의 조건이 있어서 그것까지 고려안해도 풀 수 있지만, l-r이 제한되어 있지 않다면?  
- :star: 아이디어는 사실은 재귀를 끝까지 들어가지 않아도 된다는 것!
- ❗ 케이스를 나눌 때만 잘 나눠주자. 그냥 하나하나 다 적어서 하기..

### 문자열 길이
- 계속해서 2로 나눈 나머지가 가운데에 남게 되므로, 이진수로 생각하면 편하다.
- `10 == 1010(2)` 이므로, 가운데엔 마지막 0이 있을 것이고, 그 다음 sub에선 가운데에 1이 있을 것이고, 똑같은 게 왼쪽/오른쪽 반복된다. 그리고 그 다음 0(3번째 자리의 0).. 이것 역시 양쪽에 반복...
- 이런 식으로 생각해보면, 0이 1번 나오고, 그 다음 1은 2번 나오고, 그 다음 0은 4번 나오고, 그 다음 1은 8번 나온다. 즉 각 자리의 숫자가 각 자리 의미 그대로 나온다. 즉 10 == 1010의 경우 전체 문자열의 길이가 1111 == 15가 되는 것. 그럼 문자열의 길이를 알 수가 있다.
### 1이 나오는 횟수
- 그럼 1이 나오는 횟수도 같은 맥락으로 알 수 있다. 1010에서 두번째 1은 2번 나올 것이고 4번째 1은 8번 나올 것이므로, n 그 자체가 n으로 만들어진 문자열의 1의 개수가 된다.
- :star::star::star: 따라서 전체 문자열에서 1의 개수를 구할 때는 재귀로 들어갈 필요 없이 바로 결과를 구할 수 있다. -> 그래서 시간.. 스택 초과없이 해결할 수 있다.

