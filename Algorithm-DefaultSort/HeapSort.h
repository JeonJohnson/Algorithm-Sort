#pragma once
//힙 정렬

//을 들어가기 전에 자료구조 '힙'에 대해 아라보자.

// "자료 구조 힙"
//'완전 이진 트리'의 일종. 우선순위 큐를 위해 만들어진 자료구조.
// 큐 -> 선입선출
//'완전 이진 트리' = 각 노드가 최대 두개의 자식 노드를 가지는 트리 자료 구조
//=> 마지막 레벨아니면 노드 2개를 가득 채움.
//=> 마지막 레벨은 왼쪽부터 노드를 채우면 됨.
//=> '이진 탐색 트리'와 다르게 키값 중복 가능.
//=> 우리가 썻던 map이 '이진 탐색 트리'
//=> 반정렬(느슨한 정렬)상태
//=> 상위 노드의 키값이 하위 노드 키값보다 더 큼.
//여러 값들 중 최대값, 최소값을 빠르게 찾을 수 있는 자료구조.

// "자료 구조 힙의 종류"
//최대 힙 : 부모노드의 키 값이 자식노드의 키 값보다 크거나 같음.
//최소 힙 : 부모노드의 키 값이 자식노드의 키 값보다 작거나 같음.

// "자료 구조 힙 구현"
//배열로써 구현.
//구현의 편의를 위해 배열의 첫 인덱스 0번은 사용 안함.
//각 노드들의 인덱스는 정해져 있음 (추가로 바뀌지 않음.)
//왼쪽 자식의 인덱스 = 부모 인덱스 * 2
//오른쪽 자식의 인덱스 = 부모 인덱스 * 2 + 1

// "힙에서의 삽입"
// 1. 새로운 노드를 힙의 마지막 노드에 이어서 삽입.
// 2. 부모 노드와 크기를 비교하여 교환이 필요한 경우 교환해 힙의 성질 충족 시키기.

// "힙에서의 삭제"
// 우선순위 '큐'임으로 가장 큰 값(1번 노드) 삭제.
// 그 후 가장 작은 값(마지막 번 노드)을 1번 노드에 대입.
// 자식 노드들과 비교해서 둘 중 더 큰 값과 교환. (애초에 가장 밑에 친구를 가져왔으니 분명 더 클 것.)

