
#include "CppUnitTest.h"
#include "../../CppConsoleAPI/Commands/CommandsApi.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



#define	CMD_ECHO_PARAM	"hello echo"
#define	CMD_LINE_ECHO	"echo(hello world)"





bool CommandEcho(std::vector<std::string> params)
{
	return(true);
}





namespace CppConsoleApplicationTest
{
	TEST_CLASS(CppCommandTest)
	{
	
		//Test the command line parser.
		public:	TEST_METHOD(TestParser)
		{
			//	Check command name parsing.
			Assert::IsTrue(CMD_ECHO == CommandName(CMD_LINE_ECHO));

			// Check command parameters parsing.
			std::vector<std::string> params = CommandParams(CMD_LINE_ECHO);
			Assert::IsTrue(1 == params.size());
			return;
		}
		
		//	Test the echo command function.
		public:	TEST_METHOD(TestEcho)
		{
			std::vector<std::string> params = CommandParams(CMD_LINE_ECHO);
			Assert::IsTrue(CommandEcho(params));
			return;
		}

		//	Test the commands list using the echo command function.
		public:	TEST_METHOD(TestCommandEcho)
		{
				//	Check creating a new commands list.
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);

				//	Check adding echo command to commands list.
				Assert::IsTrue(CommandAdd(pCommands, CMD_ECHO, CommandEcho));

				//	Execute the echo command in the command list.
				Assert::IsTrue(CommandExec(pCommands, CMD_LINE_ECHO));
				return;
		}
	};
}
