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

        // Player Base offsets
        int Offset_base_P = 0x966924;
        int Offset_base_0 = 0x08;
        int Offset_base_1 = 0xE8;
        int Offset_base_2 = 0x10;
        int Offset_base_3 = 0x08;

        // Class Offset:
        int P_STR_GAME = 0x04;

        int P_MaxHP = 0x08;
        int P_MaxMP = 0x0C;

        int P_LVL = 0x1C;

        int P_FCE = 0x20;
        int P_INT = 0x24;
        int P_AGI = 0x28;
        int P_VOL = 0x2C;
        int P_VIT = 0x30;

        int P_ResHoly = 0x34;
        int P_ResShadow = 0x38;
        int P_ResLightning = 0x3C;
        int P_ResFire = 0x40;
        int P_ResIce = 0x44;
        int P_ResNature = 0x48;

        int P_HP = 0x4C;
        int P_MP = 0x50;

        int P_ATQ = 0x54;
        int P_ATQ_D = 0x58;
        int P_ATQ_M = 0x5C;

        int P_DEF = 0x60;
        int P_DEF_M = 0x64;
        int P_CRIT = 0xB0;
        int P_CRIT_M = 0xB4;
        int P_ESQ = 0x6C;

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
            tPseudo.Text = Player_Pseudo;
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
                    lBind.Text = "Status: Bound Failed ...";
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

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }
    }

}
