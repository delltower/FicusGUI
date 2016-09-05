#include "CEdit.h"

void CEdit::onDraw(CAdaptor* pAda)
{
	if (pAda){
		pAda->beginDraw(rect);
		CWidget::onDraw(pAda);
		if (isText){
			pAda->drawText(title, rect.x1, rect.y1, foreColor);
		}
		if (isCursor){
			short width = pAda->getTextWidth("A");
			short x = pAda->getTextWidth(title) + 1;
			if (x > rect.getWidth())
				x = rect.getWidth();
			pAda->line(rect.x1 + width * cursorPos, rect.y1, rect.x1 + width * cursorPos, rect.y2, COLOR_RED);
		}

		pAda->endDraw();
	}
}
//处理鼠标点击
void CEdit::onMouseDown(SPoint& point)
{
	setFocus(true);
	CAdaptor::getAdaptor()->registerTimer(this, 3000);
}
//处理计时器
void CEdit::onTimer()
{
	if (isFocus()){
		isCursor = !isCursor;
		//isText = false;
		requestDraw();
	}
}
//处理键盘消息
void CEdit::onKey(SMsg& msg)
{
	if (msg.keyData == FVK_BACK){
		//删除,backspace
		int size = strlen(title);
		if (size > 0 && cursorPos > 0){
			for (int i = cursorPos - 1; i < (size - 1); i++){
				title[i] = title[i + 1];
			}
			title[size - 2] = '\0';
			setCursorPos(size - 1);
			setCursor(true);
			requestDraw();
		}
	}
	else if (msg.keyData == FVK_DELETE){
		//删除,delete
		unsigned size = strlen(title);
		if (size > 0 && (unsigned)cursorPos < size){
			for (unsigned i = cursorPos; i < (size - 1); i++){
				title[i] = title[i + 1];
			}
			title[size - 1] = '\0';
			setCursor(true);
			requestDraw();
		}
	}
	else if (msg.keyData == FVK_LEFT || msg.keyData == FVK_RIGHT){
		//左移
		if (cursorPos > 0 && msg.keyData == FVK_LEFT){
			cursorPos--;
			setCursor(true);
			requestDraw();
		}
		else if (msg.keyData == FVK_RIGHT){ //右移
			unsigned size = strlen(title);
			if ((unsigned)cursorPos < size){
				cursorPos++;
				setCursor(true);
				requestDraw();
			}
		}
	}
	else {
		//插入
		unsigned size = strlen(title);
		if (size == cursorPos) //光标在末尾
		{
			char* str = new char[size + 2];
			str[size] = (char)msg.keyData;
			for (unsigned i = 0; i < size; i++)
				str[i] = title[i];
			str[size + 1] = '\0';

			setCursorPos(size + 1);
			setCursor(true);
			char* temp = str;
			str = title;
			title = temp;

			if (str) delete str;
			requestDraw();
		}
		else {
			char* str = new char[size + 2];
			for (int i = 0; i < cursorPos; i++){
				str[i] = title[i];
			}
			for (int i = size; i > cursorPos; i--){
				str[i] = title[i - 1];
			}
			str[cursorPos] = (char)msg.keyData;
			str[size + 1] = '\0';
			setCursor(true);
			char* temp = str;
			str = title;
			title = temp;

			if (str) delete str;
			requestDraw();
		}
	}

}