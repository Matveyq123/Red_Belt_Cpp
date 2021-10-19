#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
	explicit Logger(ostream& output_stream) : _os(output_stream) {
	}
    
	void SetLogLine(bool value) { log_line = value; }
	void SetLogFile(bool value) { log_file = value; }
    
    void SetFile(const std::string& filename)
    {
        _filename = filename;
    }

    void SetLine(const unsigned int& line)
    {
        _line = line;
    }

	void Log(const string& message)
    {
        if (log_file)
        {
            log_line ? _os << _filename << ":" << _line << " " : _os << _filename << " ";
        }
        else if (log_line)
        {
            log_file ? _os << _filename << ":" << _line << " " : _os << "Line " << _line << " ";
        }
        _os << message << "\n";
    }

private:
	ostream&         _os;
    std::string      _filename;
    unsigned int     _line;

	bool log_line = false;
	bool log_file = false;
};

#define LOG(logger, message)    \
{                               \
    logger.SetLine(__LINE__);   \
    logger.SetFile(__FILE__);   \
    logger.Log(message);        \
}

void TestLog() {
	/* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
	 * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
	 * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
	 * � ��� ���� �������� ������. ��� ��������.
	 *
	 * ����� ����� ��������, �� ���������� ����������� ������ #line
	 * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
	 * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
	 * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
	 * ��� �� ��������� ����� ���*/
#line 1 "logger.cpp"

	ostringstream logs;
	Logger l(logs);
	LOG(l, "hello");

	l.SetLogFile(true);
	LOG(l, "hello");

	l.SetLogLine(true);
	LOG(l, "hello");

	l.SetLogFile(false);
	LOG(l, "hello");

	string expected = "hello\n";
	expected += "logger.cpp hello\n";
	expected += "logger.cpp:10 hello\n";
	expected += "Line 13 hello\n";
	ASSERT_EQUAL(logs.str(), expected);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestLog);
}
