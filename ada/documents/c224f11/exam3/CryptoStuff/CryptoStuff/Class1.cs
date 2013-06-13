using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Utilities;
using MyExceptions;
using System.ComponentModel;
using System.Data;
using System.Windows.Forms;


namespace CryptoStuff
{

    public interface CryptoI
    {
        string Encrypt();
        string Decrypt();
    }

    public abstract class Crypto
    {
        public String CipherType { get; protected set; }

        public Crypto(String CipherTypeIn)
        {
            CipherType = CipherTypeIn;
        }

        public string Read()
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\Desktop";
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = (FileStream)openFileDialog1.OpenFile()) != null)
                    {
                        
                        using (myStream)
                        {
                            myStream.Seek(0, SeekOrigin.Begin);
                            for (int i = 0; i < myStream.Length; i++)
                                CipherType = CipherType + (Convert.ToChar(myStream.ReadByte()));
                            myStream.Close();

                        }
                    }
                }
                catch (FileNotFoundException ex)
                {
                    MessageBox.Show("File Error: " + ex.Message);
                    
                }
                
            }
            return CipherType;
        }

        public void Write(String Output)
        {
            Stream myStream = null;
            SaveFileDialog openFileDialog1 = new SaveFileDialog();

            openFileDialog1.InitialDirectory = "c:\\Desktop";
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = (Stream)openFileDialog1.OpenFile()) != null)
                    {
                        
                        using (myStream)
                        {
                            myStream.Seek(0, SeekOrigin.Begin);
                            byte[] byteArray = Encoding.ASCII.GetBytes(Output);
                            for (int i = 0; i < byteArray.Length; i++)
                                myStream.WriteByte(byteArray[i]);
                            myStream.Close();

                        }
                    }
                }
                catch (FileNotFoundException ex)
                {
                    MessageBox.Show("File Error: " + ex.Message);
                }
            }
        }
    }


    public class Affine : Crypto, CryptoI
    {
        
        
        string temp;
        int mult, shift;
        int tempCh, encr;
        public Affine(String AffineIn, int multiplier, int shiftAmount)
            : base(AffineIn) 
        {
            mult = multiplier;
            shift = shiftAmount;
            if (UtilitiesClass.FindGCD(mult, 26) == 1)
            {
                throw new InvalidMultiplier();
            }
            else if (shift <= 0 || shift >= 26)
            {
                throw new InvalidShiftAmount();
            }
        }

        public string Encrypt()
        {
            for (int i = 0; i < CipherType.Length; i++)
            {
                tempCh = Convert.ToInt32(CipherType[i]);
                if (tempCh <= 122 && tempCh >= 97)
                {
                    tempCh = tempCh - 97;
                    encr = (mult * tempCh + shift) % 26;
                    tempCh = encr + 97;
                }
                else if (tempCh <= 90 && tempCh >= 65)
                {
                    tempCh = tempCh - 65;
                    encr = (mult * tempCh + shift) % 26;
                    tempCh = encr + 65;
                }
                temp = temp + Convert.ToChar(tempCh);
            }
            CipherType = temp;  
            return CipherType;
            
        }

        public string Decrypt()
        {
            mult = UtilitiesClass.FindInverse(mult);
            
            for (int i = 0; i < CipherType.Length; i++)
            {
                tempCh = Convert.ToInt32(CipherType[i]);
                if (tempCh <= 122 && tempCh >= 97)
                {
                    tempCh = tempCh - 97;
                    if (tempCh < shift)
                        tempCh = tempCh + 26;
                    tempCh = (mult * (tempCh - shift)) % 26;
                    tempCh = tempCh + 97;
                }
                else if (tempCh <= 90 && tempCh >= 65)
                {
                    tempCh = tempCh - 65;
                    if (tempCh < shift)
                        tempCh = tempCh + 26;
                    tempCh = (mult * (tempCh - shift)) % 26;
                    tempCh = tempCh + 65;
                }
                temp = temp + Convert.ToChar(tempCh);
            }
            CipherType = temp;
            return CipherType;
        }

    }

    public class Vignere : Crypto, CryptoI
    {
        string key, temp;
        int tempCh, tempKey;
        public Vignere(String VignereIn, String Key)
            : base(VignereIn) 
        {
            key = Key;
            for (int i = 0; i < key.Length; i++)
            {
                tempCh = Convert.ToInt32(key[i]);
                if (tempCh < 97 || tempCh > 122 || key == "")
                {
                    throw new InvalidKey();
                }   

            }
        }

        public string Encrypt()
        {
            int j = 0;
            for (int i = 0; i < CipherType.Length; i++)
            {
                tempCh = Convert.ToInt32(CipherType[i]);

                if (tempCh <= 122 && tempCh >= 97)
                {
                    tempKey = Convert.ToInt32(key[j % key.Length]);
                    tempCh = tempCh - 97;
                    tempKey = tempKey - 97;
                    j++;
                    tempCh = (tempCh + tempKey) % 26;
                    tempCh = tempCh + 97;
                    tempKey = tempKey + 97;
                }
                temp = temp + Convert.ToChar(tempCh);
            }
            CipherType = temp;
            return CipherType;
        }

        public string Decrypt()
        {
            int j = 0;
            for (int i = 0; i < CipherType.Length; i++)
            {
                tempCh = Convert.ToInt32(CipherType[i]);
                if (tempCh <= 122 && tempCh >= 97)
                {
                    tempKey = Convert.ToInt32(key[j]);
                    j = (j + 1)% key.Length;
                    tempCh = tempCh - 97;
                    tempKey = tempKey - 97;
                    if (tempCh < tempKey)
                        tempCh = tempCh + 26;
                    tempCh = (tempCh - tempKey) % 26;
                    tempCh = tempCh + 97;
                    tempKey = tempKey + 97;
                }
                temp = temp + Convert.ToChar(tempCh);
            }
            CipherType = temp;
            return CipherType;
        }
    }
}

