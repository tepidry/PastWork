using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CryptoStuff;
using MyExceptions;

namespace CryptoGUI
{
    public partial class Form1 : Form
    {
        int multiplier = 11;
        int shift = 5;
        Affine Cryptic;
        Vignere AlphaCryptic;
        bool encrypt = true;
        bool decrypt = false;
        bool vignere = false;
        bool affine = true;
        public Form1()
        {
            InitializeComponent();
            Key.Text = "turing";
            Multiplier.Text = "11";
            Shift.Text = "5";
        }

        private void Read_Button_Click(object sender, EventArgs e)
        {
            if (affine == true)
            {
                string Str = Multiplier.Text.Trim();
                string Str2 = Shift.Text.Trim();
                int Num;
                bool isNum = int.TryParse(Str, out Num);
                bool isNum2 = int.TryParse(Str2, out Num);

                if (!isNum || !isNum2)
                {
                    MessageBox.Show("Error:: Check your Shift or Multiplier Invalid number");
                }
                else
                {
                    multiplier = Convert.ToInt32(Multiplier.Text);
                    shift = Convert.ToInt32(Shift.Text);
                }
                try
                {
                    Cryptic = new Affine(Input.Text, multiplier, shift);
                    Input.Text = Cryptic.Read();
                }
                catch (InvalidMultiplier ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
                catch (InvalidShiftAmount ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
              
            }
            else if (vignere == true)
            {
                try
                {
                    AlphaCryptic = new Vignere(Input.Text, Key.Text);
                    Input.Text = AlphaCryptic.Read();
                }
                catch (InvalidKey ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
            
        }

        private void Write_Button_Click(object sender, EventArgs e)
        {
            if (affine == true)
            {
                Cryptic.Write(Output.Text);
            }
            else if (vignere == true)
            {
                AlphaCryptic.Write(Output.Text);
            }
            else
            {
                MessageBox.Show("Please Select either Vignere or Affine.");
            }
        }

        private void Affine_CheckedChanged(object sender, EventArgs e)
        {
            vignere = false;
            affine = true;
        }

        private void Vignere_CheckedChanged(object sender, EventArgs e)
        {
            vignere = true;
            affine = false;
        }

        private void Go_Button_Click(object sender, EventArgs e)
        {
            if (affine == true)
            {
                if (Shift.Text == "" || Multiplier.Text == "")
                    MessageBox.Show("Please Make sure the shift amount and multiplier are entered.");
                
                string Str = Multiplier.Text.Trim();
                string Str2 = Shift.Text.Trim();
                int Num;
                bool isNum = int.TryParse(Str, out Num);
                bool isNum2 = int.TryParse(Str2, out Num);

                if (!isNum || !isNum2)
                    MessageBox.Show("Error:: Check your Shift or Multiplier Invalid number");
                else
                {
                    multiplier = Convert.ToInt32(Multiplier.Text);
                    shift = Convert.ToInt32(Shift.Text);
                }
                    
                
                if (encrypt == true)
                {
                    
                    try
                    {
                        Cryptic = new Affine(Input.Text, multiplier, shift);
                        Output.Text = Cryptic.Encrypt();
                    }
                    catch (InvalidMultiplier ex)
                    {
                        MessageBox.Show("Error: " + ex.Message);
                    }
                    catch (InvalidShiftAmount sh)
                    {
                        MessageBox.Show("Error: " + sh.Message);
                    }
                }
                else if (decrypt == true)
                {
                    
                    try
                    {
                        Cryptic = new Affine(Input.Text, multiplier, shift);
                        Output.Text = Cryptic.Decrypt();
                    }
                    catch (InvalidMultiplier ex)
                    {
                        MessageBox.Show("Error: " + ex.Message);
                    }
                    catch (InvalidShiftAmount sh)
                    {
                        MessageBox.Show("Error: " + sh.Message);
                    }
                }
                else
                {
                    MessageBox.Show("Please Select Encrypt or Decrypt");
                }
            }
            else if (vignere == true)
            {
                
                if (encrypt == true)
                {
                    try
                    {
                        AlphaCryptic = new Vignere(Input.Text, Key.Text);
                        Output.Text = AlphaCryptic.Encrypt();
                    }
                    catch (InvalidKey ex)
                    {
                        MessageBox.Show("Error: " + ex.Message);
                    }
                }
                else if (decrypt == true)
                {
                    try
                    {
                        AlphaCryptic = new Vignere(Input.Text, Key.Text);
                        Output.Text = AlphaCryptic.Decrypt();
                    }
                    catch (InvalidKey ex)
                    {
                        MessageBox.Show("Error: " + ex.Message);
                    }
                }
                else
                {
                    MessageBox.Show("Please Select Encrypt or Decrypt");
                }
            }
            else
            {
                MessageBox.Show("Please Select either Vignere or Affine.");
            }
        }

        private void Decrypt_CheckedChanged(object sender, EventArgs e)
        {
            encrypt = false;
            decrypt = true;
        }

        private void Encrypt_CheckedChanged(object sender, EventArgs e)
        {
            encrypt = true;
            decrypt = false;
        }

        private void Copy_Button_Click(object sender, EventArgs e)
        {
            Input.Text = Output.Text;
        }

        private void Clear_Button_Click(object sender, EventArgs e)
        {
            Output.Clear();
            Input.Clear();
        }
    }
}
