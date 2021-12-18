namespace GF_Bot
{
    partial class GF_Bot
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.lBind = new System.Windows.Forms.Label();
            this.bBind = new System.Windows.Forms.Button();
            this.lPseudo = new System.Windows.Forms.Label();
            this.tPseudo = new System.Windows.Forms.TextBox();
            this.llvl = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lBind
            // 
            this.lBind.AutoSize = true;
            this.lBind.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lBind.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lBind.Location = new System.Drawing.Point(12, 558);
            this.lBind.Name = "lBind";
            this.lBind.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lBind.Size = new System.Drawing.Size(102, 20);
            this.lBind.TabIndex = 0;
            this.lBind.Text = "Status: None";
            this.lBind.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            // 
            // bBind
            // 
            this.bBind.Location = new System.Drawing.Point(12, 581);
            this.bBind.Name = "bBind";
            this.bBind.Size = new System.Drawing.Size(1175, 31);
            this.bBind.TabIndex = 1;
            this.bBind.Text = "Bind";
            this.bBind.UseVisualStyleBackColor = true;
            this.bBind.Click += new System.EventHandler(this.bBind_Click);
            // 
            // lPseudo
            // 
            this.lPseudo.AutoSize = true;
            this.lPseudo.Location = new System.Drawing.Point(6, 16);
            this.lPseudo.Name = "lPseudo";
            this.lPseudo.Size = new System.Drawing.Size(49, 13);
            this.lPseudo.TabIndex = 2;
            this.lPseudo.Text = "Pseudo :";
            // 
            // tPseudo
            // 
            this.tPseudo.Location = new System.Drawing.Point(61, 13);
            this.tPseudo.Name = "tPseudo";
            this.tPseudo.ReadOnly = true;
            this.tPseudo.Size = new System.Drawing.Size(188, 20);
            this.tPseudo.TabIndex = 3;
            // 
            // llvl
            // 
            this.llvl.AutoSize = true;
            this.llvl.Location = new System.Drawing.Point(6, 42);
            this.llvl.Name = "llvl";
            this.llvl.Size = new System.Drawing.Size(39, 13);
            this.llvl.TabIndex = 4;
            this.llvl.Text = "Level :";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(51, 39);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(60, 20);
            this.textBox1.TabIndex = 6;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lPseudo);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.tPseudo);
            this.groupBox1.Controls.Add(this.llvl);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(389, 165);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Player - Base";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // GF_Bot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1199, 624);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.bBind);
            this.Controls.Add(this.lBind);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GF_Bot";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "GF_Bot";
            this.Load += new System.EventHandler(this.GF_Bot_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lBind;
        private System.Windows.Forms.Button bBind;
        private System.Windows.Forms.Label lPseudo;
        private System.Windows.Forms.TextBox tPseudo;
        private System.Windows.Forms.Label llvl;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

