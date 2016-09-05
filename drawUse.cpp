void FG_Group::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_Widget::OnDraw(pAdaptor);

	if (TextLength())
	{
        // 画标题
		FG_Rect rect;
		GetClientRect(rect);
		WORD x;
		x = pAdaptor->GetTextWidth(GetText());

		// 画边框
		FG_Point p[6];
		p[0].y = p[1].y = p[4].y = p[5].y = rect.wTop + 6;
		p[0].x = rect.wLeft + 16;
		p[1].x = p[2].x = rect.wLeft;
		p[2].y = p[3].y = rect.wBottom - 1;
		p[3].x = p[4].x = rect.wRight - 1;
		p[5].x = rect.wLeft + 20 + x;
		pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

		p[0].y = p[1].y = rect.wTop + 7;
		p[0].x = rect.wLeft + 16;
        p[1].x = p[2].x = rect.wLeft + 1;
        p[2].y = rect.wBottom - 2;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        p[0].y = p[1].y = rect.wBottom;
        p[0].x = rect.wLeft;
        p[1].x = p[2].x = rect.wRight;
        p[2].y = rect.wTop + 6;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        pAdaptor->Line(rect.wLeft + 20 + x, rect.wTop + 7, rect.wRight - 2, rect.wTop + 7, COLOR_WHITE);

        pAdaptor->DrawText(GetText(), rect.wLeft+18, rect.wTop+1, m_ForeColor);
	}

	pAdaptor->EndDraw();
}

