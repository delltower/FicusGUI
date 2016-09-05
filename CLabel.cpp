#include "CLabel.h"

void CLabel::onDraw(CAdaptor* pAda)
{
	CWidget::onDraw(pAda);
	if (pAda){
		pAda->fillRect(getRect(), bgColor, bgColor);
		if (title)
			pAda->drawText(title, rect.x1, rect.y1, foreColor);
	}
}