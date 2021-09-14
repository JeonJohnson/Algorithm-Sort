#include <iostream>

using namespace std;

#define Desc true
#define Asce false

typedef bool SortMethod;

void SelectionSort(int _iArr[], int _iArrLength, SortMethod _method = Asce)
{
	//for (int i = 0; i < _iArrLength; ++i)
	//{
	//	int iLeastNum = _iArr[i];
	//	int iLeastIndex = i;
	//	//int iSelectNum = _iArr[i];

	//	//최솟값을 임시변수 없이 구할 수 있니...?


	//	for (int k = i; k < _iArrLength; ++k)
	//	{
	//		if (_method == Asce)
	//		{
	//			if (iLeastNum > _iArr[k])
	//			{
	//				iLeastNum = _iArr[k];
	//				iLeastIndex = k;
	//			}
	//		}
	//		else 
	//		{
	//			if (iLeastNum < _iArr[k])
	//			{
	//				iLeastNum = _iArr[k];
	//				iLeastIndex = k;
	//			}

	//		}
	//	}

	//	int iTemp = _iArr[i];
	//	_iArr[i] = iLeastNum;
	//	_iArr[iLeastIndex] = iTemp;
	//}

	for (int i = 0; i < _iArrLength-1; ++i)
	{//어차피 마지막 친구는 자동적으로 정렬이 된거라서 '길이-1' 까지만 반복하면 된다 이거야
		
		//맨 앞쪽에 정렬 순서에 맞춰 바꾸기 때문에 앞쪽 부터 정렬이 완료됨으로 
		int iSelectIndex = i;
		int iSelectNum = _iArr[i];

		//최솟값을 임시변수 없이 구할 수 있니...? => 써야함 왜 저렇게 설명이 된지 몰르겠네
		for (int k = i+1; k < _iArrLength; ++k)
		{
			if (_method == Asce)
			{
				if (iSelectNum < _iArr[k])
				{
					iSelectNum = _iArr[k];
					iSelectIndex = k;
				}
			}
			else
			{
				if (iSelectNum > _iArr[k])
				{
					iSelectNum = _iArr[k];
					iSelectIndex = k;
				}
			}
		}

		if (iSelectIndex != i)
		{
			int iTemp = _iArr[i];
			_iArr[i] = _iArr[iSelectIndex];
			_iArr[iSelectIndex] = iTemp;
		}
	}
}


void main()
{
	//210908 1937 선택정렬
	//오름차순 정렬 기준(0->n)
	//숫자 중 최솟값을 찾아 맨 첫번째 위치로 옮긴다.
	//남은 숫자들 중 최솟값을 찾아 두번째 위치, 세번째... 요런식으로 ㅇㅇ
	
	//
	


	int TestArr[10] = { 12, 6,3, 0, 8,
						1, 98, 2 ,77, 5 };

	int ArrLength = sizeof(TestArr) / sizeof(int);

	SelectionSort(TestArr, ArrLength, Desc );

	for (int i = 0; i < ArrLength; ++i)
	{
		cout << TestArr[i] << endl;
	}



	system("pause");
}