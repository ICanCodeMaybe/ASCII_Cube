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
	static void Close();

	static float GetTime();

	static float delta_time;
	
	static int fps;
private:
	static float current_time;
	static float end_time;

	static float start_time;

	static bool app_should_close;
};

#endif
