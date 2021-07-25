#include"UserIOControl.h"

namespace IOControl 
{
	bool SetMousePosition(int xpos, int ypos)
	{
		return SetCursorPos(xpos, ypos);
	}
	bool GetMousePosition(LPPOINT position)
	{
		return GetCursorPos(position);
	}
	void Mouse_Left_Click(int xpos, int ypos)
	{
		SetCursorPos(xpos, ypos);
		mouse_event(MOUSEEVENTF_LEFTDOWN, xpos, ypos, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, xpos, ypos, 0, 0);
	}
	void Mouse_Right_Click(int xpos, int ypos)
	{
		SetCursorPos(xpos, ypos);
		mouse_event(MOUSEEVENTF_RIGHTDOWN, xpos, ypos, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, xpos, ypos, 0, 0);
	}
	void Mouse_move(int xpos, int ypos)
	{
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK | MOUSEEVENTF_MOVE, xpos, ypos, 0, 0);
	}

}