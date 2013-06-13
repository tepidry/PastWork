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
        private StreamReader stream;
        private string fileName;
        public Form1()
        {
            InitializeComponent();
            stream = null;
        }

        private void inputTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                //prevents the key event from being passed onto the underlying control.  
                //So prevents the text box from trying to display enter and causing the bell to sound.
                e.SuppressKeyPress = true;
                fileName = inputTextBox.Text;
                //input name is file
                if (File.Exists(fileName))
                    ProcessFile();
                else
                    //input name is a directory
                    if (Directory.Exists(fileName))
                        ProcessDirectory();
                    //input name is neither a file nor a directory
                    else
                    {
                        outputTextBox.Clear();
                        MessageBox.Show(inputTextBox.Text + ": does not exist", "File Error", MessageBoxButtons.OK,
                            MessageBoxIcon.Error);
                    }
            }   
        }

        private void ProcessDirectory()
        {
            GetInformation();
            string[] directoryList = Directory.GetDirectories(fileName);
            outputTextBox.AppendText("Directory contents:\n");
            foreach (string directory in directoryList)
                outputTextBox.AppendText(directory + "\n");
        }


        private void ProcessFile()
        {
            GetInformation();
            try
            {
                using (stream = new StreamReader(fileName))
                {
                    outputTextBox.AppendText(stream.ReadToEnd());
                }
            }
            catch (IOException)
            {
                MessageBox.Show("Error reading from file", "File Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
               
        }
        private void GetInformation()
        {
            outputTextBox.Clear();
            outputTextBox.AppendText(fileName + " exists\n");
            outputTextBox.AppendText("Created: " + File.GetCreationTime(fileName) + "\n");
            outputTextBox.AppendText("Last changed: " + File.GetLastWriteTime(fileName) + "\n");
            outputTextBox.AppendText("Last accessed: " + File.GetLastAccessTime(fileName) + "\n");
        }
    }
}
