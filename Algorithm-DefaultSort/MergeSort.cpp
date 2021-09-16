#include <iostream>

using namespace std;

//일단 내림차순

void MergeSort(int _iArr[], int _iSize)
{
	int iHalfSize1 = _iSize / 2;
	int iHalfSize2 = _iSize - (iHalfSize1);


	int* iResultArr = new int[_iSize];
	int* iArr1 = new int[iHalfSize1];
	int* iArr2 = new int[iHalfSize2];

	//2등분 하기
	memcpy(iArr1, _iArr, sizeof(int) * (iHalfSize1));
	memcpy(iArr2, &_iArr[iHalfSize1], sizeof(int) * (iHalfSize2));
	

	//2등분 한 친구들도 2개씩 비교해서 두개씩 정렬하기
	for (int i = 0; i < iHalfSize1; i +=2)
	{
		if (iArr1[i] > iArr1[i+1])
		{
			int iTemp = iArr1[i];
			iArr1[i] = iArr1[i + 1];
			iArr1[i + 1] = iTemp;
		}
	}

	for (int i = 0; i < iHalfSize2; i += 2)
	{
		if (iArr2[i] > iArr2[i + 1])
		{
			int iTemp = iArr2[i];
			iArr2[i] = iArr2[i + 1];
			iArr2[i + 1] = iTemp;
		}
	}

	int iIndex1, iIndex2, iIndex3 = 0;

	while (iIndex1 > iHalfSize1 || iIndex2 > iHalfSize2)
	{
		if (iArr1[iIndex1] < iArr2[iIndex2])
		{
			iResultArr[iIndex3] = iArr2[iIndex2];

			++iIndex2;
			++iIndex3;
		}
		else if (iArr1[iIndex1] > iArr2[iIndex2])
		{


			iResultArr[iIndex3] = iArr2[iIndex1];

			++iIndex1;
			++iIndex3;
		}
	}

	


	//이 두덩이들을 하나씩 비교하면서 배열에 넣자






	//for (int i = 0; i < iHalfSize; ++i)
	//{
	//	cout << iArr1[i] << endl;
	//}

	//cout << "--------" << endl;

	//for (int i = 0; i < _iSize - (iHalfSize); ++i)
	//{
	//	cout << iArr2[i] << endl;
	//}


};



void main()
{
	//단계별 
	//1. 배열을 반으로 나눈다. (A / B)
	//2. 그 각각 A와 B 내에서 또 값 2개 묶음으로 쪼갠다.
	//3. 2개 묶음로 쪼갠 한 묶음에서 정렬한다.
	//4. 다시 처음에 반으로 나눌때처럼 A / B 합친다.
	//5. 이 다시 만들어진 A와 B의 원소들을 하나씩 정렬 조건에 비교하여
	//부합하는 친구부터 새로운 배열에 할당 한다.
	//ex. ABCD / 1234 일 경우
	// A와 1비교, A가 조건에 부합해 새로운 배열에 할당한다면,
	// 그다음에는 B와 1비교하는 이런 방식과 순서로
	//6. 새로운 배열의 값들을 원본 배열에 복사해서 사용한다.

	int iArr[10] = {3, 99, 66, 10, 5, 
					7, 24, 13, 6, 9};

	int iArrSize = sizeof(iArr) / sizeof(int);

	MergeSort(iArr, iArrSize);

	system("pause");

}