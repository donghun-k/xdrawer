namespace XDrawer
{
    public partial class XDrawer : Form
    {
        static int DRAW_LINE = 2;
        static int DRAW_BOX = 3;
        static int DRAW_CIRCLE = 4;

        bool isClicked = false;

        int _whatToDraw;

        public Popup mainPopup;
        public Popup pointPopup;
        public Popup linePopup;
        public Popup boxPopup;
        public Popup circlePopup;

        public PictureBox Canvas
        {
            get
            {
                return canvas;
            }
        }

        Figure _selectedFigure;
        List<Figure> _figures;

        public XDrawer()
        {            
            InitializeComponent();
            _figures = new List<Figure>();
            _whatToDraw = DRAW_LINE;

            mainPopup = new MainPopup(this);
            pointPopup = new FigurePopup(this, "Point", false);
            linePopup = new FigurePopup(this, "Point", false);
            boxPopup = new FigurePopup(this, "Point", true);
            circlePopup = new FigurePopup(this, "Point", true);
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                pointPopup.popup(e.Location);
                
                return;
            }

            else if (_whatToDraw == DRAW_LINE)
            {
                // upcasting
                _selectedFigure = new Line(e.X, e.Y);                
            }
            else if (_whatToDraw == DRAW_BOX)
            {
                _selectedFigure = new Box(e.X, e.Y);
            }
            else if (_whatToDraw == DRAW_CIRCLE)
            {
                _selectedFigure = new Circle(e.X, e.Y);
            }           

            isClicked = true;
        }

        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {   
            if (isClicked == true)
            {
                int eX = e.X;
                int eY = e.Y;

                Graphics g = canvas.CreateGraphics();

                Pen pen = new Pen(Color.Black);

                // dynamic binding
                _selectedFigure.draw(g, pen);
                               
                g.Dispose(); // garbage collection!             
                
            }

            isClicked = false;
            
            if (e.Button == MouseButtons.Left)
            {
                _selectedFigure.makeRegion();
                _figures.Add(_selectedFigure);
            }            
            _selectedFigure = null;
            // reset canvas -> result in canvas_Paint()
            canvas.Invalidate();
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (isClicked == true)
            {
                int newX = e.X;
                int newY = e.Y;

                Graphics g = canvas.CreateGraphics();

                Pen pen = new Pen(Color.Black);
                Pen backPen = new Pen(canvas.BackColor);

                // remove temporary figure
                _selectedFigure.draw(g, backPen);
                // update X, Y
                _selectedFigure.setXY2(newX, newY);
                // draw temporary figure
                _selectedFigure.draw(g, pen);
                
                g.Dispose(); // garbage collection!
            }
        }

        public void addFigure(Figure fig)
        {
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

        public void boxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_BOX;
        }
        public void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_LINE;
        }
        public void circleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_CIRCLE;
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
    }
}