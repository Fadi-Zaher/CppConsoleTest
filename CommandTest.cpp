#include "CppUnitTest.h"
#include "../CppConsoleAPI/Command.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




#define	CMD_LINE_ECHO	"echo(hello world)"





bool CommandEcho(std::vector<std::string> params)
{
	return(true);
}





namespace CppConsoleApplicationTest
{

	TEST_CLASS(CppCommandTest)
	{
		public:	TEST_METHOD(TestCommand)
		{
			Assert::IsTrue(CMD_ECHO == CommandName(CMD_LINE_ECHO));

			std::vector<std::string> params = CommandParams(CMD_LINE_ECHO);
			Assert::IsTrue(params.size() == 0);
		}
		

		public:	TEST_METHOD(TestCommands)
		{
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);
				Assert::IsTrue(CommandAdd(pCommands, CMD_ECHO, CommandEcho));
				Assert::IsTrue(CommandExec(pCommands, CMD_LINE_ECHO));
				return;
		}
	};
}
