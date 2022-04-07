namespace XDrawer
{
    public partial class XDrawer : Form
    {
        int sX;
        int sY;
        int eX;
        int eY;
        bool isClicked = false;
        public XDrawer()
        {            
            InitializeComponent();
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            //MessageBox.Show("X ÁÂÇ¥ : " + e.X + "\nY ÁÂÇ¥ : " + e.Y + "\nÅ¬¸¯ ¹öÆ° : " + e.Button);
            sX = eX = e.X;
            sY = eY = e.Y;

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
                g.DrawRectangle(pen, Math.Min(sX, eX), Math.Min(sY, eY), Math.Abs(eX - sX), Math.Abs(eY - sY));

                g.Dispose(); // garbage collection!
            }       
            isClicked = false;
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

                g.DrawRectangle(backPen, Math.Min(sX, eX), Math.Min(sY, eY), Math.Abs(eX - sX), Math.Abs(eY - sY));
                g.DrawRectangle(pen, Math.Min(sX, newX), Math.Min(sY, newY), Math.Abs(newX - sX), Math.Abs(newY - sY));

                g.Dispose(); // garbage collection!

                eX = newX;
                eY = newY;
            }
        }
    }
}