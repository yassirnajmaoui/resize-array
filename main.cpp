template <typename T> bool resize(T*& oldT, size_t oldsize, size_t newsize, T defaultvalue)
{
	size_t biggersize = (oldsize > newsize) ? oldsize : newsize;
	size_t smallersize = (oldsize < newsize) ? oldsize : newsize;
	T* copyT = new T[biggersize];
	for(size_t i=0;i<smallersize;i++)
	{
		copyT[i]=oldT[i];
	}
	delete [] oldT;
	oldT = copyT;
	for(size_t i=smallersize; i<biggersize; i++)
	{
		oldT[i]=defaultvalue;
	}
	return true;
}

#include <iostream>
template <typename T,size_t N> void showArray(T arr[N])
{
	for(size_t i=0;i<N;i++)
	{
		std::cout << "elem #"<<i<<": "<<arr[i] << std::endl;
	}
	std::cout << std::endl;
	return;
}
// TESTS
int main()
{
	const size_t initsize = 12;
	int* myArr = new int[initsize]{12,89,15,48,26,59,48,212,8,0,16,18};
	
	showArray<int,initsize>(myArr);
	const size_t finalsize= 15;
	
	resize<int>(myArr,initsize,finalsize,0);
	showArray<int,finalsize>(myArr);
	delete [] myArr;
	return 0;
}
