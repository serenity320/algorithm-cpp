using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace AlgorithmAssist.Modules
{
    public class GlobalHotkey
    {
        public static readonly int WM_HOTKEY_MSG_ID = 0x0312;

        private int _modifier;
        private int _key;
        private IntPtr _hWnd;
        private int _hashCode;
        private bool _isRegistered;

        public GlobalHotkey(int modifier, Keys keys, Form form)
        {
            _modifier = modifier;
            _key = (int)keys;
            _hWnd = form.Handle;
            _hashCode = GetHashCode();

            _isRegistered = false;
        }

        public override int GetHashCode()
        {
            return _modifier ^ _key ^ _hWnd.ToInt32();
        }

        public bool Register()
        {
            bool result = false;

            if (!_isRegistered)
            {
                result = RegisterHotKey(_hWnd, _hashCode, _modifier, _key);

                _isRegistered = result;
            }

            return result;
        }

        public bool Unregiser()
        {
            bool result = false;

            if (_isRegistered)
            {
                result = UnregisterHotKey(_hWnd, _hashCode);

                _isRegistered = !result;
            }

            return result;
        }

        [DllImport("user32.dll")]
        private static extern bool RegisterHotKey(IntPtr hWnd, int id, int fsModifiers, int vk);

        [DllImport("user32.dll")]
        private static extern bool UnregisterHotKey(IntPtr hWnd, int id);
    }
    
    public class ModifierKey
    {
        public static readonly int NOMOD = 0x0000;
        public static readonly int ALT = 0x0001;
        public static readonly int CTRL = 0x0002;
        public static readonly int SHIFT = 0x0004;
        public static readonly int WIN = 0x0008;
    }
}
