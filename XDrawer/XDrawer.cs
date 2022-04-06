namespace XDrawer
{
    public partial class XDrawer : Form
    {
        int sX;
        int sY;
        public XDrawer()
        {            
            InitializeComponent();
        }

        private void XDrawer_Load(object sender, EventArgs e)
        {

        }

        private void canvas_MouseClick(object sender, MouseEventArgs e)
        {
            //MessageBox.Show("X ÁÂÇ¥ : " + e.X + "\nY ÁÂÇ¥ : " + e.Y + "\nÅ¬¸¯ ¹öÆ° : " + e.Button);
            sX = e.X;
            sY = e.Y;
        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            int eX = e.X;
            int eY = e.Y;

            Graphics g = canvas.CreateGraphics();

            Pen pen = new Pen(Color.Black);
            g.DrawRectangle(pen, Math.Min(sX, eX), Math.Min(sY, eY), Math.Abs(eX - sX), Math.Abs(eY - sY));

            g.Dispose(); // garbage collection!   
        }
    }
}