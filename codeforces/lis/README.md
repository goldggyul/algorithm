## [문제 1. 486E LIS of Sequence](https://codeforces.com/contest/486/problem/E)

- 일반적으로 i마다 그 앞 0~i-1 값을 확인하면서 i에서의 IS의 길이를 찾으면 `O(N^2)`
- 하지만 `O(NlogN)`으로 풀어보자.

### LIS 길이 구하기

- binary search를 이용해서 logN으로 줄이는 것
- N^2 방식은, 앞에서부터 배열 값을 모두 비교해보면서 해당 배열 값보다 현재 배열 값이 크면 현재 수열 길이 값을 +1하는 방식이다.
- 하지만 앞을 모두 비교해야할까? 가장 작은 값만 알고 있어도 되지 않을까?
- 예를 들어 가장 긴 길이가 3인 곳이 두개인데, 각각 값이 5와 4라고 해보자. 그럼 4만 기억해둬도 되지 않을까?
    - 이 때 5가 4보다 배열의 뒤에 있을 수 있을까? 불가능하다. 5가 4보다 뒤였다면 길이가 3이 아니라 4였을 것이다.
    - 5와 4가 아니라 4와 4, 즉 같은 배열 값이 같은 길이 3일 수 있을까? 생각해보면 그건 충분히 가능하다.
    - 그래서 `💡 첫번째 아이디어`는 같은 길이라면, 배열 값은 점점 작거나 작아질 수 밖에 없으므로, 어떤 길이의 배열값이 나온다면? 무조건 기존 그 길이의 배열값과 같거나 작다.
        
        <img src="https://user-images.githubusercontent.com/101321313/165504697-e2f66a9a-3a66-420f-b574-137fdbdb3aba.png" width="70%" height="70%"/>
        
        <img src="!https://user-images.githubusercontent.com/101321313/165504688-6534e825-e1a1-4929-803c-8a152af104a7.png" width="50%" height="50%"/>
        
    - 따라서 각 길이마다 마지막 배열 값을 기억하는데...
    - 이제 그 길이만 생각하지말고 앞뒤 길이와의 관계도 생각해보자.
    - 더 긴 길이가 앞 길이의 배열 값보다 작을 수 있을까? 즉, 길이 2인 값의 배열값이 5였는데, 길이 3인 값의 배열값이 4일 수 있을까? 불가능하다. 그러면 4보다 더 작은 값이 분명히 4전에 있었을 것이고, 그러면 길이 2의 값이 5가 아닌 4보다 작은 무언가일 것이다. 그리고 이렇게 생각해보면? 당연히 배열 값이 같은 것도 불가능하다.
        
        <img src="https://user-images.githubusercontent.com/101321313/165504680-5fcdf7a7-63d6-46db-bb6d-c57fdffc917d.png" width="50%" height="50%"/>
        
    - 따라서 `💡 두번째 아이디어`는, 더 긴 길이라면 반드시 그 전 길이보다 크다는 것!
    - 첫번째와 두번째 아이디어를 모아보면.. 길이마다의 배열값은 저장하면 반드시 증가하는 배열이다.
    - 따라서 `인덱스를 길이로 하고 값은 그 길이의 배열값`으로 배열을 저장하면, 반드시 증가하는 배열이므로 binary search를 할 수 있다!
    - 새로운 배열값이 나오면, binary search로 새로운 배열값보다 큰 곳을 업데이트 하면 된다. 위의 그림의 배열로 살펴보자.
    - 앞에서 길이 배열값을 업데이트 했고.. 이제 5를 길이 배열에 업데이트 한다고 생각해보자. 그럼 더 작은 배열값의 길이 다음에 들어가면 되므로 길이 2, 배열값 8인 곳에 5를 넣으면 된다. 그리고 길이 2의 배열값은 5로 업데이트 되는 것이다.
        
        <img src="https://user-images.githubusercontent.com/101321313/165504666-7d59b7e4-7140-400a-abb4-43065c8f55cf.png" width="50%" height="50%"/>
        

### LIS에 속하는 값 찾기

- 위 방식대로는 LIS의 길이와, 각 길이의 마지막 배열값을 알 순 있지만, 그래서 LIS에 속하는 원소가 뭔지를 알 수 없다. 이건 어떻게 구할까?
- 답은 `거꾸로 보면서 감소하는 수열`찾기이다.
- 그림의 배열 마지막부터 보면서 감소하는 수열을 LIS와 똑같이 구한다고 생각해보자.
- 즉 [7]을 보면, [8]의 17보다 작으니까 수열 길이는 1+1=2이 될 것.

    <img src="https://user-images.githubusercontent.com/101321313/165504643-edb4a1b1-6b87-406b-bb0a-50f799b641db.png" width="70%" height="70%"/>

- 위 배열에서 LIS의 길이는 5고, 감소 수열 역시 `반대로` 보면서 `감소`하는 길이이므로 최대 길이는 LIS와 같다. 그럼 [5]를 한 번 보자. 배열 값이 8인데, LIS에 속하면서 총 길이 5중 2번째이다. 반대로 보면? 감소하는 수열 길이의 총 길이 5중 4번째이다. 즉, 증가하는 길이로 보면 2 `8` 9 10 17, 감소하는 길이로 봐도 17 10 9 `8` 2인 것이다. 즉 같은 자리인데 단지 뒤집은 자리를 의미하게 되고, `증가 수열 길이 + 감소 수열 길이` = `최대 길이 + 1`이 된다. (자기는 두번 세니까)
- 따라서 LIS에 속하는 값을 찾을 수 있다.

### 모든 LIS에 속하는가?

- 답 출력 형식을 보면 단순히 LIS에 속하냐의 문제가 아니라, LIS가 여러개 있다면 그 중 모든 LIS에 포함되는 것 vs. 아닌 것으로 나누고 있다. 이건 또 어떻게 알까?
- 일단 LIS에 속하는 건 위에서 찾았으므로, 어떤 값이 LIS에 속한다고 생각해보자.
    
    <img src="https://user-images.githubusercontent.com/101321313/165504611-adb0a573-60ec-403d-926e-d5ff286fe0af.png" width="50%" height="50%"/>
    
- 만약 배열에서, 내가 LIS에 속하는데, 내 왼쪽에 LIS에 속하는데 나보다 큰 배열 값이 있다면? 그럼 내 길이인 원소가 내 왼쪽 어딘가에 있다는 것이다. 즉 내가 모든 LIS에 속하지 않는다.
- 같은 맥락으로 오른쪽에도 LIS에 속하는데, 나보다 배열값이 더 작은 값이 있다면 그 때도 나 외에 LIS가 있다는 것이다.
- 즉, 내가 모든 LIS에 속한다면, 나보다 왼쪽은 모두 나보다 작은 LIS 값이어야하고, 오른쪽은 모두 큰 LIS여야한다.