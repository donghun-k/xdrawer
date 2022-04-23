using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XDrawer
{
    public abstract class Figure
    {
        protected Color _color;
        protected Popup _popup;
        protected Region _region;
        public Figure(Popup popup)
        {
            _color = Color.Black;
            _popup = popup;
        }
        public void setColor(Color color)
        {
            _color=color;
        }
        public void popup(System.Drawing.Point pos)
        {
            _popup.popup(pos);
        }
        public bool ptInRegion(int x, int y)
        {
            if(_region != null)
            {
                return _region.IsVisible(x, y);
            }
            else
            {
                return false;
            }
        }
        public virtual void setFill()
        {

        }
        // hook function
        public virtual int getX1()
        {
            return -1;
        }
        public virtual int getY1()
        {
            return -1;
        }
        public virtual int getX2()
        {
            return -1;
        }
        public virtual int getY2()
        {
            return -1;
        }
        public virtual String getClassName()
        {
            return "Figure"; 
        }              
        public virtual void drawing(IntPtr hdc, int newX, int newY)
        {
            draw(hdc);
            setXY2(newX, newY);
            draw(hdc);
        }
        public virtual void move(IntPtr hdc, int dx, int dy)
        {
            draw(hdc);
            move(dx, dy);
            draw(hdc);
        }
        public abstract void draw(Graphics g, Pen pen);
        public abstract void setXY2(int newX, int newY);
        public abstract void makeRegion();
        public abstract Figure clone();
        public abstract void move(int dx, int dy);
        public abstract void draw(IntPtr hdc);
    }
}
