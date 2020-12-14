## 프로그래머스 C++을 무기로 강의 속 문제 풀이

 ### 해쉬 - 완주하지 못한 선수
 	**제한사항**
   1. 참여한 선수의 수는 1명 이상 100,000명 이하 = n이 최대 100,000
   2. 동명이인이 있을 수 있다.
  
  **제공 값**
   1. participant<vector<string>> : 마라톤에 참여한 선수 이름 목록
   2. completion<vector<string>> : 마라톤을 완주한 선수 이름 목록
  
  **풀이**
   - unordered_map<string, int> runner선언 (Visual Studio에서 hash_map의 사용이 안된다고 한다)
   - participant의 크기만큼 반복하며 선수들을 runner에 `1씩 증가시키며` 참가자 목록을 만든다.
   - completion의 크기만큼 반복하며 선수들을 runner에서 `1씩 감소시키며` 완주자를 목록에서 제외한다.
   - 최종적으로 다시 한번 participant의 크기만큼 반복문을 통해 현재 runner에 second의 값이 `0이 아닌 것`을 찾아 return 해준다.
