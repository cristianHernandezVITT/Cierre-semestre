using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Security.Permissions;

namespace Holagera
{
    public partial class Form1 : Form
    {
        SerialPort puertoar;
        public Form1()
        {
            InitializeComponent();
            

        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            puertoar = new SerialPort();
            puertoar.PortName = "COM9";
            puertoar.BaudRate = 115200;
            puertoar.DtrEnable = true;
            try
            {
                puertoar.Open();
                MessageBox.Show("Sí se conectó :)");
            }
            catch (Exception ex)
            {
                MessageBox.Show("No está conectado" + ex);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                puertoar.WriteLine(textBox1.ToString());
                MessageBox.Show("Se envio correctamente");
            }
            catch(Exception ex)
            {
                MessageBox.Show("No se envió" +ex);
            }
        }
    }
}
