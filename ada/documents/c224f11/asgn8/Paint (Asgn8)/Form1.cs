using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace Paint__Asgn8_
{
    public partial class Form1 : Form
    {
        private bool paint = false;
        private bool rainbow = false;
        int msize = 4;
        int index = 0;
        protected SolidBrush brush;
        protected Color color;
        protected Color[] refracted =  {System.Drawing.Color.Red, System.Drawing.Color.Orange, System.Drawing.Color.Yellow,
            System.Drawing.Color.Green, System.Drawing.Color.Blue, System.Drawing.Color.Indigo, System.Drawing.Color.Violet};

        public Form1()
        {
            InitializeComponent();
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            paint = true;
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            paint = false;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            SolidBrush brush;
            if (paint)
            {
                using (Graphics graphics = CreateGraphics())
                {
                    if (rainbow)
                    {
                        brush = new SolidBrush(refracted[index]);
                        index = (index + 1) % 7;
                    }
                    else
                    {
                        brush = new SolidBrush(color);
                    }
                    graphics.FillEllipse(brush, e.X, e.Y, msize, msize);
                    
                }
            }
        }

        private void Red_CheckChanged(object sender, EventArgs e)
        {
            rainbow = false;
            color = System.Drawing.Color.Red;
        }

        private void Blue_CheckedChanged(object sender, EventArgs e)
        {
            rainbow = false;
            color = System.Drawing.Color.Blue;
        }

        private void Green_CheckedChanged(object sender, EventArgs e)
        {
            rainbow = false;
            color = System.Drawing.Color.Green;
        }

        private void Black_CheckedChanged(object sender, EventArgs e)
        {
            rainbow = false;
            color = System.Drawing.Color.Black;
        }

        private void Rainbow_CheckedChanged(object sender, EventArgs e)
        {
            rainbow = true;
        }

        private void Random_CheckedChanged(object sender, EventArgs e)
        {
            rainbow = false;
            Random randonGen = new Random();
            color = System.Drawing.Color.FromArgb(randonGen.Next(255), randonGen.Next(255), randonGen.Next(255));
        }

        private void Small_CheckedChanged(object sender, EventArgs e)
        {
            msize = 5;
        }

        private void Medium_CheckedChanged(object sender, EventArgs e)
        {
            msize = 15;
        }

        private void Large_CheckedChanged(object sender, EventArgs e)
        {
            msize = 35;
        }
    }
}
