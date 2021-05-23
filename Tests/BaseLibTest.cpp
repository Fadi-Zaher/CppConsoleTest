// Include files.
#include "CppUnitTest.h"
#include "../../CppConsoleAPI/BaseLib/BaseLib.h"


//	Impoerted namespaces.
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



//	Constants.
#define HELLO_WORLD_TRIMED			"Hello World"


//Test namespace.
namespace CppConsoleApplicationTest
{
	//	String trimming test.
	TEST_CLASS(CppBaseLibTest)
	{
		//	Right left string trimming test.
		public:	TEST_METHOD(TestTrim)
		{
			std::string trimmed = trim(" \t\n  Hello World  ");
			Assert::IsTrue(0 == trimmed.compare(HELLO_WORLD_TRIMED));
		}
	};
};
