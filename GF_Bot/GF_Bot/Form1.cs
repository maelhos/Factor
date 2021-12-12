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
        public static string GF_Process_Name = "GrandFantasia";
        public string GF_Path;
        public int GF_PID;
        public int GF_StartAdress;

        public VAMemory Mem = new VAMemory(GF_Process_Name);

        public bool bind;

        // OFFSETS
        int Offset_Pseudo = 0x965D44;
        int Offset_Charges = 0xC8;

        // Player Base offsets
        int Offset_base_p = 0x966924;
        int Offset_base_0 = 0x08;
        int Offset_base_1 = 0xE8;
        int Offset_base_2 = 0x10;
        int Offset_base_3 = 0x08;


        // Simple Non-Updating variables
        string Player_Pseudo;

        public GF_Bot()
        {
            InitializeComponent();
        }
        public bool InitBind()
        {
            foreach (Process P in Process.GetProcesses())
            {
                if (P.ProcessName.ToString() == GF_Process_Name)
                {
                    GF_Path = P.MainModule.FileName;
                    GF_PID = P.Id;
                    GF_StartAdress = (int)P.MainModule.BaseAddress;
                    return true;
                }
            }
            return false;

        }

        
        public void MainCheat()
        {
            // Pseudo
            Player_Pseudo = Mem.ReadStringASCII((IntPtr)(GF_StartAdress + Offset_Pseudo), 0xff);
            lPseudo.Text = Player_Pseudo;
        }

        private void bBind_Click(object sender, EventArgs e)
        {
            if (bind)
            {
                lBind.Text = "Status: None";
                lBind.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
                bBind.Text = "Bind";
                bind = false;
            }
            else
            {
                if (InitBind())
                {
                    bind = true;
                    lBind.Text = "Status: Bound successfully !";
                    lBind.ForeColor = System.Drawing.Color.Green;
                    bBind.Text = "UnBind";
                    MainCheat();
                }
                else
                {
                    bBind.Text = "Status: Bound Failed ...";
                    lBind.ForeColor = System.Drawing.Color.Red;
                }
            }
            
        }

        private void GF_Bot_Load(object sender, EventArgs e)
        {
            bind = false;
            lBind.Text = "Status: None";
            lBind.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            lBind.TextAlign = ContentAlignment.MiddleLeft;
        }
    }

}
