#include "Unittest.h"
#include <iostream>
#include "UtilityFunctions.h"

namespace myUnittest
{
	void Unittest::MinTest()
	{
		const uint8_t TEST_SET_SIZE { 6 };

		int testSetForFirstParm[TEST_SET_SIZE] = { 1,2,-1,0,-10,-5 };
		int testSetForSecondParm[TEST_SET_SIZE] = { 2,1,0,-1,-5,-10 };

		std::cout << "\n\n\tUnittest is running for Min function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 << '\n';
			std::cout << "\t::First parameter : " << testSetForFirstParm[i] << '\n';
			std::cout << "\t::Second parameter : " << testSetForSecondParm[i] << '\n';
			std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Min(testSetForFirstParm[i], testSetForSecondParm[i])) << '\n';
			std::cout << "\t---------------------------------------";
		}
	}

	void Unittest::MaxTest()
	{
		const uint8_t TEST_SET_SIZE { 6 };

		int testSetForFirstParm[TEST_SET_SIZE] = { 4,2,-1,0,-10,-50 };
		int testSetForSecondParm[TEST_SET_SIZE] = { 2,4,0,-1,-50,-10 };

		std::cout << "\n\n\tUnittest is running for Max function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 << '\n';
			std::cout << "\t::First parameter : " << testSetForFirstParm[i] << '\n';
			std::cout << "\t::Second parameter : " << testSetForSecondParm[i] << '\n';
			std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Max(testSetForFirstParm[i], testSetForSecondParm[i])) << '\n';
			std::cout << "\t---------------------------------------";
		}
	}

	void Unittest::ClampTest()
	{
		const uint8_t TEST_SET_SIZE { 9 };
		const int MIN_VALUE_ONE { 2 };
		const int MAX_VALUE_ONE { 10 };
		const int MIN_VALUE_TWO { -30 };
		const int MAX_VALUE_TWO { -10 };

		int testSet[TEST_SET_SIZE] = { 4, 10, 2, 12, 0, 3, 5, 6, 8 };
		std::cout << "\n\n\tUnittest is running for Clamp function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 << '\n';
			std::cout << "\t::First parameter (value) : " << testSet[i] << '\n';
			std::cout << "\t::Second parameter (min) : " << MIN_VALUE_ONE/*(i > 4 && i <= 7) ? MIN_VALUE_TWO : MIN_VALUE_ONE*/ << '\n';
			std::cout << "\t::Third parameter (Max) : " << MAX_VALUE_ONE/*(i > 7) ? MAX_VALUE_TWO : MAX_VALUE_ONE*/ << '\n';
			std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Clamp(testSet[i], MIN_VALUE_ONE, MAX_VALUE_ONE/*(i > 4 && i <= 7) ? MIN_VALUE_TWO : MIN_VALUE_ONE, (i > 7) ? MAX_VALUE_TWO : MAX_VALUE_ONE*/)) << '\n';
			std::cout << "\t---------------------------------------";
		}
		//std::cout << "\n\t::First parameter (value) : " << 4 << '\n';
		//std::cout << "\t::Second parameter (min) : " << 20 << '\n';
		//std::cout << "\t::Third parameter (Max) : " << 10 << '\n';
		//std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Clamp(4, 20, 10)) << '\n';
		//std::cout << "\t---------------------------------------\n";
	}
	void Unittest::AbsTest()
	{
		const uint8_t TEST_SET_SIZE { 2 };

		int testSet[TEST_SET_SIZE] = { 1, -2 };

		std::cout << "\n\n\tUnittest is running for Abs function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 << '\n';
			std::cout << "\t::First parameter : " << testSet[i] << '\n';
			std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Abs(testSet[i])) << '\n';
			std::cout << "\t---------------------------------------";
		}
	}
	void Unittest::SwapTest()
	{
		const uint8_t TEST_SET_SIZE { 4 };

		int testSetForFirstParm[TEST_SET_SIZE] = { 4,2,-1,0 };
		int testSetForSecondParm[TEST_SET_SIZE] = { 2,4,0,-1 };

		std::cout << "\n\n\tUnittest is running for Swap function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 << '\n';
			std::cout << "\tBEFORE function call\n";
			std::cout << "\t::First value : " << testSetForFirstParm[i] << '\n';
			std::cout << "\t::Second value : " << testSetForSecondParm[i] << '\n';
			std::cout << "\n\tAFTER function call\n";
			CommonUtilities::Swap(testSetForFirstParm[i], testSetForSecondParm[i]);
			std::cout << "\t::First value : " << testSetForFirstParm[i] << '\n';
			std::cout << "\t::Second value : " << testSetForSecondParm[i] << '\n';
			std::cout << "\t---------------------------------------";
		}
	}
	void Unittest::LerpTest()
	{
		const uint8_t TEST_SET_SIZE { 3 };

		float testSet[TEST_SET_SIZE] = { 0, 1, 0.5 };

		std::cout << "\n\n\tUnittest is running for Lerp function, the number of test : " << static_cast<int>(TEST_SET_SIZE) << '\n';
		for(int i = 0; i < TEST_SET_SIZE; i++)
		{
			std::cout << "\n\t::TEST #" << i + 1 <<'\n';
			std::cout << "\t::Lerp value : " << testSet[i] << '\n';
			std::cout << "\t::Function returned : " << static_cast<int>(CommonUtilities::Lerp(2, 4, testSet[i])) << '\n';
			std::cout << "\t---------------------------------------";
		}
	}
	void Unittest::RunTest()
	{
		std::cout << "\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		std::cout << "\tUNITTEST PROJECT \n";
		std::cout << "\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		MinTest();
		MaxTest();
		ClampTest();
		AbsTest();
		SwapTest();
		LerpTest();
		std::cout << "\n\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		std::cout << "\tEND \n";
		std::cout << "\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

	}
}