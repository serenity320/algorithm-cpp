namespace AlgorithmAssist
{
    partial class MainForm
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.notifyIcon = new System.Windows.Forms.NotifyIcon(this.components);
            this.contextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.txbInput1 = new System.Windows.Forms.TextBox();
            this.txbInput3 = new System.Windows.Forms.TextBox();
            this.txbInput2 = new System.Windows.Forms.TextBox();
            this.txbInput4 = new System.Windows.Forms.TextBox();
            this.txbInput5 = new System.Windows.Forms.TextBox();
            this.txbOutput1 = new System.Windows.Forms.TextBox();
            this.txbOutput2 = new System.Windows.Forms.TextBox();
            this.txbOutput3 = new System.Windows.Forms.TextBox();
            this.txbOutput4 = new System.Windows.Forms.TextBox();
            this.txbOutput5 = new System.Windows.Forms.TextBox();
            this.btnExample1 = new System.Windows.Forms.Button();
            this.btnExample2 = new System.Windows.Forms.Button();
            this.btnExample3 = new System.Windows.Forms.Button();
            this.btnExample4 = new System.Windows.Forms.Button();
            this.btnExample5 = new System.Windows.Forms.Button();
            this.contextMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // notifyIcon
            // 
            this.notifyIcon.ContextMenuStrip = this.contextMenuStrip;
            this.notifyIcon.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon.Icon")));
            this.notifyIcon.Text = "Algorithm Assist";
            this.notifyIcon.Visible = true;
            this.notifyIcon.DoubleClick += new System.EventHandler(this.notifyIcon_DoubleClick);
            // 
            // contextMenuStrip
            // 
            this.contextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.contextMenuStrip.Name = "contextMenuStrip";
            this.contextMenuStrip.Size = new System.Drawing.Size(94, 26);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(93, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // txbInput1
            // 
            this.txbInput1.Location = new System.Drawing.Point(12, 41);
            this.txbInput1.Multiline = true;
            this.txbInput1.Name = "txbInput1";
            this.txbInput1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbInput1.Size = new System.Drawing.Size(150, 300);
            this.txbInput1.TabIndex = 1;
            // 
            // txbInput3
            // 
            this.txbInput3.Location = new System.Drawing.Point(324, 41);
            this.txbInput3.Multiline = true;
            this.txbInput3.Name = "txbInput3";
            this.txbInput3.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbInput3.Size = new System.Drawing.Size(150, 300);
            this.txbInput3.TabIndex = 2;
            // 
            // txbInput2
            // 
            this.txbInput2.Location = new System.Drawing.Point(168, 41);
            this.txbInput2.Multiline = true;
            this.txbInput2.Name = "txbInput2";
            this.txbInput2.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbInput2.Size = new System.Drawing.Size(150, 300);
            this.txbInput2.TabIndex = 3;
            // 
            // txbInput4
            // 
            this.txbInput4.Location = new System.Drawing.Point(480, 41);
            this.txbInput4.Multiline = true;
            this.txbInput4.Name = "txbInput4";
            this.txbInput4.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbInput4.Size = new System.Drawing.Size(150, 300);
            this.txbInput4.TabIndex = 4;
            // 
            // txbInput5
            // 
            this.txbInput5.Location = new System.Drawing.Point(636, 41);
            this.txbInput5.Multiline = true;
            this.txbInput5.Name = "txbInput5";
            this.txbInput5.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbInput5.Size = new System.Drawing.Size(150, 300);
            this.txbInput5.TabIndex = 5;
            // 
            // txbOutput1
            // 
            this.txbOutput1.Location = new System.Drawing.Point(12, 347);
            this.txbOutput1.Multiline = true;
            this.txbOutput1.Name = "txbOutput1";
            this.txbOutput1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbOutput1.Size = new System.Drawing.Size(150, 100);
            this.txbOutput1.TabIndex = 6;
            // 
            // txbOutput2
            // 
            this.txbOutput2.Location = new System.Drawing.Point(168, 347);
            this.txbOutput2.Multiline = true;
            this.txbOutput2.Name = "txbOutput2";
            this.txbOutput2.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbOutput2.Size = new System.Drawing.Size(150, 100);
            this.txbOutput2.TabIndex = 7;
            // 
            // txbOutput3
            // 
            this.txbOutput3.Location = new System.Drawing.Point(324, 347);
            this.txbOutput3.Multiline = true;
            this.txbOutput3.Name = "txbOutput3";
            this.txbOutput3.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbOutput3.Size = new System.Drawing.Size(150, 100);
            this.txbOutput3.TabIndex = 8;
            // 
            // txbOutput4
            // 
            this.txbOutput4.Location = new System.Drawing.Point(480, 347);
            this.txbOutput4.Multiline = true;
            this.txbOutput4.Name = "txbOutput4";
            this.txbOutput4.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbOutput4.Size = new System.Drawing.Size(150, 100);
            this.txbOutput4.TabIndex = 9;
            // 
            // txbOutput5
            // 
            this.txbOutput5.Location = new System.Drawing.Point(636, 347);
            this.txbOutput5.Multiline = true;
            this.txbOutput5.Name = "txbOutput5";
            this.txbOutput5.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txbOutput5.Size = new System.Drawing.Size(150, 100);
            this.txbOutput5.TabIndex = 10;
            // 
            // btnExample1
            // 
            this.btnExample1.Location = new System.Drawing.Point(12, 12);
            this.btnExample1.Name = "btnExample1";
            this.btnExample1.Size = new System.Drawing.Size(150, 23);
            this.btnExample1.TabIndex = 11;
            this.btnExample1.Text = "Example 1";
            this.btnExample1.UseVisualStyleBackColor = true;
            this.btnExample1.Click += new System.EventHandler(this.btnExample1_Click);
            // 
            // btnExample2
            // 
            this.btnExample2.Location = new System.Drawing.Point(168, 12);
            this.btnExample2.Name = "btnExample2";
            this.btnExample2.Size = new System.Drawing.Size(150, 23);
            this.btnExample2.TabIndex = 12;
            this.btnExample2.Text = "Example 2";
            this.btnExample2.UseVisualStyleBackColor = true;
            this.btnExample2.Click += new System.EventHandler(this.btnExample2_Click);
            // 
            // btnExample3
            // 
            this.btnExample3.Location = new System.Drawing.Point(324, 12);
            this.btnExample3.Name = "btnExample3";
            this.btnExample3.Size = new System.Drawing.Size(150, 23);
            this.btnExample3.TabIndex = 13;
            this.btnExample3.Text = "Example 3";
            this.btnExample3.UseVisualStyleBackColor = true;
            this.btnExample3.Click += new System.EventHandler(this.btnExample3_Click);
            // 
            // btnExample4
            // 
            this.btnExample4.Location = new System.Drawing.Point(480, 12);
            this.btnExample4.Name = "btnExample4";
            this.btnExample4.Size = new System.Drawing.Size(150, 23);
            this.btnExample4.TabIndex = 14;
            this.btnExample4.Text = "Example 4";
            this.btnExample4.UseVisualStyleBackColor = true;
            this.btnExample4.Click += new System.EventHandler(this.btnExample4_Click);
            // 
            // btnExample5
            // 
            this.btnExample5.Location = new System.Drawing.Point(636, 12);
            this.btnExample5.Name = "btnExample5";
            this.btnExample5.Size = new System.Drawing.Size(150, 23);
            this.btnExample5.TabIndex = 15;
            this.btnExample5.Text = "Example 5";
            this.btnExample5.UseVisualStyleBackColor = true;
            this.btnExample5.Click += new System.EventHandler(this.btnExample5_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(799, 461);
            this.Controls.Add(this.btnExample5);
            this.Controls.Add(this.btnExample4);
            this.Controls.Add(this.btnExample3);
            this.Controls.Add(this.btnExample2);
            this.Controls.Add(this.btnExample1);
            this.Controls.Add(this.txbOutput5);
            this.Controls.Add(this.txbOutput4);
            this.Controls.Add(this.txbOutput3);
            this.Controls.Add(this.txbOutput2);
            this.Controls.Add(this.txbOutput1);
            this.Controls.Add(this.txbInput5);
            this.Controls.Add(this.txbInput4);
            this.Controls.Add(this.txbInput2);
            this.Controls.Add(this.txbInput3);
            this.Controls.Add(this.txbInput1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Algorithm Assist";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.contextMenuStrip.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NotifyIcon notifyIcon;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.TextBox txbInput1;
        private System.Windows.Forms.TextBox txbInput3;
        private System.Windows.Forms.TextBox txbInput2;
        private System.Windows.Forms.TextBox txbInput4;
        private System.Windows.Forms.TextBox txbInput5;
        private System.Windows.Forms.TextBox txbOutput1;
        private System.Windows.Forms.TextBox txbOutput2;
        private System.Windows.Forms.TextBox txbOutput3;
        private System.Windows.Forms.TextBox txbOutput4;
        private System.Windows.Forms.TextBox txbOutput5;
        private System.Windows.Forms.Button btnExample1;
        private System.Windows.Forms.Button btnExample2;
        private System.Windows.Forms.Button btnExample3;
        private System.Windows.Forms.Button btnExample4;
        private System.Windows.Forms.Button btnExample5;
    }
}

