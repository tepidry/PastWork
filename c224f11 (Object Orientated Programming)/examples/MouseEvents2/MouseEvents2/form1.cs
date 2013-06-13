using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;


namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        ArrayList points; //see Chapter 23
        public Form1()
        {
            InitializeComponent();
            points = new ArrayList(1);
        }
        
        private void panel1_MouseClick(object sender, MouseEventArgs e)
        {
            Point pt = new Point(e.X, e.Y);
            points.Add(pt);
        }

        private void drawButton_MouseClick(object sender, MouseEventArgs e)
        {
            if (points.Count >= 2)
                using (Graphics graphics = panel1.CreateGraphics())
                {
                    Point[] pt = (Point[])points.ToArray(typeof(Point));
                    SolidBrush brush = new SolidBrush(Color.BlueViolet);
                    Pen pen = new Pen(brush);
                    graphics.DrawPolygon(pen, pt);
                }
            else
                MessageBox.Show("You must click at least twice.  Start over");
            points.Clear();
        }

        private void clearButton_MouseClick(object sender, MouseEventArgs e)
        {
            using (Graphics graphics = panel1.CreateGraphics())
                {
                   graphics.Clear(Color.White);
                }
        }
    }
}
