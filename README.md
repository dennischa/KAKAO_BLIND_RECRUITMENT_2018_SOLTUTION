# KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION
2019 카카오 신입 공채 1차 코딩 테스트 문제 풀이

![](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
## 문제 목록
---
이름 | 코드 | 문제 링크
|:-------|:---:|:---:|
|1. 오픈채팅방| [Open_Chat_Room](Open_Chatt_Room.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42888)
|2. 실패율| [Failure_Ratio](Failure_Ratio.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42889)
|3. 후보키| [Candidate_Key](Candidate_Key.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42890)
|4. 무지의 먹방 라이브 | [MUJIS_Eating_Broadcast](MUJIS_Eating_Broadcast.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42891)
|5. 길 찾기 게임 | [Pathfinding](Pathfinding.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42892)
|6. 매칭 점수 | [Matching_Score](Matching_Score.cpp) | [Link](https://programmers.co.kr/learn/courses/30/lessons/42893)
|7. 블록 게임 | [Block_Game](Block_Game.cpp_) | [Link](ttps://programmers.co.kr/learn/courses/30/lessons/42894)

## 문제 설명
---

### 1. 오픈채팅방
* [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42888)
* [솔루션](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Open_Chatt_Room.cpp)
#### 문제 풀이
* 자료구조 : 배열, 맵
* 시간 복잡도 예상 : O(n)
1. 배열을 사용하여 출력될 메세지를 기록해 둡니다.
2. 유저 아이디를 키로 닉네임을 값으로 저장하는 맵을 사용하여 관리합니다.
3. 배열을 순회하며 메세지를 생성할 때 맵에 저장된 아이디별 최종 닉네임을 이용합니다.
* **주요 부분** : 유저 아이디 맵으로 관리
```cpp
name_map[id] = string(name);
```
### 2. 실패율
* [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42889)
* [솔루션](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Failure_Ratio.cpp)

#### 문제 풀이
* 자료구조 : 배열, 맵
* 시간 복잡도 예상 : O(n^2)
1. stages 백터 정보를 바탕으로 스테이지 별 실패율을 계산하다.
2. 조건에 맞게 정렬한다.  
* **주요 부분** : 정렬 비교 함수
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

### 3.후보키
* [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42890)
* [솔루션](https://github.com/dennischa/KAKAO_BLIND_RECRUITMENT_2019_SOLTUTION/blob/master/Candidate_Key.cpp)

#### 문제 풀이
* 자료구조 : 비트셋, 맵
* 시간 복잡도 예상 : O(2^n)
1. bitset을 통해 모든 키 조합을 표현합니다.
2. `비트 연산 &`을 통해 조합의 최소성을 확보합니다.
3. 맵을 통해 투플의 종류 수를 구해 유일성을 확보합니다.

* **주요 부분**  : 최소성 확보
```cpp
bitset<8> set = i;

for (int i = 0; i < keys.size(); i++)
{
	if ((keys[i] & set) == keys[i]) // 앞서 구한 키조합의 부분 집합인지 확인한다.
	{
		is_minimal = false;
		break;
	}
}
```