using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Utilities;




namespace WindowsFormsApplication1
{
   
    public partial class Form1 : Form
    {
        public int total;
        public int entered;
        public string op;
        public string baseNum;
        
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            baseNum = "";
            op = "";
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

        private void button4_Click(object sender, EventArgs e)
        {
            initTextBox();  
            textBox1.Text = textBox1.Text + '4';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '5';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '6';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '7';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '8';
            entered = Convert.ToInt32(textBox1.Text);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '9';
            entered = Convert.ToInt32(textBox1.Text);
        }

        //0
        private void button10_Click(object sender, EventArgs e)
        {
            initTextBox();
            textBox1.Text = textBox1.Text + '0';
            entered = Convert.ToInt32(textBox1.Text);
        }

        //+
        private void button11_Click(object sender, EventArgs e)
        {
            op = "+";
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
            else 
                total =  Convert.ToInt32(textBox1.Text);
            textBox1.Text = "";
            groupBox2.Enabled = false;
            button14.Enabled = false;
            button15.Enabled = false;
            button17.Enabled = false;
        }

        //=
        private void button12_Click(object sender, EventArgs e)
        {
            if (baseNum == "binary")
                entered = UtilitiesClass.ConvertToDecimal(textBox1.Text);

            if (op == "+")
                total = total + entered;
            else if (op == "-")
                total = total - entered;
            else if (op == "*")
                total = total * entered;
            else if (op == "/")
            {
                try
                {
                    total = total / entered;
                }
                catch (DivideByZeroException ex)
                {
                    textBox1.Text = Convert.ToString(ex.Message);
                }
            }
            else if (op == "gcd")
            {
                total = UtilitiesClass.FindGCD(total, entered);

            }

            if (baseNum == "binary")
                textBox1.Text = Convert.ToString(UtilitiesClass.ConvertToBinary(total));
            else
                textBox1.Text = Convert.ToString(total);

            groupBox1.Enabled = true;
            groupBox2.Enabled = true;
            groupBox3.Enabled = true;
            button11.Enabled = true;
            button14.Enabled = true;
            button15.Enabled = true;
            button17.Enabled = true;
        }

        //C
        private void button13_Click(object sender, EventArgs e)
        {
            op = "";
            total = 0;
            entered = 0;
            textBox1.Text = Convert.ToString('0');
        }
        private void initTextBox()
        {
            if (textBox1.Text == Convert.ToString('0'))
                textBox1.Text = "";
        }

        

        //x
        private void button15_Click(object sender, EventArgs e)
        {
            op = "*";
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
            else
                total = Convert.ToInt32(textBox1.Text);
            textBox1.Text = "";
            
            
        }

        //divide
        private void button17_Click(object sender, EventArgs e)
        {
            op = "/";
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
            else
                total = Convert.ToInt32(textBox1.Text);
            textBox1.Text = "";
            groupBox2.Enabled = false;
            button11.Enabled = false;
            button14.Enabled = false;
            button15.Enabled = false;
        }

        //GCD
        private void button19_Click(object sender, EventArgs e)
        {
            op = "gcd";
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
            else
                total = Convert.ToInt32(textBox1.Text);
            groupBox2.Enabled = false;
            groupBox3.Enabled = false;
            textBox1.Text = "";
        }

        //-
        private void button14_Click(object sender, EventArgs e)
        {
            op = "-";
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
            else
                total = Convert.ToInt32(textBox1.Text);
            textBox1.Text = "";
            groupBox2.Enabled = false;
            button11.Enabled = false;
            button15.Enabled = false;
            button17.Enabled = false;
        }

        //prime
        private void button18_Click(object sender, EventArgs e)
        {
            if (op != "prime")
            {
                op = "prime";
                total = Convert.ToInt32(textBox1.Text);
                if (UtilitiesClass.IsPrime(total))
                    textBox1.Text = "Prime";
                else
                    textBox1.Text = "Composite";
                groupBox3.Enabled = false;
                groupBox1.Enabled = false;
                radioButton3.Enabled = false;
                radioButton4.Enabled = false;
                button19.Enabled = false;
            }
            else
            {
                groupBox3.Enabled = true;
                groupBox1.Enabled = true;
                radioButton3.Enabled = true;
                radioButton4.Enabled = true;
                button19.Enabled = true;
                textBox1.Text = Convert.ToString(total);
            }
        }

        //To Binary
        private void radioButton3_Click(object sender, EventArgs e)
        {
            if (baseNum == "")
                textBox1.Text = UtilitiesClass.ConvertToBinary(entered);

            baseNum = "binary";
            button2.Enabled = false;
            button3.Enabled = false;
            button4.Enabled = false;
            button5.Enabled = false;
            button6.Enabled = false;
            button7.Enabled = false;
            button8.Enabled = false;
            button9.Enabled = false;
        }

        //To Decimal
        private void radioButton4_Click(object sender, EventArgs e)
        {
            if (baseNum == "binary")
                total = UtilitiesClass.ConvertToDecimal(textBox1.Text);
                textBox1.Text = Convert.ToString(entered);
            baseNum = "";
            button2.Enabled = true;
            button3.Enabled = true;
            button4.Enabled = true;
            button5.Enabled = true;
            button6.Enabled = true;
            button7.Enabled = true;
            button8.Enabled = true;
            button9.Enabled = true;
        }
    }
}
