#pragma once

#include <fstream>
using namespace std;

class Logger
{
	Logger() {};

	static Logger* instance;

public:
	Logger(Logger&) = delete;

	Logger& operator = (Logger&) = delete;

	void LogError(string error)
	{
		ofstream fout("C:\\Users\\МаРіЧкА\\source\\repos\\Bookshop4\\Bookshop4\\errors.txt");
		fout << error << endl;

		fout.close();
	}

	static Logger* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Logger();
		}

		return instance;
	}
};

Logger* Logger::instance = nullptr;
