﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public class Box : TwoPointFigure
    {
        private bool _fillFlag;
        public Box(Popup popup, int x, int y)
            : base(popup, x, y)
        {
            _fillFlag = false;
        }
        public Box(Popup popup, int x1, int y1, int x2, int y2)
            : base(popup, x1, y1, x2, y2)
        {
            _fillFlag = false;
        }
        public override void setFill()
        {
            _fillFlag = !_fillFlag;
        }
        public override void draw(Graphics g, Pen pen)
        {
            if (_fillFlag == true)
            {
                Brush br = new SolidBrush(_color);
                g.FillRectangle(br, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
                br.Dispose();
            }
            Color oldColor = pen.Color;
            pen.Color = _color;
            g.DrawRectangle(pen, Math.Min(_x1, _x2), Math.Min(_y1, _y2), Math.Abs(_x2 - _x1), Math.Abs(_y2 - _y1));
            pen.Color = oldColor;            
        }
    }
}
