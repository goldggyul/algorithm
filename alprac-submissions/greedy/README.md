# Greedy

- �̷��� �ϸ� ���� �ǰڴ� ������ �ƴ� ��Ȯ�� ������ Ȯ������.

## 1. [734B](https://codeforces.com/problemset/problem/734/B)

- ����: �־��� ���� 32�� 256�� ����µ�, ������� 32�� 256�� ��� ������ �� ���� ���� ũ�� ����.
- �翬�� ��ġ�� �� 2�̹Ƿ�.. 5/6�� 3�� ���� �� 2�� 56�� ���� ���̰� �������� 32�� ���̸� �ȴ�
- Ǫ�� �� �߿��� �� �ƴϰ�.. �� �̰� Ȯ���� ���ΰ�?
  - greedy�� ���� �� �����̷���? �׸��� �ƴ� �ٸ� ���� �� �������� �ʴ´�(��)�� ���� �����ϸ� �ȴ�.
  - �� �ع���� ���� ���� �ִٰ� ����. �׷� �ű⼭ greedy���� ���� ���� �������� �ʴ´ٴ� �� ���̸� �ǹǷ�, 2�� 32������ �Űܺ���! �׷� �翬�� 256�� �������� 32�� �������ϱ� �� �������� �ʴ´�. ���� greedy�� �� ��.

## 2. [158B](https://codeforces.com/problemset/problem/158/B)

- ����: n�� �׷�, �� �׷��� 1~4������ �Ǿ��ְ�, �ýô� �ִ� 4������ Ż �� ����. �ٸ� �׷쵵 ���� Ż �� ������, �� �׷��� ���� �ýÿ��� Ÿ�� �ȴٸ� �ּ� �� ���� �ýð� �ʿ��Ѱ�?
- ��?

  1. 4�� �¿��
  2. 3/1�� ���� �¿��
  3. 2/2 ���� �¿��
  4. 2/1/1 ���� �¿��

- �̰� �� �����ΰ�? �׷��� ���ߴٰ� �ĺ���!
  - Greedy�� ���� ���信��, � �׷��� �ٸ� �ýÿ� �¿�����!
  - �׷� �� �׷��� ���� �ִ� �ý÷� �׳� ������ ���� ��..
  - �״ϱ� ����(?)

## 3. [160A](https://codeforces.com/problemset/problem/160/A)

- ����: ������ ������ �����µ�, ���� ������ �� ���� value�� ��������, �ּ� �� ���� ����?
- ū �ź��� ������ �ȵǳ�?? �ȴ�! �װ� ���̴�! �ٵ� <span style="color:red">**��?**</span>
  - [�� > �� > �� > ��] > �� > .... > �� > ��: �̰� Greedy �� ���� ���̶�� ����
  - [�� > ��] > ~~��~~ > [��] > �� > .... > [��] > ��: Greedy�� �ƴ϶��? �߰��� ���� ������ ��� �ٸ��� ����� �� �� �׷� �翬�� ���� �پ���
    - Greedy: ���� ū �� ���� ������. �׷��ϱ� Greedy�� �ƴ� �����̶�� �� ū�͵� �߿� ���� �� ���� ��.