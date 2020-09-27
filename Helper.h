#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
class Helper {
public:
	static int FindArrayIndex(int arr[], int x, int size);
	static int* CopyArray(int* arr, int size);
};

int Helper::FindArrayIndex(int arr[], int x, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int* Helper::CopyArray(int* arr, int size) {
	int* orgArray;
	orgArray = new int[size];
	for (unsigned i = 0; i < size; i++)
	{
		orgArray[i] = arr[i];
	}

	return orgArray;
}
