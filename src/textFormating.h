#ifndef FORMATING_H
#define FORMATING_H

#define NORMAL_TEXT		"\033[39m"
#define RED_TEXT 		"\033[31m"
#define BLACK_TEXT 		"\033[30m"
#define BLUE_TEXT 		"\033[34m"
#define GREEN_TEXT 		"\033[32m"
#define YELLOW_TEXT 		"\033[33m"
#define MAGENTA_TEXT 		"\033[35m"
#define CYAN_TEXT 		"\033[36M"

#define BACKGROUND_NORMAL	"\033[49m"
#define BACKGROUND_RED		"\033[41m"
#define BACKGROUND_BLACK	"\033[40m"
#define BACKGROUND_BLUE		"\033[44m"
#define BACKGROUND_GREEN	"\033[42m"
#define BACKGROUND_YELLOW	"\033[43m"
#define BACKGROUND_MAGENTA	"\033[45m"
#define BACKGROUND_CYAN		"\033[46m"

#define CLEAR_SCREEN "\033[2J"

//#define SET_CURSOR_POS(widht, height) (std::cout << "\033["+ #width + ";" + #height + "N")

#define SET_CURSOR_POS(width, height) new const char** message =  "\033[" + #width + ";" + #height+ "H"; \
	std::cout << message; \
	delete message

#endif
