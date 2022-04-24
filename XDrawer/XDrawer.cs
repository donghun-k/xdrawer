using System.Drawing.Printing;
namespace XDrawer
{
    public partial class XDrawer : Form
    {
        public static int DRAW_POINT = 1;
        public static int DRAW_LINE = 2;
        public static int DRAW_BOX = 3;
        public static int DRAW_CIRCLE = 4;
        public static int DRAW_KITE = 5;

        static int R2_NOTXORPEN = 10;

        static int MOUSE_DEFAULT = 0;
        static int MOUSE_DRAWING = 1;
        static int MOUSE_MOVING = 2;

        int _whatToDraw;

        public Popup mainPopup = null;
        public Popup pointPopup = null;
        public Popup linePopup = null;
        public Popup boxPopup = null;
        public Popup circlePopup = null;
        public Popup kitePopup = null;

        Figure _selectedFigure;
        List<Figure> _figures;        
        Color _currentColor;

        int _actionMode;
        int _currentX;
        int _currentY;

        public PictureBox Canvas
        {
            get { return canvas; }
        }
        public List<Figure> Figures
        {
            get { return _figures; }
        }
        public Color CurrentColor
        {
            get { return _currentColor; } 
            set { _currentColor = value; }
        }

        public XDrawer()
        {            
            InitializeComponent();
            _figures = new List<Figure>();
            _whatToDraw = DRAW_LINE;
            _currentColor = Color.Black;
            _selectedFigure = null;
            _actionMode = MOUSE_DEFAULT;
            _currentX = 0;
            _currentY = 0;

            mainPopup = new MainPopup(this);
            pointPopup = new FigurePopup(this, "Point", false);
            linePopup = new FigurePopup(this, "Line", false);
            boxPopup = new FigurePopup(this, "Box", true);
            circlePopup = new FigurePopup(this, "Circle", true);
            kitePopup = new FigurePopup(this, "Kite", false);

            toolStripBlackButton.Image = Image.FromFile("Black.png");
            toolStripRedButton.Image = Image.FromFile("Red.png");
            toolStripYellowButton.Image = Image.FromFile("Yellow.png");
            toolStripBlueButton.Image = Image.FromFile("Blue.png");

            toolStripSelectBox.Items.Add("Point");
            toolStripSelectBox.Items.Add("Line");
            toolStripSelectBox.Items.Add("Box");
            toolStripSelectBox.Items.Add("Circle");
            toolStripSelectBox.Items.Add("Kite");
            toolStripSelectBox.SelectedIndex = 1;
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                _selectedFigure = null;
                foreach (Figure ptr in _figures)
                {
                    if (ptr.ptInRegion(e.X, e.Y))
                    {
                        _selectedFigure = ptr;
                        break;
                    }
                }
                if (_selectedFigure != null)
                {
                    _selectedFigure.popup(e.Location);
                }
                else
                {
                    mainPopup.popup(e.Location);
                }     
                return;
            }

            _selectedFigure = null;
            foreach (Figure ptr in _figures)
            {
                if (ptr.ptInRegion(e.X, e.Y))
                {
                    _selectedFigure = ptr;
                    break;
                }
            }
            if (_selectedFigure != null)
            {
                _actionMode = MOUSE_MOVING;
                _figures.Remove(_selectedFigure);
                _currentX = e.X;
                _currentY = e.Y;
                return;
            }

            if (_whatToDraw == DRAW_POINT)
            {             
                _selectedFigure = new Point(pointPopup, e.X, e.Y);
            }
            else if (_whatToDraw == DRAW_LINE)
            {
                // upcasting
                _selectedFigure = new Line(linePopup, e.X, e.Y);                
            }
            else if (_whatToDraw == DRAW_BOX)
            {
                _selectedFigure = new Box(boxPopup, e.X, e.Y);
            }
            else if (_whatToDraw == DRAW_CIRCLE)
            {
                _selectedFigure = new Circle(circlePopup, e.X, e.Y);
            }
            else if (_whatToDraw == DRAW_KITE)
            {
                _selectedFigure = new Kite(kitePopup, e.X, e.Y);
            }
            _selectedFigure.setColor(_currentColor);
            _actionMode = MOUSE_DRAWING;
        }

        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            if (_selectedFigure == null) return;

            if (_actionMode != MOUSE_DEFAULT)
            {
                int eX = e.X;
                int eY = e.Y;

                Graphics g = canvas.CreateGraphics();

                Pen pen = new Pen(Color.Black);                             

                // dynamic binding
                _selectedFigure.draw(g, pen);
                               
                g.Dispose(); // garbage collection!  
            }
            
