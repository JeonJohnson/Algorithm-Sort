#include <iostream>

using namespace std;

//desc 내림차순
//asce 오름차순
#define Desc true 
#define Asce false

typedef bool SortMethod;

void BubbleSort(int _arr[], int _arrLength, SortMethod _method = Desc)
{
	//int iArrLength = _arrLength-1;
	//int iSortCount = _arrLength - 1;
	//최종 사이클 횟수와 한 사이클에서 정렬 회수는 결국 같음
	//for문의 식을 잘 세우면 변수를 하나도 안 세우고 사용가능.

	for (int i = _arrLength - 1; i > 0; --i)
	{//결국 n-1번만큼 돌아야함.
		for (int j = 0; j < i; ++j)
		{//실제로 정렬 하는 곳.

			int iTemp = 0;

			if (_method == Desc)
			{
				if (_arr[j] > _arr[j + 1])
				{
					iTemp = _arr[j];
					_arr[j] = _arr[j+1];
					_arr[j + 1] = iTemp;
				}
			}
			else 
			{
				if (_arr[j] < _arr[j + 1])
				{
					iTemp = _arr[j];
					_arr[j] = _arr[j + 1];
					_arr[j + 1] = iTemp;
				}
			}
		}
		//--iSortCount;
	}
}


void main()
{//210908 수 
	//안녕 친구들 오늘은 버블 소트에 대해 알아볼꺼야
	//서로 인접한 두 원소르 검사하여 정렬하는 알고리즘이야
	//오름차순 정렬시 1트에 가장 큰 녀석이 맨 뒤로 가고(n번째 는 완료)
	//2트때 그 다음 칸(n-1번째 완료)이 정렬이 완료된다... 이마리야
	
	//장점 : 구현이 간단하다.
	//단점 : 이동이 너무 빈번하게 일어난다. => 맨끝에서부터 순서대로 정렬이 완료됨으로 중간에 자기 자리에 왔더라도 아니면 또 이동함.
			//정렬이 좀 되어있든 아니든 걍 무적권 n-1번의 사이클은 돌아가야함
				//=> 무겁다 이말이야.


	int TestArr[10] = { 5, 55, 1, 96, 2, 6, 0, 9, 12, 8 };

	BubbleSort(TestArr,sizeof(TestArr) / sizeof(int),Desc);


	for (int i = 0; i < sizeof(TestArr) / sizeof(int); ++i)
	{
		cout << TestArr[i] << endl;
	}



	system("pause");
}