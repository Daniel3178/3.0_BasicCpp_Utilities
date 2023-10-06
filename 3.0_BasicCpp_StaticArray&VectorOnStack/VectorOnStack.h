
#pragma once
#include <iostream>
#include <cassert>
namespace CommonUtilities
{
	template <class T, unsigned int size, typename CountType = unsigned short, bool safeMode = true>
	class VectorOnStack
	{
		T myStackArray[size];
		CountType myCurrentSize;
		CountType myCurrentPos;
		bool myIsAccessable[size];
	public:
		VectorOnStack()
		{
			myCurrentSize = size;
			myCurrentPos = 0;
			myIsAccessable = { false };
		}

		VectorOnStack(const VectorOnStack& aVectorOnStack)
		{
			if(aVectorOnStack.safeMode == false)
			{
				std::memcpy(&myStackArray, aVectorOnStack.myStackArray, sizeof(aVectorOnStack.myStackArray));
				std::memcpy(&myCurrentPos, aVectorOnStack.myCurrentPos, sizeof(aVectorOnStack.myCurrentPos));
				std::memcpy(&myIsAccessable, aVectorOnStack.myIsAccessable, sizeof(aVectorOnStack.myIsAccessable));
			}
			else
			{
				for(int i = 0; i < aVectorOnStack.myCurrentSize; i++)
				{
					this.myStackArray[i] = aVectorOnStack.myStackArray[i];
					this->myIsAccessable[i] = aVectorOnStack.myIsAccessable[i];
				}
				this->myCurrentPos = aVectorOnStack.myCurrentPos;
			}

		}

		~VectorOnStack()
		{
			myIsAccessable = { false };
			myCurrentPos = 0;
			myCurrentSize = 0;
		}

		VectorOnStack& operator=(const VectorOnStack& aVectorOnStack)
		{
			if(!safeMode)
			{
				std::memcpy(&myCurrentPos, &aVectorOnStack.myCurrentPos, sizeof(aVectorOnStack.myCurrentPos));
				std::memcpy(&myCurrentSize, &aVectorOnStack.myCurrentSize, sizeof(aVectorOnStack.myCurrentSize));
				std::memcpy(&myIsAccessable, &aVectorOnStack.myIsAccessable, sizeof(aVectorOnStack.myIsAccessable));
				std::memcpy(&myStackArray, &aVectorOnStack.myStackArray, sizeof(aVectorOnStack.myStackArray));
			}
			else
			{
				this->myCurrentPos = aVectorOnStack.myCurrentPos;
				this->myCurrentSize = aVectorOnStack.myCurrentSize;
				for(int i = 0; i < aVectorOnStack.myCurrentSize; i++)
				{
					this->myIsAccessable[i] = aVectorOnStack.myIsAccessable[i];
					this->myStackArray[i] = aVectorOnStack.myStackArray[i];
				}
			}
			return *this;
		}

		inline T& operator[](const CountType anIndex)
		{
			if(anIndex < 0 || anIndex >= myCurrentSize)
			{
				assert("Index out of range !");
			}

			if(myIsAccessable[anIndex] == true)
			{
				return myStackArray[anIndex];
			}
		}

		inline void Add(const T& anObject)
		{
			if(myCurrentPos >= size)
			{
				assert("The array is full!");
			}

			myStackArray[myCurrentPos] = anObject;
			myIsAccessable[myCurrentPos] = true;
			myCurrentPos++;
			myCurrentSize++;
		}

		inline void Insert(const CountType anIndex, const T& anObject)
		{
			if(anIndex > (size - 1))
			{
				assert("Out of range !");
			}
			else
			{
				if((myCurrentSize + 1) > size)
				{
					assert("Array is full");
				}
				else
				{
					if(anIndex == 0)
					{
						if(!safeMode && myIsAccessable[anIndex] == false)
						{
							std::memcpy(&myStackArray[0], &anObject, sizeof(anObject));
							myIsAccessable[anIndex] == true;
							myCurrentSize++;
						}

						else if(myIsAccessable[anIndex] == false)
						{
							myStackArray[anIndex] == anObject;
							myIsAccessable[anIndex] == true;
							myCurrentSize++;
						}
					}
					else
					{

						T temporary[size];
						for(int i = 0; i < myCurrentSize; i++)
						{
							if(i > anIndex)
							{
								temporary[i] = myStackArray[i];
							}
							else if(i == anIndex)
							{
								temporary[i] = anObject;
							}
							else
							{
								temporary[i] = myStackArray[i];
							}
						}

						if(!safeMode)
						{
							std::memcpy(&myStackArray, &temporary, sizeof(temporary));
						}
						else
						{

							for(int i = 0; i < myCurrentSize; i++)
							{
								myStackArray[i] = temporary[i];
							}
						}

						myCurrentPos++;
						myCurrentSize++;
						myIsAccessable[anIndex + 1] = true;
					}
				}
			}
		}

		inline void RemoveCyclic(const T& anObject)
		{
			int pos = 0;
			T lasObject;

			for(int i = 0; i < size; i++)
			{
				if(myStackArray[i] == anObject)
				{
					pos = i;
					break;
				}
			}

			lasObject = myStackArray[myCurrentSize - 1];
			myStackArray[pos] = lasObject;
			myIsAccessable[myCurrentSize - 1] = false;
			myCurrentSize--;
		}

		inline void RemoveCyclicAtIndex(const CountType anItemNum)
		{
			T lastObject = myStackArray[myCurrentSize - 1];
			myStackArray[anItemNum] = lastObject;
			myIsAccessable[myCurrentSize - 1] = false;
			myCurrentSize--;
		}

		inline void Clear()
		{
			myCurrentSize = 0;
			myCurrentPos = 0;
			myIsAccessable = { false };
		}
	};
}