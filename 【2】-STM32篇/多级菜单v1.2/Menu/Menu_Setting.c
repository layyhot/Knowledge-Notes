#include "menu.h" 

struct option_class option_list[];

void Set_CursorStyle(void)
{
	if(CurStyle == reverse)
	{
		CurStyle = mouse;
		option_list[1].Name = "光标风格[鼠标]";
	}
	else if(CurStyle == mouse)
	{
		CurStyle = frame;
		option_list[1].Name = "光标风格[矩形]";
	}
	else //if(CurStyle == frame)
	{
		CurStyle = reverse;
		option_list[1].Name = "光标风格[反相]";
	}
}

void Set_animation_speed(void)
{
	if(Speed_Factor == 8)
	{
		Speed_Factor = 16;
		Roll_Speed = 1.1;
		option_list[2].Name = "动画速度[慢]";
	}
	else if(Speed_Factor == 16)
	{
		Speed_Factor = 1;
		Roll_Speed = 16;
		option_list[2].Name = "动画速度[关]";
	}
	else //if(Speed_Factor == 16)
	{
		Speed_Factor = 8;
		Roll_Speed = 2;
		option_list[2].Name = "动画速度[快]";
	}
}

void Setting_menu(void)
{
	run_menu(option_list);
}
struct option_class option_list[] = {
	{"退出"},
	{"光标风格[反相]", Set_CursorStyle},
	{"动画速度[快]", Set_animation_speed},
	{".."}
};
