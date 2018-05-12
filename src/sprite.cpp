#include "sprite.h"
#include "utils.h"

void Sprite2D::SetImage(const char* imagePath)
{
	mTexture = CreateTexture2DFromPNG(imagePath);
}

void Sprite2D::SetRect(float x, float y, float width, float height)
{
	mVertexes[0].x = x;
	mVertexes[0].y = y;
	mVertexes[1].x = x + width;
	mVertexes[1].y = y;
	mVertexes[2].x = x + width;
	mVertexes[2].y = y + height;
	mVertexes[3].x = x;
	mVertexes[3].y = y + height;
}
void Sprite2D::Draw()
{
	glEnable(GL_BLEND); // 对png开启alpha混合透明
	// 源采用的alpha 、 目标采用的alpha
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 最终画面 = SRC * SRC_ALPHA + DST * ( 1 - SRC_ALPHA )


	glDisable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glColor4ub(255, 255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(mVertexes[0].x, mVertexes[0].y, mVertexes[0].z);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(mVertexes[1].x, mVertexes[1].y, mVertexes[1].z);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(mVertexes[2].x, mVertexes[2].y, mVertexes[2].z);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(mVertexes[3].x, mVertexes[3].y, mVertexes[3].z);
	glEnd();

	glDisable(GL_BLEND);
}