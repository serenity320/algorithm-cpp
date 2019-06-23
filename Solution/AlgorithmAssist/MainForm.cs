using AlgorithmAssist.Modules;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace AlgorithmAssist
{
    public partial class MainForm : Form
    {
        HotkeyManager _hotkeyManager;
        ClipboardHelper _clipboardHelper;

        public MainForm()
        {
            InitializeComponent();

            _hotkeyManager = new HotkeyManager();
            _clipboardHelper = new ClipboardHelper();
        }

        protected override void WndProc(ref Message m)
        {
            if (m.Msg == GlobalHotkey.WM_HOTKEY_MSG_ID)
            {
                Keys key = (Keys)((m.LParam.ToInt32()) >> 16);

                switch (key)
                {
                    case Keys.D1:
                        _clipboardHelper.SetTextClipboard(txbInput1.Text, true);
                        break;

                    case Keys.D2:
                        _clipboardHelper.SetTextClipboard(txbInput2.Text, true);
                        break;

                    case Keys.D3:
                        _clipboardHelper.SetTextClipboard(txbInput3.Text, true);
                        break;

                    case Keys.D4:
                        _clipboardHelper.SetTextClipboard(txbInput4.Text, true);
                        break;

                    case Keys.D5:
                        _clipboardHelper.SetTextClipboard(txbInput5.Text, true);
                        break;
                }
            }

            base.WndProc(ref m);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            if (!_hotkeyManager.registerGlobalHotkey(ModifierKey.CTRL, Keys.D1, this) ||
                !_hotkeyManager.registerGlobalHotkey(ModifierKey.CTRL, Keys.D2, this) ||
                !_hotkeyManager.registerGlobalHotkey(ModifierKey.CTRL, Keys.D3, this) ||
                !_hotkeyManager.registerGlobalHotkey(ModifierKey.CTRL, Keys.D4, this) ||
                !_hotkeyManager.registerGlobalHotkey(ModifierKey.CTRL, Keys.D5, this))
            {
                _hotkeyManager.unregiserGlobalHotkeys();

                MessageBox.Show("Hotkey 초기화를 실패했습니다. 프로그램을 종료합니다.", "Algorithm Assist");
                Environment.Exit(1);
            }
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;

            Hide();
        }

        private void notifyIcon_DoubleClick(object sender, EventArgs e)
        {
            Show();

            if (WindowState == FormWindowState.Minimized)
            {
                WindowState = FormWindowState.Normal;
            }

            Activate();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _hotkeyManager.unregiserGlobalHotkeys();

            notifyIcon.Visible = false;

            Environment.Exit(1); //Application.Exit();
        }

        private void btnExample1_Click(object sender, EventArgs e)
        {
            _clipboardHelper.SetTextClipboard(txbInput1.Text, false);
        }

        private void btnExample2_Click(object sender, EventArgs e)
        {
            _clipboardHelper.SetTextClipboard(txbInput2.Text, false);
        }

        private void btnExample3_Click(object sender, EventArgs e)
        {
            _clipboardHelper.SetTextClipboard(txbInput3.Text, false);
        }

        private void btnExample4_Click(object sender, EventArgs e)
        {
            _clipboardHelper.SetTextClipboard(txbInput4.Text, false);
        }

        private void btnExample5_Click(object sender, EventArgs e)
        {
            _clipboardHelper.SetTextClipboard(txbInput5.Text, false);
        }
    }
}
