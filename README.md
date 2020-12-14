알고리즘 공부

 2020.12.14 - 프로그래머스 강의 시작
 
 <예정>
 
 백준 - 새로운 강의 런칭 후 수강 예정
 
## 프로그래머스 C++을 무기로 강의 속 문제 풀이

### C++
 - STL(Standard Template Library) 를 사용하자
 - ...


 ### 해쉬 - 완주하지 못한 선수
 
 **제한사항**
   1. 참여한 선수의 수는 1명 이상 100,000명 이하 = n이 최대 100,000
   2. 동명이인이 있을 수 있다.
   3. 선수 이름은 소문자로만 구성되어 있다.
  
  **제공 값**
   1. participant<vector<string>> : 마라톤에 참여한 선수 이름 목록
   2. completion<vector<string>> : 마라톤을 완주한 선수 이름 목록
  
  **풀이**
   - `#include<unordered_map>` 선언
   - `unordered_map<string, int> runner`선언 (Visual Studio에서 hash_map의 사용이 안된다고 한다)
   - participant의 크기만큼 반복하며 선수들을 runner에 `1씩 증가시키며` 참가자 목록을 만든다.
   - completion의 크기만큼 반복하며 선수들을 runner에서 `1씩 감소시키며` 완주자를 목록에서 제외한다.
   - 최종적으로 다시 한번 participant의 크기만큼 반복문을 통해 현재 runner에 second의 값이 `0이 아닌 것`을 찾아 return 해준다.

  **강의에서 얻은 지식**
   - map과 unordered_map의 key에 의한 접근(새로운 원소 추가, 특정 key의 value 찾기, 원소 삭제, ...) 시간은 다르다
   
      map = O(logN) :: 주로 binary search tree 사용
      
                       binary search tree = 이진 트리로 부모노드보다 작은 값은 왼쪽 노드로, 크면 오른쪽 노드로 자식을 구성한다.
                       
      unorderd_map = O(1)  :: hash_table 사용
   - unordered_map 순회하기
   
       for(auto i : runner){
       
         cout << i.first << "-" << i.second << '\n';
         
       }
       
       **해당 문제에서는 값을 참조하고 가져오기만 하면 되기 때문에 auto i 로 작성하였으나, 값을 변경해야 하면 auto &i 로 작성하는 것이 맞다.**
       
       **마찬가지로 participant와 completion의 선수 이름이 소문자와 대문자가 섞여 있으나 이를 고려하지 않는다면 lower를 사용할 때, auto &i로 써주어야 한다.**
       
   - 정렬을 통해 풀이하는 방법도 있지만, 정렬을 하는 과정이 오래 걸리기 때문에 이 문제에서는 적절하지 않다.