            if (e.Button == MouseButtons.Left)
            {
                _selectedFigure.makeRegion();
                _figures.Add(_selectedFigure);
                _selectedFigure = null;
            }                        
            // reset canvas -> result in canvas_Paint()
            canvas.Invalidate();
            _actionMode = MOUSE_DEFAULT;
        }

        [System.Runtime.InteropServices.DllImport("gdi32.dll")]
        internal static extern int SetROP2(IntPtr hdc, int rop2);
        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            positionLable.Text = "X : " + e.X + ", Y : " + e.Y;

            bool inFigure = false;
            foreach (Figure ptr in _figures)
            {
                if(ptr.ptInRegion(e.X, e.Y))
                {
                    inFigure = true;
                    break;
                }
            }
            if (inFigure == true)
            {
                Cursor = Cursors.NoMove2D;
            }
            else
            {
                Cursor = Cursors.Default;
            }

            if(_actionMode == MOUSE_DEFAULT) { return; }

            int newX = e.X;
            int newY = e.Y;

            Graphics g = canvas.CreateGraphics();
            IntPtr hdc = g.GetHdc();
            int oldMode = SetROP2(hdc, R2_NOTXORPEN);

            if (_actionMode == MOUSE_DRAWING)
            {
                _selectedFigure.drawing(hdc, newX, newY);
                SetROP2(hdc, oldMode);
                g.ReleaseHdc(hdc);
                g.Dispose(); // garbage collection!
            } else if (_actionMode == MOUSE_MOVING)
            {
                _selectedFigure.move(hdc, newX - _currentX, newY - _currentY);
                _currentX = newX;
                _currentY = newY;  
            }
        }

        public void addFigure(Figure fig)
        {
            fig.makeRegion();
            _figures.Add(fig);
            canvas.Invalidate();
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Color.DarkRed);    
            
            foreach(Figure ptr in _figures)
            {
                ptr.draw(g, pen);
            }
        }

        private void canvas_Click(object sender, EventArgs e)
        {

        }

        private void figureToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        public void setFigureTypeLable(String s)
        {
            figureTypeLable.Text = s;
        }
        public void pointToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_POINT;
            setFigureTypeLable("Point");
        }
        public void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_LINE;
            setFigureTypeLable("Line");
        }
        public void boxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_BOX;
            setFigureTypeLable("Box");
        }        
        public void circleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_CIRCLE;
            setFigureTypeLable("Circle");
        }
        public void kiteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_KITE;
            setFigureTypeLable("Kite");
        }
        private void modalDialogToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FigureDialog dlg = new FigureDialog(this);

            dlg.ShowDialog();
        }

        private void modalessDialogToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FigureDialog dlg = new FigureDialog(this);
            dlg.Show();
        }
        public void deleteFigure(object sender, EventArgs e)
        {
            if (_selectedFigure == null) return;
            _figures.Remove(_selectedFigure);
            canvas.Invalidate();
        }   
        private void setColor(Color color)
        {
            if (_selectedFigure == null) return;
            _selectedFigure.setColor(color);
            canvas.Invalidate();
        }
        public void setBlackColor(object sender, EventArgs e)
        {
            setColor(Color.Black);
        }
        public void setRedColor(object sender, EventArgs e)
        {
            setColor(Color.Red);
        }
        public void setYellowColor(object sender, EventArgs e)
        {
            setColor(Color.Yellow);
        }
        public void setBlueColor(object sender, EventArgs e)
        {
            setColor(Color.Blue);
        }
        public void setFill(object sender, EventArgs e)
        {
            if (_selectedFigure == null) return;
            _selectedFigure.setFill();
            canvas.Invalidate();
        }
        public void copyFigure(object sender, EventArgs e)
        {
            if (_selectedFigure == null) return;
            Figure newFigure = _selectedFigure.clone();
            newFigure.move(10, 20);
            addFigure(newFigure);
        }

        private void toolStripBlackButton_Click(object sender, EventArgs e)
        {
            _currentColor = Color.Black;
        }

        private void toolStripRedButton_Click(object sender, EventArgs e)
        {
            _currentColor = Color.Red;
        }

        private void toolStripYellowButton_Click(object sender, EventArgs e)
        {
            _currentColor = Color.Yellow;
        }

        private void toolStripBlueButton_Click(object sender, EventArgs e)
        {
            _currentColor = Color.Blue;
        }

        private void toolStripSelectBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (toolStripSelectBox.SelectedIndex + 1 == XDrawer.DRAW_POINT)
            {
                pointToolStripMenuItem_Click(sender, e);
            }
            else if (toolStripSelectBox.SelectedIndex + 1 == XDrawer.DRAW_LINE)
            {
                lineToolStripMenuItem_Click(sender, e);
            }
            else if (toolStripSelectBox.SelectedIndex + 1 == XDrawer.DRAW_BOX)
            {
                boxToolStripMenuItem_Click(sender, e);
            }
            else if (toolStripSelectBox.SelectedIndex + 1 == XDrawer.DRAW_CIRCLE)
            {
                circleToolStripMenuItem_Click(sender, e);
            }
            else if (toolStripSelectBox.SelectedIndex + 1 == XDrawer.DRAW_KITE)
            {
                kiteToolStripMenuItem_Click(sender, e);
            }
        }

        private void treeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TreeForm tree = new TreeForm(this);
            tree.ShowDialog();
        }

        private void tableViewToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ListForm table = new ListForm(this);
            table.ShowDialog();
        }

        private void printToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDialog dialog = new PrintDialog();
            PrintDocument document = new PrintDocument();

            document.PrintPage += new PrintPageEventHandler(doPrint);
            dialog.Document = document;

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                document.Print();
            }
        }
        private void doPrint(object sender, PrintPageEventArgs ev)
        {
            Graphics g = ev.Graphics;
            Pen pen = new Pen(Color.DarkRed);

            foreach (Figure ptr in _figures)
            { 
                ptr.draw(g, pen);
            }
        }

        private void printPreviewToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintPreviewDialog dialog = new PrintPreviewDialog();
            PrintDocument document = new PrintDocument();

            document.PrintPage += new PrintPageEventHandler(doPrint);
            dialog.Document = document;

            dialog.ShowDialog();
        }        
    }
}