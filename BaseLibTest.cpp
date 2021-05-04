#include "CppUnitTest.h"
#include "../CppConsoleAPI/BaseLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



#define HELLO_WORLD_TRIMED			"Hello World"





namespace CppConsoleApplicationTest
{
	TEST_CLASS(CppCommandTest)
	{
		public:	TEST_METHOD(TestTrim)
		{
			std::string trimmed = trim(" \t\n  Hello World  ");
			Assert::IsTrue(0 == trimmed.compare(HELLO_WORLD_TRIMED));
		}
	};
};
