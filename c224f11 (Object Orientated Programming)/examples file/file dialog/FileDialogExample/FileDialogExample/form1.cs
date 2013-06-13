using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;


namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseClick(object sender, MouseEventArgs e)
        {

            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\Desktop";
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = (FileStream) openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            myStream.Seek(0, SeekOrigin.Begin);
                            for (int i = 0; i < myStream.Length; i++)
                                outBox.Text = outBox.Text + (Convert.ToChar(myStream.ReadByte()));
                            myStream.Close();
                     
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("File Error: " + ex.Message);
                }
            }
        }
    }
}
    

       
