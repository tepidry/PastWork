//Ryan Draper
//exam2
//rydraper@gmail.com

using System.Collections.Generic;
using System;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using Utilities;


namespace Paint__Asgn8_
{
    public partial class Form1 : Form
    {
        int Nth=5;
        int Kth=2;
        ArrayList points;
        private bool Bs = false;
        private bool sB = false;
        private bool loop = false;
        private bool paint = false;
        private bool rainbow = false;
        int msize = 40;
        int index = 0;
        protected SolidBrush brush;
        protected Color color = System.Drawing.Color.Red;
        protected Color[] refracted =  {System.Drawing.Color.Red, System.Drawing.Color.Orange, System.Drawing.Color.Yellow,
            System.Drawing.Color.Green, System.Drawing.Color.Blue, System.Drawing.Color.Indigo, System.Drawing.Color.Violet};

        public Form1()
        {
            InitializeComponent();
            points = new ArrayList(1);
            NTH.Text = Convert.ToString(Nth);
            KTH.Text = Convert.ToString(Kth);
        }

        private void panel1_MouseClick(object sender, MouseEventArgs e)
        {
            paint = true;
            panel1_MouseMove(sender, e);
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            paint = true;
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            paint = false;
        }

        private void S_to_B_CheckedChanged(object sender, EventArgs e)
        {
            boxSize.Enabled = false;
            msize = 5;
            sB = true;
            Bs = false;
        }

        private void B_to_S_CheckedChanged(object sender, EventArgs e)
        {
            boxSize.Enabled = false;
            msize = 200;
            Bs = true;
            sB = false;
        }

        private void Loop_CheckedChanged(object sender, EventArgs e)
        {
            boxSize.Enabled = false;
            msize = 10;
            Bs = false;
            sB = true;
            loop = true;
        }

        private void Regular_CheckedChanged(object sender, EventArgs e)
        {
            boxSize.Enabled = true;
            Small.Checked = true;
            sB = false;
            Bs = false;
            loop = false;
            msize = 40;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            Nth = Convert.ToInt32(NTH.Text);
            Kth = Convert.ToInt32(KTH.Text);
            if (UtilitiesClass.FindGCD(Nth, Kth) == 1)
            {
                SolidBrush brush;
                
                if (paint)
                {
                    if (sB)
                    {
                        if (msize == 200 && !loop)
                        {
                            msize = 5;
                        }
                        else if (msize == 195 && loop)
                        {
                            Bs = true;
                            sB = false;
                        }
                        msize = msize + 5;
                    }

                    if (Bs)
                    {
                        if (msize == 5 && !loop)
                        {
                            msize = 200;
                        }
                        else if (msize == 10 && loop)
                        {
                            sB = true;
                            Bs = false;
                        }
                        msize = msize - 5;
                    } 
                    Point plot = new Point(e.X + msize, e.Y);
                    points.Add(plot);
                    for (int i = 1; i < Nth; i++)
                    {
                        points.Add(new Point(e.X + Convert.ToInt32(Math.Cos((i * 2) * Math.PI / Nth) * msize), e.Y - Convert.ToInt32(Math.Sin((i * 2) * Math.PI / Nth) * msize)));
                    }
                    Point[] pt = (Point[])points.ToArray(typeof(Point));
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
                        Point[] star = new Point[Nth + 1];
                        int count, kP;
                        for (count = 0, kP = 0; count <= Nth; count++, kP = (kP + Kth) % Nth)
                        {
                            star[count] = pt[kP];
                        }
                        
                        graphics.FillPolygon(brush, star);
                    }
                }
            }
            else
            {
                MessageBox.Show("Your N and K values must be entered and relatively prime.");
                Nth = 1;
                Kth = 1;
            }
            points.Clear();
            
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
            msize = 40;
        }

        private void Medium_CheckedChanged(object sender, EventArgs e)
        {
            msize = 80;
        }

        private void Large_CheckedChanged(object sender, EventArgs e)
        {
            msize = 160;
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            using (Graphics graphics = CreateGraphics())
            {
                graphics.Clear(System.Drawing.Color.White);
            }
            boxSize.Enabled = true;
            Regular.Checked = true;

            Small.Checked = true;
            sB = false;
            Bs = false;
            loop = false;
            msize = 40;
        }
    }
}
