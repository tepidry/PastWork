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
   
    public partial class Form1 : Form
    {
        double total;
        double entered;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            total = 0;
            entered = 0;
            textBox1.Text = Convert.ToString('0');
        }

        private void button1_Click(object sender, EventArgs e)
        {
            initTextBox();  
            textBox1.Text = textBox1.Text + '1';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            initTextBox();  
            textBox1.Text = textBox1.Text + '2';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            initTextBox();  
            textBox1.Text = textBox1.Text + '3';
            entered = Convert.ToInt32(textBox1.Text);

        }

        private void button6_Click(object sender, EventArgs e)
        {
            initTextBox();  
            textBox1.Text = textBox1.Text + '4';
            entered = Convert.ToInt32(textBox1.Text);
        }
       

        //+
        private void button11_Click(object sender, EventArgs e)
        {
         
            total = total + Convert.ToInt32(textBox1.Text);
            //textBox1.Text = Convert.ToString(total);
            textBox1.Text = "";
        }

        //=
        private void button12_Click(object sender, EventArgs e)
        {
            total = total + entered;
            textBox1.Text = Convert.ToString(total);
        }

        //C
        private void button13_Click(object sender, EventArgs e)
        {
            total = 0;
            entered = 0;
            textBox1.Text = Convert.ToString('0');
        }
        private void initTextBox()
        {
            if (textBox1.Text == Convert.ToString('0'))
                textBox1.Text = "";
        }
    }
}
