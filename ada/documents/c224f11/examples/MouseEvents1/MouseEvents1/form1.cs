using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace WindowsFormsApplication1
{
    public partial class Painter : Form
    {
        private bool paint = false;
        Point[] ptArray  = new Point[3]; 
        int numClicks = 0;

        public Painter()
        {
            InitializeComponent();
        }

        private void Painter_MouseDown(object sender, MouseEventArgs e)
        {
            paint = true;
        }

        private void Painter_MouseUp(object sender, MouseEventArgs e)
        {
            paint = false;
        }

        private void Painter_MouseMove(object sender, MouseEventArgs e)
        {
            if (paint)
            {
                using (Graphics graphics = CreateGraphics())
                {
                    SolidBrush brush = new SolidBrush(Color.BlueViolet);
                    graphics.FillEllipse(brush, e.X, e.Y, 4, 4);
                }
            }
        }

        private void Triangle_MouseClick(object sender, MouseEventArgs e)
        {
            numClicks = 0;
            using (Graphics graphics = CreateGraphics())
            {
                Pen myPen = new Pen(Color.Magenta);
                graphics.DrawLine(myPen, ptArray[0], ptArray[1]);
                graphics.DrawLine(myPen, ptArray[1], ptArray[2]);
                graphics.DrawLine(myPen, ptArray[2], ptArray[0]);
            }

        }

        private void Painter_MouseClick(object sender, MouseEventArgs e)
        {
            if (numClicks < 3)
            {
                ptArray[numClicks].X = e.X;
                ptArray[numClicks].Y = e.Y;
                numClicks++;
            }
     
        }

        private void Painter_Load(object sender, EventArgs e)
        {

        }
        
    }
}
