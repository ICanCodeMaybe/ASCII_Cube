#ifndef CORE_H
#define CORE_H

namespace math{
	class Vec2;
}

class Core{
private:
	Core(){}
	static Core* s_instance;

public:
	static Core* GetCore();
	static void SignalHandler(int signal_num);	
	static void MainLoop();
	static void Close();
	static void SetWidthHeight(int width, int height){s_width = width; s_height=height;}
	static float GetTime();

	static math::Vec2 GetSize();

	static float delta_time;
	
	static int fps;
private:
	static float current_time;
	static float end_time;

	static float start_time;

	static bool app_should_close;

	static int s_width;
	static int s_height;
};

#endif
