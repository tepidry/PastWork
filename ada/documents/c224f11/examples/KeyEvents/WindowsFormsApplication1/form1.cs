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
    public partial class KeyEvents : Form
    {
        public KeyEvents()
        {
            InitializeComponent();
        }

        private void KeyEvents_Load(object sender, EventArgs e)
        {

        }


        private void KeyEvents_KeyPress(object sender, KeyPressEventArgs e)
        {
          
           charLabel.Text = "Key Pressed: " + e.KeyChar;
           
        }


        private void KeyEvents_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                EnterStuff();
            }
            else
                OtherStuff(e);
        }

        private void EnterStuff()
        {
            string[] poem = new string[6];
            poem[0] = "I have seen them riding seaward on the waves\n";
            poem[1] = "Combing the white hair of the sea blown back\n";
            poem[2] = "While the wind blows the water white and black\n";
            poem[3] = "I have lingered in the chambers of the sea\n";
            poem[4] = "With sea nymphs ringed with seaweed red and brown\n";
            poem[5] = "Till human voices wake us and we drown\n";
            string newPoem = "";

            
            for (int i = 0; i < 6; i++)
            {
              newPoem = newPoem + poem[i];
            }
            enterLabel.Text = newPoem;
        }

        private void OtherStuff(KeyEventArgs e)
        {
            string altKey, shiftKey, controlKey, altKeyText, shiftKeyText, controlKeyText, keyCodeText, keyDataText, keyValueText;
            if (e.Alt)
                altKey = "Yes";
            else
                altKey = "No";
            if (e.Shift)
                shiftKey = "Yes";
            else
                shiftKey = "No";
            if (e.Control)
                controlKey = "Yes";
            else
                controlKey = "No";
            altKeyText = "Alt: " + altKey + '\n';
            shiftKeyText = "Shift: " + shiftKey + '\n';
            controlKeyText = "Ctrl: " + controlKey + '\n';
            keyCodeText = "Key Code " + e.KeyCode + '\n';
            keyDataText = "Key Data " + e.KeyData + '\n';
            keyValueText = "Key Value " + e.KeyValue + '\n';

            keyLabel.Text = altKeyText + shiftKeyText + controlKeyText + keyCodeText + keyDataText + keyValueText;

        }

        private void KeyEvents_KeyUp(object sender, KeyEventArgs e)
        {
            charLabel.Text = "";
            keyLabel.Text = "";
            enterLabel.Text = "";
        }

       

        
        
        
    }
}
