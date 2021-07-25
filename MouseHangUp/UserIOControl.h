#pragma once
#include <windows.h>
#pragma comment(lib, "user32.lib")
#include <vfw.h>
#pragma comment( lib, "Vfw32.lib" )
#include<vector>
namespace IOControl
{
	//mouse
	bool SetMousePosition(int xpos, int ypos);
	bool GetMousePosition(LPPOINT position);
	void Mouse_Left_Click(int xpos, int ypos);
	void Mouse_Right_Click(int xpos, int ypos);
	void Mouse_move(int xpos, int ypos);

	//keyboard
	
}