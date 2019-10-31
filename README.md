# KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION
2019 īī�� ���� ��ä 1�� �ڵ� �׽�Ʈ ���� Ǯ��

![](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
## ���� ���
---
�̸� | �ڵ� | ���� ��ũ
|:-------|:---:|:---:|
|1. ����ä�ù�| [Open_Chat_Room](Open_Chatt_Room.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42888)
|2. ������| [Failure_Ratio](Failure_Ratio.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42889)
|3. �ĺ�Ű| [Candidate_Key](Candidate_Key.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42890)
|4. ������ �Թ� ���̺� | [MUJIS_Eating_Broadcast](MUJIS_Eating_Broadcast.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42891)
|5. �� ã�� ���� | [Pathfinding](Pathfinding.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42892)
|6. ��Ī ���� | [Matching_Score](Matching_Score.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42893)
|7. ��� ���� | [Block_Game](Block_Game.cpp_) | [Link](ttps://programmers.co.kr/learn/courses/30/lessons/42894)

## ���� ����
---

### 1. ����ä�ù�
* [���� ��ũ](https://programmers.co.kr/learn/courses/30/lessons/42888)
* [�ַ��](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Open_Chatt_Room.cpp)
#### ���� Ǯ��
* �ڷᱸ�� : �迭, ��
* �ð� ���⵵ ���� : O(n)
1. �迭�� ����Ͽ� ��µ� �޼����� ����� �Ӵϴ�.
2. ���� ���̵� Ű�� �г����� ������ �����ϴ� ���� ����Ͽ� �����մϴ�.
3. �迭�� ��ȸ�ϸ� �޼����� ������ �� �ʿ� ����� ���̵� ���� �г����� �̿��մϴ�.
* **�ֿ� �κ�** : ���� ���̵� ������ ����
```cpp
name_map[id] = string(name);
```
### 2. ������
* [���� ��ũ](https://programmers.co.kr/learn/courses/30/lessons/42889)
* [�ַ��](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Failure_Ratio.cpp)

#### ���� Ǯ��
* �ڷᱸ�� : �迭, ��
* �ð� ���⵵ ���� : O(n^2)
1. stages ���� ������ �������� �������� �� �������� ����ϴ�.
2. ���ǿ� �°� �����Ѵ�.  
* **�ֿ� �κ�** : ���� �� �Լ�
```cpp
bool operator<(const Stage& comp)
{
	const float f1 = this->get_failure_ratio();
	const float f2 = comp.get_failure_ratio();

	if (f1 == f2)
		return this->num < comp.num;
	else
		return f1 > f2;
}
```

### 3.�ĺ�Ű
* [���� ��ũ](https://programmers.co.kr/learn/courses/30/lessons/42890)
* [�ַ��](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Candidate_Key.cpp)

#### ���� Ǯ��
* �ڷᱸ�� : ��Ʈ��, ��
* �ð� ���⵵ ���� : O(2^n)
1. bitset�� ���� ��� Ű ������ ǥ���մϴ�.
2. `��Ʈ ���� &`�� ���� ������ �ּҼ��� Ȯ���մϴ�.
3. ���� ���� ������ ���� ���� ���� ���ϼ��� Ȯ���մϴ�.

* **�ֿ� �κ�**  : �ּҼ� Ȯ��
```cpp
bitset<8> set = i;

for (int i = 0; i < keys.size(); i++)
{
	if ((keys[i] & set) == keys[i]) // �ռ� ���� Ű������ �κ� �������� Ȯ���Ѵ�.
	{
		is_minimal = false;
		break;
	}
}
```