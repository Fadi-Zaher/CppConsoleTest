#include "CppUnitTest.h"
#include "../CppConsoleAPI/BaseLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



#define HELLO_WORLD_TRIMED			"Hello World"





namespace CppConsoleApplicationTest
{
	TEST_CLASS(CppCommandTest)
	{
		public:	TEST_METHOD(TestCommand)
		{
			std::string s = " \t\n  Hello World  ";
			std::string trimmed = trim(s);
			Assert::IsTrue(0 == trimmed.compare(HELLO_WORLD_TRIMED));
		}
	};
};
