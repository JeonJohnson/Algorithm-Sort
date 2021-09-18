#include <iostream>

using namespace std;

//�ϴ� ��������
//ũ�� �� ���ҷ� ��������.
//�迭�� ��ͷ� ���� �ɰ��� �κ�
//���� �κ��� ���Ͽ� ���ı��ش�� ������ �� ���� �� �κ�?
//�� �̻� �ɰ��� ������ ���� �ɰ� ��
//�ϳ��� ��ġ�鼭 ������ �ؼ� ��ġ�� ���.

#pragma region ReferenceSolution
void Merge(int _iArr[], int _iLeft, int _iCenter, int _iRight)
{//���⼭ �ɰ� ���ҵ��� ��ġ�鼭 ���� ���� �κ�.

	int i = _iLeft;
	int j = _iCenter + 1;
	int k = _iLeft;

	int resultArr[11];

	while (i <= _iCenter && j <= _iRight)
	{//�� �迭�� �ϳ��� ���������� ��ħ.
		if (_iArr[i] <= _iArr[j])
		{//����,���� ���� �� �����ؼ� �����.
			//������ ����� ������ ���ڸ� Ű��� ���� ������ �ϴ°�������
			//��ó�� �������� resultArr[1] = iArr[1];�� �ϴ°ǵ�
			//���� �������� ����
			//resultArr[0] = iArr[0]�� �ϰ��� ���������� �ϱ� ������
			//�ٸ� ���� ���� �� �ۿ� ����.
			//resultArr[++k] = _iArr[++i];
			resultArr[k++] = _iArr[i++];
		}
		else
		{
			resultArr[k++] = _iArr[j++];
		}
	}

	if (i > _iCenter)
	{//�� ������ ������ ������ �迭�� ���� ���Ұ� �ִٸ� �ֱ�
		for (int x = j; x <= _iRight; ++x)
		{
			resultArr[k++] = _iArr[x];
		}
	}
	else 
	{//�� ������ ������ ���� �迭�� ���� ���Ұ� �ִٸ� �ֱ�
		for (int x = i; x <= _iCenter; ++x)
		{
			resultArr[k++] = _iArr[x];
		}
	}

	for (int x = _iLeft; x <= _iRight; ++x)
	{//���� �迭�� �ٽ� �ű��
		_iArr[x] = resultArr[x];
	}
}
#pragma endregion

void MergeSort(int _iArr[], int _iLeft, int _iRight)
{//���Ⱑ ��� �����鼭 �迭�� �ɰ��� �κ�.

#pragma region MySolution-Wrong
	//int iHalfSize1 = _iSize / 2;
	//int iHalfSize2 = _iSize - (iHalfSize1);


	//int* iResultArr = new int[_iSize];
	//int* iArr1 = new int[iHalfSize1];
	//int* iArr2 = new int[iHalfSize2];

	////2��� �ϱ�
	//memcpy(iArr1, _iArr, sizeof(int) * (iHalfSize1));
	//memcpy(iArr2, &_iArr[iHalfSize1], sizeof(int) * (iHalfSize2));
	//

	////2��� �� ģ���鵵 2���� ���ؼ� �ΰ��� �����ϱ�
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

	////�� �ε��̵��� �ϳ��� ���ϸ鼭 �迭�� ����
#pragma endregion

#pragma region ReferenceSolution 
	int iCenterIndex;

	if (_iLeft < _iRight)
	{
		iCenterIndex = (_iLeft + _iRight) / 2;

		//���⼭ ���� �κ��� �� �ɰ� �� ���� ������ ��� �����°�
		MergeSort(_iArr, _iLeft, iCenterIndex);

		//������ ������ �� �ɰ����� �����ʵ� �� �ɰ� �� ���� �� ���� �ɰ�.
		MergeSort(_iArr, iCenterIndex + 1, _iRight);

		Merge(_iArr, _iLeft, iCenterIndex, _iRight);

	}

#pragma endregion
};



void main()
{
	//�ܰ躰 
	//1. �迭�� ������ ������. (A / B)
	//2. �� ���� A�� B ������ �� �� 2�� �������� �ɰ���.
	//3. 2�� ������ �ɰ� �� �������� �����Ѵ�.
	//4. �ٽ� ó���� ������ ������ó�� A / B ��ģ��.
	//5. �� �ٽ� ������� A�� B�� ���ҵ��� �ϳ��� ���� ���ǿ� ���Ͽ�
	//�����ϴ� ģ������ ���ο� �迭�� �Ҵ� �Ѵ�.
	//ex. ABCD / 1234 �� ���
	// A�� 1��, A�� ���ǿ� ������ ���ο� �迭�� �Ҵ��Ѵٸ�,
	// �״������� B�� 1���ϴ� �̷� ��İ� ������
	//6. ���ο� �迭�� ������ ���� �迭�� �����ؼ� ����Ѵ�.

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