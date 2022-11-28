#ifndef CORE_H
#define CORE_H

class Core{
private:
	Core(){}
	static Core* s_instance;

public:
	static Core* GetCore();
	static void SignalHandler(int signal_num);	
	static void MainLoop();

private:

	static bool app_should_close;
};

#endif
