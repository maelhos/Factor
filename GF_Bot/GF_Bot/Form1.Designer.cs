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
            this.SuspendLayout();
            // 
            // lBind
            // 
            this.lBind.AutoSize = true;
            this.lBind.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lBind.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.lBind.Location = new System.Drawing.Point(347, 384);
            this.lBind.Name = "lBind";
            this.lBind.Size = new System.Drawing.Size(94, 20);
            this.lBind.TabIndex = 0;
            this.lBind.Text = "State: None";
            this.lBind.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // bBind
            // 
            this.bBind.Location = new System.Drawing.Point(12, 407);
            this.bBind.Name = "bBind";
            this.bBind.Size = new System.Drawing.Size(764, 31);
            this.bBind.TabIndex = 1;
            this.bBind.Text = "Bind";
            this.bBind.UseVisualStyleBackColor = true;
            this.bBind.Click += new System.EventHandler(this.bBind_Click);
            // 
            // GF_Bot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
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
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lBind;
        private System.Windows.Forms.Button bBind;
    }
}

