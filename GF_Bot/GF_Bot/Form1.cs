using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GF_Bot
{
    public partial class GF_Bot : Form
    {
        public string GF_Process_Name = "GrandFantasia";
        public VAMemory Mem = new VAMemory();
        public GF_Bot()
        {
            InitializeComponent();
        }

        public void StatusNoneInit()
        {
            lBind.Text = "State: None";
            lBind.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            lBind.TextAlign = ContentAlignment.MiddleLeft;
        }
        public void InitBind()
        {
            foreach (Process P in Process.GetProcesses())
            {
                if (P.ProcessName.ToString() == GF_Process_Name)
                {
                    string fullpath = P.MainModule.FileName;
                    lBind.Text = fullpath;
                }
                Console.WriteLine(P.ProcessName.ToString());
            }

        }




        private void bBind_Click(object sender, EventArgs e)
        {
            InitBind();
        }

        private void GF_Bot_Load(object sender, EventArgs e)
        {

        }
    }

}
