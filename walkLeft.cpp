#include "stdafx.h"
#include "Bob.h"

int Bob::walkLeft()
{
	if (rectSourceSprite2.left == 128)
	{
		m_Position.x -= 4 * m_Scale.x;
		rectSourceSprite1.left += 16;
		rectSourceSprite2.left += 16;
	}
	else if (rectSourceSprite2.left == 144)
	{
		m_Position.x -= 4 * m_Scale.x;
		rectSourceSprite1.left += 16;
		rectSourceSprite2.left += 16;
	}
	else if (rectSourceSprite2.left == 160)
	{
		m_Position.x -= 4 * m_Scale.x;
		rectSourceSprite1.left += 16;
		rectSourceSprite2.left += 16;
	}
	else if (rectSourceSprite2.left == 176)
	{
		m_Position.x -= 4 * m_Scale.x;
		rectSourceSprite1.left = 128;
		rectSourceSprite2.left = 128;
		m_Position_Direction = "STOP";
	}
	return rectSourceSprite2.left;
}