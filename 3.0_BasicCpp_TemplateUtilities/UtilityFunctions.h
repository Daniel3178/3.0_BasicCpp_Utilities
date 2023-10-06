#pragma once
#include <iostream>
#include <cassert>
namespace CommonUtilities
{
	template <typename T> typename std::enable_if<std::is_arithmetic<T>::value, T>::type Max(const T& aFirstValue, const T& aSecondValue)
	{
		if(aFirstValue < aSecondValue)
		{
			return aSecondValue;
		}
		else if(aFirstValue > aSecondValue)
		{
			return aFirstValue;
		}
		else
		{
			return 0;
		}
	}

	template <const std::string&> const std::string& Max(const std::string& aFirstString, const std::string& aSecondString)
	{
		auto& firstIterator = aFirstString.begin();
		auto& secondIterator = aSecondString.begin();

		while(firstIterator != aFirstString.end() && secondIterator != aSecondString.end() && *firstIterator == *secondIterator)
		{
			firstIterator++;
			secondIterator++;
		}

		if(*firstIterator < *secondIterator)
		{
			return aSecondString;
		}
		else if(*firstIterator > *secondIterator)
		{
			return aFirstString;
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T> typename std::enable_if<std::is_arithmetic<T>::value, T>::type Min(const T& aFirstValue, const T& aSecondValue)
	{
		if(aFirstValue < aSecondValue)
		{
			return aFirstValue;
		}
		else if(aFirstValue > aSecondValue)
		{
			return aSecondValue;
		}
		else
		{
			return 0;
		}
	}

	template <const std::string&> const std::string& Min(const std::string& aFirstString, const std::string& aSecondString)
	{
		auto& firstIterator = aFirstString.begin();
		auto& secondIterator = aSecondString.begin();

		while(firstIterator != aFirstString.end() && secondIterator != aSecondString.end() && *firstIterator == *secondIterator)
		{
			firstIterator++;
			secondIterator++;
		}

		if(*firstIterator < *secondIterator)
		{
			return aFirstString;
		}
		else if(*firstIterator > *secondIterator)
		{
			return aSecondString;
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T> typename std::enable_if<std::is_arithmetic<T>::value, T>::type Abs(const T& aValue)
	{
		if(aValue < 0)
		{
			return aValue * -1;
		}
		
		return aValue;
	}

	template <typename T> typename std::enable_if<std::is_arithmetic<T>::value, T>::type Clamp(const T& aValue, const T& aMinValue, const T& aMaxValue)
	{
		assert(aMaxValue > aMinValue, "The max value is not bigger than the min value! ");

		if(aValue < aMinValue)
		{
			return aMinValue;
		}
		else if(aValue > aMaxValue)
		{
			return aMaxValue;
		}
		else
		{
			return aValue;
		}
	}

	template <typename T> typename std::enable_if<std::is_arithmetic<T>::value, T>::type Lerp(const T& aFirstValue, const T& aSecondValue, const float& aFloatValue)
	{
		return (aFirstValue + aFloatValue * (aSecondValue - aFirstValue));
	}

	template <typename  T> void Swap( T& aFirstType,  T& aSecondType)
	{
		T placeHolder = aFirstType;
		aFirstType = aSecondType;
		aSecondType = placeHolder;
	}
}