
#include "CppUnitTest.h"
#include "../../CppConsoleAPI/Commands/CommandsApi.h"
#include "../../CppConsoleAPI/ConsoleApplication/AppCommands.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



#define	CMD_ECHO_PARAM	"hello echo"
#define	CMD_LINE_ECHO	"echo(hello world)"
#define CMD_ADD_PARAM   "add(1,1,1,1)"
#define CMD_MULL_PARAM   "mul(1,1,1,1)"
#define CMD_DIV_PARAM   "div(1,1,1,1)"
#define CMD_SUB_PARAM   "sub(1,1,1,1)"






bool CommandEcho(std::vector<std::string> params)
{
	return(true);
}
bool CommandAddition(std::vector<std::string> params)
{
	return(true);
}
bool CommandSubtraction(std::vector<std::string> params)
{
	return(true);
}
bool CommandMultiplying(std::vector<std::string> params)
{
	return(true);
}
bool CommandDividing(std::vector<std::string> params)
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

		//	Test the echo command function.
		public:	TEST_METHOD(TestAdd)
		{
			std::vector<std::string> params = CommandParams(CMD_ADD_PARAM);
			Assert::IsTrue(CommandAddition(params));
			return;
		}
		public:	TEST_METHOD(TestSub)
		{
			std::vector<std::string> params = CommandParams(CMD_SUB_PARAM);
			Assert::IsTrue(CommandAddition(params));
			return;
		}
		public:	TEST_METHOD(TestMul)
		{
			std::vector<std::string> params = CommandParams(CMD_MULL_PARAM);
			Assert::IsTrue(CommandAddition(params));
			return;
		}
		public:	TEST_METHOD(TestDiv)
		{
			std::vector<std::string> params = CommandParams(CMD_DIV_PARAM);
			Assert::IsTrue(CommandAddition(params));
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

		public:	TEST_METHOD(TestCommandAddition)
		{
				//	Check creating a new commands list.
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);

				//	Check adding echo command to commands list.
				Assert::IsTrue(CommandAdd(pCommands, CMD_ADD, CommandAddition));

				//	Execute the echo command in the command list.
				Assert::IsTrue(CommandExec(pCommands, CMD_ADD_PARAM));
				return;
		}

		public:	TEST_METHOD(TestCommandSubtraction)
		{
				//	Check creating a new commands list.
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);

				//	Check adding echo command to commands list.
				Assert::IsTrue(CommandAdd(pCommands, CMD_SUB, CommandSubtraction));

				//	Execute the echo command in the command list.
				Assert::IsTrue(CommandExec(pCommands, CMD_SUB_PARAM));
				return;
		}
		
		public:	TEST_METHOD(TestCommandMultiplying)
		{
				//	Check creating a new commands list.
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);

				//	Check adding echo command to commands list.
				Assert::IsTrue(CommandAdd(pCommands, CMD_MUL, CommandMultiplying));

				//	Execute the echo command in the command list.
				Assert::IsTrue(CommandExec(pCommands, CMD_MULL_PARAM));
				return;
		}

		public:	TEST_METHOD(TestCommandDividing)
		{
				//	Check creating a new commands list.
				Commands* pCommands = CommandsInit();
				Assert::IsNotNull(pCommands);

				//	Check adding echo command to commands list.
				Assert::IsTrue(CommandAdd(pCommands, CMD_DIV, CommandDividing));

				//	Execute the echo command in the command list.
				Assert::IsTrue(CommandExec(pCommands, CMD_DIV_PARAM));
				return;
		}
	};
}
