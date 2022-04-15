namespace XDrawer
{
    public partial class XDrawer : Form
    {
        static int DRAW_LINE = 2;
        static int DRAW_BOX = 3;
        static int DRAW_CIRCLE = 4;

        bool isClicked = false;

        int _whatToDraw;       

        Figure _selectedFigure;
        List<Figure> _figures;

        public XDrawer()
        {            
            InitializeComponent();
            _figures = new List<Figure>();
            _whatToDraw = DRAW_LINE;
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            if (_whatToDraw == DRAW_LINE)
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
            _figures.Add(_selectedFigure);

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

        private void boxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_BOX;
        }

        private void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_LINE;
        }

        private void circleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _whatToDraw = DRAW_CIRCLE;
        }
    }
}