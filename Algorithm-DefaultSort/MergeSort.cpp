#include <iostream>

using namespace std;

//일단 오름차순
//크게 두 역할로 나눌꺼임.
//배열을 재귀로 통해 쪼개는 부분
//나눈 부분을 비교하여 정렬기준대로 정렬한 뒤 삽입 할 부분?
//더 이상 쪼갤수 없을때 까지 쪼갠 뒤
//하나씩 합치면서 정렬을 해서 합치는 방법.

#pragma region ReferenceSolution
void Merge(int _iArr[], int _iLeft, int _iCenter, int _iRight)
{//여기서 쪼갠 원소들을 합치면서 정렬 해줄 부분.

	int i = _iLeft;
	int j = _iCenter + 1;
	int k = _iLeft;

	int resultArr[11];

	while (i <= _iCenter && j <= _iRight)
	{//두 배열중 하나가 끝날때까지 합침.
		if (_iArr[i] <= _iArr[j])
		{//전위,후위 연산 잘 생각해서 써야함.
			//전위를 사용해 버리면 숫자를 키우고 나서 대입을 하는거임으로
			//맨처음 기준으로 resultArr[1] = iArr[1];을 하는건데
			//후위 연산으로 들어가면
			//resultArr[0] = iArr[0]을 하고나서 증가연산을 하기 때문에
			//다른 값이 나올 수 밖에 없음.
			//resultArr[++k] = _iArr[++i];
			resultArr[k++] = _iArr[i++];
		}
		else
		{
			resultArr[k++] = _iArr[j++];
		}
	}

	if (i > _iCenter)
	{//윗 과정이 끝나고 오른쪽 배열에 남은 원소가 있다면 넣기
		for (int x = j; x <= _iRight; ++x)
		{
			resultArr[k++] = _iArr[x];
		}
	}
	else 
	{//윗 과정이 끝나고 왼쪽 배열에 남은 원소가 있다면 넣기
		for (int x = i; x <= _iCenter; ++x)
		{
			resultArr[k++] = _iArr[x];
		}
	}

	for (int x = _iLeft; x <= _iRight; ++x)
	{//실제 배열로 다시 옮기기
		_iArr[x] = resultArr[x];
	}
}
#pragma endregion

void MergeSort(int _iArr[], int _iLeft, int _iRight)
{//여기가 재귀 돌리면서 배열을 쪼개는 부분.

#pragma region MySolution-Wrong
	//int iHalfSize1 = _iSize / 2;
	//int iHalfSize2 = _iSize - (iHalfSize1);


	//int* iResultArr = new int[_iSize];
	//int* iArr1 = new int[iHalfSize1];
	//int* iArr2 = new int[iHalfSize2];

	////2등분 하기
	//memcpy(iArr1, _iArr, sizeof(int) * (iHalfSize1));
	//memcpy(iArr2, &_iArr[iHalfSize1], sizeof(int) * (iHalfSize2));
	//

	////2등분 한 친구들도 2개씩 비교해서 두개씩 정렬하기
	//for (int i = 0; i < iHalfSize1; i +=2)
	//{
	//	if (iArr1[i] > iArr1[i+1])
	//	{
	//		int iTemp = iArr1[i];
	//		iArr1[i] = iArr1[i + 1];
	//		iArr1[i + 1] = iTemp;
	//	}
	//}

	//for (int i = 0; i < iHalfSize2; i += 2)
	//{
	//	if (iArr2[i] > iArr2[i + 1])
	//	{
	//		int iTemp = iArr2[i];
	//		iArr2[i] = iArr2[i + 1];
	//		iArr2[i + 1] = iTemp;
	//	}
	//}

	//int iIndex1, iIndex2, iIndex3 = 0;

	//while (iIndex1 > iHalfSize1 || iIndex2 > iHalfSize2)
	//{
	//	if (iArr1[iIndex1] < iArr2[iIndex2])
	//	{
	//		iResultArr[iIndex3] = iArr2[iIndex2];

	//		++iIndex2;
	//		++iIndex3;
	//	}
	//	else if (iArr1[iIndex1] > iArr2[iIndex2])
	//	{


	//		iResultArr[iIndex3] = iArr2[iIndex1];

	//		++iIndex1;
	//		++iIndex3;
	//	}
	//}

	////이 두덩이들을 하나씩 비교하면서 배열에 넣자
#pragma endregion

#pragma region ReferenceSolution 
	int iCenterIndex;

	if (_iLeft < _iRight)
	{
		iCenterIndex = (_iLeft + _iRight) / 2;

		//여기서 왼쪽 부분을 더 쪼갤 수 없을 때까지 재귀 돌리는거
		MergeSort(_iArr, _iLeft, iCenterIndex);

		//위에서 왼쪽을 쭉 쪼갰으면 오른쪽도 더 쪼갤 수 없을 떄 까지 쪼갬.
		MergeSort(_iArr, iCenterIndex + 1, _iRight);

		Merge(_iArr, _iLeft, iCenterIndex, _iRight);

	}

#pragma endregion
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

	MergeSort(iArr, 0, iArrSize-1);

	for (int i = 0; i < iArrSize; ++i)
	{
		cout << iArr[i] << endl;
	}

	system("pause");

}